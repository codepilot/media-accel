Shader = require('./Shader')
glGeti = require('./glGeti').glGeti
http = require('http')
fs = require('fs')

debugDrawGLScene = false

pipe = undefined
textureTriangle = undefined
textureSquare = undefined
vertexProg = undefined
dstBuffer = undefined
fragProg = undefined
uniformBuf = undefined
uniformBuffer = undefined

USE_DSA = true
USE_64BIT = false
USE_PREMULTIPLIED_ALPHA = true

os = require('os')

USE_OS_TIME = false

#textureFilename = "./png/s01i3p01.png"
#textureFilename = "./png/AlphaEdge.png"
#textureFilename = "./png/AlphaBall.png"
#textureFilename = "./png/MagnoliaAlpha-0.5.png"

USE_TEXTURE_URL = false

textureTrianglePath = './png/IceAlpha.png'
textureTriangleURL = 'http://www.libpng.org/pub/png/img_png/IceAlpha.png'
	#from http://www.libpng.org/pub/png/png-IceAlpha.html
	#free use copyright

textureSquarePath = './png/MagnoliaAlpha.png'
textureSquareURL = 'http://www.libpng.org/pub/png/img_png/MagnoliaAlpha.png'
	#from http://www.libpng.org/pub/png/png-MagnoliaAlpha.html
	#free use copyright

