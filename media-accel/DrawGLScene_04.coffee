util = require 'util'

debugDrawGLScene = false

drawFuncOption = 0
DrawGLSceneOptions = {}
DrawGLSceneOptionKey = undefined

isFirstCall = true

glGeti = require('./glGeti').glGeti

InternalFormat2 = require('./InternalFormat2')

testTexture = ->
	#console.log util.inspect(InternalFormat2.getAllInternalFormats(), {depth: null, colors: true})
	#process.exit 1

	#virtualPageSizes = InternalFormat2.getVirtualPageInfo()
	#console.log 'virtualPageSizes', virtualPageSizes

	isFirstCall = false

	require('./gl.Texture2dArray').init gl

	#console.log 'gl.CreateTexture2dArray', gl.CreateTexture2dArray

	tex2dArray = gl.CreateTexture2dArray(gl.GL_TEXTURE_2D_ARRAY, 1)

	tex2dArray.parameter gl.GL_VIRTUAL_PAGE_SIZE_INDEX, 0
	tex2dArray.parameter gl.GL_TEXTURE_SPARSE_ARB, 1

	#console.log 'tex2dArray'
	#console.log 'tex2dArray.isTexture', tex2dArray.isTexture

	tex2dArray.storage NaN,
		gl.GL_SRGB8_ALPHA8,
		glGeti(gl.GL_MAX_SPARSE_TEXTURE_SIZE_ARB),
		glGeti(gl.GL_MAX_SPARSE_TEXTURE_SIZE_ARB),
		glGeti(gl.GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB)

	#console.log 'tex2dArray.isTexture', tex2dArray.isTexture

	#for k, v of tex2dArray
	#	console.log k, v

	#console.log JSON.stringify tex2dArray, null, '  '

	#console.log 'tex2dArray', tex2dArray
	#console.log 'tex2dArray.length', tex2dArray.length
	#console.log 'tex2dArray.destructorObj', tex2dArray.destructorObj
	#console.log 'tex2dArray.bind', tex2dArray.bind
	#console.log 'tex2dArray.generateMipmap', tex2dArray.generateMipmap
	#console.log 'tex2dArray.storage', tex2dArray.storage


	#arrTex = new gl.ArrayTexture(10)
	#console.log 'arrTex', arrTex
	##console.log 'util.isArray(arrTex)', util.isArray(arrTex)
	##console.log 'arrTex.length', arrTex.length
	##console.log 'arrTex.slice', arrTex.slice
	#console.log 'arrTex.bind()', arrTex.bind()
  #
	#tex = new gl.Texture()
	#console.log 'tex', tex
  #
	##arrOfTex = (new gl.Texture() for i in [0...10])
	##console.log 'arrOfTex', arrOfTex
	##console.log 'util.isArray(arrOfTex)', util.isArray(arrOfTex)
	##console.log 'arrOfTex.length', arrOfTex.length
	##console.log 'arrOfTex.slice', arrOfTex.slice

#//GLAPI void APIENTRY glTextureSubImage2DEXT (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
#	gl.glTextureSubImage2DEXT(tex2dArray[0], gl.GL_TEXTURE_2D_ARRAY, 0, 0, 0, bitmap.Width, bitmap.Height, gl.GL_RGBA, gl.GL_UNSIGNED_BYTE, bitmap)
#	gl.glGetTextureImageEXT(tex2dArray[0], gl.GL_TEXTURE_2D_ARRAY, 0, gl.GL_RGBA, gl.GL_UNSIGNED_BYTE, dstBuffer)

setupFrameBuffer = (width, height)->
	ret =
		width: width
		height: height
	#RGBA8 2D texture, 24 bit depth texture, width x height
	ret.colorTextureTarget = 'TEXTURE_2D'
#	ret.colorTextureTarget = 'TEXTURE_2D_MULTISAMPLE'
#	ret.colorTextureSparse = false
	ret.colorTextureSparse = true

