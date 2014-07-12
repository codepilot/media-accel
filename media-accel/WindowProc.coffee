#require('./media-accel')

ReSizeGLScene = require('./ReSizeGLScene').ReSizeGLScene
WinStructs = require('./Win-Structs')

debugWindowProc = false

exports.WindowProc = WindowProc = (hWnd, uMsg, wParam, lParam, winObj) ->
	if false
		console.log 'WindowProc', JSON.stringify
			hWnd: hWnd
			uMsg: uMsg
			wParam: wParam
			lParam: lParam

	if debugWindowProc then console.log 'WindowProc: ',
		hWnd: hWnd
		uMsg: uMsg
		wParam: wParam
		lParam: lParam
		arguments: arguments
#		this: this

	switch uMsg                                                                            # Check For Windows Messages
		when User32.WM_ACTIVATE                                                              # Watch For Window Activate Message
			if debugWindowProc then console.log 'WM_ACTIVATE'
			                                                                                   # LoWord Can Be WA_INACTIVE, WA_ACTIVE, WA_CLICKACTIVE,
			                                                                                   # The High-Order Word Specifies The Minimized State Of The Window Being Activated Or Deactivated.
			                                                                                   # A NonZero Value Indicates The Window Is Minimized.
			if ((User32.LOWORD(wParam) != User32.WA_INACTIVE) && !(User32.HIWORD(wParam)))
				if debugWindowProc then console.log 'WndProc: WM_ACTIVATE TRUE'
				active=User32.TRUE                                                                      # Program Is Active
				return 0                                                                           # Return To The Message Loop
			else
				if debugWindowProc then console.log 'WndProc: WM_ACTIVATE FALSE'
				active=User32.FALSE                                                                     # Program Is No Longer Active
				return 0                                                                           # Return To The Message Loop

		when User32.WM_SYSCOMMAND#Intercept System Commands
			switch wParam                                                                      # Check System Calls
				when User32.SC_SCREENSAVE                                                        # Screensaver Trying To Start?
					if debugWindowProc then console.log ' WndProc: WM_SYSCOMMAND SC_SCREENSAVE'
					return 0							                                                         # Prevent From Happening
				when User32.SC_MONITORPOWER                                                      # Monitor Trying To Enter Powersave?
					if debugWindowProc then console.log 'WndProc: WM_SYSCOMMAND SC_MONITORPOWER'
					return 0							                                                         # Prevent From Happening

		when User32.WM_CLOSE                                                                 #Did We Receive A Close Message?
			if debugWindowProc then console.log 'WndProc: WM_CLOSE'
			User32.PostQuitMessage(0)                                                          # Send A Quit Message
			return 0                                                                           # Jump Back

		when User32.WM_KEYDOWN                                                               #Is A Key Being Held Down?
			if debugWindowProc then console.log 'WndProc: WM_KEYDOWN', wParam: wParam
			winObj.keys[wParam] = User32.TRUE                                                         # If So, Mark It As TRUE
			switch String.fromCharCode(wParam)
				#when 'V' then gl.wglSwapIntervalEXT(not gl.wglGetSwapIntervalEXT())
				when 'F'
					

					if (winObj.fullscreen = !winObj.fullscreen)                                         #Are We Still In Fullscreen Mode?
						dwExStyle = User32.WS_EX_APPWINDOW | User32.WS_EX_TOPMOST
						dwStyle = User32.WS_VISIBLE | User32.WS_CLIPSIBLINGS | User32.WS_CLIPCHILDREN | User32.WS_POPUP
					else
						dwExStyle = User32.WS_EX_APPWINDOW | User32.WS_EX_WINDOWEDGE | User32.WS_EX_OVERLAPPEDWINDOW
						dwStyle = User32.WS_VISIBLE | User32.WS_CLIPSIBLINGS | User32.WS_CLIPCHILDREN | User32.WS_OVERLAPPEDWINDOW

					old_dwExStyle = User32.SetWindowLongPtr(winObj.hWnd, User32.GWL_EXSTYLE, dwExStyle)
					old_dwStyle = User32.SetWindowLongPtr(winObj.hWnd, User32.GWL_STYLE, dwStyle)

			return 0                                                                           # Jump Back

		when User32.WM_KEYUP                                                                 #Has A Key Been Released?
			if debugWindowProc then console.log 'WndProc: WM_KEYUP', wParam: wParam
			winObj.keys[wParam] = User32.FALSE                                                        # If So, Mark It As FALSE
			return 0                                                                           # Jump Back

		when User32.WM_SIZE                                                                         #Resize The OpenGL Window
			if debugWindowProc
				console.log 'WndProc: WM_SIZE', 
					x: User32.LOWORD(lParam)
					y: User32.HIWORD(lParam)

			ReSizeGLScene(User32.LOWORD(lParam), User32.HIWORD(lParam))                                       # LoWord=Width, HiWord=Height
			return 0                                                                           # Jump Back
		else
			if debugWindowProc then console.log 'Message not in main switch', uMsg

	if debugWindowProc then console.log 'calling DefWindowProc', [hWnd,uMsg,wParam,lParam]
	defRet = User32.DefWindowProc(hWnd,uMsg,wParam,lParam)
	if debugWindowProc then console.log defRet: defRet
	return defRet