createBitmapTexture = (dstTexture, pathOrBuffer)->
	if USE_64BIT
		if USE_PREMULTIPLIED_ALPHA
			bitmap = new MediaAccel.GDIPLUS_BITMAP(pathOrBuffer, GDIPLUS.PixelFormat64bppPARGB)
		else
			bitmap = new MediaAccel.GDIPLUS_BITMAP(pathOrBuffer, GDIPLUS.PixelFormat64bppARGB)
		#console.log (n for n in bitmap)
	else
		if USE_PREMULTIPLIED_ALPHA
			bitmap = new MediaAccel.GDIPLUS_BITMAP(pathOrBuffer, GDIPLUS.PixelFormat32bppPARGB)
		else
			bitmap = new MediaAccel.GDIPLUS_BITMAP(pathOrBuffer, GDIPLUS.PixelFormat32bppARGB)
		
		#console.log (n for n in bitmap)
		if true or debugDrawGLScene
			console.log
				length: bitmap.length
				Width: bitmap.Width
				Height: bitmap.Height
				Stride: bitmap.Stride
				PixelFormat: bitmap.PixelFormat
				Scan0: bitmap.Scan0




	if debugDrawGLScene
		console.log 'glTextureStorage2DEXT'
	
	numLevels = 1 + Math.floor(Math.log(Math.max(bitmap.Width, bitmap.Height)) * Math.LOG2E)
	console.log 'numLevels', numLevels
	#numLevels = 11

	#gl.glBindTexture(gl.GL_TEXTURE_2D, dstTexture)
	#gl.glBindTexture(gl.GL_TEXTURE_2D, 0)

	if USE_DSA
		#gl.glBindTexture(gl.GL_TEXTURE_2D, dstTexture)
		if USE_64BIT
			gl.glTextureStorage2DEXT(dstTexture, gl.GL_TEXTURE_2D, numLevels, gl.GL_RGBA16, bitmap.Width, bitmap.Height)
		else
			gl.glTextureStorage2DEXT(dstTexture, gl.GL_TEXTURE_2D, numLevels, gl.GL_RGBA8, bitmap.Width, bitmap.Height)
		
	else
		gl.glBindTexture(gl.GL_TEXTURE_2D, dstTexture)
		if USE_64BIT
			gl.glTexStorage2D(                gl.GL_TEXTURE_2D, numLevels, gl.GL_RGBA16, bitmap.Width, bitmap.Height)
		else
			gl.glTexStorage2D(                gl.GL_TEXTURE_2D, numLevels, gl.GL_RGBA8, bitmap.Width, bitmap.Height)

	#storage causes errors
	gl.glGetError()
	MediaAccel.GlErrorAbort('DrawGLScene_04_Shader: 45')

	if debugDrawGLScene
		console.log 'glTextureImage2DEXT'

	if USE_DSA
		if USE_64BIT
			gl.glTextureSubImage2DEXT(dstTexture, gl.GL_TEXTURE_2D, 0, 0, 0, bitmap.Width, bitmap.Height, gl.GL_BGRA, gl.GL_UNSIGNED_SHORT, bitmap)
		else
			gl.glTextureSubImage2DEXT(dstTexture, gl.GL_TEXTURE_2D, 0, 0, 0, bitmap.Width, bitmap.Height, gl.GL_BGRA, gl.GL_UNSIGNED_BYTE, bitmap)
	else
		gl.glBindTexture(gl.GL_TEXTURE_2D, dstTexture)
		if USE_64BIT
			gl.glTexSubImage2D(                gl.GL_TEXTURE_2D, 0, 0, 0, bitmap.Width, bitmap.Height, gl.GL_BGRA, gl.GL_UNSIGNED_SHORT, bitmap)
		else
			gl.glTexSubImage2D(                gl.GL_TEXTURE_2D, 0, 0, 0, bitmap.Width, bitmap.Height, gl.GL_BGRA, gl.GL_UNSIGNED_BYTE, bitmap)

	gl.glGetError()
	MediaAccel.GlErrorAbort('DrawGLScene_04_Shader: 49')

	if USE_DSA
		gl.glTextureParameteriEXT(dstTexture, gl.GL_TEXTURE_2D, gl.GL_TEXTURE_MIN_FILTER, gl.GL_LINEAR_MIPMAP_LINEAR)
		gl.glTextureParameteriEXT(dstTexture, gl.GL_TEXTURE_2D, gl.GL_TEXTURE_MAG_FILTER, gl.GL_LINEAR)
		gl.glTextureParameteriEXT(dstTexture, gl.GL_TEXTURE_2D, gl.GL_TEXTURE_WRAP_S, gl.GL_CLAMP_TO_EDGE)
		gl.glTextureParameteriEXT(dstTexture, gl.GL_TEXTURE_2D, gl.GL_TEXTURE_WRAP_T, gl.GL_CLAMP_TO_EDGE)
		gl.glTextureParameteriEXT(dstTexture, gl.GL_TEXTURE_2D, gl.GL_TEXTURE_MAX_ANISOTROPY_EXT, glGeti(gl.GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT))
		gl.glGenerateTextureMipmapEXT(dstTexture, gl.GL_TEXTURE_2D)
	else
		gl.glBindTexture(gl.GL_TEXTURE_2D, dstTexture)
		gl.glTexParameteri(                gl.GL_TEXTURE_2D, gl.GL_TEXTURE_MIN_FILTER, gl.GL_LINEAR_MIPMAP_LINEAR)
		gl.glTexParameteri(                gl.GL_TEXTURE_2D, gl.GL_TEXTURE_MAG_FILTER, gl.GL_LINEAR)
		gl.glTexParameteri(                gl.GL_TEXTURE_2D, gl.GL_TEXTURE_WRAP_S, gl.GL_CLAMP_TO_EDGE)
		gl.glTexParameteri(                gl.GL_TEXTURE_2D, gl.GL_TEXTURE_WRAP_T, gl.GL_CLAMP_TO_EDGE)
		gl.glTexParameteri(                gl.GL_TEXTURE_2D, gl.GL_TEXTURE_MAX_ANISOTROPY_EXT, glGeti(gl.GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT))
		MediaAccel.GlErrorAbort('DrawGLScene_04_Shader: 88')
		gl.glGenerateMipmap(gl.GL_TEXTURE_2D)


	if 0 #test if dstTexture was uploaded
		#dstBuffer = new Uint32Array bitmap.Width * bitmap.Height
		if USE_64BIT
			dstBuffer = new Buffer(bitmap.Width * bitmap.Height * 4 * 2)
		else
			dstBuffer = new Buffer(bitmap.Width * bitmap.Height * 4)


		if debugDrawGLScene
			console.log 'made buffer', dstBuffer
			console.log 'getting image'

		if USE_DSA
			if USE_64BIT
				gl.glGetTextureImageEXT(dstTexture, gl.GL_TEXTURE_2D, 0, gl.GL_BGRA, gl.GL_UNSIGNED_SHORT, dstBuffer)
			else
				gl.glGetTextureImageEXT(dstTexture, gl.GL_TEXTURE_2D, 0, gl.GL_BGRA, gl.GL_UNSIGNED_BYTE, dstBuffer)
			
		else
			if USE_64BIT
				gl.glGetTexImage(gl.GL_TEXTURE_2D, 0, gl.GL_BGRA, gl.GL_UNSIGNED_SHORT, dstBuffer)
			else
				gl.glGetTexImage(gl.GL_TEXTURE_2D, 0, gl.GL_BGRA, gl.GL_UNSIGNED_BYTE, dstBuffer)

		if debugDrawGLScene
			console.log 'got image'

		MediaAccel.GlErrorAbort('DrawGLScene_04_Shader: 65')
		if true or debugDrawGLScene
			#console.log dstBuffer.toString('hex')
			console.log (n for n in dstBuffer)

