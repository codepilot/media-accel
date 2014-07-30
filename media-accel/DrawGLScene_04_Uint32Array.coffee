makeBufferFromTypedArray = require('./makeBufferFromTypedArray').makeBufferFromTypedArray
debugDrawGLScene = false

Uint32Array_TypedArray = [ #	4	32-bit unsigned integer	unsigned int
	new Uint32Array([ 0xFFFFFFFF,  0x00000000, 0x00000000])#red
	new Uint32Array([ 0x00000000,  0xFFFFFFFF, 0x00000000])#green
]

Uint32Array_Buffer = (makeBufferFromTypedArray(n) for n in Uint32Array_TypedArray)

exports.DrawGLScene_Uint32Array_TypedArray = (winObj)-> #Here's Where We Do All The Drawing
	if debugDrawGLScene
		console.log 'DrawGLScene'

	unless global.gl?
		console.log 'no gl'
		return User32.TRUE

	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix
	gl.glTranslatef(-1.5, 0, -6)                                # Move Left 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rtri,0,1,0)                                    # Rotate The Triangle On The Y axis ( NEW )

	gl.glColor3uiv(Uint32Array_Buffer[0])
	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles
	gl.glVertex3f( 0, 1, 0)                                     # Move Up One Unit From Center (Top Point)
	gl.glVertex3f(-1,-1, 0)                                     # Left And Down One Unit (Bottom Left)
	gl.glVertex3f( 1,-1, 0)                                     # Right And Down One Unit (Bottom Right)
	gl.glEnd()                                                  # Finished Drawing The Triangle

	gl.glLoadIdentity()                                         # Reset The Current Modelview Matrix
	gl.glTranslatef(1.5,0,-6)                                   # Move Right 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rquad,1,0,0)                                   # Rotate The Quad On The X axis ( NEW )
	gl.glColor3uiv(Uint32Array_Buffer[1])
	gl.glBegin(gl.GL_QUADS)                                     # Draw A Quad
	gl.glVertex3f(-1,  1, 0)                                    # Left And Up 1 Unit (Top Left)
	gl.glVertex3f( 1,  1, 0)                                    # Right And Up 1 Unit (Top Right)
	gl.glVertex3f( 1, -1, 0)                                    # Right And Down One Unit (Bottom Right)
	gl.glVertex3f(-1, -1, 0)                                    # Left And Down One Unit (Bottom Left)
	gl.glEnd()                                                  # Done Drawing The Quad

	winObj.rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	winObj.rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going

exports.DrawGLScene_Uint32Array_Buffer = (winObj)-> #Here's Where We Do All The Drawing
	if debugDrawGLScene
		console.log 'DrawGLScene'

	unless global.gl?
		console.log 'no gl'
		return User32.TRUE

	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix
	gl.glTranslatef(-1.5, 0, -6)                                # Move Left 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rtri,0,1,0)                                    # Rotate The Triangle On The Y axis ( NEW )

	gl.glColor3uiv(Uint32Array_Buffer[0])
	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles
	gl.glVertex3f( 0, 1, 0)                                     # Move Up One Unit From Center (Top Point)
	gl.glVertex3f(-1,-1, 0)                                     # Left And Down One Unit (Bottom Left)
	gl.glVertex3f( 1,-1, 0)                                     # Right And Down One Unit (Bottom Right)
	gl.glEnd()                                                  # Finished Drawing The Triangle

	gl.glLoadIdentity()                                         # Reset The Current Modelview Matrix
	gl.glTranslatef(1.5,0,-6)                                   # Move Right 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rquad,1,0,0)                                   # Rotate The Quad On The X axis ( NEW )
	gl.glColor3uiv(Uint32Array_Buffer[1])
	gl.glBegin(gl.GL_QUADS)                                     # Draw A Quad
	gl.glVertex3f(-1,  1, 0)                                    # Left And Up 1 Unit (Top Left)
	gl.glVertex3f( 1,  1, 0)                                    # Right And Up 1 Unit (Top Right)
	gl.glVertex3f( 1, -1, 0)                                    # Right And Down One Unit (Bottom Right)
	gl.glVertex3f(-1, -1, 0)                                    # Left And Down One Unit (Bottom Left)
	gl.glEnd()                                                  # Done Drawing The Quad

	winObj.rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	winObj.rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going