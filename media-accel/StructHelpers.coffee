exports.add_fromObjects = (cls) ->
	cls.fromObjects = ->
		ret = new cls()
		for n in arguments
			for k, v of n
				ret[k] = v
		return ret

exports.add_toObject = (cls) ->
	Object.defineProperty cls.prototype, 'toObject',
		writable: false
		enumerable: false
		configurable : false
		value: ->
			sto={}
			for k of cls.prototype
				sto[k] = @[k]
				sto[k] = sto[k].toString 'hex' if Buffer.isBuffer sto[k]
			sto

exports.add_toString = (cls) ->
	Object.defineProperty cls.prototype, 'toString',
		writable: false
		enumerable: false
		configurable : false
		value: -> JSON.stringify @toObject(), undefined, ' '


exports.addStandardFunctions = (cls) ->
	exports.add_toObject cls
	exports.add_toString cls
	exports.add_fromObjects cls
