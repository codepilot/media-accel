require('./media-accel')

#console.log MediaAccel.Destructor

collectGarbage = ->
#	console.log 'collectGarbage before'
	gc() for i in [0...100]
#	console.log 'collectGarbage after'
	console.log ''

textureIDs = {}
textureID_next = 1

fake_glGenTexture = ->
	ret = textureID_next++
	textureIDs[ret] = 'allocated'
	console.log 'fake_glGenTexture', textureIDs
	ret

fake_glDeleteTexture = (texture)->
	console.log 'fake_glDeleteTexture', texture, textureIDs
	delete textureIDs[texture]
	console.log 'fake_glDeleteTexture deleted', texture, textureIDs
	textureIDs[texture]

class JsDestructor
	constructor: (@cb)->
		@CppDes = new MediaAccel.Destructor ->
		console.log 'cpp/js destructor!!!'
		cb?()

#class Texture
#	constructor: (@name='Unnamed_Texture')->
#		console.log 'Texture.constructor before', this
#		#@destructorObj = new MediaAccel.Destructor @destructor.bind @
#		#@destructorObj = new MediaAccel.Destructor @destructor
#		textureID = 1
#		#curThis = this
#		@destructorObj = new MediaAccel.Destructor ->
#			console.log 'Texture.destructor before', textureID: textureID
#			textureID = fake_glDeleteTexture textureID
#			console.log 'Texture.destructor after', textureID: textureID
#
#		
#		console.log 'Texture.constructor after', this
##	destructor: ->
##		console.log 'Texture.destructor before', this
##		@releaseTexture()
##		console.log 'Texture.destructor after', this
#	releaseTexture: ->
#		console.log 'releaseTexture before', this
#		#call glDeleteTextures...
#		delete @textureID
#		console.log 'releaseTexture after ', this
#	genTexture: ->
#		console.log 'genTexture before', this
#		#call glGenTextures...
#		@textureID = 1
#		console.log 'genTexture after ', this
#		#@destructorObj = new MediaAccel.Destructor @destructor.bind @
#		#console.log this

#class Texture
#	constructor: (@name='Unnamed_Texture')->
#		console.log 'Texture.constructor before', this
#
#		#item to reclaim must be inside of the constructor function, and thus private
#		textureID = 1
#
#		#keeping this alive disables the cpp destructor!
#		#curThis = this
#
#		@destructorObj = new MediaAccel.Destructor ->
#			console.log 'Texture.destructor before', textureID: textureID
#			textureID = fake_glDeleteTexture textureID
#			console.log 'Texture.destructor after', textureID: textureID
#
#			#keeping this alive disables the cpp destructor!
#			#console.log 'curThis', curThis
#
#		@releaseTexture = ->
#			console.log 'releaseTexture before', this
#			#call glDeleteTextures...
#			delete @textureID
#			console.log 'releaseTexture after ', this
#
#		@genTexture = ->
#			console.log 'genTexture before', this
#			#call glGenTextures...
#			@textureID = 1
#			console.log 'genTexture after ', this
#			#@destructorObj = new MediaAccel.Destructor @destructor.bind @
#			#console.log this
#
#		console.log 'Texture.constructor after', this

class Texture
	constructor: (name='Unnamed_Texture')->
		#console.log 'Texture.constructor before', this

		#item to reclaim must be inside of the constructor function, and thus private
		textureID = fake_glGenTexture()

		Object.defineProperty this, 'name',
			configurable: false
			enumerable: true
			writable: false
			value: name

		Object.defineProperty this, 'textureID',
			configurable: false
			enumerable: true
			get: -> textureID

		Object.defineProperty this, 'destructorObj',
			configurable: false
			enumerable: false
			writable: false
			value: new MediaAccel.Destructor ->
				#console.log 'Texture.destructor before', textureID: textureID
				if textureID?
					console.log 'Texture.destructor releasing textureID', textureID
					textureID = fake_glDeleteTexture textureID
				else
					console.log 'Texture.destructor not releasing textureID', textureID
				#console.log 'Texture.destructor after', textureID: textureID

		Object.defineProperty this, 'releaseTexture',
			configurable: false
			enumerable: false
			writable: false
			value: ->
				#console.log 'releaseTexture before', textureID
				textureID = fake_glDeleteTexture textureID
				#console.log 'releaseTexture after ', textureID

		Object.defineProperty this, 'genTexture',
			configurable: false
			enumerable: false
			writable: false
			value: ->
				#console.log 'genTexture before', this
				#call glGenTextures...
				unless textureID?
					textureID = fake_glGenTexture()
				#console.log 'genTexture after ', this
				#@destructorObj = new MediaAccel.Destructor @destructor.bind @
				#console.log this

		Object.freeze this
		#console.log 'Texture.constructor after', this
		return this

class TextureExtender extends Texture
	constructor: (@name='Unnamed_Texture')->
		console.log 'TextureExtender.constructor', this
	destructor: ->
		console.log 'TextureExtender.destructor', this
		@releaseTexture()
#	releaseTexture: ->
#		console.log 'TextureExtender.releaseTexture before', this
#		#call glDeleteTextures...
#		delete @textureID
#		console.log 'TextureExtender.releaseTexture after ', this
#	genTexture: ->
#		console.log 'TextureExtender.genTexture before', this
#		#call glGenTextures...
#		@textureID = 1
#		console.log 'TextureExtender.genTexture after ', this
#		#@destructorObj = new MediaAccel.Destructor @destructor.bind @
#		#console.log this



testDestructor = ->
#	jsDes = new MediaAccel.Destructor ->
#		console.log 'js destructor!!!'
	jsDes = new JsDestructor -> console.log 'interior'

#console.log testDestructor()

test_Texture_no_gen = ->
	console.log 'test_Texture_no_gen start'
	test = {}
	console.log 'test', test
	collectGarbage()

	test.tex = new Texture('A')
	console.log 'test', test
	collectGarbage()

	delete test.tex
	console.log 'test', test
	collectGarbage()

	test.tex = new Texture('A1')
	console.log 'test', test
	collectGarbage()

	test.tex.releaseTexture()
	console.log 'test', test
	collectGarbage()

	delete test.tex
	console.log 'test', test
	collectGarbage()

	test.tex = new Texture('A2')
	console.log 'test', test
	collectGarbage()

	test.tex.releaseTexture()
	console.log 'test', test
	collectGarbage()

	test.tex.genTexture()
	console.log 'test', test
	collectGarbage()

	delete test.tex
	console.log 'test', test
	collectGarbage()

	console.log 'test_Texture_no_gen end'




test_Texture_with_gen = ->
	console.log 'test_Texture_with_gen start'
	tex = new Texture('B')
	tex.genTexture()
	collectGarbage()
	console.log 'test_Texture_with_gen end'


test_TextureExtender_with_gen = ->
	console.log 'test_TextureExtender_with_gen start'
	tex = new TextureExtender('C')
	tex.genTexture()
	collectGarbage()
	console.log 'test_TextureExtender_with_gen end'


test_Texture_no_gen()
collectGarbage()


#test_Texture_with_gen()
#collectGarbage()
#
#
#test_TextureExtender_with_gen()
#collectGarbage()
#
#