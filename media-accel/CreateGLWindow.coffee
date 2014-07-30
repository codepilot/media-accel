#require('./media-accel')

debugCreateGLWindow = false

WinStructs = require('./Win-Structs')
ReSizeGLScene = require('./ReSizeGLScene').ReSizeGLScene
InitGL = require('./InitGL').InitGL
WindowProc = require('./WindowProc').WindowProc
KillGLWindow = require('./KillGLWindow').KillGLWindow

glGeti = require('./glGeti').glGeti
GL_GET_PNAME_FUNC = require('./glGeti').GL_GET_PNAME_FUNC


errorMessage = (msg) -> User32.MessageBox User32.NULL, msg, 'ERROR', User32.MB_OK | User32.MB_ICONEXCLAMATION

exports.CreateGLWindow = CreateGLWindow = (winObj, title, width, height, bits, fullscreenflag)->
	if debugCreateGLWindow
		console.log 'CreateGLWindow',
			title: title
			width: width
			height: height
			bits: bits
			fullscreenflag: fullscreenflag

	PixelFormat = undefined                                                         #(GLuint)Holds The Results After Searching For A Match
	#winObj.wc = undefined                                                                 #(WNDCLASS) Windows Class Structure
	#winObj.wc = new User32.WNDCLASSW()
	dwExStyle = undefined                                                           #(DWORD)  Window Extended Style
	dwStyle = undefined                                                             #(DWORD)  Window Style

	winObj.width = width
	winObj.height = height

	WindowRect = WinStructs.RECT.fromObjects                                     #(RECT)  Grabs Rectangle Upper Left / Lower Right Values
		left: 0                                                                        #Set Left Value To 0
		right: width                                                                   #Set Right Value To Requested Width
		top: 0                                                                         #Set Top Value To 0
		bottom: height                                                                 #Set Bottom Value To Requested Height

	winObj.fullscreen = fullscreenflag                                                     #Set The Global Fullscreen Flag

	winObj.hInstance = User32.GetModuleHandle()                                            #Grab An Instance For Our Window
	if debugCreateGLWindow then console.log 'winObj: ', winObj

	winObj.wc = User32.WNDCLASSW.fromObjects
		style: User32.CS_HREDRAW | User32.CS_VREDRAW | User32.CS_OWNDC   #Redraw On Size, And Own DC For Window.
		cbClsExtra: 0                                                    #No Extra Window Data
		cbWndExtra: 0                                                    #No Extra Window Data
		hbrBackground: User32.NULL                                       #No Background Required For GL
		#lpszMenuName: User32.NULL                                        #We Don't Want A Menu
		lpszClassName: 'OpenGL'                                          #Set The Class Name

	if debugCreateGLWindow then console.log 'winObj.wc: ', winObj.wc.toObject()

	winObj.wc.SetCallback (hWnd, uMsg, wParam, lParam)-> WindowProc(hWnd, uMsg, wParam, lParam, winObj)

	unless winObj.wc.RegisterClass()                                                       #Attempt To Register The Window Class
		errorMessage 'Failed To Register The Window Class.'
		return User32.FALSE                                                           #  Return FALSE

	if debugCreateGLWindow then console.log 'winObj.wc: ', winObj.wc.toObject()

	if winObj.fullscreen                                                #Are We Still In Fullscreen Mode?
		dwExStyle = User32.WS_EX_APPWINDOW | User32.WS_EX_TOPMOST
		dwStyle = User32.WS_VISIBLE | User32.WS_CLIPSIBLINGS | User32.WS_CLIPCHILDREN | User32.WS_POPUP
	else
		dwExStyle = User32.WS_EX_APPWINDOW | User32.WS_EX_WINDOWEDGE | User32.WS_EX_OVERLAPPEDWINDOW
		dwStyle = User32.WS_VISIBLE | User32.WS_CLIPSIBLINGS | User32.WS_CLIPCHILDREN | User32.WS_OVERLAPPEDWINDOW

	if debugCreateGLWindow then console.log 'WindowRect: ', WindowRect.toObject()

	User32.AdjustWindowRectEx(                                    #  Adjust Window To True Requested Size
		WindowRect,
		dwStyle,
		User32.FALSE,
		dwExStyle)

	if debugCreateGLWindow then console.log 'WindowRect: ', WindowRect.toObject()

	winObj.hWnd = User32.CreateWindowEx(
		dwExStyle,                                                 #  Extended Style For The Window
		'OpenGL',                                                  #  Class Name
		title,                                                     #  Window Title
		dwStyle,                                                   #  Required Window Style
		0, 0,                                                      #  Window Position
		WindowRect.right-WindowRect.left,                          #  Calculate Window Width
		WindowRect.bottom-WindowRect.top,                          #  Calculate Window Height
		User32.NULL,                                               #  No Parent Window
		User32.NULL,                                               #  No Menu
		winObj.hInstance,                                                 #  Instance
		winObj.wc.GetPointer())

	if debugCreateGLWindow then console.log 'winObj: ', winObj

	#  Create The Window
	unless winObj.hWnd                                                   #  Dont Pass Anything To WM_CREATE
		KillGLWindow(winObj)                                             #  Reset The Display
		errorMessage 'Window Creation Error.'
		return User32.FALSE                                        #  Return FALSE


	winObj.hDC=User32.GetDC(winObj.hWnd)
	if debugCreateGLWindow then console.log 'winObj: ', winObj

	unless winObj.hDC                                                   #  Did We Get A Device Context?
		KillGLWindow(winObj)                                             #  Reset The Display
		errorMessage 'Can\'t Create A GL Device Context.'
		return User32.FALSE                                        #  Return FALSE


	pfd = WinStructs.PIXELFORMATDESCRIPTOR.fromObjects
		nSize:      User32.sizeof_PIXELFORMATDESCRIPTOR            #  Size Of This Pixel Format Descriptor
		nVersion:   1                                              #  Version Number
		dwFlags:
			User32.PFD_DRAW_TO_WINDOW |                              #  Format Must Support Window
			User32.PFD_SUPPORT_OPENGL |                              #  Format Must Support OpenGL
			User32.PFD_DOUBLEBUFFER                                  #  Must Support Double Buffering
		iPixelType: User32.PFD_TYPE_RGBA                           #  Request An RGBA Format
		cColorBits: bits                                           #  Select Our Color Depth
		cDepthBits: 24                                             #  24Bit Z-Buffer (Depth Buffer)
		iLayerType: User32.PFD_MAIN_PLANE                          #  Main Drawing Layer

	if debugCreateGLWindow then console.log 'pfd: ', pfd.toObject()

	PixelFormat = User32.ChoosePixelFormat(winObj.hDC,pfd)
	if debugCreateGLWindow then console.log PixelFormat: PixelFormat