#	ret.colorTextureFormat = 'RGBA2'
#	ret.colorTextureFormat = 'R3_G3_B2'
#	ret.colorTextureFormat = 'RGBA4'
#	ret.colorTextureFormat = 'RGB5_A1'
	ret.colorTextureFormat = 'RGBA8'
#	ret.colorTextureFormat = 'RGB10_A2'
#	ret.colorTextureFormat = 'RGB10_A2UI'#bad green
#	ret.colorTextureFormat = 'RGBA12'
#	ret.colorTextureFormat = 'RGBA16'
#	ret.colorTextureFormat = 'RGBA16F'
#	ret.colorTextureFormat = 'R11F_G11F_B10F'
#	ret.colorTextureFormat = 'RGB9_E5'#bad green
#	ret.colorTextureFormat = 'RGBA32F'
#	ret.colorTextureFormat = 'LUMINANCE'

	###
ALPHA
ALPHA4
ALPHA8
ALPHA12
ALPHA16
COMPRESSED_ALPHA
COMPRESSED_LUMINANCE
COMPRESSED_LUMINANCE_ALPHA
COMPRESSED_INTENSITY
COMPRESSED_RGB
COMPRESSED_RGBA
DEPTH_COMPONENT
DEPTH_COMPONENT16
DEPTH_COMPONENT24
DEPTH_COMPONENT32
LUMINANCE
LUMINANCE4
LUMINANCE8
LUMINANCE12
LUMINANCE16
LUMINANCE_ALPHA
LUMINANCE4_ALPHA4
LUMINANCE6_ALPHA2
LUMINANCE8_ALPHA8
LUMINANCE12_ALPHA4
LUMINANCE12_ALPHA12
LUMINANCE16_ALPHA16
INTENSITY
INTENSITY4
INTENSITY8
INTENSITY12
INTENSITY16
R3_G3_B2
RGB
RGB4
RGB5
RGB8
RGB10
RGB12
RGB16
RGBA
RGBA2
RGBA4
RGB5_A1
RGBA8
RGB10_A2
RGBA12
RGBA16
SLUMINANCE
SLUMINANCE8
SLUMINANCE_ALPHA
SLUMINANCE8_ALPHA8
SRGB
SRGB8
SRGB_ALPHA
SRGB8_ALPHA8
	###

#	ret.color_tex_target = gl.GL_TEXTURE_2D
	ret.color_tex_target = gl['GL_' + ret.colorTextureTarget]

	ret.targetFormat = InternalFormat2.getAllInternalFormats([ret.colorTextureTarget], [ret.colorTextureFormat])

#	console.log util.inspect(ret.targetFormat, {depth: null, colors: true})

	if true
		console.log 'ret.targetFormat',
			ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].VIRTUAL_PAGE_SIZE_X_ARB,
			ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].VIRTUAL_PAGE_SIZE_Y_ARB,
			ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].VIRTUAL_PAGE_SIZE_Z_ARB
			gl.glGetError()

	console.log ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].VIRTUAL_PAGE_SIZE_X_ARB

	if true
		if ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].NUM_VIRTUAL_PAGE_SIZES_ARB > 0
			ret.xsize = ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].VIRTUAL_PAGE_SIZE_X_ARB
			ret.ysize = ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].VIRTUAL_PAGE_SIZE_Y_ARB
			while ret.width % ret.xsize
				ret.width++
	
			while ret.height % ret.ysize
				ret.height++

