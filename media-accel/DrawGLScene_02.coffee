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

	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix
	gl.glTranslatef(-1.5, 0, -6)                                # Move Left 1.5 Units And Into The Screen 6.0

	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles
	gl.glVertex3f( 0,  1, 0)                                    # Top
	gl.glVertex3f(-1, -1, 0)                                    # Bottom Left
	gl.glVertex3f( 1, -1, 0)                                    # Bottom Right
	gl.glEnd()                                                  # Finished Drawing The Triangle

	gl.glTranslatef(3, 0, 0)                                    # Move Right 3 Units
	gl.glBegin(gl.GL_QUADS)                                     # Draw A Quad
	gl.glVertex3f(-1,  1, 0)                                    # Top Left
	gl.glVertex3f( 1,  1, 0)                                    # Top Right
	gl.glVertex3f( 1, -1, 0)                                    # Bottom Right
	gl.glVertex3f(-1, -1, 0)                                    # Bottom Left
	gl.glEnd()                                                  # Done Drawing The Quad
	return User32.TRUE                                          # Keep Going