#	PixelFormat = 101

	unless PixelFormat                                           #  Did Windows Find A Matching Pixel Format?
		KillGLWindow(winObj)                                             #  Reset The Display
		return User32.FALSE                                        #  Return FALSE


	spfStatus = User32.SetPixelFormat(winObj.hDC,PixelFormat,pfd)
	if debugCreateGLWindow then console.log spfStatus: spfStatus

	unless spfStatus                                             #  Are We Able To Set The Pixel Format?
		KillGLWindow(winObj)                                             #  Reset The Display
		errorMessage 'Can\'t Set The PixelFormat.'
		return User32.FALSE                                        #  Return FALSE


	winObj.hRC = User32.wglCreateContext(winObj.hDC)
	if debugCreateGLWindow then console.log 'winObj: ', winObj

	unless winObj.hRC                                                   #  Are We Able To Get A Rendering Context?
		KillGLWindow(winObj)                                             #  Reset The Display
		errorMessage 'Can\'t Create A GL Rendering Context.'
		return User32.FALSE                                        #  Return FALSE


	glmcStatus = User32.wglMakeCurrent(winObj.hDC,winObj.hRC)

	global.gl = new MediaAccel.OpenGL()
	global.wgl = new MediaAccel.WGL()
	
	require('./gl.Texture').init gl

	MediaAccel.GlErrorAbort('CreateGLWindow: 156')

	if 0
		for k, v of GL_GET_PNAME_FUNC
			gotten = glGeti gl[k], 0
			error = gl.glGetError()
			if error
				console.log k
				console.log error
				console.log gotten
				console.log ''
			else
				console.log k, gotten
			#glGeti gl[k], 0