#	console.log ret
#	throw 'text'

	MediaAccel.GlErrorAbort('DrawGLScene_04: 80')

	color_tex_buf = new Uint32Array([0])

	gl.glGenTextures(1, color_tex_buf)
	ret.color_tex = color_tex_buf[0]

	gl.glBindTexture(ret.color_tex_target, ret.color_tex)
	MediaAccel.GlErrorAbort('DrawGLScene_04: 91')

	#gl.glTexParameteri(ret.color_tex_target, gl.GL_TEXTURE_WRAP_S, gl.GL_CLAMP_TO_EDGE)
	#gl.glTexParameteri(ret.color_tex_target, gl.GL_TEXTURE_WRAP_T, gl.GL_CLAMP_TO_EDGE)
	MediaAccel.GlErrorAbort('DrawGLScene_04: 91a')

	#gl.glTexParameteri(ret.color_tex_target, gl.GL_TEXTURE_MIN_FILTER, gl.GL_NEAREST)
	#gl.glTexParameteri(ret.color_tex_target, gl.GL_TEXTURE_MAG_FILTER, gl.GL_NEAREST)
	MediaAccel.GlErrorAbort('DrawGLScene_04: 92')

	if ret.color_tex_target is gl.GL_TEXTURE_2D

		if ret.colorTextureSparse
			gl.glTexParameteri(ret.color_tex_target, gl.GL_VIRTUAL_PAGE_SIZE_INDEX_ARB, 0)
			gl.glTexParameteri(ret.color_tex_target, gl.GL_TEXTURE_SPARSE_ARB, 1)
			MediaAccel.GlErrorAbort('DrawGLScene_04: 93')

		gl.glTexStorage2D(ret.color_tex_target, 1, gl['GL_' + ret.colorTextureFormat], ret.width, ret.height)
		console.log 'gl.glTexStorage2D', ret.color_tex_target, 1, gl['GL_' + ret.colorTextureFormat], ret.width, ret.height
		MediaAccel.GlErrorAbort('DrawGLScene_04: 94a')

		#if colorTextureSparse
			#   glTexturePageCommitmentEXT(texture,       level,   xoffset,   yoffset, zoffset,     width,     height, depth, commit);
			#gl.glTexturePageCommitmentEXT(ret.color_tex,     0,         0,         0,       0, ret.xsize,  ret.ysize,     1,      1);
			#gl.glTexturePageCommitmentEXT(ret.color_tex,     0, ret.xsize,         0,       0, ret.xsize,  ret.ysize,     1,      1);
			#gl.glTexturePageCommitmentEXT(ret.color_tex,     0,         0, ret.ysize,       0, ret.xsize,  ret.ysize,     1,      1);
			#gl.glTexturePageCommitmentEXT(ret.color_tex,     0, ret.xsize, ret.ysize,       0, ret.xsize,  ret.ysize,     1,      1);
			#gl.glGetError()

	else if ret.color_tex_target is gl.GL_TEXTURE_2D_MULTISAMPLE
		ret.maxSamples = 0
		for samples in ret.targetFormat[ret.colorTextureTarget][ret.colorTextureFormat].SAMPLES
			ret.maxSamples = Math.max(ret.maxSamples, samples)

		gl.glTexStorage2DMultisample(ret.color_tex_target, ret.maxSamples, gl['GL_' + ret.colorTextureFormat], ret.width, ret.height, 1)
		MediaAccel.GlErrorAbort('DrawGLScene_04: 94b')


	gl.glBindTexture(ret.color_tex_target, 0)
	console.log 'color_tex', ret.color_tex

	MediaAccel.GlErrorAbort('DrawGLScene_04: 95')

	#-------------------------

	fb_buf = new Uint32Array([0])
	gl.glGenFramebuffers(1, fb_buf)
	ret.fb = fb_buf[0]

	MediaAccel.GlErrorAbort('DrawGLScene_04: 103')

	gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, ret.fb)
	#Attach 2D texture to this FBO

	MediaAccel.GlErrorAbort('DrawGLScene_04: 108')

	gl.glFramebufferTexture(gl.GL_FRAMEBUFFER, gl.GL_COLOR_ATTACHMENT0, ret.color_tex, 0)
	console.log 'ret.fb', ret.fb

	MediaAccel.GlErrorAbort('DrawGLScene_04: 113')

	#-------------------------

	if ret.color_tex_target is gl.GL_TEXTURE_2D
		depth_rb_buf = new Uint32Array([0])
		gl.glGenRenderbuffers(1, depth_rb_buf)
		ret.depth_rb = depth_rb_buf[0]
		gl.glBindRenderbuffer(gl.GL_RENDERBUFFER, ret.depth_rb)
		gl.glRenderbufferStorage(gl.GL_RENDERBUFFER, gl.GL_DEPTH_COMPONENT24, ret.width, ret.height)
		console.log 'depth_rb', ret.depth_rb
	
		MediaAccel.GlErrorAbort('DrawGLScene_04: 118')
	
		#-------------------------
		#Attach depth buffer to FBO
	
		#gl.glFramebufferRenderbuffer(gl.GL_FRAMEBUFFER, gl.GL_DEPTH_ATTACHMENT, gl.GL_RENDERBUFFER, depth_rb)
	
		MediaAccel.GlErrorAbort('DrawGLScene_04: 125')

	#-------------------------
	#Does the GPU support current FBO configuration?

	status = gl.glCheckFramebufferStatus(gl.GL_FRAMEBUFFER)
	switch status
		when gl.GL_FRAMEBUFFER_COMPLETE                      then console.log 'gl.GL_FRAMEBUFFER_COMPLETE'
		when gl.GL_FRAMEBUFFER_UNDEFINED                     then console.log 'gl.GL_FRAMEBUFFER_UNDEFINED'                     #is returned if target is the default framebuffer, but the default framebuffer does not exist.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT         then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT'         #is returned if any of the framebuffer attachment points are framebuffer incomplete.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT' #is returned if the framebuffer does not have at least one image attached to it.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER        then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER'        #is returned if the value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for any color attachment point(s) named by GL_DRAW_BUFFERi.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER        then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER'        #is returned if GL_READ_BUFFER is not GL_NONE and the value of GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE is GL_NONE for the color attachment point named by GL_READ_BUFFER.
		when gl.GL_FRAMEBUFFER_UNSUPPORTED                   then console.log 'gl.GL_FRAMEBUFFER_UNSUPPORTED'                   #is returned if the combination of internal formats of the attached images violates an implementation-dependent set of restrictions.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE        then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE'        #is returned if the value of GL_RENDERBUFFER_SAMPLES is not the same for all attached renderbuffers; if the value of GL_TEXTURE_SAMPLES is the not same for all attached textures; or, if the attached images are a mix of renderbuffers and textures, the value of GL_RENDERBUFFER_SAMPLES does not match the value of GL_TEXTURE_SAMPLES.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE        then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE'        #is also returned if the value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not the same for all attached textures; or, if the attached images are a mix of renderbuffers and textures, the value of GL_TEXTURE_FIXED_SAMPLE_LOCATIONS is not GL_TRUE for all attached textures.
		when gl.GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS      then console.log 'gl.GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS'      #is returned if any framebuffer attachment is layered, and any populated attachment is not layered, or if all populated color attachments are not from textures of the same target.
		else console.log 'HANDLE_THE_ERROR', status


	MediaAccel.GlErrorAbort('DrawGLScene_04: 145')

	#-------------------------
	#and now you can render to gl.GL_TEXTURE_2D

	return ret #{fb: fb, color_tex: color_tex, depth_rb: depth_rb, width: width, height: height}

	#gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, fb)
	#gl.glClearColor(0.0, 0.0, 0.0, 0.0)
	#gl.glClearDepth(1.0f)
	#gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT)

	#-------------------------

	#gl.glViewport(0, 0, 256, 256)
	#gl.glMatrixMode(gl.GL_PROJECTION)
	#gl.glLoadIdentity()
	#gl.glOrtho(0.0, 256.0, 0.0, 256.0, -1.0, 1.0) 
	#gl.glMatrixMode(gl.GL_MODELVIEW)
	#gl.glLoadIdentity()

	#-------------------------

	#gl.glDisable(gl.GL_TEXTURE_2D)
	#gl.glDisable(gl.GL_BLEND)
	#gl.glEnable(gl.GL_DEPTH_TEST)

	#-------------------------
	#**************************
	#RenderATriangle, {0.0, 0.0}, {256.0, 0.0}, {256.0, 256.0}
	#Read http://www.opengl.org/wiki/VBO_-_just_examples
	#RenderATriangle()
	#-------------------------

	#GLubyte pixels[4*4*4]
	#gl.glReadPixels(0, 0, 4, 4, gl.GL_BGRA, gl.GL_UNSIGNED_BYTE, pixels)

	#pixels 0, 1, 2 should be white
	#pixel 4 should be black
	#----------------
	#Bind 0, which means render to back buffer

	#gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)

