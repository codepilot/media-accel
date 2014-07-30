debugTexture = true

exports.init = (target)->

	target.GenTextures = GenTextures = (n)->
		param = new Uint32Array(n)

		errorBefore = target.glGetError()
		target.glGenTextures(n, param)
		errorAfter = target.glGetError()

		if debugTexture
			console.log 'GenTextures',
				errorBefore: errorBefore
				param: (n for n in param)
				errorAfter: errorAfter

		return if errorAfter

		for n in param
			continue if target.glIsTexture(n)
			n

	target.DeleteTextures = DeleteTextures = (n)->
		param = new Uint32Array(n)

		errorBefore = target.glGetError()
		target.glDeleteTextures(n, param)
		errorAfter = target.glGetError()

		if debugTexture
			console.log 'DeleteTextures',
				errorBefore: errorBefore
				param: (n for n in param)
				errorAfter: errorAfter

		return if errorAfter

		for n in param
			continue if target.glIsTexture(n)
			n
		return

	target.DeleteTexture = DeleteTexture = (n)-> DeleteTextures([n]); return
	target.GenTexture = GenTexture = -> return GenTextures(1)[0]

	target.Texture = class Texture
		constructor: ->
			textureIDsBuf = new Uint32Array(1)
			target.glGenTextures(textureIDsBuf.length, textureIDsBuf)

			Object.defineProperty this, 'destructorObj',
				value: new MediaAccel.Destructor ->
					target.glDeleteTextures textureIDsBuf.length, textureIDsBuf
					console.log '~Texture'

			Object.defineProperty this, 'textureID',
				get: ->
					textureIDsBuf[0]

			Object.defineProperty this, 'bind',
				value: (first = 0)->
					target.glBindTextures first, textureIDsBuf.length, textureIDsBuf

			Object.freeze this
			return this
	target.Texture.prototype = null

#	target.ArrayTexture = class ArrayTexture
#		constructor: (count, name='Unamed_Texture')->
#			return unless count
#			ids = GenTextures(count)
#			for i in ids
#				this.push(new Texture(name + '_' + i))
#
#			Object.defineProperty this, 'bind',
#				configurable: false
#				enumerable: false
#				writable: false
#				value: (first = 0)->
#					console.log 'bind', first
#					target.glBindTextures first, ids.length, new Uint32Array(ids)
#
#			return this
#
#	target.ArrayTexture.prototype = Array.prototype

	target.ArrayTexture = class ArrayTexture
		constructor: (count)->
			return unless count

			textureIDsBuf = new Uint32Array(count)

			target.glGenTextures(textureIDsBuf.length, textureIDsBuf)

			#item to reclaim must be inside of the constructor function, and thus private
			for n in textureIDsBuf
				this.push(n)

			Object.defineProperty this, 'destructorObj',
				value: new MediaAccel.Destructor ->
					target.glDeleteTextures textureIDsBuf.length, textureIDsBuf
					console.log '~ArrayTexture'

			Object.defineProperty this, 'bind',
				value: (first = 0)->
					target.glBindTextures first, textureIDsBuf.length, textureIDsBuf

#			Object.defineProperty this, 'generateMipmap',
#				value: (first = 0)->
#					for n in textureIDsBuf
#						glGenerateTextureMipmapEXT(
#					target.glBindTextures first, textureIDsBuf.length, textureIDsBuf

					
			Object.freeze this
			return this

	target.ArrayTexture.prototype = Array.prototype