loadTextureFromPath = (dstTexture, path)->
	fs.readFile path, (err, data)->
		createBitmapTexture dstTexture, data

loadTextureFromUrl = (dstTexture, url)->
	req = http.request url, (res)->
		showPicture = ->
			console.log wholeData = Buffer.concat(dataParts)
			#return
			#fs.writeFileSync 'tempFileTexture', wholeData
			bitmapSource = wholeData
			createBitmapTexture dstTexture, bitmapSource

		console.log
			STATUS: res.statusCode
			HEADERS: res.headers

		dataParts = []
		res.on 'data', (chunk)->
			console.log 'res', 'data'
			dataParts.push chunk
			#showPicture()

		res.on 'end', ->
			console.log 'res', 'end'
			showPicture()

	req.end()

exports.DrawGLScene_04_Shader = DrawGLScene_04_Shader = (winObj)-> #Here's Where We Do All The Drawing

	gl.glEnable(gl.GL_BLEND)
	if USE_PREMULTIPLIED_ALPHA
		gl.glBlendFunc(gl.GL_ONE, gl.GL_ONE_MINUS_SRC_ALPHA)
	else
		gl.glBlendFunc(gl.GL_SRC_ALPHA, gl.GL_ONE_MINUS_SRC_ALPHA)

	if debugDrawGLScene
		console.log 'DrawGLScene'

	unless global.gl?
		console.log 'no gl'
		return User32.TRUE

	unless pipe#initialize everything...
		if debugDrawGLScene
			console.log 'before pipe'

		pipe = Shader.CreateProgramPipelineFromFiles
			INCLUDE_IN_ALL: 'simple.include.glsl'
			#GL_COMPUTE_SHADER: 'simple.compute.glsl'
			GL_VERTEX_SHADER: 'simple.vertex.glsl'
			#GL_TESS_CONTROL_SHADER: 'simple.control.glsl'
			#GL_TESS_EVALUATION_SHADER: 'simple.evaluation.glsl'
			#GL_GEOMETRY_SHADER: 'simple.geometry.glsl'
			GL_FRAGMENT_SHADER: 'simple.fragment.glsl'

		if debugDrawGLScene
			console.log 'pipe', pipe

		vertexProg = Shader.GetProgramPipelineAll(pipe).GL_VERTEX_SHADER
		if debugDrawGLScene
			console.log Shader.GetProgramPipelineAll(pipe)

		textureTriangle = Shader.GenTexture()
		textureSquare = Shader.GenTexture()
		MediaAccel.GlErrorAbort('DrawGLScene_04_Shader: 41')

		if USE_TEXTURE_URL
			loadTextureFromUrl(textureTriangle, textureTriangleURL)
			loadTextureFromUrl(textureSquare, textureSquareURL)
		else
			loadTextureFromPath(textureTriangle, textureTrianglePath)
			loadTextureFromPath(textureSquare, textureSquarePath)

		fragProg = Shader.GetProgramPipelineAll(pipe).GL_FRAGMENT_SHADER
		
		gl.glActiveShaderProgram(pipe, fragProg)

		gl.glValidateProgram(fragProg)
		programAll = Shader.GetProgramAll(fragProg)
		if programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH <= 1 or programAll.GL_ATTACHED_SHADERS
			console.log 'after validate', programAll
		if programAll.GL_INFO_LOG_LENGTH > 1
			programInfoLog = Shader.GetProgramInfoLog(fragProg)
			if programInfoLog isnt 'Validation successful.'
				console.log 'GetProgramInfoLog fragProg: ', programInfoLog


		gl.glProgramUniform1i fragProg, 8, 0
		gl.glUniform1i 8, 0

		gl.glValidateProgram(fragProg)
		programAll = Shader.GetProgramAll(fragProg)
		if programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH <= 1 or programAll.GL_ATTACHED_SHADERS
			console.log 'after validate', programAll
		if programAll.GL_INFO_LOG_LENGTH > 1
			programInfoLog = Shader.GetProgramInfoLog(fragProg)
			#if programInfoLog isnt 'Validation successful.'
			console.log 'GetProgramInfoLog fragProg: ', programInfoLog

		gl.glValidateProgramPipeline(pipe)
		unless Shader.GetProgramPipelineAll(pipe).GL_VALIDATE_STATUS
			console.log 'after validate', Shader.GetProgramPipelineAll(pipe)
	
		if Shader.GetProgramPipelineAll(pipe).GL_INFO_LOG_LENGTH > 1
			console.log 'pipe log after validate', Shader.GetProgramPipelineInfoLog(pipe)

		uniformBuffer = Shader.GenBuffer()
		uniformBuf = new Buffer 16 * 4 + 16 * 4 + 4 * 4 + 8
		gl.glBindBuffer(gl.GL_SHADER_STORAGE_BUFFER, uniformBuffer)
		if debugDrawGLScene
			console.log 'glBufferStorage before'