frameBuffer = undefined
DrawGLSceneOptions['DrawGLScene_04 normal method'] = (winObj)-> #Here's Where We Do All The Drawing
#	global.gc?()
	gl.glDisable(gl.GL_FRAMEBUFFER_SRGB)

	gl.glGetError()
	MediaAccel.GlErrorAbort('DrawGLScene_04: 182')


	if isFirstCall
		isFirstCall = false
		#testTexture()
		frameBuffer = setupFrameBuffer(winObj.width, winObj.height)
		console.log 'frameBuffer', frameBuffer
		MediaAccel.GlErrorAbort('DrawGLScene_04: 189')

	unless frameBuffer.width >= winObj.width and frameBuffer.height >= winObj.height
		if frameBuffer.fb
			frameBuffer.fb_buf = new Uint32Array([frameBuffer.fb])
			gl.glDeleteFramebuffers(frameBuffer.fb_buf.length, frameBuffer.fb_buf)

		if frameBuffer.color_tex
			frameBuffer.color_tex_buf = new Uint32Array([frameBuffer.color_tex])
			gl.glDeleteTextures(frameBuffer.color_tex_buf.length, frameBuffer.color_tex_buf)

		if frameBuffer.depth_rb
			frameBuffer.depth_rb_buf = new Uint32Array([frameBuffer.depth_rb])
			gl.glDeleteRenderbuffers(frameBuffer.depth_rb_buf.length, frameBuffer.depth_rb_buf)

		frameBuffer = setupFrameBuffer(winObj.width, winObj.height)

	if debugDrawGLScene
		console.log 'DrawGLScene'

	unless global.gl?
		console.log 'no gl'
		return User32.TRUE

	MediaAccel.GlErrorAbort('DrawGLScene_04: 197')

	gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)
	MediaAccel.GlErrorAbort('DrawGLScene_04: 198')

	gl.glViewport(0, 0, winObj.width, winObj.height)
	MediaAccel.GlErrorAbort('DrawGLScene_04: 199')

	#gl.glClearColor(Math.random(), 0, 0, 0)
	gl.glClearColor(0, 0.25, 0, 0)
	MediaAccel.GlErrorAbort('DrawGLScene_04: 200')

	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer
	MediaAccel.GlErrorAbort('DrawGLScene_04: 202')

	gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, frameBuffer.fb)
	if 0
		gl.glViewport(0, 0, frameBuffer.width, frameBuffer.height)
	else
		gl.glViewport(0, 0, winObj.width, winObj.height)

