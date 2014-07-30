exports.getVirtualPageInfo = getVirtualPageInfo = (target = gl.GL_TEXTURE_2D_ARRAY, internalFormat = gl.GL_RGBA8)->
#	console.log
#		GL_MAX_SPARSE_TEXTURE_SIZE_ARB: glGeti gl.GL_MAX_SPARSE_TEXTURE_SIZE_ARB
#		GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB: glGeti gl.GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB
#		GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB: glGeti gl.GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB
#		GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB: glGeti gl.GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB

	numSizes = Int32Array([0])
	gl.glGetInternalformativ(target, internalFormat, gl.GL_NUM_VIRTUAL_PAGE_SIZES_ARB, numSizes.length, numSizes)

	xSizes = Int32Array(numSizes[0])
	ySizes = Int32Array(numSizes[0])
	zSizes = Int32Array(numSizes[0])

	gl.glGetInternalformativ(target, internalFormat, gl.GL_VIRTUAL_PAGE_SIZE_X_ARB, xSizes.length, xSizes)
	gl.glGetInternalformativ(target, internalFormat, gl.GL_VIRTUAL_PAGE_SIZE_Y_ARB, ySizes.length, ySizes)
	gl.glGetInternalformativ(target, internalFormat, gl.GL_VIRTUAL_PAGE_SIZE_Z_ARB, zSizes.length, zSizes)

	({x: xSizes[i], y: ySizes[i], z: zSizes[i]} for i in [0...numSizes[0]])

exports.GetInternalFormat_Int32Array = GetInternalFormat_Int32Array = (target, internalFormat, pname, count = 1)->
	param = Int32Array(count)
	gl.glGetInternalformativ(target, internalFormat, pname, param.length, param)
	return param[0] if count is 1
	(n for n in param)

exports.GetInternalFormat_Int64Array = GetInternalFormat_Int64Array = (target, internalFormat, pname, count = 1)->
	param = Int32Array(count * 2)
	gl.glGetInternalformati64v(target, internalFormat, pname, param.length >>> 1, param)
	list = for i in [0..count]
		param[i * 2] + (param[i * 2 + 1] * 0x100000000)

	return list[0] if count is 1
	list