#		gl.glBufferStorage(gl.GL_SHADER_STORAGE_BUFFER, uniformBuf.length, uniformBuf, gl.GL_DYNAMIC_STORAGE_BIT)
		gl.glBufferStorage(gl.GL_SHADER_STORAGE_BUFFER, uniformBuf.length, 0, gl.GL_DYNAMIC_STORAGE_BIT)
		if debugDrawGLScene
			console.log 'glBufferStorage after'

	gl.glBindProgramPipeline pipe

	gl.glProgramUniform4f fragProg, 12, 0, 0, winObj.width, winObj.height

	gl.glActiveShaderProgram(pipe, Shader.GetProgramPipelineAll(pipe).GL_VERTEX_SHADER)

	gl.glClearColor(0.25, 0.3, 0.5, 0)
	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) # Clear Screen And Depth Buffer

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix
	gl.glTranslatef(-1.5, 0, -6)                                # Move Left 1.5 Units And Into The Screen 6.0

	gl.glRotatef((if USE_OS_TIME then os.uptime() * 20 else winObj.rtri),0,1,0)                             # Rotate The Triangle On The Y axis ( NEW )

	if true
		ProjectionMatrix = new Float32Array(16)
		ModelViewMatrix = new Float32Array(16)

		gl.glGetFloatv(gl.GL_PROJECTION_MATRIX, ProjectionMatrix)
		gl.glGetFloatv(gl.GL_MODELVIEW_MATRIX, ModelViewMatrix)

#		gl.glUniformMatrix4fv 0, 1, gl.GL_FALSE, ProjectionMatrix
#		gl.glUniformMatrix4fv 4, 1, gl.GL_FALSE, ModelViewMatrix

		gl.glProgramUniformMatrix4fv vertexProg, 0, 1, gl.GL_FALSE, ProjectionMatrix
		gl.glProgramUniformMatrix4fv vertexProg, 4, 1, gl.GL_FALSE, ModelViewMatrix