#	gl.glClearColor(0, Math.random() * 0.50, 0, 0)
#	gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer

	if frameBuffer.colorTextureSparse
		#  glTexturePageCommitmentEXT(texture,   level, xoffset, yoffset, zoffset, width, height, depth, commit);
		gl.glTexturePageCommitmentEXT(frameBuffer.color_tex,     0,                   0,                   0,       0, frameBuffer.xsize,  frameBuffer.ysize,     1,      1);
		gl.glTexturePageCommitmentEXT(frameBuffer.color_tex,     0,   frameBuffer.xsize,                   0,       0, frameBuffer.xsize,  frameBuffer.ysize,     1,      1);
		gl.glTexturePageCommitmentEXT(frameBuffer.color_tex,     0,                   0,   frameBuffer.ysize,       0, frameBuffer.xsize,  frameBuffer.ysize,     1,      1);
		gl.glTexturePageCommitmentEXT(frameBuffer.color_tex,     0,   frameBuffer.xsize,   frameBuffer.ysize,       0, frameBuffer.xsize,  frameBuffer.ysize,     1,      1);
		gl.glGetError()

#	clearBuf = new Float32Array [0, 0, Math.random() * 0.25, 0]
	gl.glInvalidateTexImage(frameBuffer.color_tex, 0)

	clearBuf = new Float32Array [0, 0, 0.25, 0]
	gl.glClearTexImage(frameBuffer.color_tex, 0, gl.GL_RGBA, gl.GL_FLOAT, clearBuf);

	gl.glClear(gl.GL_DEPTH_BUFFER_BIT) #Clear Screen And Depth Buffer

	gl.glMatrixMode(gl.GL_MODELVIEW)                            # Select The Modelview Matrix
	gl.glLoadIdentity()                                         # Reset The Modelview Matrix
	gl.glTranslatef(-1.5, 0, -6)                                # Move Left 1.5 Units And Into The Screen 6.0

	gl.glRotatef(winObj.rtri,0,1,0)                                    # Rotate The Triangle On The Y axis ( NEW )
	gl.glBegin(gl.GL_TRIANGLES)                                 # Drawing Using Triangles
	gl.glColor3f(  1, 0, 0)                                     # Set The Color To Red
	gl.glVertex3f( 0, 1, 0)                                     # Move Up One Unit From Center (Top Point)
	gl.glColor3f(  0, 1, 0)                                     # Set The Color To Green
	gl.glVertex3f(-1,-1, 0)                                     # Left And Down One Unit (Bottom Left)
	gl.glColor3f(  0, 0, 1)                                     # Set The Color To Blue
	gl.glVertex3f( 1,-1, 0)                                     # Right And Down One Unit (Bottom Right)
	gl.glEnd()                                                  # Done Drawing A Triangle

	gl.glLoadIdentity()                                         # Reset The Current Modelview Matrix
	gl.glTranslatef(1.5,0,-6)                                   # Move Right 1.5 Units And Into The Screen 6.0
	gl.glRotatef(winObj.rquad,1,0,0)                                   # Rotate The Quad On The X axis ( NEW )
	gl.glColor3f(0.5, 0.5, 1)                                   # Set The Color To Blue One Time Only
	gl.glBegin(gl.GL_QUADS)                                     # Start Drawing Quads
	gl.glVertex3f(-1,  1, 0)                                    # Left And Up 1 Unit (Top Left)
	gl.glVertex3f( 1,  1, 0)                                    # Right And Up 1 Unit (Top Right)
	gl.glVertex3f( 1, -1, 0)                                    # Right And Down One Unit (Bottom Right)
	gl.glVertex3f(-1, -1, 0)                                    # Left And Down One Unit (Bottom Left)
	gl.glEnd()                                                  # Done Drawing A Quad


	gl.glBindFramebuffer(gl.GL_DRAW_FRAMEBUFFER, 0)
	gl.glBindFramebuffer(gl.GL_READ_FRAMEBUFFER, frameBuffer.fb)
	gl.glViewport(0, 0, winObj.width, winObj.heigth)
	if 0
		gl.glBlitFramebuffer(
			0, 0, 256, 256,
			0, 0, winObj.width, winObj.height,
			gl.GL_COLOR_BUFFER_BIT, gl.GL_LINEAR)
	else if 1
		gl.glBlitFramebuffer(
			0, 0, winObj.width, winObj.height,
			0, 0, winObj.width, winObj.height,
			gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT, gl.GL_NEAREST)
	else if 1
		gl.glBlitFramebuffer(
			0, 0, Math.min(frameBuffer.width, winObj.width), Math.min(frameBuffer.height, winObj.height),
			0, 0, Math.min(frameBuffer.width, winObj.width), Math.min(frameBuffer.height, winObj.height),
			gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT, gl.GL_NEAREST)
	else
		gl.glBlitFramebuffer(
			0, 0, 256, 256,
			0, 0, winObj.width, winObj.height,
			gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT, gl.GL_NEAREST)

	gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)

	winObj.rtri += 0.2 #Increase The Rotation Variable For The Triangle ( NEW )
	winObj.rquad -= 0.15 #Decrease The Rotation Variable For The Quad ( NEW )
	return User32.TRUE #Keep Going