#	console.log 'GL_ALIASED_LINE_WIDTH_RANGE', glGeti gl.GL_ALIASED_LINE_WIDTH_RANGE

	#GLAPI const GLubyte *APIENTRY glGetStringi (GLenum name, GLuint index);
		#GL_EXTENSIONS
			#For glGetStringi only, returns the extension string supported by the implementation at index.
	gl.glGetStrings = (name)->
		ret = []
		loop
			errorBefore = gl.glGetError()
			n = gl?.glGetStringi? name, ret.length
			errorAfter = gl.glGetError()
			break if errorAfter
			if n?.length
				ret.push n
			else
				break
		if ret.length
			return ret
		else
			errorBefore = gl.glGetError()
			ret = gl.glGetString(name)
			errorAfter = gl.glGetError()
			return if errorAfter
			return ret

	MediaAccel.GlErrorAbort('CreateGLWindow: 189')


	if debugCreateGLWindow then console.log 'GL_VENDOR:                   ', gl.glGetStrings(gl.GL_VENDOR)
	if debugCreateGLWindow then console.log 'GL_RENDERER:                 ', gl.glGetStrings(gl.GL_RENDERER)
	if debugCreateGLWindow then console.log 'GL_VERSION:                  ', gl.glGetStrings(gl.GL_VERSION)
	if debugCreateGLWindow then console.log 'GL_SHADING_LANGUAGE_VERSION: ', gl.glGetStrings(gl.GL_SHADING_LANGUAGE_VERSION)
	if debugCreateGLWindow then console.log 'GL_EXTENSIONS:               ', gl.glGetStrings(gl.GL_EXTENSIONS)

	MediaAccel.GlErrorAbort('CreateGLWindow: 198')

	for n in gl.glGetStrings(gl.GL_EXTENSIONS)
		if n?.length
			gl[n] = true

	MediaAccel.GlErrorAbort('CreateGLWindow: 202')

	#GLAPI const GLubyte *APIENTRY glGetString (GLenum name);
		#GL_VENDOR
			#Returns the company responsible for this GL implementation. This name does not change from release to release.
		#GL_RENDERER
			#Returns the name of the renderer. This name is typically specific to a particular configuration of a hardware platform. It does not change from release to release.
		#GL_VERSION
			#Returns a version or release number.
		#GL_SHADING_LANGUAGE_VERSION
			#Returns a version or release number for the shading language.

	if debugCreateGLWindow then console.log 'wglGetExtensionsStringEXT', wgl.wglGetExtensionsStringEXT?().split(' ')
		#GLAPI const char *APIENTRY wglGetExtensionsStringEXT ();

	if debugCreateGLWindow then console.log 'wglGetExtensionsStringARB', wgl.wglGetExtensionsStringARB?(winObj.hDC).split(' ')
		#GLAPI const char *APIENTRY wglGetExtensionsStringARB (HDC hdc);

	MediaAccel.GlErrorAbort('CreateGLWindow: 218')

	for n in wgl.wglGetExtensionsStringEXT?().split(' ')
		if n?.length
			wgl[n] = true

	for n in wgl.wglGetExtensionsStringARB?(winObj.hDC).split(' ')
		if n?.length
			wgl[n] = true

	MediaAccel.GlErrorAbort('CreateGLWindow: 226')

	if debugCreateGLWindow then console.log gl: gl
	if debugCreateGLWindow then console.log gl: wgl


	if debugCreateGLWindow then console.log glmcStatus: glmcStatus

	unless glmcStatus                                            #  Try To Activate The Rendering Context
		KillGLWindow(winObj)                                             #  Reset The Display
		errorMessage 'Can\'t Activate The GL Rendering Context.'
		return User32.FALSE                                        #  Return FALSE


	swStatus = User32.ShowWindow(winObj.hWnd, User32.SW_SHOW)                      #  Show The Window
	if debugCreateGLWindow then console.log swStatus: swStatus

	sfwStatus = User32.SetForegroundWindow(winObj.hWnd)                             #  Slightly Higher Priority
	if debugCreateGLWindow then console.log sfwStatus: sfwStatus

	sfStatus = User32.SetFocus(winObj.hWnd)                                        #  Sets Keyboard Focus To The Window
	if debugCreateGLWindow then console.log sfStatus: sfStatus

	MediaAccel.GlErrorAbort('CreateGLWindow: 247')

	ReSizeGLScene(winObj, width, height)                                 #  Set Up Our Perspective GL Screen

	MediaAccel.GlErrorAbort()

	initStatus = InitGL(width, height)
	if debugCreateGLWindow then console.log initStatus: initStatus

	#unless initStatus                                            #  Initialize Our Newly Created GL Window
	#	console.log initStatus: initStatus
	#	KillGLWindow(winObj)                                             #  Reset The Display
	#	errorMessage 'Initialization Failed.'
	#	return User32.FALSE                                               #  Return FALSE

	return User32.TRUE                                           #  Success