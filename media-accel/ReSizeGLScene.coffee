require('./media-accel') #adds MediaAccel, gl, wgl, glu, User32, Gdi32 to global space

debugReSizeGLScene = false

exports.ReSizeGLScene = ReSizeGLScene = (width, height) -> # Resize And Initialize The GL Window
	if debugReSizeGLScene then console.log 'ReSizeGLScene', width: width, height: height
	unless height                                            # Prevent A Divide By Zero By
		height = 1                                             # Making Height Equal One

	gl.glViewport(0, 0, width, height)                       # Reset The Current Viewport

	gl.glMatrixMode(gl.GL_PROJECTION)                        # Select The Projection Matrix
	gl.glLoadIdentity()                                      # Reset The Projection Matrix

	glu.gluPerspective(45, width / height, 0.1, 100)         # Calculate The Aspect Ratio Of The Window

	gl.glMatrixMode(gl.GL_MODELVIEW)                         # Select The Modelview Matrix
	gl.glLoadIdentity()                                      # Reset The Modelview Matrix
