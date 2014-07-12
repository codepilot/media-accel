require('./media-accel')

CreateGLWindow = require('./CreateGLWindow').CreateGLWindow
WinStructs = require('./Win-Structs')
DrawGLScene = require('./DrawGLScene').DrawGLScene
ReSizeGLScene = require('./ReSizeGLScene').ReSizeGLScene
KillGLWindow = require('./KillGLWindow').KillGLWindow

debugWinMain = false


winObj =
	keys: new Buffer(new Array(256))
	hDC: undefined
	hRC: undefined
	hWnd: undefined
	hInstance: undefined
	wc: undefined
	fullscreen: false

done = false#Bool Variable To Exit Loop
active = true

mainLoop = ->
	if done
		if debugWinMain then console.log done: done
		#Shutdown
		#console.log 'Shutown'
		KillGLWindow(winObj)#Kill The Window
		return
	else
		setImmediate mainLoop

	msg = new WinStructs.MSG()
	pmStatus = User32.PeekMessage(msg, winObj.hWnd, 0, 0, User32.PM_REMOVE)
	if pmStatus #Is There A Message Waiting?
		if debugWinMain then console.log pmStatus: pmStatus
		if debugWinMain then console.log 'msg: ', msg.toObject()
		if msg.message is User32.WM_QUIT                  #Have We Received A Quit Message?
			console.log 'User32.WM_QUIT'
			done = true                                     #If So done=TRUE
		else                                              #If Not, Deal With Window Messages
			tmStatus = User32.TranslateMessage(msg)                    #Translate The Message
			if debugWinMain then console.log tmStatus: tmStatus
			dmStatus = User32.DispatchMessage(msg)                     #Dispatch The Message
			if debugWinMain then console.log dmStatus: dmStatus
	else                                                #If There Are No Messages
		dglsStatus = DrawGLScene()
#		if debugWinMain then console.log dglsStatus: dglsStatus
		if (active && !dglsStatus) || winObj.keys[User32.VK_ESCAPE] #Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene() Active?  Was There A Quit Received?
#			console.log 'dglsStatus', dglsStatus
			done = true                                     #ESC or DrawGLScene Signalled A Quit
		else                                              #Not Time To Quit, Update Screen
			sbStatus = User32.SwapBuffers(winObj.hDC)                         #Swap Buffers (Double Buffering)
			unless sbStatus
				if debugWinMain
					console.log
						sbStatus: sbStatus
						hDC: winObj.hDC

		if winObj.keys[User32.VK_F1]                             #Is F1 Being Pressed?
			winObj.keys[User32.VK_F1]=User32.FALSE                        #If So Make Key FALSE
			KillGLWindow(winObj)                                  #Kill Our Current Window
			winObj.fullscreen=!winObj.fullscreen                          #Toggle Fullscreen / Windowed Mode
			unless CreateGLWindow(winObj, 'NeHe\'s Solid Object Tutorial', 640, 480, 32, winObj.fullscreen) #Recreate Our OpenGL Window
				return 0                                      #Quit If Window Was Not Created
			else
				User32.FreeConsole()

exports.WinMain = WinMain = ->
	#Ask The User Which Screen Mode They Prefer
	winObj.fullscreen = User32.MessageBox(User32.NULL, 'Would You Like To Run In Fullscreen Mode?', 'Start FullScreen?', User32.MB_YESNO | User32.MB_ICONQUESTION) isnt User32.IDNO
	unless CreateGLWindow(winObj, 'NeHe\'s Solid Object Tutorial', 640, 480, 32, winObj.fullscreen)# Create Our OpenGL Window
		return 0                                            #Quit If Window Was Not Created

	ReSizeGLScene(640, 480)
	#gl.wglSwapIntervalEXT(0)
	setImmediate mainLoop
