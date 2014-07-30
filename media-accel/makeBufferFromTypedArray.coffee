exports.makeBufferFromTypedArray = (ta)->
	ret = new Buffer ta.buffer.byteLength
	#for n, i in ta.buffer
	#	ret[i] = n
	for i in [0...ta.buffer.byteLength]
		ret[i] = ta.buffer[i]
	return ret

	console.log ret
	console.log ta.buffer

	return ret

