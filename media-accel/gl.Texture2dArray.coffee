init = -> #the target is this gl is now this
#	console.log this
	Object.defineProperty this, 'CreateTexture2dArray', value: (target = @GL_TEXTURE_2D_ARRAY, count = 1)=>
		
		textures = new Uint32Array(count)
		@glGenTextures(textures.length, textures)
		
		ret = Object.create null,
			length: enumerable: true, value: count
			destructorObj: value: new MediaAccel.Destructor =>
				@glDeleteTextures textures.length, textures
				console.log '~Texture2dArray'

			bind: value: (first = 0)=>
				#GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
				@glBindTextures first, textures.length, textures

			generateMipmap: value: =>
				for texture in textures
					#GLAPI void APIENTRY glGenerateTextureMipmapEXT (GLuint texture, GLenum target);
					@glGenerateTextureMipmapEXT(texture, target)

			isTexture: enumerable: true, get: =>
				for texture in textures
					@glIsTexture texture

			parameter: value: (pname, param)=>
				for texture, i in textures
					#//GLAPI void APIENTRY glTextureParameteriEXT (GLuint texture, GLenum target, GLenum pname, GLint param);
					@glTextureParameteriEXT(texture, target, pname, param)
				
			#clear
			#view
			#invalidate
			#sparse
			#bindless
			#//GLAPI void APIENTRY glTexturePageCommitmentEXT (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
			pageCommitment: value: (textureNum, level, xoffset, yoffset, zoffset, width, height, depth, commit)=>
				@glTexturePageCommitmentEXT(textures[textureNum], level, xoffset, yoffset, zoffset, width, height, depth, commit);
#			        void glTexturePageCommitmentEXT(uint texture,
#                                      int level,
#                                      int xoffset,
#                                      int yoffset,
#                                      int zoffset,
#                                      sizei width,
#                                      sizei height,
#                                      sizei depth,
#                                      boolean commit);
			
			storage: value: (levels, internalformat, width, height, depth)=>
				if isNaN(levels)
					
					levels = 1
					maxWH = Math.max width, height
					loop
						#console.log
						#	level: levels - 1
						#	maxWH: maxWH
						break if maxWH <= 1
						levels++
						maxWH >>>= 1

					#console.log
					#	width: width
					#	height: height
					#	levels: levels

				for texture in textures
					#GLAPI void APIENTRY glTextureStorage3DEXT (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
					@glTextureStorage3DEXT(texture, target, levels, internalformat, width, height, depth)

		for texture, i in textures
			Object.defineProperty ret, i, enumerable: true, value: texture

		#{r: float32, g: float32, b: float32, a: float32}
		for texParam in 'GL_TEXTURE_BORDER_COLOR'.split ' '
			do (texParam)=>
				Object.defineProperty ret, texParam, enumerable: true, get: =>
					for texture in textures
						params = new Float32Array([NaN, NaN, NaN, NaN])
						@glGetTextureParameterfvEXT(texture, target, @[texParam], params)
						{r: params[0], g: params[1], b: params[2], a: params[3]}

		#{r: enum, g: enum, b: enum, a: enum}
		for texParam in 'GL_TEXTURE_SWIZZLE_RGBA'.split ' '
			do (texParam)=>
				Object.defineProperty ret, texParam, enumerable: true, get: =>
					for texture in textures
						params = new Int32Array([0, 0, 0, 0])
						@glGetTextureParameterivEXT(texture, target, @[texParam], params)
						{r: params[0], g: params[1], b: params[2], a: params[3]}
		
		#enum
		for texParam in 'GL_NUM_SPARSE_LEVELS_ARB GL_TEXTURE_SPARSE_ARB GL_VIRTUAL_PAGE_SIZE_INDEX_ARB GL_DEPTH_STENCIL_TEXTURE_MODE GL_TEXTURE_MAG_FILTER GL_TEXTURE_MIN_FILTER GL_TEXTURE_SWIZZLE_R GL_TEXTURE_SWIZZLE_G GL_TEXTURE_SWIZZLE_B GL_TEXTURE_SWIZZLE_A GL_TEXTURE_WRAP_S GL_TEXTURE_WRAP_T GL_TEXTURE_WRAP_R GL_TEXTURE_COMPARE_MODE GL_TEXTURE_COMPARE_FUNC GL_TEXTURE_IMMUTABLE_FORMAT'.split ' '
			do (texParam)=>
				Object.defineProperty ret, texParam, enumerable: true, get: =>
						for texture in textures
							params = new Int32Array([0])
							#GLAPI void APIENTRY glGetTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
							@glGetTextureParameterivEXT(texture, target, @[texParam], params)
							params[0]

		#float32
		for texParam in 'GL_TEXTURE_MIN_LOD GL_TEXTURE_MAX_LOD GL_TEXTURE_BASE_LEVEL GL_TEXTURE_MAX_LEVEL GL_TEXTURE_VIEW_MIN_LEVEL GL_TEXTURE_VIEW_NUM_LEVELS GL_TEXTURE_VIEW_MIN_LAYER GL_TEXTURE_VIEW_NUM_LAYERS GL_TEXTURE_IMMUTABLE_LEVELS'.split ' '
			do (texParam)=>
				Object.defineProperty ret, texParam, enumerable: true, get: =>
					for texture in textures
						params = new Int32Array([0])
						#GLAPI void APIENTRY glGetTextureParameterivEXT (GLuint texture, GLenum target, GLenum pname, GLint *params);
						@glGetTextureParameterivEXT(texture, target, @[texParam], params)
						params[0]


		#int32
		for texParam in 'GL_TEXTURE_WIDTH GL_TEXTURE_HEIGHT GL_TEXTURE_DEPTH GL_TEXTURE_RED_SIZE GL_TEXTURE_GREEN_SIZE GL_TEXTURE_BLUE_SIZE GL_TEXTURE_ALPHA_SIZE GL_TEXTURE_DEPTH_SIZE GL_TEXTURE_COMPRESSED_IMAGE_SIZE GL_TEXTURE_BUFFER_OFFSET GL_TEXTURE_BUFFER_SIZE'.split ' '
			do (texParam)=>
				Object.defineProperty ret, texParam, enumerable: true, get: =>
					for texture, i in textures
						for levels in [0...ret.GL_TEXTURE_IMMUTABLE_LEVELS[i]]
							params = new Int32Array([0])
							#GLAPI void APIENTRY glGetTextureLevelParameterivEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
							@glGetTextureLevelParameterivEXT(texture, target, levels, @[texParam], params)
							params[0]

		#enum
		for texParam in 'GL_TEXTURE_INTERNAL_FORMAT GL_TEXTURE_RED_TYPE GL_TEXTURE_GREEN_TYPE GL_TEXTURE_BLUE_TYPE GL_TEXTURE_ALPHA_TYPE GL_TEXTURE_DEPTH_TYPE GL_TEXTURE_COMPRESSED'.split ' '
			do (texParam)=>
				Object.defineProperty ret, texParam, enumerable: true, get: =>
					for texture, i in textures
						for levels in [0...ret.GL_TEXTURE_IMMUTABLE_LEVELS[i]]
							params = new Float32Array([NaN])
							#GLAPI void APIENTRY glGetTextureLevelParameterfvEXT (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
							@glGetTextureLevelParameterfvEXT(texture, target, levels, @[texParam], params)
							params[0]

		Object.freeze ret
		return ret


exports.init = (target)-> init.call target