exports.getAllInternalFormats = getAllInternalFormats =(_targetList, _internalFormatList)  ->
	targetList = [
		'TEXTURE_1D'
		'TEXTURE_1D_ARRAY'
		'TEXTURE_2D'
		'TEXTURE_2D_ARRAY'
		'TEXTURE_3D'
		'TEXTURE_CUBE_MAP'
		'TEXTURE_CUBE_MAP_ARRAY'
		'TEXTURE_RECTANGLE'
		'TEXTURE_BUFFER'
		'RENDERBUFFER'
		'TEXTURE_2D_MULTISAMPLE'
		'TEXTURE_2D_MULTISAMPLE_ARRAY'
	]

	internalFormatList = [
		'R8'
		'R8_SNORM'
		'R16'
		'R16_SNORM'
		'RG8'
		'RG8_SNORM'
		'RG16'
		'RG16_SNORM'
		'R3_G3_B2'
		'RGB4'
		'RGB8'
		'RGB565'
		'RGB8'
		'RGB8_SNORM'
		'RGB10'
		'RGB12'
		'RGB16'
		'RGB16_SNORM'
		'RGBA2'
		'RGBA4'
		'RGB5_A1'
		'RGBA8'
		'RGBA8_SNORM'
		'RGB10_A2'
		'RGB10_A2UI'
		'RGBA12'
		'RGBA16'
		'RGBA16_SNORM'
		'SRGB8'
		'SRGB8_ALPHA8'
		'R16F'
		'RG16F'
		'RGB16F'
		'RGBA16F'
		'R32F'
		'RG32F'
		'RGB32F'
		'RGBA32F'
		'R11F_G11F_B10F'
		'RGB9_E5'
		'R8I'
		'R8UI'
		'R16I'
		'R16UI'
		'R32I'
		'R32UI'
		'RG8I'
		'RG8UI'
		'RG16I'
		'RG16UI'
		'RG32I'
		'RG32UI'
		'RGB8I'
		'RGB8UI'
		'RGB16I'
		'RGB16UI'
		'RGB32I'
		'RGB32UI'
		'RGBA8I'
		'RGBA8UI'
		'RGBA16I'
		'RGBA16UI'
		'RGBA32I'
		'RGBA32UI'
	]

	###
		targetList = ['TEXTURE_2D']
		targetList = ['TEXTURE_2D_ARRAY']
	targetList = ['TEXTURE_2D_MULTISAMPLE']
		internalFormatList = ['RGBA8']
	###
	#glGeti gl.GL_COMPRESSED_TEXTURE_FORMATS

	if _targetList?
		targetList = _targetList #_targetList['TEXTURE_2D']
	if _internalFormatList?
		internalFormatList = _internalFormatList #['RGBA8']
	

	targetFormat = {}
	for target in targetList
		formatSizes = {}
		for iFormat in internalFormatList
			formatSizes[iFormat] = {}
			#formatSizes[iFormat].virtualPageSize = getVirtualPageInfo gl['GL_' + target], gl['GL_' + iFormat]
			#Int32 x 1
			for pname in 'NUM_SAMPLE_COUNTS NUM_VIRTUAL_PAGE_SIZES_ARB INTERNALFORMAT_SUPPORTED INTERNALFORMAT_PREFERRED INTERNALFORMAT_RED_SIZE INTERNALFORMAT_GREEN_SIZE INTERNALFORMAT_BLUE_SIZE INTERNALFORMAT_ALPHA_SIZE INTERNALFORMAT_DEPTH_SIZE INTERNALFORMAT_STENCIL_SIZE INTERNALFORMAT_SHARED_SIZE INTERNALFORMAT_RED_TYPE INTERNALFORMAT_GREEN_TYPE INTERNALFORMAT_BLUE_TYPE INTERNALFORMAT_ALPHA_TYPE INTERNALFORMAT_DEPTH_TYPE INTERNALFORMAT_STENCIL_TYPE MAX_WIDTH MAX_HEIGHT MAX_DEPTH MAX_LAYERS IMAGE_TEXEL_SIZE'.split(' ')
				formatSizes[iFormat][pname] = GetInternalFormat_Int32Array(gl['GL_' + target], gl['GL_' + iFormat], gl['GL_' + pname])

			for pname in 'VIRTUAL_PAGE_SIZE_X_ARB VIRTUAL_PAGE_SIZE_Y_ARB VIRTUAL_PAGE_SIZE_Z_ARB'.split(' ')
				formatSizes[iFormat][pname] = GetInternalFormat_Int32Array(gl['GL_' + target], gl['GL_' + iFormat], gl['GL_' + pname], formatSizes[iFormat].NUM_VIRTUAL_PAGE_SIZES_ARB)

			for pname in 'SAMPLES'.split(' ')
				formatSizes[iFormat][pname] = GetInternalFormat_Int32Array(gl['GL_' + target], gl['GL_' + iFormat], gl['GL_' + pname], formatSizes[iFormat].NUM_SAMPLE_COUNTS)

			for pname in 'MAX_COMBINED_DIMENSIONS'.split(' ')
				formatSizes[iFormat][pname] = GetInternalFormat_Int64Array(gl['GL_' + target], gl['GL_' + iFormat], gl['GL_' + pname])

			#Enum x 1
			for pname in 'COLOR_COMPONENTS DEPTH_COMPONENTS STENCIL_COMPONENTS COLOR_RENDERABLE DEPTH_RENDERABLE STENCIL_RENDERABLE FRAMEBUFFER_RENDERABLE FRAMEBUFFER_RENDERABLE_LAYERED FRAMEBUFFER_BLEND READ_PIXELS READ_PIXELS_FORMAT READ_PIXELS_TYPE TEXTURE_IMAGE_FORMAT TEXTURE_IMAGE_TYPE GET_TEXTURE_IMAGE_FORMAT GET_TEXTURE_IMAGE_TYPE MIPMAP MANUAL_GENERATE_MIPMAP AUTO_GENERATE_MIPMAP COLOR_ENCODING SRGB_READ SRGB_WRITE FILTER VERTEX_TEXTURE TESS_CONTROL_TEXTURE TESS_EVALUATION_TEXTURE GEOMETRY_TEXTURE FRAGMENT_TEXTURE COMPUTE_TEXTURE TEXTURE_SHADOW TEXTURE_GATHER TEXTURE_GATHER_SHADOW SHADER_IMAGE_LOAD SHADER_IMAGE_STORE SHADER_IMAGE_ATOMIC IMAGE_COMPATIBILITY_CLASS IMAGE_PIXEL_FORMAT IMAGE_PIXEL_TYPE IMAGE_FORMAT_COMPATIBILITY_TYPE SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE TEXTURE_COMPRESSED TEXTURE_COMPRESSED_BLOCK_WIDTH TEXTURE_COMPRESSED_BLOCK_HEIGHT TEXTURE_COMPRESSED_BLOCK_SIZE CLEAR_BUFFER TEXTURE_VIEW VIEW_COMPATIBILITY_CLASS CLEAR_TEXTURE'.split(' ')
				formatSizes[iFormat][pname] = GetInternalFormat_Int32Array(gl['GL_' + target], gl['GL_' + iFormat], gl['GL_' + pname])

		targetFormat[target] = formatSizes

	return targetFormat
