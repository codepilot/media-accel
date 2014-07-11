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

console.log
	MediaAccelMethod: MediaAccelMethod
	MediaAccelPath: MediaAccelPath

MediaAccel.FreeConsole()


global.MediaAccel = MediaAccel
global.gl = MediaAccel
global.glu = MediaAccel
global.User32 = MediaAccel
global.Gdi32 = MediaAccel
global.wgl = MediaAccel

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