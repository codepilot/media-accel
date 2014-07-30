debugInitGL = false

exports.InitGL_05 = InitGL = (width, height) ->                   #All Setup For OpenGL Goes Here
	if debugInitGL
		console.log 'InitGL', width, height

	unless global.gl?
		console.log 'no gl'
		return User32.TRUE

	gl.glShadeModel(gl.GL_SMOOTH)                                #Enable Smooth Shading
	gl.glClearColor(0, 0, 0, 0.5)                                #Black Background
	gl.glClearDepth(1)                                           #Depth Buffer Setup
	gl.glEnable(gl.GL_DEPTH_TEST)                                #Enables Depth Testing
	gl.glDepthFunc(gl.GL_LEQUAL)                                 #The Type Of Depth Testing To Do
	gl.glHint(gl.GL_PERSPECTIVE_CORRECTION_HINT, gl.GL_NICEST)   #Really Nice Perspective Calculations

	return User32.TRUE                                               #Initialization Went OK

switch global.NeHeLesson
	when 2, 3, 4, 5 then exports.InitGL = exports.InitGL_05
