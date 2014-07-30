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
	gl.glColor3f(  1, 0, 0)                                     # Set The Color To Red
	gl.glVertex3f( 0, 1, 0)                                     # Move Up One Unit From Center (Top Point)
	gl.glColor3f(  0, 1, 0)                                     # Set The Color To Green
	gl.glVertex3f(-1,-1, 0)                                     # Left And Down One Unit (Bottom Left)
	gl.glColor3f(  0, 0, 1)                                     # Set The Color To Blue
	gl.glVertex3f( 1,-1, 0)                                     # Right And Down One Unit (Bottom Right)
	gl.glEnd()                                                  # Done Drawing A Triangle
	
	gl.glTranslatef(3,0,0)                                      # From Right Point Move 3 Units Right
	gl.glColor3f(0.5, 0.5, 1)                                   # Set The Color To Blue One Time Only
	gl.glBegin(gl.GL_QUADS)                                     # Start Drawing Quads
	gl.glVertex3f(-1,  1, 0)                                    # Left And Up 1 Unit (Top Left)
	gl.glVertex3f( 1,  1, 0)                                    # Right And Up 1 Unit (Top Right)
	gl.glVertex3f( 1, -1, 0)                                    # Right And Down One Unit (Bottom Right)
	gl.glVertex3f(-1, -1, 0)                                    # Left And Down One Unit (Bottom Left)
	gl.glEnd()                                                  # Done Drawing A Quad
	return User32.TRUE                                          # Keep Going