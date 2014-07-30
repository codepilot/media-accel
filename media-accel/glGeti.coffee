exports.GL_GET_PNAME_FUNC = GL_GET_PNAME_FUNC ={}

TypedArray_to_Array = (ta)->
	for i in [0...ta.length]
		ta[i]

GL_GET_PNAME_FUNC['GL_ACTIVE_TEXTURE'] = (index=0)->#data returns a single value indicating the active multitexture unit. The initial value is GL_TEXTURE0. See glActiveTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_ACTIVE_TEXTURE, index, buf)
			else
				gl.glGetDoublev(gl.GL_ACTIVE_TEXTURE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_SPARSE_TEXTURE_SIZE_ARB'] = ->
			buf = new Float64Array(1)
			gl.glGetDoublev(gl.GL_MAX_SPARSE_TEXTURE_SIZE_ARB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB'] = ->
			buf = new Float64Array(1)
			gl.glGetDoublev(gl.GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB'] = ->
			buf = new Float64Array(1)
			gl.glGetDoublev(gl.GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB'] = ->
			buf = new Float64Array(1)
			gl.glGetDoublev(gl.GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT'] = ->
			buf = new Float64Array(1)
			gl.glGetDoublev(gl.GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_ALIASED_LINE_WIDTH_RANGE'] = (index=0)->#data returns a pair of values indicating the range of widths supported for aliased lines. See glLineWidth.
			buf = new Float64Array(2)
			if index
				gl.glGetDoublei_v(gl.GL_ALIASED_LINE_WIDTH_RANGE, index, buf)
			else
				gl.glGetDoublev(gl.GL_ALIASED_LINE_WIDTH_RANGE, buf)
			return {min: buf[0], max: buf[1]}

GL_GET_PNAME_FUNC['GL_ARRAY_BUFFER_BINDING'] = (index=0)->#data returns a single value, the name of the buffer object currently bound to the target GL_ARRAY_BUFFER. If no buffer object is bound to this target, 0 is returned. The initial value is 0. See glBindBuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_ARRAY_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_ARRAY_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND'] = (index=0)->#data returns a single boolean value indicating whether blending is enabled. The initial value is GL_FALSE. See glBlendFunc.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND_COLOR'] = (index=0)->#data returns four values, the red, green, blue, and alpha values which are the components of the blend color. See glBlendColor.
			buf = new Float64Array(4)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_COLOR, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_COLOR, buf)
			return {r: buf[0], g: buf[1], b: buf[2], a: buf[3]}

GL_GET_PNAME_FUNC['GL_BLEND_DST_ALPHA'] = (index=0)->#data returns one value, the symbolic constant identifying the alpha destination blend function. The initial value is GL_ZERO. See glBlendFunc and glBlendFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_DST_ALPHA, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_DST_ALPHA, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND_DST_RGB'] = (index=0)->#data returns one value, the symbolic constant identifying the RGB destination blend function. The initial value is GL_ZERO. See glBlendFunc and glBlendFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_DST_RGB, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_DST_RGB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND_EQUATION_RGB'] = (index=0)->#data returns one value, a symbolic constant indicating whether the RGB blend equation is GL_FUNC_ADD, GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT, GL_MIN or GL_MAX. See glBlendEquationSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_EQUATION_RGB, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_EQUATION_RGB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND_EQUATION_ALPHA'] = (index=0)->#data returns one value, a symbolic constant indicating whether the Alpha blend equation is GL_FUNC_ADD, GL_FUNC_SUBTRACT, GL_FUNC_REVERSE_SUBTRACT, GL_MIN or GL_MAX. See glBlendEquationSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_EQUATION_ALPHA, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_EQUATION_ALPHA, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND_SRC_ALPHA'] = (index=0)->#data returns one value, the symbolic constant identifying the alpha source blend function. The initial value is GL_ONE. See glBlendFunc and glBlendFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_SRC_ALPHA, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_SRC_ALPHA, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_BLEND_SRC_RGB'] = (index=0)->#data returns one value, the symbolic constant identifying the RGB source blend function. The initial value is GL_ONE. See glBlendFunc and glBlendFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_BLEND_SRC_RGB, index, buf)
			else
				gl.glGetDoublev(gl.GL_BLEND_SRC_RGB, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_COLOR_CLEAR_VALUE'] = (index=0)->#data returns four values: the red, green, blue, and alpha values used to clear the color buffers. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. The initial value is (0, 0, 0, 0). See glClearColor.
			buf = new Float64Array(4)
			if index
				gl.glGetDoublei_v(gl.GL_COLOR_CLEAR_VALUE, index, buf)
			else
				gl.glGetDoublev(gl.GL_COLOR_CLEAR_VALUE, buf)
			return {r: buf[0], g: buf[1], b: buf[2], a: buf[3]}

GL_GET_PNAME_FUNC['GL_COLOR_LOGIC_OP'] = (index=0)->#data returns a single boolean value indicating whether a fragment's RGBA color values are merged into the framebuffer using a logical operation. The initial value is GL_FALSE. See glLogicOp.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_COLOR_LOGIC_OP, index, buf)
			else
				gl.glGetDoublev(gl.GL_COLOR_LOGIC_OP, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_COLOR_WRITEMASK'] = (index=0)->#data returns four boolean values: the red, green, blue, and alpha write enables for the color buffers. The initial value is (GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE). See glColorMask.
			buf = new Float64Array(4)
			if index
				gl.glGetDoublei_v(gl.GL_COLOR_WRITEMASK, index, buf)
			else
				gl.glGetDoublev(gl.GL_COLOR_WRITEMASK, buf)
			return {r: buf[0], g: buf[1], b: buf[2], a: buf[3]}

GL_GET_PNAME_FUNC['GL_COMPRESSED_TEXTURE_FORMATS'] = (index=0)->#data returns a list of symbolic constants of length GL_NUM_COMPRESSED_TEXTURE_FORMATS indicating which compressed texture formats are available. See glCompressedTexImage2D.
			buf = new Float64Array(exports.glGeti(gl.GL_NUM_COMPRESSED_TEXTURE_FORMATS))
			if index
				gl.glGetDoublei_v(gl.GL_COMPRESSED_TEXTURE_FORMATS, index, buf)
			else
				gl.glGetDoublev(gl.GL_COMPRESSED_TEXTURE_FORMATS, buf)
			return TypedArray_to_Array buf

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum number of active shader storage blocks that may be accessed by a compute shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum total number of active shader storage blocks that may be accessed by all active shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_UNIFORM_BLOCKS'] = (index=0)->#data returns one value, the maximum number of uniform blocks per compute shader. The value must be at least 14. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_UNIFORM_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_UNIFORM_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS'] = (index=0)->#data returns one value, the maximum supported texture image units that can be used to access texture maps from the compute shader. The value may be at least 16. See glActiveTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of individual floating-point, integer, or boolean values that can be held in uniform variable storage for a compute shader. The value must be at least 1024. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to compute shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS'] = (index=0)->#data returns a single value, the maximum number of atomic counter buffers that may be accessed by a compute shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the number of words for compute shader uniform variables in all uniform blocks (including default). The value must be at least 1. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS'] = (index=0)->#data returns one value, the number of invocations in a single local work group (i.e., the product of the three dimensions) that may be dispatched to a compute shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_WORK_GROUP_COUNT'] = (index=0)->#Accepted by the indexed versions of glGet. data the maximum number of work groups that may be dispatched to a compute shader. Indices 0, 1, and 2 correspond to the X, Y and Z dimensions, respectively.
			ret = {}
			buf = new Float64Array(1)
			gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, buf); ret.x = buf[0]
			gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, buf); ret.y = buf[0]
			gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, buf); ret.z = buf[0]
			return ret

GL_GET_PNAME_FUNC['GL_MAX_COMPUTE_WORK_GROUP_SIZE'] = (index=0)->#Accepted by the indexed versions of glGet. data the maximum size of a work groups that may be used during compilation of a compute shader. Indices 0, 1, and 2 correspond to the X, Y and Z dimensions, respectively.
			ret = {}
			buf = new Float64Array(1)
			gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, buf); ret.x = buf[0]
			gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, buf); ret.y = buf[0]
			gl.glGetDoublei_v(gl.GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, buf); ret.z = buf[0]
			return ret

GL_GET_PNAME_FUNC['GL_DISPATCH_INDIRECT_BUFFER_BINDING'] = (index=0)->#data returns a single value, the name of the buffer object currently bound to the target GL_DISPATCH_INDIRECT_BUFFER. If no buffer object is bound to this target, 0 is returned. The initial value is 0. See glBindBuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DISPATCH_INDIRECT_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_DISPATCH_INDIRECT_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_DEBUG_GROUP_STACK_DEPTH'] = (index=0)->#data returns a single value, the maximum depth of the debug message group stack.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_DEBUG_GROUP_STACK_DEPTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_DEBUG_GROUP_STACK_DEPTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DEBUG_GROUP_STACK_DEPTH'] = (index=0)->#data returns a single value, the current depth of the debug message group stack.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DEBUG_GROUP_STACK_DEPTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_DEBUG_GROUP_STACK_DEPTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_CONTEXT_FLAGS'] = (index=0)->#data returns one value, the flags with which the context was created (such as debugging functionality).
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_CONTEXT_FLAGS, index, buf)
			else
				gl.glGetDoublev(gl.GL_CONTEXT_FLAGS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_CULL_FACE'] = (index=0)->#data returns a single boolean value indicating whether polygon culling is enabled. The initial value is GL_FALSE. See glCullFace.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_CULL_FACE, index, buf)
			else
				gl.glGetDoublev(gl.GL_CULL_FACE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_CURRENT_PROGRAM'] = (index=0)->#data returns one value, the name of the program object that is currently active, or 0 if no program object is active. See glUseProgram.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_CURRENT_PROGRAM, index, buf)
			else
				gl.glGetDoublev(gl.GL_CURRENT_PROGRAM, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DEPTH_CLEAR_VALUE'] = (index=0)->#data returns one value, the value that is used to clear the depth buffer. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. The initial value is 1. See glClearDepth.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DEPTH_CLEAR_VALUE, index, buf)
			else
				gl.glGetDoublev(gl.GL_DEPTH_CLEAR_VALUE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DEPTH_FUNC'] = (index=0)->#data returns one value, the symbolic constant that indicates the depth comparison function. The initial value is GL_LESS. See glDepthFunc.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DEPTH_FUNC, index, buf)
			else
				gl.glGetDoublev(gl.GL_DEPTH_FUNC, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DEPTH_RANGE'] = (index=0)->#data returns two values: the near and far mapping limits for the depth buffer. Integer values, if requested, are linearly mapped from the internal floating-point representation such that 1.0 returns the most positive representable integer value, and -1.0 returns the most negative representable integer value. The initial value is (0, 1). See glDepthRange.
			buf = new Float64Array(2)
			if index
				gl.glGetDoublei_v(gl.GL_DEPTH_RANGE, index, buf)
			else
				gl.glGetDoublev(gl.GL_DEPTH_RANGE, buf)
			return {min: buf[0], max: buf[1]}

GL_GET_PNAME_FUNC['GL_DEPTH_TEST'] = (index=0)->#data returns a single boolean value indicating whether depth testing of fragments is enabled. The initial value is GL_FALSE. See glDepthFunc and glDepthRange.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DEPTH_TEST, index, buf)
			else
				gl.glGetDoublev(gl.GL_DEPTH_TEST, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DEPTH_WRITEMASK'] = (index=0)->#data returns a single boolean value indicating if the depth buffer is enabled for writing. The initial value is GL_TRUE. See glDepthMask.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DEPTH_WRITEMASK, index, buf)
			else
				gl.glGetDoublev(gl.GL_DEPTH_WRITEMASK, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DITHER'] = (index=0)->#data returns a single boolean value indicating whether dithering of fragment colors and indices is enabled. The initial value is GL_TRUE.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DITHER, index, buf)
			else
				gl.glGetDoublev(gl.GL_DITHER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DOUBLEBUFFER'] = (index=0)->#data returns a single boolean value indicating whether double buffering is supported.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DOUBLEBUFFER, index, buf)
			else
				gl.glGetDoublev(gl.GL_DOUBLEBUFFER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DRAW_BUFFER'] = (index=0)->#data returns one value, a symbolic constant indicating which buffers are being drawn to. See glDrawBuffer. The initial value is GL_BACK if there are back buffers, otherwise it is GL_FRONT.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DRAW_BUFFER, index, buf)
			else
				gl.glGetDoublev(gl.GL_DRAW_BUFFER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DRAW_BUFFER '] = (index=0)->#data returns one value, a symbolic constant indicating which buffers are being drawn to by the corresponding output color. See glDrawBuffers. The initial value of GL_DRAW_BUFFER0 is GL_BACK if there are back buffers, otherwise it is GL_FRONT. The initial values of draw buffers for all other output colors is GL_NONE.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DRAW_BUFFER , index, buf)
			else
				gl.glGetDoublev(gl.GL_DRAW_BUFFER , buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_DRAW_FRAMEBUFFER_BINDING'] = (index=0)->#data returns one value, the name of the framebuffer object currently bound to the GL_DRAW_FRAMEBUFFER target. If the default framebuffer is bound, this value will be zero. The initial value is zero. See glBindFramebuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_DRAW_FRAMEBUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_DRAW_FRAMEBUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_READ_FRAMEBUFFER_BINDING'] = (index=0)->#data returns one value, the name of the framebuffer object currently bound to the GL_READ_FRAMEBUFFER target. If the default framebuffer is bound, this value will be zero. The initial value is zero. See glBindFramebuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_READ_FRAMEBUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_READ_FRAMEBUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_ELEMENT_ARRAY_BUFFER_BINDING'] = (index=0)->#data returns a single value, the name of the buffer object currently bound to the target GL_ELEMENT_ARRAY_BUFFER. If no buffer object is bound to this target, 0 is returned. The initial value is 0. See glBindBuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_ELEMENT_ARRAY_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_ELEMENT_ARRAY_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_FRAGMENT_SHADER_DERIVATIVE_HINT'] = (index=0)->#data returns one value, a symbolic constant indicating the mode of the derivative accuracy hint for fragment shaders. The initial value is GL_DONT_CARE. See glHint.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_FRAGMENT_SHADER_DERIVATIVE_HINT, index, buf)
			else
				gl.glGetDoublev(gl.GL_FRAGMENT_SHADER_DERIVATIVE_HINT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_IMPLEMENTATION_COLOR_READ_FORMAT'] = (index=0)->#data returns a single GLenum value indicating the implementation's preferred pixel data format. See glReadPixels.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_IMPLEMENTATION_COLOR_READ_FORMAT, index, buf)
			else
				gl.glGetDoublev(gl.GL_IMPLEMENTATION_COLOR_READ_FORMAT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_IMPLEMENTATION_COLOR_READ_TYPE'] = (index=0)->#data returns a single GLenum value indicating the implementation's preferred pixel data type. See glReadPixels.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_IMPLEMENTATION_COLOR_READ_TYPE, index, buf)
			else
				gl.glGetDoublev(gl.GL_IMPLEMENTATION_COLOR_READ_TYPE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_LINE_SMOOTH'] = (index=0)->#data returns a single boolean value indicating whether antialiasing of lines is enabled. The initial value is GL_FALSE. See glLineWidth.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_LINE_SMOOTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_LINE_SMOOTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_LINE_SMOOTH_HINT'] = (index=0)->#data returns one value, a symbolic constant indicating the mode of the line antialiasing hint. The initial value is GL_DONT_CARE. See glHint.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_LINE_SMOOTH_HINT, index, buf)
			else
				gl.glGetDoublev(gl.GL_LINE_SMOOTH_HINT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_LINE_WIDTH'] = (index=0)->#data returns one value, the line width as specified with glLineWidth. The initial value is 1.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_LINE_WIDTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_LINE_WIDTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_LAYER_PROVOKING_VERTEX'] = (index=0)->#data returns one value, the implementation dependent specifc vertex of a primitive that is used to select the rendering layer. If the value returned is equivalent to GL_PROVOKING_VERTEX, then the vertex selection follows the convention specified by glProvokingVertex. If the value returned is equivalent to GL_FIRST_VERTEX_CONVENTION, then the selection is always taken from the first vertex in the primitive. If the value returned is equivalent to GL_LAST_VERTEX_CONVENTION, then the selection is always taken from the last vertex in the primitive. If the value returned is equivalent to GL_UNDEFINED_VERTEX, then the selection is not guaranteed to be taken from any specific vertex in the primitive.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_LAYER_PROVOKING_VERTEX, index, buf)
			else
				gl.glGetDoublev(gl.GL_LAYER_PROVOKING_VERTEX, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_LOGIC_OP_MODE'] = (index=0)->#data returns one value, a symbolic constant indicating the selected logic operation mode. The initial value is GL_COPY. See glLogicOp.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_LOGIC_OP_MODE, index, buf)
			else
				gl.glGetDoublev(gl.GL_LOGIC_OP_MODE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAJOR_VERSION'] = (index=0)->#data returns one value, the major version number of the OpenGL API supported by the current context.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAJOR_VERSION, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAJOR_VERSION, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_3D_TEXTURE_SIZE'] = (index=0)->#data returns one value, a rough estimate of the largest 3D texture that the GL can handle. The value must be at least 64. Use GL_PROXY_TEXTURE_3D to determine if a texture is too large. See glTexImage3D.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_3D_TEXTURE_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_3D_TEXTURE_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_ARRAY_TEXTURE_LAYERS'] = (index=0)->#data returns one value. The value indicates the maximum number of layers allowed in an array texture, and must be at least 256. See glTexImage2D.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_ARRAY_TEXTURE_LAYERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_ARRAY_TEXTURE_LAYERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_CLIP_DISTANCES'] = (index=0)->#data returns one value, the maximum number of application-defined clipping distances. The value must be at least 8.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_CLIP_DISTANCES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_CLIP_DISTANCES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COLOR_TEXTURE_SAMPLES'] = (index=0)->#data returns one value, the maximum number of samples in a color multisample texture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COLOR_TEXTURE_SAMPLES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COLOR_TEXTURE_SAMPLES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to all active shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the number of words for fragment shader uniform variables in all uniform blocks (including default). The value must be at least 1. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the number of words for geometry shader uniform variables in all uniform blocks (including default). The value must be at least 1. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS'] = (index=0)->#data returns one value, the maximum supported texture image units that can be used to access texture maps from the vertex shader and the fragment processor combined. If both the vertex shader and the fragment processing stage access the same texture image unit, then that counts as using two texture image units against this limit. The value must be at least 48. See glActiveTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_UNIFORM_BLOCKS'] = (index=0)->#data returns one value, the maximum number of uniform blocks per program. The value must be at least 70. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_UNIFORM_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_UNIFORM_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the number of words for vertex shader uniform variables in all uniform blocks (including default). The value must be at least 1. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_CUBE_MAP_TEXTURE_SIZE'] = (index=0)->#data returns one value. The value gives a rough estimate of the largest cube-map texture that the GL can handle. The value must be at least 1024. Use GL_PROXY_TEXTURE_CUBE_MAP to determine if a texture is too large. See glTexImage2D.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_CUBE_MAP_TEXTURE_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_CUBE_MAP_TEXTURE_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_DEPTH_TEXTURE_SAMPLES'] = (index=0)->#data returns one value, the maximum number of samples in a multisample depth or depth-stencil texture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_DEPTH_TEXTURE_SAMPLES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_DEPTH_TEXTURE_SAMPLES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_DRAW_BUFFERS'] = (index=0)->#data returns one value, the maximum number of simultaneous outputs that may be written in a fragment shader. The value must be at least 8. See glDrawBuffers.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_DRAW_BUFFERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_DRAW_BUFFERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_DUAL_SOURCE_DRAW_BUFFERS'] = (index=0)->#data returns one value, the maximum number of active draw buffers when using dual-source blending. The value must be at least 1. See glBlendFunc and glBlendFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_DUAL_SOURCE_DRAW_BUFFERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_DUAL_SOURCE_DRAW_BUFFERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_ELEMENTS_INDICES'] = (index=0)->#data returns one value, the recommended maximum number of vertex array indices. See glDrawRangeElements.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_ELEMENTS_INDICES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_ELEMENTS_INDICES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_ELEMENTS_VERTICES'] = (index=0)->#data returns one value, the recommended maximum number of vertex array vertices. See glDrawRangeElements.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_ELEMENTS_VERTICES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_ELEMENTS_VERTICES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAGMENT_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to fragment shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAGMENT_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAGMENT_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum number of active shader storage blocks that may be accessed by a fragment shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAGMENT_INPUT_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of components of the inputs read by the fragment shader, which must be at least 128.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAGMENT_INPUT_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAGMENT_INPUT_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAGMENT_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of individual floating-point, integer, or boolean values that can be held in uniform variable storage for a fragment shader. The value must be at least 1024. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAGMENT_UNIFORM_VECTORS'] = (index=0)->#data returns one value, the maximum number of individual 4-vectors of floating-point, integer, or boolean values that can be held in uniform variable storage for a fragment shader. The value is equal to the value of GL_MAX_FRAGMENT_UNIFORM_COMPONENTS divided by 4 and must be at least 256. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAGMENT_UNIFORM_VECTORS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAGMENT_UNIFORM_VECTORS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAGMENT_UNIFORM_BLOCKS'] = (index=0)->#data returns one value, the maximum number of uniform blocks per fragment shader. The value must be at least 12. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAGMENT_UNIFORM_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAGMENT_UNIFORM_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAMEBUFFER_WIDTH'] = (index=0)->#data returns one value, the maximum width for a framebuffer that has no attachments, which must be at least 16384. See glFramebufferParameter.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAMEBUFFER_WIDTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAMEBUFFER_WIDTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAMEBUFFER_HEIGHT'] = (index=0)->#data returns one value, the maximum height for a framebuffer that has no attachments, which must be at least 16384. See glFramebufferParameter.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAMEBUFFER_HEIGHT, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAMEBUFFER_HEIGHT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAMEBUFFER_LAYERS'] = (index=0)->#data returns one value, the maximum number of layers for a framebuffer that has no attachments, which must be at least 2048. See glFramebufferParameter.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAMEBUFFER_LAYERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAMEBUFFER_LAYERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_FRAMEBUFFER_SAMPLES'] = (index=0)->#data returns one value, the maximum samples in a framebuffer that has no attachments, which must be at least 4. See glFramebufferParameter.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_FRAMEBUFFER_SAMPLES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_FRAMEBUFFER_SAMPLES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to geometry shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum number of active shader storage blocks that may be accessed by a geometry shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_INPUT_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of components of inputs read by a geometry shader, which must be at least 64.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_INPUT_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_INPUT_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_OUTPUT_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of components of outputs written by a geometry shader, which must be at least 128.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS'] = (index=0)->#data returns one value, the maximum supported texture image units that can be used to access texture maps from the geometry shader. The value must be at least 16. See glActiveTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_UNIFORM_BLOCKS'] = (index=0)->#data returns one value, the maximum number of uniform blocks per geometry shader. The value must be at least 12. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_UNIFORM_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_UNIFORM_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_GEOMETRY_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of individual floating-point, integer, or boolean values that can be held in uniform variable storage for a geometry shader. The value must be at least 1024. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_GEOMETRY_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_GEOMETRY_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_INTEGER_SAMPLES'] = (index=0)->#data returns one value, the maximum number of samples supported in integer format multisample buffers.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_INTEGER_SAMPLES, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_INTEGER_SAMPLES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MIN_MAP_BUFFER_ALIGNMENT'] = (index=0)->#data returns one value, the minimum alignment in basic machine units of pointers returned fromglMapBuffer and glMapBufferRange. This value must be a power of two and must be at least 64.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MIN_MAP_BUFFER_ALIGNMENT, index, buf)
			else
				gl.glGetDoublev(gl.GL_MIN_MAP_BUFFER_ALIGNMENT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_LABEL_LENGTH'] = (index=0)->#data returns one value, the maximum length of a label that may be assigned to an object. See glObjectLabel and glObjectPtrLabel.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_LABEL_LENGTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_LABEL_LENGTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_PROGRAM_TEXEL_OFFSET'] = (index=0)->#data returns one value, the maximum texel offset allowed in a texture lookup, which must be at least 7.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_PROGRAM_TEXEL_OFFSET, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_PROGRAM_TEXEL_OFFSET, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MIN_PROGRAM_TEXEL_OFFSET'] = (index=0)->#data returns one value, the minimum texel offset allowed in a texture lookup, which must be at most -8.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MIN_PROGRAM_TEXEL_OFFSET, index, buf)
			else
				gl.glGetDoublev(gl.GL_MIN_PROGRAM_TEXEL_OFFSET, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_RECTANGLE_TEXTURE_SIZE'] = (index=0)->#data returns one value. The value gives a rough estimate of the largest rectangular texture that the GL can handle. The value must be at least 1024. Use GL_PROXY_TEXTURE_RECTANGLE to determine if a texture is too large. See glTexImage2D.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_RECTANGLE_TEXTURE_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_RECTANGLE_TEXTURE_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_RENDERBUFFER_SIZE'] = (index=0)->#data returns one value. The value indicates the maximum supported size for renderbuffers. See glFramebufferRenderbuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_RENDERBUFFER_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_RENDERBUFFER_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_SAMPLE_MASK_WORDS'] = (index=0)->#data returns one value, the maximum number of sample mask words.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_SAMPLE_MASK_WORDS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_SAMPLE_MASK_WORDS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_SERVER_WAIT_TIMEOUT'] = (index=0)->#data returns one value, the maximum glWaitSync timeout interval.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_SERVER_WAIT_TIMEOUT, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_SERVER_WAIT_TIMEOUT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS'] = (index=0)->#data returns one value, the maximum number of shader storage buffer binding points on the context, which must be at least 8.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to tessellation control shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to tessellation evaluation shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum number of active shader storage blocks that may be accessed by a tessellation control shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum number of active shader storage blocks that may be accessed by a tessellation evaluation shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TEXTURE_BUFFER_SIZE'] = (index=0)->#data returns one value. The value gives the maximum number of texels allowed in the texel array of a texture buffer object. Value must be at least 65536.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TEXTURE_BUFFER_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TEXTURE_BUFFER_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TEXTURE_IMAGE_UNITS'] = (index=0)->#data returns one value, the maximum supported texture image units that can be used to access texture maps from the fragment shader. The value must be at least 16. See glActiveTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TEXTURE_IMAGE_UNITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TEXTURE_IMAGE_UNITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TEXTURE_LOD_BIAS'] = (index=0)->#data returns one value, the maximum, absolute value of the texture level-of-detail bias. The value must be at least 2.0.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TEXTURE_LOD_BIAS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TEXTURE_LOD_BIAS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_TEXTURE_SIZE'] = (index=0)->#data returns one value. The value gives a rough estimate of the largest texture that the GL can handle. The value must be at least 1024. Use a proxy texture target such as GL_PROXY_TEXTURE_1D or GL_PROXY_TEXTURE_2D to determine if a texture is too large. See glTexImage1D and glTexImage2D.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_TEXTURE_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_TEXTURE_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_UNIFORM_BUFFER_BINDINGS'] = (index=0)->#data returns one value, the maximum number of uniform buffer binding points on the context, which must be at least 36.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_UNIFORM_BUFFER_BINDINGS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_UNIFORM_BUFFER_BINDINGS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_UNIFORM_BLOCK_SIZE'] = (index=0)->#data returns one value, the maximum size in basic machine units of a uniform block, which must be at least 16384.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_UNIFORM_BLOCK_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_UNIFORM_BLOCK_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_UNIFORM_LOCATIONS'] = (index=0)->#data returns one value, the maximum number of explicitly assignable uniform locations, which must be at least 1024.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_UNIFORM_LOCATIONS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_UNIFORM_LOCATIONS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VARYING_COMPONENTS'] = (index=0)->#data returns one value, the number components for varying variables, which must be at least 60.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VARYING_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VARYING_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VARYING_VECTORS'] = (index=0)->#data returns one value, the number 4-vectors for varying variables, which is equal to the value of GL_MAX_VARYING_COMPONENTS and must be at least 15.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VARYING_VECTORS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VARYING_VECTORS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VARYING_FLOATS'] = (index=0)->#data returns one value, the maximum number of interpolators available for processing varying variables used by vertex and fragment shaders. This value represents the number of individual floating-point values that can be interpolated; varying variables declared as vectors, matrices, and arrays will all consume multiple interpolators. The value must be at least 32.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VARYING_FLOATS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VARYING_FLOATS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_ATOMIC_COUNTERS'] = (index=0)->#data returns a single value, the maximum number of atomic counters available to vertex shaders.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_ATOMIC_COUNTERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_ATOMIC_COUNTERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_ATTRIBS'] = (index=0)->#data returns one value, the maximum number of 4-component generic vertex attributes accessible to a vertex shader. The value must be at least 16. See glVertexAttrib.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_ATTRIBS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_ATTRIBS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS'] = (index=0)->#data returns one value, the maximum number of active shader storage blocks that may be accessed by a vertex shader.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS'] = (index=0)->#data returns one value, the maximum supported texture image units that can be used to access texture maps from the vertex shader. The value may be at least 16. See glActiveTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_UNIFORM_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of individual floating-point, integer, or boolean values that can be held in uniform variable storage for a vertex shader. The value must be at least 1024. See glUniform.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_UNIFORM_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_UNIFORM_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_UNIFORM_VECTORS'] = (index=0)->#data returns one value, the maximum number of 4-vectors that may be held in uniform variable storage for the vertex shader. The value of GL_MAX_VERTEX_UNIFORM_VECTORS is equal to the value of GL_MAX_VERTEX_UNIFORM_COMPONENTS and must be at least 256.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_UNIFORM_VECTORS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_UNIFORM_VECTORS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_OUTPUT_COMPONENTS'] = (index=0)->#data returns one value, the maximum number of components of output written by a vertex shader, which must be at least 64.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_OUTPUT_COMPONENTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_OUTPUT_COMPONENTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_UNIFORM_BLOCKS'] = (index=0)->#data returns one value, the maximum number of uniform blocks per vertex shader. The value must be at least 12. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_UNIFORM_BLOCKS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_UNIFORM_BLOCKS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VIEWPORT_DIMS'] = (index=0)->#data returns two values: the maximum supported width and height of the viewport. These must be at least as large as the visible dimensions of the display being rendered to. See glViewport.
			buf = new Float64Array(2)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VIEWPORT_DIMS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VIEWPORT_DIMS, buf)
			return {maxWidth: buf[0], maxHeight: buf[1]}

GL_GET_PNAME_FUNC['GL_MAX_VIEWPORTS'] = (index=0)->#data returns one value, the maximum number of simultaneous viewports that are supported. The value must be at least 16. See glViewportIndexed.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VIEWPORTS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VIEWPORTS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MINOR_VERSION'] = (index=0)->#data returns one value, the minor version number of the OpenGL API supported by the current context.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MINOR_VERSION, index, buf)
			else
				gl.glGetDoublev(gl.GL_MINOR_VERSION, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_NUM_COMPRESSED_TEXTURE_FORMATS'] = (index=0)->#data returns a single integer value indicating the number of available compressed texture formats. The minimum value is 4. See glCompressedTexImage2D.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_NUM_COMPRESSED_TEXTURE_FORMATS, index, buf)
			else
				gl.glGetDoublev(gl.GL_NUM_COMPRESSED_TEXTURE_FORMATS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_NUM_EXTENSIONS'] = (index=0)->#data returns one value, the number of extensions supported by the GL implementation for the current context. See glGetString.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_NUM_EXTENSIONS, index, buf)
			else
				gl.glGetDoublev(gl.GL_NUM_EXTENSIONS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_NUM_PROGRAM_BINARY_FORMATS'] = (index=0)->#data returns one value, the number of program binary formats supported by the implementation.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_NUM_PROGRAM_BINARY_FORMATS, index, buf)
			else
				gl.glGetDoublev(gl.GL_NUM_PROGRAM_BINARY_FORMATS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_NUM_SHADER_BINARY_FORMATS'] = (index=0)->#data returns one value, the number of binary shader formats supported by the implementation. If this value is greater than zero, then the implementation supports loading binary shaders. If it is zero, then the loading of binary shaders by the implementation is not supported.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_NUM_SHADER_BINARY_FORMATS, index, buf)
			else
				gl.glGetDoublev(gl.GL_NUM_SHADER_BINARY_FORMATS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_ALIGNMENT'] = (index=0)->#data returns one value, the byte alignment used for writing pixel data to memory. The initial value is 4. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_ALIGNMENT, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_ALIGNMENT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_IMAGE_HEIGHT'] = (index=0)->#data returns one value, the image height used for writing pixel data to memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_IMAGE_HEIGHT, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_IMAGE_HEIGHT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_LSB_FIRST'] = (index=0)->#data returns a single boolean value indicating whether single-bit pixels being written to memory are written first to the least significant bit of each unsigned byte. The initial value is GL_FALSE. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_LSB_FIRST, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_LSB_FIRST, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_ROW_LENGTH'] = (index=0)->#data returns one value, the row length used for writing pixel data to memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_ROW_LENGTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_ROW_LENGTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_SKIP_IMAGES'] = (index=0)->#data returns one value, the number of pixel images skipped before the first pixel is written into memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_SKIP_IMAGES, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_SKIP_IMAGES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_SKIP_PIXELS'] = (index=0)->#data returns one value, the number of pixel locations skipped before the first pixel is written into memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_SKIP_PIXELS, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_SKIP_PIXELS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_SKIP_ROWS'] = (index=0)->#data returns one value, the number of rows of pixel locations skipped before the first pixel is written into memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_SKIP_ROWS, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_SKIP_ROWS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PACK_SWAP_BYTES'] = (index=0)->#data returns a single boolean value indicating whether the bytes of two-byte and four-byte pixel indices and components are swapped before being written to memory. The initial value is GL_FALSE. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PACK_SWAP_BYTES, index, buf)
			else
				gl.glGetDoublev(gl.GL_PACK_SWAP_BYTES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PIXEL_PACK_BUFFER_BINDING'] = (index=0)->#data returns a single value, the name of the buffer object currently bound to the target GL_PIXEL_PACK_BUFFER. If no buffer object is bound to this target, 0 is returned. The initial value is 0. See glBindBuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PIXEL_PACK_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_PIXEL_PACK_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PIXEL_UNPACK_BUFFER_BINDING'] = (index=0)->#data returns a single value, the name of the buffer object currently bound to the target GL_PIXEL_UNPACK_BUFFER. If no buffer object is bound to this target, 0 is returned. The initial value is 0. See glBindBuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PIXEL_UNPACK_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_PIXEL_UNPACK_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POINT_FADE_THRESHOLD_SIZE'] = (index=0)->#data returns one value, the point size threshold for determining the point size. See glPointParameter.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POINT_FADE_THRESHOLD_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_POINT_FADE_THRESHOLD_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PRIMITIVE_RESTART_INDEX'] = (index=0)->#data returns one value, the current primitive restart index. The initial value is 0. See glPrimitiveRestartIndex.
			buf = new Float64Array(1)
			gl.glGetDoublev(gl.GL_PRIMITIVE_RESTART_INDEX, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PROGRAM_BINARY_FORMATS'] = (index=0)->#data an array of GL_NUM_PROGRAM_BINARY_FORMATS values, indicating the proram binary formats supported by the implementation.
			buf = new Float64Array(glGeti(gl.GL_NUM_PROGRAM_BINARY_FORMATS))
			if index
				gl.glGetDoublei_v(gl.GL_PROGRAM_BINARY_FORMATS, index, buf)
			else
				gl.glGetDoublev(gl.GL_PROGRAM_BINARY_FORMATS, buf)
			return TypedArray_to_Array buf

GL_GET_PNAME_FUNC['GL_PROGRAM_PIPELINE_BINDING'] = (index=0)->#data a single value, the name of the currently bound program pipeline object, or zero if no program pipeline object is bound. See glBindProgramPipeline.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PROGRAM_PIPELINE_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_PROGRAM_PIPELINE_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PROGRAM_POINT_SIZE'] = (index=0)->#data returns a single boolean value indicating whether vertex program point size mode is enabled. If enabled, then the point size is taken from the shader built-in gl_PointSize. If disabled, then the point size is taken from the point state as specified by glPointSize. The initial value is GL_FALSE.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PROGRAM_POINT_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_PROGRAM_POINT_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_PROVOKING_VERTEX'] = (index=0)->#data returns one value, the currently selected provoking vertex convention. The initial value is GL_LAST_VERTEX_CONVENTION. See glProvokingVertex.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_PROVOKING_VERTEX, index, buf)
			else
				gl.glGetDoublev(gl.GL_PROVOKING_VERTEX, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POINT_SIZE'] = (index=0)->#data returns one value, the point size as specified by glPointSize. The initial value is 1.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POINT_SIZE, index, buf)
			else
				gl.glGetDoublev(gl.GL_POINT_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POINT_SIZE_GRANULARITY'] = (index=0)->#data returns one value, the size difference between adjacent supported sizes for antialiased points. See glPointSize.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POINT_SIZE_GRANULARITY, index, buf)
			else
				gl.glGetDoublev(gl.GL_POINT_SIZE_GRANULARITY, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POINT_SIZE_RANGE'] = (index=0)->#data returns two values: the smallest and largest supported sizes for antialiased points. The smallest size must be at most 1, and the largest size must be at least 1. See glPointSize.
			buf = new Float64Array(2)
			if index
				gl.glGetDoublei_v(gl.GL_POINT_SIZE_RANGE, index, buf)
			else
				gl.glGetDoublev(gl.GL_POINT_SIZE_RANGE, buf)
			return {min: buf[0], max: buf[1]}

GL_GET_PNAME_FUNC['GL_POLYGON_OFFSET_FACTOR'] = (index=0)->#data returns one value, the scaling factor used to determine the variable offset that is added to the depth value of each fragment generated when a polygon is rasterized. The initial value is 0. See glPolygonOffset.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_OFFSET_FACTOR, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_OFFSET_FACTOR, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POLYGON_OFFSET_UNITS'] = (index=0)->#data returns one value. This value is multiplied by an implementation-specific value and then added to the depth value of each fragment generated when a polygon is rasterized. The initial value is 0. See glPolygonOffset.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_OFFSET_UNITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_OFFSET_UNITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POLYGON_OFFSET_FILL'] = (index=0)->#data returns a single boolean value indicating whether polygon offset is enabled for polygons in fill mode. The initial value is GL_FALSE. See glPolygonOffset.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_OFFSET_FILL, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_OFFSET_FILL, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POLYGON_OFFSET_LINE'] = (index=0)->#data returns a single boolean value indicating whether polygon offset is enabled for polygons in line mode. The initial value is GL_FALSE. See glPolygonOffset.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_OFFSET_LINE, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_OFFSET_LINE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POLYGON_OFFSET_POINT'] = (index=0)->#data returns a single boolean value indicating whether polygon offset is enabled for polygons in point mode. The initial value is GL_FALSE. See glPolygonOffset.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_OFFSET_POINT, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_OFFSET_POINT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POLYGON_SMOOTH'] = (index=0)->#data returns a single boolean value indicating whether antialiasing of polygons is enabled. The initial value is GL_FALSE. See glPolygonMode.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_SMOOTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_SMOOTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_POLYGON_SMOOTH_HINT'] = (index=0)->#data returns one value, a symbolic constant indicating the mode of the polygon antialiasing hint. The initial value is GL_DONT_CARE. See glHint.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_POLYGON_SMOOTH_HINT, index, buf)
			else
				gl.glGetDoublev(gl.GL_POLYGON_SMOOTH_HINT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_READ_BUFFER'] = (index=0)->#data returns one value, a symbolic constant indicating which color buffer is selected for reading. The initial value is GL_BACK if there is a back buffer, otherwise it is GL_FRONT. See glReadPixels.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_READ_BUFFER, index, buf)
			else
				gl.glGetDoublev(gl.GL_READ_BUFFER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_RENDERBUFFER_BINDING'] = (index=0)->#data returns a single value, the name of the renderbuffer object currently bound to the target GL_RENDERBUFFER. If no renderbuffer object is bound to this target, 0 is returned. The initial value is 0. See glBindRenderbuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_RENDERBUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_RENDERBUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SAMPLE_BUFFERS'] = (index=0)->#data returns a single integer value indicating the number of sample buffers associated with the framebuffer. See glSampleCoverage.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SAMPLE_BUFFERS, index, buf)
			else
				gl.glGetDoublev(gl.GL_SAMPLE_BUFFERS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SAMPLE_COVERAGE_VALUE'] = (index=0)->#data returns a single positive floating-point value indicating the current sample coverage value. See glSampleCoverage.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SAMPLE_COVERAGE_VALUE, index, buf)
			else
				gl.glGetDoublev(gl.GL_SAMPLE_COVERAGE_VALUE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SAMPLE_COVERAGE_INVERT'] = (index=0)->#data returns a single boolean value indicating if the temporary coverage value should be inverted. See glSampleCoverage.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SAMPLE_COVERAGE_INVERT, index, buf)
			else
				gl.glGetDoublev(gl.GL_SAMPLE_COVERAGE_INVERT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SAMPLER_BINDING'] = (index=0)->#data returns a single value, the name of the sampler object currently bound to the active texture unit. The initial value is 0. See glBindSampler.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SAMPLER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_SAMPLER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SAMPLES'] = (index=0)->#data returns a single integer value indicating the coverage mask size. See glSampleCoverage.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SAMPLES, index, buf)
			else
				gl.glGetDoublev(gl.GL_SAMPLES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SCISSOR_BOX'] = (index=0)->#data returns four values: the x and y window coordinates of the scissor box, followed by its width and height. Initially the x and y window coordinates are both 0 and the width and height are set to the size of the window. See glScissor.
			buf = new Float64Array(4)
			if index
				gl.glGetDoublei_v(gl.GL_SCISSOR_BOX, index, buf)
			else
				gl.glGetDoublev(gl.GL_SCISSOR_BOX, buf)
			return {x: buf[0], y: buf[1], width: buf[2], height: buf[3]}

GL_GET_PNAME_FUNC['GL_SCISSOR_TEST'] = (index=0)->#data returns a single boolean value indicating whether scissoring is enabled. The initial value is GL_FALSE. See glScissor.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SCISSOR_TEST, index, buf)
			else
				gl.glGetDoublev(gl.GL_SCISSOR_TEST, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SHADER_COMPILER'] = (index=0)->#data returns a single boolean value indicating whether an online shader compiler is present in the implementation. All desktop OpenGL implementations must support online shader compilations, and therefore the value of GL_SHADER_COMPILER will always be GL_TRUE.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SHADER_COMPILER, index, buf)
			else
				gl.glGetDoublev(gl.GL_SHADER_COMPILER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SHADER_STORAGE_BUFFER_BINDING'] = (index=0)->#When used with non-indexed variants of glGet (such as glGetIntegerv), data returns a single value, the name of the buffer object currently bound to the target GL_SHADER_STORAGE_BUFFER. If no buffer object is bound to this target, 0 is returned. When used with indexed variants of glGet (such as glGetIntegeri_v), data returns a single value, the name of the buffer object bound to the indexed shader storage buffer binding points. The initial value is 0 for all targets. See glBindBuffer, glBindBufferBase, and glBindBufferRange.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SHADER_STORAGE_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_SHADER_STORAGE_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT'] = (index=0)->#data returns a single value, the minimum required alignment for shader storage buffer sizes and offset. The initial value is 1. See glShaderStorateBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, index, buf)
			else
				gl.glGetDoublev(gl.GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SHADER_STORAGE_BUFFER_START'] = (index=0)->#When used with indexed variants of glGet (such as glGetInteger64i_v), data returns a single value, the start offset of the binding range for each indexed shader storage buffer binding. The initial value is 0 for all bindings. See glBindBufferRange.
			buf = new Float64Array(1)
			#if index > 0
			gl.glGetDoublei_v(gl.GL_SHADER_STORAGE_BUFFER_START, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_SHADER_STORAGE_BUFFER_START, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SHADER_STORAGE_BUFFER_SIZE'] = (index=0)->#When used with indexed variants of glGet (such as glGetInteger64i_v), data returns a single value, the size of the binding range for each indexed shader storage buffer binding. The initial value is 0 for all bindings. See glBindBufferRange.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_SHADER_STORAGE_BUFFER_SIZE, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_SHADER_STORAGE_BUFFER_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SMOOTH_LINE_WIDTH_RANGE'] = (index=0)->#data returns a pair of values indicating the range of widths supported for smooth (antialiased) lines. See glLineWidth.
			buf = new Float64Array(2)
			if index
				gl.glGetDoublei_v(gl.GL_SMOOTH_LINE_WIDTH_RANGE, index, buf)
			else
				gl.glGetDoublev(gl.GL_SMOOTH_LINE_WIDTH_RANGE, buf)
			return {min: buf[0], max: buf[1]}

GL_GET_PNAME_FUNC['GL_SMOOTH_LINE_WIDTH_GRANULARITY'] = (index=0)->#data returns a single value indicating the level of quantization applied to smooth line width parameters.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SMOOTH_LINE_WIDTH_GRANULARITY, index, buf)
			else
				gl.glGetDoublev(gl.GL_SMOOTH_LINE_WIDTH_GRANULARITY, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_FAIL'] = (index=0)->#data returns one value, a symbolic constant indicating what action is taken for back-facing polygons when the stencil test fails. The initial value is GL_KEEP. See glStencilOpSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_FAIL, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_FAIL, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_FUNC'] = (index=0)->#data returns one value, a symbolic constant indicating what function is used for back-facing polygons to compare the stencil reference value with the stencil buffer value. The initial value is GL_ALWAYS. See glStencilFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_FUNC, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_FUNC, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_PASS_DEPTH_FAIL'] = (index=0)->#data returns one value, a symbolic constant indicating what action is taken for back-facing polygons when the stencil test passes, but the depth test fails. The initial value is GL_KEEP. See glStencilOpSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_PASS_DEPTH_FAIL, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_PASS_DEPTH_FAIL, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_PASS_DEPTH_PASS'] = (index=0)->#data returns one value, a symbolic constant indicating what action is taken for back-facing polygons when the stencil test passes and the depth test passes. The initial value is GL_KEEP. See glStencilOpSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_PASS_DEPTH_PASS, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_PASS_DEPTH_PASS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_REF'] = (index=0)->#data returns one value, the reference value that is compared with the contents of the stencil buffer for back-facing polygons. The initial value is 0. See glStencilFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_REF, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_REF, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_VALUE_MASK'] = (index=0)->#data returns one value, the mask that is used for back-facing polygons to mask both the stencil reference value and the stencil buffer value before they are compared. The initial value is all 1's. See glStencilFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_VALUE_MASK, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_VALUE_MASK, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_BACK_WRITEMASK'] = (index=0)->#data returns one value, the mask that controls writing of the stencil bitplanes for back-facing polygons. The initial value is all 1's. See glStencilMaskSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_BACK_WRITEMASK, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_BACK_WRITEMASK, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_CLEAR_VALUE'] = (index=0)->#data returns one value, the index to which the stencil bitplanes are cleared. The initial value is 0. See glClearStencil.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_CLEAR_VALUE, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_CLEAR_VALUE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_FAIL'] = (index=0)->#data returns one value, a symbolic constant indicating what action is taken when the stencil test fails. The initial value is GL_KEEP. See glStencilOp. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilOpSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_FAIL, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_FAIL, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_FUNC'] = (index=0)->#data returns one value, a symbolic constant indicating what function is used to compare the stencil reference value with the stencil buffer value. The initial value is GL_ALWAYS. See glStencilFunc. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_FUNC, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_FUNC, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_PASS_DEPTH_FAIL'] = (index=0)->#data returns one value, a symbolic constant indicating what action is taken when the stencil test passes, but the depth test fails. The initial value is GL_KEEP. See glStencilOp. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilOpSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_PASS_DEPTH_FAIL, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_PASS_DEPTH_FAIL, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_PASS_DEPTH_PASS'] = (index=0)->#data returns one value, a symbolic constant indicating what action is taken when the stencil test passes and the depth test passes. The initial value is GL_KEEP. See glStencilOp. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilOpSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_PASS_DEPTH_PASS, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_PASS_DEPTH_PASS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_REF'] = (index=0)->#data returns one value, the reference value that is compared with the contents of the stencil buffer. The initial value is 0. See glStencilFunc. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_REF, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_REF, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_TEST'] = (index=0)->#data returns a single boolean value indicating whether stencil testing of fragments is enabled. The initial value is GL_FALSE. See glStencilFunc and glStencilOp.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_TEST, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_TEST, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_VALUE_MASK'] = (index=0)->#data returns one value, the mask that is used to mask both the stencil reference value and the stencil buffer value before they are compared. The initial value is all 1's. See glStencilFunc. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilFuncSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_VALUE_MASK, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_VALUE_MASK, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STENCIL_WRITEMASK'] = (index=0)->#data returns one value, the mask that controls writing of the stencil bitplanes. The initial value is all 1's. See glStencilMask. This stencil state only affects non-polygons and front-facing polygons. Back-facing polygons use separate stencil state. See glStencilMaskSeparate.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STENCIL_WRITEMASK, index, buf)
			else
				gl.glGetDoublev(gl.GL_STENCIL_WRITEMASK, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_STEREO'] = (index=0)->#data returns a single boolean value indicating whether stereo buffers (left and right) are supported.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_STEREO, index, buf)
			else
				gl.glGetDoublev(gl.GL_STEREO, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_SUBPIXEL_BITS'] = (index=0)->#data returns one value, an estimate of the number of bits of subpixel resolution that are used to position rasterized geometry in window coordinates. The value must be at least 4.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_SUBPIXEL_BITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_SUBPIXEL_BITS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_1D'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_1D. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_1D, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_1D, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_1D_ARRAY'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_1D_ARRAY. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_1D_ARRAY, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_1D_ARRAY, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_2D'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_2D. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_2D, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_2D, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_2D_ARRAY'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_2D_ARRAY. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_2D_ARRAY, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_2D_ARRAY, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_2D_MULTISAMPLE'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_2D_MULTISAMPLE. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_2D_MULTISAMPLE, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_2D_MULTISAMPLE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_2D_MULTISAMPLE_ARRAY. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_3D'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_3D. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_3D, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_3D, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_BUFFER'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_BUFFER. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_BUFFER, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_BUFFER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_CUBE_MAP'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_CUBE_MAP. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_CUBE_MAP, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_CUBE_MAP, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_RECTANGLE'] = (index=0)->#data returns a single value, the name of the texture currently bound to the target GL_TEXTURE_RECTANGLE. The initial value is 0. See glBindTexture.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_RECTANGLE, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_RECTANGLE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_COMPRESSION_HINT'] = (index=0)->#data returns a single value indicating the mode of the texture compression hint. The initial value is GL_DONT_CARE.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_COMPRESSION_HINT, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_COMPRESSION_HINT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BINDING_BUFFER'] = (index=0)->#data returns a single value, the name of the buffer object currently bound to the GL_TEXTURE_BUFFER buffer binding point. The initial value is 0. See glBindBuffer.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BINDING_BUFFER, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BINDING_BUFFER, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT'] = (index=0)->#data returns a single value, the minimum required alignment for texture buffer sizes and offset. The initial value is 1. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT, index, buf)
			else
				gl.glGetDoublev(gl.GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TIMESTAMP'] = (index=0)->#data returns a single value, the 64-bit value of the current GL time. See glQueryCounter.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TIMESTAMP, index, buf)
			else
				gl.glGetDoublev(gl.GL_TIMESTAMP, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TRANSFORM_FEEDBACK_BUFFER_BINDING'] = (index=0)->#When used with non-indexed variants of glGet (such as glGetIntegerv), data returns a single value, the name of the buffer object currently bound to the target GL_TRANSFORM_FEEDBACK_BUFFER. If no buffer object is bound to this target, 0 is returned. When used with indexed variants of glGet (such as glGetIntegeri_v), data returns a single value, the name of the buffer object bound to the indexed transform feedback attribute stream. The initial value is 0 for all targets. See glBindBuffer, glBindBufferBase, and glBindBufferRange.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_TRANSFORM_FEEDBACK_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_TRANSFORM_FEEDBACK_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TRANSFORM_FEEDBACK_BUFFER_START'] = (index=0)->#When used with indexed variants of glGet (such as glGetInteger64i_v), data returns a single value, the start offset of the binding range for each transform feedback attribute stream. The initial value is 0 for all streams. See glBindBufferRange.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_TRANSFORM_FEEDBACK_BUFFER_START, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_TRANSFORM_FEEDBACK_BUFFER_START, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_TRANSFORM_FEEDBACK_BUFFER_SIZE'] = (index=0)->#When used with indexed variants of glGet (such as glGetInteger64i_v), data returns a single value, the size of the binding range for each transform feedback attribute stream. The initial value is 0 for all streams. See glBindBufferRange.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_TRANSFORM_FEEDBACK_BUFFER_SIZE, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_TRANSFORM_FEEDBACK_BUFFER_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNIFORM_BUFFER_BINDING'] = (index=0)->#When used with non-indexed variants of glGet (such as glGetIntegerv), data returns a single value, the name of the buffer object currently bound to the target GL_UNIFORM_BUFFER. If no buffer object is bound to this target, 0 is returned. When used with indexed variants of glGet (such as glGetIntegeri_v), data returns a single value, the name of the buffer object bound to the indexed uniform buffer binding point. The initial value is 0 for all targets. See glBindBuffer, glBindBufferBase, and glBindBufferRange.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNIFORM_BUFFER_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNIFORM_BUFFER_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT'] = (index=0)->#data returns a single value, the minimum required alignment for uniform buffer sizes and offset. The initial value is 1. See glUniformBlockBinding.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNIFORM_BUFFER_SIZE'] = (index=0)->#When used with indexed variants of glGet (such as glGetInteger64i_v), data returns a single value, the size of the binding range for each indexed uniform buffer binding. The initial value is 0 for all bindings. See glBindBufferRange.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_UNIFORM_BUFFER_SIZE, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_UNIFORM_BUFFER_SIZE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNIFORM_BUFFER_START'] = (index=0)->#When used with indexed variants of glGet (such as glGetInteger64i_v), data returns a single value, the start offset of the binding range for each indexed uniform buffer binding. The initial value is 0 for all bindings. See glBindBufferRange.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_UNIFORM_BUFFER_START, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_UNIFORM_BUFFER_START, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_ALIGNMENT'] = (index=0)->#data returns one value, the byte alignment used for reading pixel data from memory. The initial value is 4. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_ALIGNMENT, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_ALIGNMENT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_IMAGE_HEIGHT'] = (index=0)->#data returns one value, the image height used for reading pixel data from memory. The initial is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_IMAGE_HEIGHT, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_IMAGE_HEIGHT, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_LSB_FIRST'] = (index=0)->#data returns a single boolean value indicating whether single-bit pixels being read from memory are read first from the least significant bit of each unsigned byte. The initial value is GL_FALSE. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_LSB_FIRST, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_LSB_FIRST, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_ROW_LENGTH'] = (index=0)->#data returns one value, the row length used for reading pixel data from memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_ROW_LENGTH, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_ROW_LENGTH, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_SKIP_IMAGES'] = (index=0)->#data returns one value, the number of pixel images skipped before the first pixel is read from memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_SKIP_IMAGES, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_SKIP_IMAGES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_SKIP_PIXELS'] = (index=0)->#data returns one value, the number of pixel locations skipped before the first pixel is read from memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_SKIP_PIXELS, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_SKIP_PIXELS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_SKIP_ROWS'] = (index=0)->#data returns one value, the number of rows of pixel locations skipped before the first pixel is read from memory. The initial value is 0. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_SKIP_ROWS, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_SKIP_ROWS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_UNPACK_SWAP_BYTES'] = (index=0)->#data returns a single boolean value indicating whether the bytes of two-byte and four-byte pixel indices and components are swapped after being read from memory. The initial value is GL_FALSE. See glPixelStore.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_UNPACK_SWAP_BYTES, index, buf)
			else
				gl.glGetDoublev(gl.GL_UNPACK_SWAP_BYTES, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_VERTEX_ARRAY_BINDING'] = (index=0)->#data returns a single value, the name of the vertex array object currently bound to the context. If no vertex array object is bound to the context, 0 is returned. The initial value is 0. See glBindVertexArray.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_VERTEX_ARRAY_BINDING, index, buf)
			else
				gl.glGetDoublev(gl.GL_VERTEX_ARRAY_BINDING, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_VERTEX_BINDING_DIVISOR'] = (index=0)->#Accepted by the indexed forms. data returns a single integer value representing the instance step divisor of the first element in the bound buffer's data store for vertex attribute bound to index.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_VERTEX_BINDING_DIVISOR, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_VERTEX_BINDING_DIVISOR, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_VERTEX_BINDING_OFFSET'] = (index=0)->#Accepted by the indexed forms. data returns a single integer value representing the byte offset of the first element in the bound buffer's data store for vertex attribute bound to index.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_VERTEX_BINDING_OFFSET, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_VERTEX_BINDING_OFFSET, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_VERTEX_BINDING_STRIDE'] = (index=0)->#Accepted by the indexed forms. data returns a single integer value representing the byte offset between the start of each element in the bound buffer's data store for vertex attribute bound to index.
			buf = new Float64Array(1)
			#if index
			gl.glGetDoublei_v(gl.GL_VERTEX_BINDING_STRIDE, index, buf)
			#else
			#gl.glGetDoublev(gl.GL_VERTEX_BINDING_STRIDE, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET'] = (index=0)->#data returns a single integer value containing the maximum offset that may be added to a vertex binding offset.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_MAX_VERTEX_ATTRIB_BINDINGS'] = (index=0)->#data returns a single integer value containing the maximum number of vertex buffers that may be bound.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_MAX_VERTEX_ATTRIB_BINDINGS, index, buf)
			else
				gl.glGetDoublev(gl.GL_MAX_VERTEX_ATTRIB_BINDINGS, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_VIEWPORT'] = (index=0)->#When used with non-indexed variants of glGet (such as glGetIntegerv), data returns four values: the x and y window coordinates of the viewport, followed by its width and height. Initially the x and y window coordinates are both set to 0, and the width and height are set to the width and height of the window into which the GL will do its rendering. See glViewport.
		#When used with indexed variants of glGet (such as glGetIntegeri_v), data returns four values: the x and y window coordinates of the indexed viewport, followed by its width and height. Initially the x and y window coordinates are both set to 0, and the width and height are set to the width and height of the window into which the GL will do its rendering. See glViewportIndexedf.
			buf = new Float64Array(4)
			if index
				gl.glGetDoublei_v(gl.GL_VIEWPORT, index, buf)
			else
				gl.glGetDoublev(gl.GL_VIEWPORT, buf)
			return {x: buf[0], y: buf[1], width: buf[2], height: buf[3]}

GL_GET_PNAME_FUNC['GL_VIEWPORT_BOUNDS_RANGE'] = (index=0)->#data returns two values, the minimum and maximum viewport bounds range. The minimum range should be at least [-32768, 32767].
			buf = new Float64Array(2)
			if index
				gl.glGetDoublei_v(gl.GL_VIEWPORT_BOUNDS_RANGE, index, buf)
			else
				gl.glGetDoublev(gl.GL_VIEWPORT_BOUNDS_RANGE, buf)
			return {min: buf[0], max: buf[1]}

GL_GET_PNAME_FUNC['GL_VIEWPORT_INDEX_PROVOKING_VERTEX'] = (index=0)->#data returns one value, the implementation dependent specifc vertex of a primitive that is used to select the viewport index. If the value returned is equivalent to GL_PROVOKING_VERTEX, then the vertex selection follows the convention specified by glProvokingVertex. If the value returned is equivalent to GL_FIRST_VERTEX_CONVENTION, then the selection is always taken from the first vertex in the primitive. If the value returned is equivalent to GL_LAST_VERTEX_CONVENTION, then the selection is always taken from the last vertex in the primitive. If the value returned is equivalent to GL_UNDEFINED_VERTEX, then the selection is not guaranteed to be taken from any specific vertex in the primitive.
			buf = new Float64Array(1)
			#if index
			#gl.glGetDoublei_v(gl.GL_VIEWPORT_INDEX_PROVOKING_VERTEX, index, buf)
			#else
			gl.glGetDoublev(gl.GL_VIEWPORT_INDEX_PROVOKING_VERTEX, buf)
			return buf[0]

GL_GET_PNAME_FUNC['GL_VIEWPORT_SUBPIXEL_BITS'] = (index=0)->#data returns a single value, the number of bits of sub-pixel precision which the GL uses to interpret the floating point viewport bounds. The minimum value is 0.
			buf = new Float64Array(1)
			if index
				gl.glGetDoublei_v(gl.GL_VIEWPORT_SUBPIXEL_BITS, index, buf)
			else
				gl.glGetDoublev(gl.GL_VIEWPORT_SUBPIXEL_BITS, buf)
			return buf[0]

#GL_GET_PNAME_FUNC['GL_MAX_ELEMENT_INDEX'] = (index=0)->#data returns a single value, the maximum index that may be specified during the transfer of generic vertex attributes to the GL.
#			buf = new Float64Array(1)
#			#if index
#			gl.glGetDoublei_v(gl.GL_MAX_ELEMENT_INDEX, index, buf)
#			#else
#			#gl.glGetDoublev(gl.GL_MAX_ELEMENT_index, buf)
#			return buf[0]

exports.GL_GET_PNAME_KEYS = GL_GET_PNAME_KEYS = Object.keys(GL_GET_PNAME_FUNC)

exports.GL_GET_PNAME_NUM_FUNC = GL_GET_PNAME_NUM_FUNC = {}

for k, v of GL_GET_PNAME_FUNC
	GL_GET_PNAME_NUM_FUNC[MediaAccel.OpenGL.prototype[k]] = v

exports.glGeti = glGeti = (pname, index=0)->
#Many of the boolean parameters can also be queried more easily using glIsEnabled.
	return unless GL_GET_PNAME_NUM_FUNC[pname]?
	return GL_GET_PNAME_NUM_FUNC[pname](index)
