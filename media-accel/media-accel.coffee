#process
#	.on 'uncaughtException', (err)->
#		console.log 'Caught exception: ' + err


try
	MediaAccelMethod = 'process.argv[2]'
	MediaAccelPath = process.argv[2]
	MediaAccel = require(MediaAccelPath)
catch
	try
		MediaAccelMethod = 'Release x64'
		MediaAccelPath = './../x64/Release/media-accel.node'
		MediaAccel = require(MediaAccelPath)
	catch
		try
			MediaAccelMethod = 'Debug x64'
			MediaAccelPath = './../x64/Debug/media-accel.node'
			MediaAccel = require(MediaAccelPath)
		catch
			console.log 'Cannot find media-accel.node'
			process.exit 1

#console.log
#	MediaAccelMethod: MediaAccelMethod
#	MediaAccelPath: MediaAccelPath

global.MediaAccel = MediaAccel
#global.gl
#global.glu = MediaAccel
global.User32 = MediaAccel
global.GL_CONST = MediaAccel
#global.Gdi32 = MediaAccel
#global.wgl = MediaAccel
global.GDIPLUS = new MediaAccel.GDIPLUS()


log = ->
	console.log.apply console, arguments
	MediaAccel.OutputDebugString.apply MediaAccel, [String(arguments[0]) + '\n']


MediaAccel.WNDCLASSW.prototype.toObject = ->
	style:         @style
	lpfnWndProc:   @lpfnWndProc
	cbClsExtra:    @cbClsExtra
	cbWndExtra:    @cbWndExtra
	hInstance:     @hInstance
	hIcon:         @hIcon
	hCursor:       @hCursor
	hbrBackground: @hbrBackground
	lpszMenuName:  @lpszMenuName
	lpszClassName: @lpszClassName
	RegisterClass: @RegisterClass

	User32.WNDCLASSW.prototype.toObject = ->
	style:         @style
	lpfnWndProc:   @lpfnWndProc
	cbClsExtra:    @cbClsExtra
	cbWndExtra:    @cbWndExtra
	hInstance:     @hInstance
	hIcon:         @hIcon
	hCursor:       @hCursor
	hbrBackground: @hbrBackground
	lpszMenuName:  @lpszMenuName
	lpszClassName: @lpszClassName
	RegisterClass: @RegisterClass
	ClassATOM:     @ClassATOM

User32.WNDCLASSW.prototype.toString = -> return JSON.stringify @toObject()

StructHelpers = require('./StructHelpers')

StructHelpers.add_fromObjects MediaAccel.WNDCLASSW

#console.log MediaAccel.class_OpenGL.prototype
#console.log global.gl, gl.glViewport


#console.log GL_CONST
#console.log MediaAccel.OpenGL.prototype.GL_ALWAYS_FAST_HINT_PGI

MediaAccel.GlErrorAbort =(location) ->
	error = gl.glGetError()
	errorStr = ''
	if error
		switch error
			when gl.GL_INVALID_ENUM then errorStr = 'GL_INVALID_ENUM'
			when gl.GL_INVALID_VALUE then errorStr = 'GL_INVALID_VALUE'
			when gl.GL_INVALID_OPERATION then errorStr = 'GL_INVALID_OPERATION'
			when gl.GL_STACK_OVERFLOW then errorStr = 'GL_STACK_OVERFLOW'
			when gl.GL_STACK_OVERFLOW_KHR then errorStr = 'GL_STACK_OVERFLOW_KHR'
			when gl.GL_STACK_UNDERFLOW then errorStr = 'GL_STACK_UNDERFLOW'
			when gl.GL_STACK_UNDERFLOW_KHR then errorStr = 'GL_STACK_UNDERFLOW_KHR'
			when gl.GL_OUT_OF_MEMORY then errorStr = 'GL_OUT_OF_MEMORY'
			when gl.GL_INVALID_FRAMEBUFFER_OPERATION then errorStr = 'GL_INVALID_FRAMEBUFFER_OPERATION'
			when gl.GL_INVALID_FRAMEBUFFER_OPERATION_EXT then errorStr = 'GL_INVALID_FRAMEBUFFER_OPERATION_EXT'
			when gl.GL_INVALID_FRAMEBUFFER_OPERATION_OES then errorStr = 'GL_INVALID_FRAMEBUFFER_OPERATION_OES'

		console.log 'gl.glGetError()', errorStr, '0x' + error.toString(16), location
		process.exit error
	else
		#console.log 'gl.glGetError() No Error', location