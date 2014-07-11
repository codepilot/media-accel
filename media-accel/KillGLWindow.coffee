require('./media-accel') #adds MediaAccel, gl, wgl, glu, User32, Gdi32 to global space

shutdownErrorMessage = (msg) -> User32.MessageBox User32.NULL, msg, 'SHUTDOWN ERROR', User32.MB_OK | User32.MB_ICONEXCLAMATION

exports.KillGLWindow = KillGLWindow = (winObj)->                           #Properly Kill The Window
	if winObj.hRC                                                            #Do We Have A Rendering Context?
		unless gl.wglMakeCurrent(User32.NULL,User32.NULL)                         #Are We Able To Release The DC And RC Contexts?
			shutdownErrorMessage 'Release Of DC And RC Failed.'

		unless gl.wglDeleteContext(winObj.hRC)                                    #Are We Able To Delete The RC?
			shutdownErrorMessage 'Release Rendering Context Failed.'

	winObj.hRC=User32.NULL                                                   #Set RC To NULL

	if winObj.hDC
		unless User32.ReleaseDC(winObj.hWnd,winObj.hDC)                        #Are We Able To Release The DC
			shutdownErrorMessage 'Release Device Context Failed.'

	winObj.hDC=User32.NULL                                                   #Set DC To NULL

	if winObj.hWnd
		unless User32.DestroyWindow(winObj.hWnd)                               #Are We Able To Destroy The Window?
			shutdownErrorMessage 'Could Not Release hWnd.'

	winObj.hWnd=User32.NULL                                                  #Set hWnd To NULL

	unless User32.UnregisterClassW(winObj.wc.lpszClassName, winObj.hInstance) #Are We Able To Unregister Class
			shutdownErrorMessage 'Could Not Unregister Class.'

	winObj.wc=User32.NULL                                                    #Set wc To NULL
