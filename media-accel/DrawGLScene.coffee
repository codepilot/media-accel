#require('./media-accel')
debugDrawGLScene = false

rtri = 0
rquad = 0

exports.DrawGLScene = -> #Here's Where We Do All The Drawing
	if debugDrawGLScene
		console.log 'DrawGLScene'

	unless global.gl?
		console.log 'no gl'
		return User32.TRUE
		
	#gl.glClearColor(Math.random(), Math.random(), Math.random(), Math.random())

	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer

	gl.glMatrixMode(gl.GL_MODELVIEW)                         # Select The Modelview Matrix
	gl.glLoadIdentity()                                      # Reset The Modelview Matrix
	gl.glTranslatef(-1.5, 0, -6) #Move Left 1.5 Units And Into The Screen 6.0
	gl.glRotatef(rtri, 0, 1, 0) #Rotate The Triangle On The Y axis ( NEW )

	unless gl.glBegin(gl.GL_TRIANGLES) #Start Drawing A Triangle (if needed for indention)
		gl.glColor3f(  1,  0,  0) #Red
		gl.glVertex3f( 0,  1,  0) #Top Of Triangle (Front)
		gl.glColor3f(  0,  1,  0) #Green
		gl.glVertex3f(-1, -1,  1) #Left Of Triangle (Front)
		gl.glColor3f(  0,  0,  1) #Blue
		gl.glVertex3f( 1, -1,  1) #Right Of Triangle (Front)
		gl.glColor3f(  1,  0,  0) #Red
		gl.glVertex3f( 0,  1,  0) #Top Of Triangle (Right)
		gl.glColor3f(  0,  0,  1) #Blue
		gl.glVertex3f( 1, -1,  1) #Left Of Triangle (Right)
		gl.glColor3f(  0,  1,  0) #Green
		gl.glVertex3f( 1, -1, -1) #Right Of Triangle (Right)
		gl.glColor3f(  1,  0,  0) #Red
		gl.glVertex3f( 0,  1,  0) #Top Of Triangle (Back)
		gl.glColor3f(  0,  1,  0) #Green
		gl.glVertex3f( 1, -1, -1) #Left Of Triangle (Back)
		gl.glColor3f(  0,  0,  1) #Blue
		gl.glVertex3f(-1, -1, -1) #Right Of Triangle (Back)
		gl.glColor3f(  1,  0,  0) #Red
		gl.glVertex3f( 0,  1,  0) #Top Of Triangle (Left)
		gl.glColor3f(  0,  0,  1) #Blue
		gl.glVertex3f(-1, -1, -1) #Left Of Triangle (Left)
		gl.glColor3f(  0,  1,  0) #Green
		gl.glVertex3f(-1, -1,  1) #Right Of Triangle (Left)
	gl.glEnd() #Done Drawing The Pyramid

	gl.glMatrixMode(gl.GL_MODELVIEW)                         # Select The Modelview Matrix
	gl.glLoadIdentity()                                      # Reset The Modelview Matrix
	gl.glTranslatef(1.5, 0, -7) #Move Right 1.5 Units And Into The Screen 7.0
	gl.glRotatef(rquad, 1, 1, 1) #Rotate The Quad On The X axis ( NEW )

	unless gl.glBegin(gl.GL_QUADS) #Draw A Quad (if needed for indention)
		gl.glColor3f(  0,   1,  0) #Set The Color To Green
		gl.glVertex3f( 1,   1, -1) #Top Right Of The Quad (Top)
		gl.glVertex3f(-1,   1, -1) #Top Left Of The Quad (Top)
		gl.glVertex3f(-1,   1,  1) #Bottom Left Of The Quad (Top)
		gl.glVertex3f( 1,   1,  1) #Bottom Right Of The Quad (Top)
		gl.glColor3f(  1, 0.5,  0) #Set The Color To Orange
		gl.glVertex3f( 1,  -1,  1) #Top Right Of The Quad (Bottom)
		gl.glVertex3f(-1,  -1,  1) #Top Left Of The Quad (Bottom)
		gl.glVertex3f(-1,  -1, -1) #Bottom Left Of The Quad (Bottom)
		gl.glVertex3f( 1,  -1, -1) #Bottom Right Of The Quad (Bottom)
		gl.glColor3f(  1,   0,  0) #Set The Color To Red
		gl.glVertex3f( 1,   1,  1) #Top Right Of The Quad (Front)
		gl.glVertex3f(-1,   1,  1) #Top Left Of The Quad (Front)
		gl.glVertex3f(-1,  -1,  1) #Bottom Left Of The Quad (Front)
		gl.glVertex3f( 1,  -1,  1) #Bottom Right Of The Quad (Front)
		gl.glColor3f(  1,   1,  0) #Set The Color To Yellow
		gl.glVertex3f( 1,  -1, -1) #Top Right Of The Quad (Back)
		gl.glVertex3f(-1,  -1, -1) #Top Left Of The Quad (Back)
		gl.glVertex3f(-1,   1, -1) #Bottom Left Of The Quad (Back)
		gl.glVertex3f( 1,   1, -1) #Bottom Right Of The Quad (Back)
		gl.glColor3f(  0,   0,  1) #Set The Color To Blue
		gl.glVertex3f(-1,   1,  1) #Top Right Of The Quad (Left)
		gl.glVertex3f(-1,   1, -1) #Top Left Of The Quad (Left)
		gl.glVertex3f(-1,  -1, -1) #Bottom Left Of The Quad (Left)
		gl.glVertex3f(-1,  -1,  1) #Bottom Right Of The Quad (Left)
		gl.glColor3f(  1,   0,  1) #Set The Color To Violet
		gl.glVertex3f( 1,   1, -1) #Top Right Of The Quad (Right)
		gl.glVertex3f( 1,   1,  1) #Top Left Of The Quad (Right)
		gl.glVertex3f( 1,  -1,  1) #Bottom Left Of The Quad (Right)
		gl.glVertex3f( 1,  -1, -1) #Bottom Right Of The Quad (Right)
	gl.glEnd() #Done Drawing The Quad

	rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going