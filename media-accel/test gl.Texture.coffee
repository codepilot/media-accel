unless global.MediaAccel?
	require('./media-accel')


textureIDs = {}
textureID_next = 1

t =
	name: 'fake_gl'
	glGenTexture: ->
		ret = textureID_next++
		textureIDs[ret] = 'allocated'
		console.log 'fake_glGenTexture', Object.keys textureIDs
		ret

	glDeleteTexture: (texture)->
		#console.log 'fake_glDeleteTexture', texture, textureIDs
		delete textureIDs[texture]
		console.log 'fake_glDeleteTexture deleted', texture, Object.keys textureIDs
		textureIDs[texture]


require('./gl.Texture').init t

console.log t
if false
	do ->
		console.log t.Texture
	#	tex = new t.Texture()
		tex = new t.Texture()
		console.log 'tex toString', Object.toString(tex)
		console.log 'tex toString', typeof tex
		console.log 'tex', tex
		console.log Object.isFrozen(tex)
		console.log 'proto'
		console.log Object.getPrototypeOf(tex)
		console.log Object.getPrototypeOf(Object.getPrototypeOf(tex))

console.log 'textureIDs', Object.keys textureIDs

if true
	do ->
		console.log 'Array of texture', (new t.Texture() for i in [0...10])

console.log 'textureIDs', Object.keys textureIDs
console.log 'gc()'
gc()
console.log 'textureIDs', Object.keys textureIDs