DrawGLSceneOptions['DrawGLScene_04 using a shader'] = require('./DrawGLScene_04_Shader').DrawGLScene_04_Shader
DrawGLSceneOptions['DrawGLScene_04 using   Uint8Array        Buffer']     = require('./DrawGLScene_04_Uint8Array').DrawGLScene_Uint8Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using   Uint8ClampedArray Buffer']     = require('./DrawGLScene_04_Uint8ClampedArray').DrawGLScene_Uint8ClampedArray_Buffer
DrawGLSceneOptions['DrawGLScene_04 using  Uint16Array        Buffer']     = require('./DrawGLScene_04_Uint16Array').DrawGLScene_Uint16Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using  Uint32Array        Buffer']     = require('./DrawGLScene_04_Uint32Array').DrawGLScene_Uint32Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using    Int8Array        Buffer']     = require('./DrawGLScene_04_Int8Array').DrawGLScene_Int8Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using   Int16Array        Buffer']     = require('./DrawGLScene_04_Int16Array').DrawGLScene_Int16Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using   Int32Array        Buffer']     = require('./DrawGLScene_04_Int32Array').DrawGLScene_Int32Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using Float32Array        Buffer']     = require('./DrawGLScene_04_Float32Array').DrawGLScene_Float32Array_Buffer
DrawGLSceneOptions['DrawGLScene_04 using Float64Array        Buffer']     = require('./DrawGLScene_04_Float64Array').DrawGLScene_Float64Array_Buffer

