makeBufferFromTypedArray = require('./makeBufferFromTypedArray').makeBufferFromTypedArray
debugDrawGLScene = false

Int16Array_TypedArray = [ #	2	16-bit twos complement signed integer	short
	new Int16Array([ 0x7FFF,  0x0000, 0x0000])#red
	new Int16Array([ 0,  1, 0])
	new Int16Array([-1, -1, 0])
	new Int16Array([ 1, -1, 0])
	new Int16Array([ 0x0000,  0x7FFF, 0x0000])#green
	new Int16Array([-1,  1, 0])
	new Int16Array([ 1,  1, 0])
	new Int16Array([ 1, -1, 0])
	new Int16Array([-1, -1, 0])
]

Int16Array_Buffer = (makeBufferFromTypedArray(n) for n in Int16Array_TypedArray)

exports.DrawGLScene_Int16Array_TypedArray = (winObj)-> #Here's Where We Do All The Drawing
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

	gl.glColor3sv(Int16Array_TypedArray[0])
	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles
	gl.glVertex3sv(Int16Array_TypedArray[1])                         # Top
	gl.glVertex3sv(Int16Array_TypedArray[2])                         # Bottom Left
	gl.glVertex3sv(Int16Array_TypedArray[3])                         # Bottom Right
	gl.glEnd()                                                  # Finished Drawing The Triangle

	gl.glLoadIdentity()                                         # Reset The Current Modelview Matrix
	gl.glTranslatef(1.5,0,-6)                                   # Move Right 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rquad,1,0,0)                                   # Rotate The Quad On The X axis ( NEW )
	gl.glColor3sv(Int16Array_TypedArray[4])
	gl.glBegin(gl.GL_QUADS)                                     # Draw A Quad
	gl.glVertex3sv(Int16Array_TypedArray[5])                         # Top Left
	gl.glVertex3sv(Int16Array_TypedArray[6])                         # Top Right
	gl.glVertex3sv(Int16Array_TypedArray[7])                         # Bottom Right
	gl.glVertex3sv(Int16Array_TypedArray[8])                         # Bottom Left
	gl.glEnd()                                                  # Done Drawing The Quad

	winObj.rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	winObj.rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going

exports.DrawGLScene_Int16Array_Buffer = (winObj)-> #Here's Where We Do All The Drawing
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

	gl.glColor3sv(Int16Array_Buffer[0])
	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles
	gl.glVertex3sv(Int16Array_Buffer[1])                         # Top
	gl.glVertex3sv(Int16Array_Buffer[2])                         # Bottom Left
	gl.glVertex3sv(Int16Array_Buffer[3])                         # Bottom Right
	gl.glEnd()                                                  # Finished Drawing The Triangle

	gl.glLoadIdentity()                                         # Reset The Current Modelview Matrix
	gl.glTranslatef(1.5,0,-6)                                   # Move Right 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rquad,1,0,0)                                   # Rotate The Quad On The X axis ( NEW )
	gl.glColor3sv(Int16Array_Buffer[4])
	gl.glBegin(gl.GL_QUADS)                                     # Draw A Quad
	gl.glVertex3sv(Int16Array_Buffer[5])                         # Top Left
	gl.glVertex3sv(Int16Array_Buffer[6])                         # Top Right
	gl.glVertex3sv(Int16Array_Buffer[7])                         # Bottom Right
	gl.glVertex3sv(Int16Array_Buffer[8])                         # Bottom Left
	gl.glEnd()                                                  # Done Drawing The Quad

	winObj.rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	winObj.rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going

