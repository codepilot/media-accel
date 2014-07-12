#require('./media-accel')

debugReSizeGLScene = false

gluPerspective = (fovY, aspect, zNear, zFar)->
	fH = Math.tan( fovY * Math.PI / 360) * zNear;
	fW = fH * aspect;
	gl.glFrustum( -fW, fW, -fH, fH, zNear, zFar );


exports.ReSizeGLScene = ReSizeGLScene = (width, height) -> # Resize And Initialize The GL Window
	return unless global.gl?
	if debugReSizeGLScene then console.log 'ReSizeGLScene', width: width, height: height
	unless height                                            # Prevent A Divide By Zero By
		height = 1                                             # Making Height Equal One

	gl.glViewport(0, 0, width, height)                       # Reset The Current Viewport

	gl.glMatrixMode(gl.GL_PROJECTION)                        # Select The Projection Matrix
	gl.glLoadIdentity()                                      # Reset The Projection Matrix

	gluPerspective(45, width / height, 0.1, 100)         # Calculate The Aspect Ratio Of The Window

	gl.glMatrixMode(gl.GL_MODELVIEW)                         # Select The Modelview Matrix
	gl.glLoadIdentity()                                      # Reset The Modelview Matrix