DrawGLSceneOptions['DrawGLScene_04 using   Uint8Array        TypedArray'] = require('./DrawGLScene_04_Uint8Array').DrawGLScene_Uint8Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using   Uint8ClampedArray TypedArray'] = require('./DrawGLScene_04_Uint8ClampedArray').DrawGLScene_Uint8ClampedArray_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using  Uint16Array        TypedArray'] = require('./DrawGLScene_04_Uint16Array').DrawGLScene_Uint16Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using  Uint32Array        TypedArray'] = require('./DrawGLScene_04_Uint32Array').DrawGLScene_Uint32Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using    Int8Array        TypedArray'] = require('./DrawGLScene_04_Int8Array').DrawGLScene_Int8Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using   Int16Array        TypedArray'] = require('./DrawGLScene_04_Int16Array').DrawGLScene_Int16Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using   Int32Array        TypedArray'] = require('./DrawGLScene_04_Int32Array').DrawGLScene_Int32Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using Float32Array        TypedArray'] = require('./DrawGLScene_04_Float32Array').DrawGLScene_Float32Array_TypedArray
DrawGLSceneOptions['DrawGLScene_04 using Float64Array        TypedArray'] = require('./DrawGLScene_04_Float64Array').DrawGLScene_Float64Array_TypedArray

exports.DrawGLScene = (winObj)-> #Here's Where We Do All The Drawing
	winObj.rtri = 0 unless winObj.rtri?
	winObj.rquad = 0 unless winObj.rquad?

	for keyPressEvent in winObj.keyPressEvents
		switch keyPressEvent.str
			when 'n'
				drawFuncOption++
				DrawGLSceneOptionKey = undefined

	unless DrawGLSceneOptionKey?
		DrawGLSceneOptionKey = Object.keys(DrawGLSceneOptions)[drawFuncOption % Object.keys(DrawGLSceneOptions).length]
		console.log DrawGLSceneOptionKey

	DrawGLSceneOptions[DrawGLSceneOptionKey](winObj)