#		if debugDrawGLScene
#			console.log 'write ProjectionMatrix before'
#		for n, i in ProjectionMatrix
#			uniformBuf.writeFloatLE n, i * 4
#		if debugDrawGLScene
#			console.log 'write ProjectionMatrix after'
#
#		if debugDrawGLScene
#			console.log 'write ModelViewMatrix before'
#		for n, i in ModelViewMatrix
#			uniformBuf.writeFloatLE n, 16 * 4 + i * 4
#		if debugDrawGLScene
#			console.log 'write ModelViewMatrix after'
#
#		if debugDrawGLScene
#			console.log 'write viewport before'
#		for n, i in [0, 0, winObj.width, winObj.height]
#			uniformBuf.writeFloatLE 0, 32 * 4 + i * 4
#		if debugDrawGLScene
#			console.log 'write viewport after'
#
#		if debugDrawGLScene
#			console.log 'glBufferSubData before'
#		gl.glBufferSubData(gl.GL_SHADER_STORAGE_BUFFER, 0, uniformBuf.length, uniformBuf)
#		if debugDrawGLScene
#			console.log 'glBufferSubData after'
#
#		if debugDrawGLScene
#			console.log uniformBuf.toString('hex')


	gl.glBindTexture(gl.GL_TEXTURE_2D, textureTriangle)
	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles

	gl.glVertexAttrib3f(1,  1, 0, 0)                                     # Set The Color To Red
	gl.glVertexAttrib2f(2, 0.5, 1)
	gl.glVertex3f( 0, 1, 0)                                     # Move Up One Unit From Center (Top Point)

	gl.glVertexAttrib3f(1,  0, 1, 0)                                     # Set The Color To Green
	gl.glVertexAttrib2f(2, 0, 0)
	gl.glVertex3f(-1,-1, 0)                                     # Left And Down One Unit (Bottom Left)

	gl.glVertexAttrib3f(1,  0, 0, 1)                                     # Set The Color To Blue
	gl.glVertexAttrib2f(2, 1, 0)
	gl.glVertex3f( 1,-1, 0)                                     # Right And Down One Unit (Bottom Right)

	gl.glEnd()                                                  # Done Drawing A Triangle

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix

	gl.glTranslatef(1.5,0,-6)                                   # Move Right 1.5 Units And Into The Screen 6.0
	gl.glRotatef((if USE_OS_TIME then -os.uptime() * 15 else winObj.rquad),1,0,0)                            # Rotate The Quad On The X axis ( NEW )
	gl.glVertexAttrib3f(1, 0.5, 0.5, 1)                                   # Set The Color To Blue One Time Only

	if true
		ProjectionMatrix = new Float32Array(16)
		ModelViewMatrix = new Float32Array(16)

		gl.glGetFloatv(gl.GL_PROJECTION_MATRIX, ProjectionMatrix)
		gl.glGetFloatv(gl.GL_MODELVIEW_MATRIX, ModelViewMatrix)

#		gl.glUniformMatrix4fv 0, 1, gl.GL_FALSE, ProjectionMatrix
#		gl.glUniformMatrix4fv 4, 1, gl.GL_FALSE, ModelViewMatrix

		gl.glProgramUniformMatrix4fv vertexProg, 0, 1, gl.GL_FALSE, ProjectionMatrix
		gl.glProgramUniformMatrix4fv vertexProg, 4, 1, gl.GL_FALSE, ModelViewMatrix

	gl.glBindTexture(gl.GL_TEXTURE_2D, textureSquare)
	gl.glBegin(gl.GL_QUADS)                                     # Start Drawing Quads

	gl.glVertexAttrib2f(2, 0, 1)
	gl.glVertex3f(-1,  1, 0)                                    # Left And Up 1 Unit (Top Left)

	gl.glVertexAttrib2f(2, 1, 1)
	gl.glVertex3f( 1,  1, 0)                                    # Right And Up 1 Unit (Top Right)

	gl.glVertexAttrib2f(2, 1, 0)
	gl.glVertex3f( 1, -1, 0)                                    # Right And Down One Unit (Bottom Right)

	gl.glVertexAttrib2f(2, 0, 0)
	gl.glVertex3f(-1, -1, 0)                                    # Left And Down One Unit (Bottom Left)

	gl.glEnd()                                                  # Done Drawing A Quad

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix

	gl.glBindProgramPipeline 0

	
	winObj.rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	winObj.rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going