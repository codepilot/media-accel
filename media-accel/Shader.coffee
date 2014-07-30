#shaders and programs use the same namespace

fs = require 'fs'
crypto = require 'crypto'
glGeti = require('./glGeti').glGeti

USE_SHADER_BINARY_CACHE = false

debugShader = false

#if debugShader
#	console.log 'crypto',
#		Ciphers: crypto.getCiphers()
#		Hashes: crypto.getHashes()

sha256_hex = (buf)->
	hash = crypto.createHash('sha256')
	hash.update(buf)
	return hash.digest('hex')

#console.log sha256_hex fs.readFileSync('./simple.vertex.glsl')

exports.GenBuffer =            GenBuffer            = -> return GenBuffers(1)[0]
exports.GenFramebuffer =       GenFramebuffer       = -> return GenFramebuffers(1)[0]
exports.GenProgramPipeline =   GenProgramPipeline   = -> return GenProgramPipelines(1)[0]
exports.GenQuery =             GenQuery             = -> return GenQueries(1)[0]
exports.GenRenderbuffer =      GenRenderbuffer      = -> return GenRenderbuffers(1)[0]
exports.GenSampler =           GenSampler           = -> return GenSamplers(1)[0]
exports.GenShader =            GenShader= (shaderType)-> return GenShaders(shaderType)[0]
exports.GenTexture =           GenTexture           = -> return GenTextures(1)[0]
exports.GenTransformFeedback = GenTransformFeedback = -> return GenTransformFeedbacks(1)[0]
exports.GenVertexArray =       GenVertexArray       = -> return GenVertexArrays(1)[0]

exports.GenPrograms = GenPrograms = (n)->
	for i in [0...n]
		errorBefore = gl.glGetError()
		program = gl.glCreateProgram()
		errorAfter = gl.glGetError()

		if debugShader
			console.log 'GenPrograms',
				errorBefore: errorBefore
				program: program
				errorAfter: errorAfter

		continue unless gl.glIsProgram(program)
		program

exports.GenShaders = GenShaders = (shaderTypes...)->
#	console.log 'GenShaders', arguments
	gl.glGetError()
	ret = []
	for arg in arguments
		if typeof arg is 'number'
			errorBefore = gl.glGetError()
			shader = gl.glCreateShader(arg)
			errorAfter = gl.glGetError()

			if debugShader
				console.log 'GenShaders',
					errorBefore: errorBefore
					shader: shader
					errorAfter: errorAfter

			continue unless gl.glIsShader(shader)
			ret.push shader
		else
			for shaderType in arg

				errorBefore = gl.glGetError()
				shader = gl.glCreateShader(shaderType)
				errorAfter = gl.glGetError()

				if debugShader
					console.log 'GenShaders',
						errorBefore: errorBefore
						shader: shader
						errorAfter: errorAfter

				#console.log 'gl.glCreateShader(', shaderType, ') = ', shader
				#console.log 'shader', shader, 'is', gl.glIsShader(shader)
				#console.log shader
				#continue if gl.glGetError()

				continue unless gl.glIsShader(shader)
				ret.push shader
	return ret

exports.GenBuffers = GenBuffers = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenBuffers(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenBuffers',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsBuffer(n)
		n

exports.GenFramebuffers = GenFramebuffers = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenFramebuffers(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenFramebuffers',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsFramebuffer(n)
		n

exports.GenProgramPipelines = GenProgramPipelines = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenProgramPipelines(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenProgramPipelines',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	return (n for n in param)

	for n in param
		#console.log 'gl.glIsProgramPipeline(' + n + ')', gl.glIsProgramPipeline(n)
		continue if gl.glIsProgramPipeline(n)
		#AMD Driver Broken, unbound generated name should return false
		#glIsProgramPipeline returns GL_TRUE if pipeline is currently the name of a program pipeline object. If pipeline is zero, or if pipeline is not the name of a program pipeline object, or if an error occurs, glIsProgramPipeline returns GL_FALSE. If pipeline is a name returned by glGenProgramPipelines, but that has not yet been bound through a call to glBindProgramPipeline, then the name is not a program pipeline object and glIsProgramPipeline returns GL_FALSE.
		n

exports.GenQueries = GenQueries = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenQueries(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenQueries',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsQuery(n)
		n

exports.GenRenderbuffers = GenRenderbuffers = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenRenderbuffers(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenRenderbuffers',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsRenderbuffer(n)
		n

exports.GenSamplers = GenSamplers = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenSamplers(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenSamplers',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue unless gl.glIsSampler(n)
		n

exports.GenTextures = GenTextures = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenTextures(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenTextures',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsTexture(n)
		n

exports.GenTransformFeedbacks = GenTransformFeedbacks = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenTransformFeedbacks(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenTransformFeedbacks',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsTransformFeedback(n)
		n

exports.GenVertexArrays = GenVertexArrays = (n)->
	param = new Uint32Array(n)

	errorBefore = gl.glGetError()
	gl.glGenVertexArrays(n, param)
	errorAfter = gl.glGetError()

	if debugShader
		console.log 'GenVertexArrays',
			errorBefore: errorBefore
			param: (n for n in param)
			errorAfter: errorAfter

	return if errorAfter

	for n in param
		continue if gl.glIsVertexArray(n)
		n


exports.CreateProgramPipelineFromFiles = CreateProgramPipelineFromFiles = (obj)->
#	console.log obj
#	console.log 'GenProgramPipelines', GenProgramPipelines(5)
#	console.log 'GenProgramPipeline', GenProgramPipeline()

	pipe = GenProgramPipeline()
	unless pipe
		console.log 'pipe', pipe
		return
	if GetProgramPipelineInfoLog(pipe).GL_INFO_LOG_LENGTH > 1
		console.log 'after gen', GetProgramPipelineAll(pipe)
		console.log 'pipe log after gen', GetProgramPipelineInfoLog(pipe)

	stages = 0
	for k, v of obj
		if debugShader
			console.log k: k, v: v
		switch k
			when 'GL_COMPUTE_SHADER', 'GL_VERTEX_SHADER', 'GL_TESS_CONTROL_SHADER', 'GL_TESS_EVALUATION_SHADER', 'GL_GEOMETRY_SHADER', 'GL_FRAGMENT_SHADER'
				files = []
				files.push new Buffer '#define is' + k + '\n'

				unless obj?.INCLUDE_IN_ALL?
				else if typeof obj.INCLUDE_IN_ALL is 'string'
					files.push obj.INCLUDE_IN_ALL
				else
					for n in obj.INCLUDE_IN_ALL
						files.push n

				if typeof v is 'string'
					files.push v
				else
					for n in v
						files.push n

				if debugShader
					console.log k, files

				shaderProgram = CreateShaderProgramFromFiles gl[k], files

				if debugShader
					console.log k, shaderProgram

				errorBefore = gl.glGetError()
				gl.glUseProgramStages pipe, gl[k + '_BIT'], shaderProgram
				errorAfter = gl.glGetError()

				if debugShader
					console.log
						shaderType: k
						files: files
						errorBefore: errorBefore
						errorAfter: errorAfter
				unless GetProgramPipelineAll(pipe)[k]
					console.log 'after use', k, GetProgramPipelineAll(pipe)
					
				if k is 'GL_VERTEX_SHADER'
					gl.glActiveShaderProgram(pipe, shaderProgram)
	
	if GetProgramPipelineAll(pipe).GL_INFO_LOG_LENGTH > 1
		console.log 'after all use', GetProgramPipelineAll(pipe)
		console.log 'pipe log after all use', GetProgramPipelineInfoLog(pipe)

	gl.glValidateProgramPipeline(pipe)
	unless GetProgramPipelineAll(pipe).GL_VALIDATE_STATUS
		console.log 'after validate', GetProgramPipelineAll(pipe)

	if GetProgramPipelineAll(pipe).GL_INFO_LOG_LENGTH > 1
		console.log 'pipe log after validate', GetProgramPipelineInfoLog(pipe)

	return pipe


exports.GetShaderSource = GetShaderSource = (shader)->
	param = new Uint32Array(1)
	gl.glGetShaderiv(shader, gl.GL_SHADER_SOURCE_LENGTH, param)
	buf = new Buffer(param[0])
	returnedLength = new Uint32Array(1)

	gl.glGetShaderSource(shader, param[0], returnedLength, buf)
	return buf.toString('utf8')

exports.GetShaderInfoLog = GetShaderInfoLog = (shader)->
	param = new Uint32Array(1)
	gl.glGetShaderiv(shader, gl.GL_INFO_LOG_LENGTH, param)
	buf = new Buffer(param[0])
	returnedLength = new Uint32Array(1)

	gl.glGetShaderInfoLog(shader, param[0], returnedLength, buf)
	return buf.toString('utf8', 0, returnedLength[0] - 1)

exports.GetProgramInfoLog = GetProgramInfoLog = (program)->
	param = new Uint32Array(1)
	gl.glGetProgramiv(program, gl.GL_INFO_LOG_LENGTH, param)
	buf = new Buffer(param[0])
	returnedLength = new Uint32Array(1)

	gl.glGetProgramInfoLog(program, param[0], returnedLength, buf)
	return buf.toString('utf8', 0, returnedLength[0] - 1)

exports.GetProgramBinary = GetProgramBinary = (program)->
	console.log 'GetProgramBinary', program

	bufSizeBuffer = new Uint32Array(1)
	gl.glGetProgramiv(program, gl.GL_PROGRAM_BINARY_LENGTH, bufSizeBuffer)

	bufSize = bufSizeBuffer[0]
	console.log bufSize: bufSize


	binaryBuf = new Buffer(bufSize)
	returnedLengthBuf = new Uint32Array(1)
	binaryFormatBuffer = new Uint32Array(1)
	gl.glGetProgramBinary(program, bufSize, returnedLengthBuf, binaryFormatBuffer, binaryBuf)
	ret =
		returnedLength: returnedLengthBuf[0]
		binaryFormat: binaryFormatBuffer[0]
		binary: binaryBuf

exports.GetProgramPipelineInfoLog = GetProgramPipelineInfoLog = (programPipeline)->
	param = new Uint32Array(1)
	gl.glGetProgramPipelineiv(programPipeline, gl.GL_INFO_LOG_LENGTH, param)
	buf = new Buffer(param[0])
	returnedLength = new Uint32Array(1)

	gl.glGetProgramPipelineInfoLog(programPipeline, param[0], returnedLength, buf)
	return buf.toString('utf8', 0, returnedLength[0] - 1)

exports.CreateShaderProgramFromFiles = CreateShaderProgramFromFiles = (type, filePaths...)->
	if debugShader
		console.log 'CreateShaderProgramFromFiles', type, filePaths

	fileList = []
	for filePath in filePaths
		if typeof filePath is 'string'
			buf = fs.readFileSync(filePath)
			fileList.push buf if buf.length
		else
			for fp in filePath
				if typeof fp is 'string'
					buf = fs.readFileSync(fp)
					fileList.push buf if buf.length
				else
					fileList.push fp

	hash = crypto.createHash('sha256')

	fileLengths = for fileItem in fileList
		hash.update(fileItem)
		fileItem.length

	programHash = hash.digest('hex')
	
	for binaryFormat in glGeti gl.GL_PROGRAM_BINARY_FORMATS
		break unless USE_SHADER_BINARY_CACHE
#		console.log binaryFormat: '0x' + binaryFormat.toString(16)
		possibleBinaryFilename = ['programBinary', '0x' + binaryFormat.toString(16), '0x' + programHash].join('_')
#		console.log possibleBinaryFilename: possibleBinaryFilename
		try
			binary = fs.readFileSync(possibleBinaryFilename)
#			console.log binaryFile: binary
			program = gl.glCreateProgram()
			#console.log program: program, filePaths: filePaths
			continue unless program

			programAll = GetProgramAll(program)
	
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS or programAll.GL_VALIDATE_STATUS or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS
				console.log 'after create', programAll
	
			if programAll.GL_INFO_LOG_LENGTH > 1
				console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)
	
			gl.glProgramParameteri(program, gl.GL_PROGRAM_SEPARABLE, gl.GL_TRUE)
	
			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS or programAll.GL_VALIDATE_STATUS or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS
				console.log 'after seperable', programAll
	
			if programAll.GL_INFO_LOG_LENGTH > 1
				console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)
	

			gl.glProgramBinary(program, binaryFormat, binary, binary.length)

			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS
				console.log 'after glProgramBinary', programAll
			if programAll.GL_INFO_LOG_LENGTH > 1
				console.log 'GetProgramInfoLog glProgramBinary: ', GetProgramInfoLog(program)

			gl.glValidateProgram(program)

			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH < 1 or programAll.GL_ATTACHED_SHADERS
				console.log 'after validate', programAll
			if programAll.GL_INFO_LOG_LENGTH > 1
				programInfoLog = GetProgramInfoLog(program)
				if programInfoLog isnt 'Validation successful.'
					console.log 'GetProgramInfoLog After Load: ', programInfoLog
#			console.log 'returning program from binary'
			return program

		catch e
			continue

	fileLengthsBuffer = new Uint32Array(fileLengths)

	shader = gl.glCreateShader(type);
	return unless shader > 0

	unless fileList.length
		console.log 'gl.glShaderSource(', shader, fileList.length, fileList, fileLengths, ')'
	gl.glShaderSource(shader, fileList.length, fileList, fileLengthsBuffer)
#	console.log 'GetShaderSource', GetShaderSource(shader)

	shaderAll = GetShaderAll(shader)
	if shaderAll.GL_INFO_LOG_LENGTH > 1
		console.log 'GetShaderInfoLog After Load: ', GetShaderInfoLog(shader)

	gl.glCompileShader(shader)

	shaderAll = GetShaderAll(shader)
	if shaderAll.GL_INFO_LOG_LENGTH > 1
		console.log 'CreateShaderProgramFromFiles',
			type: type
			filePaths: filePaths
			'GetShaderInfoLog After Compile': GetShaderInfoLog(shader)

	program = gl.glCreateProgram()
#	console.log program: program, filePaths: filePaths
	if program
		programAll = GetProgramAll(program)

		if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS or programAll.GL_VALIDATE_STATUS or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS
			console.log 'after create', programAll

		if programAll.GL_INFO_LOG_LENGTH > 1
			console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)

		gl.glProgramParameteri(program, gl.GL_PROGRAM_SEPARABLE, gl.GL_TRUE)

		programAll = GetProgramAll(program)
		if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS or programAll.GL_VALIDATE_STATUS or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS
			console.log 'after seperable', programAll

		if programAll.GL_INFO_LOG_LENGTH > 1
			console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)

		if shaderAll.GL_COMPILE_STATUS
			#console.log 'shader compiled'

			gl.glAttachShader(program, shader)

			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS or programAll.GL_VALIDATE_STATUS or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS isnt 1
				console.log 'after attach', programAll
			if programAll.GL_INFO_LOG_LENGTH > 1
				console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)

			console.log 'link program before'
			gl.glLinkProgram(program)
			console.log 'link program after'

			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS isnt 1
				console.log 'after link', programAll
			if programAll.GL_INFO_LOG_LENGTH > 1
				console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)

			gl.glDetachShader(program, shader)

			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH > 1 or programAll.GL_ATTACHED_SHADERS
				console.log 'after detach', programAll
			if programAll.GL_INFO_LOG_LENGTH > 1
				console.log 'GetProgramInfoLog After Load: ', GetProgramInfoLog(program)

			gl.glValidateProgram(program)

			programAll = GetProgramAll(program)
			if debugShader or programAll.GL_DELETE_STATUS or programAll.GL_LINK_STATUS isnt 1 or programAll.GL_VALIDATE_STATUS isnt 1 or programAll.GL_INFO_LOG_LENGTH > 1 is 0 or programAll.GL_ATTACHED_SHADERS
				console.log 'after validate', programAll
			if programAll.GL_INFO_LOG_LENGTH > 1
				programInfoLog = GetProgramInfoLog(program)
				if programInfoLog isnt 'Validation successful.'
					console.log 'GetProgramInfoLog After Load: ', programInfoLog

		else
			console.log 'not compiled'

		#/* append-shader-info-log-to-program-info-log */
	gl.glDeleteShader(shader)

	if USE_SHADER_BINARY_CACHE
		programBinary = GetProgramBinary program
		programBinary.hash = programHash
		programBinary.fileName = ['programBinary', '0x' + programBinary.binaryFormat.toString(16), '0x' + programHash].join('_')
		console.log programBinary
		fs.writeFileSync programBinary.fileName, programBinary.binary
	
	return program

exports.GetShaderAll = GetShaderAll = (shaderName)->
	params = new Uint32Array(1)
	ret = {}

	gl.glGetError()
	gl.glGetShaderiv(shaderName, gl.GL_SHADER_TYPE, params)
	ret.GL_SHADER_TYPE = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetShaderiv(shaderName, gl.GL_DELETE_STATUS, params)
	ret.GL_DELETE_STATUS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetShaderiv(shaderName, gl.GL_COMPILE_STATUS, params)
	ret.GL_COMPILE_STATUS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetShaderiv(shaderName, gl.GL_INFO_LOG_LENGTH, params)
	ret.GL_INFO_LOG_LENGTH = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetShaderiv(shaderName, gl.GL_SHADER_SOURCE_LENGTH, params)
	ret.GL_SHADER_SOURCE_LENGTH = params[0] unless gl.glGetError()

	if debugShader
		console.log 'GetShaderAll', ret

	return ret

exports.GetProgramAll = GetProgramAll = (programName)->
	console.log 'GetProgramAll', programName
	params = new Uint32Array(4)
	console.log 'params.length', params.length
	ret = {}

	console.log 'gl.glGetError(); #before 1'
	gl.glGetError()
	console.log 'gl.glGetProgramiv(programName, gl.GL_DELETE_STATUS, params); #before'
	gl.glGetProgramiv(programName, gl.GL_DELETE_STATUS, params);
		#params returns GL_TRUE if program is currently flagged for deletion, and GL_FALSE otherwise.
	console.log 'ret.GL_DELETE_STATUS = params[0] unless gl.glGetError(); #before'
	ret.GL_DELETE_STATUS = params[0] unless gl.glGetError()
	console.log 'ret.GL_DELETE_STATUS = params[0] unless gl.glGetError(); #before'
	console.log 'GL_DELETE_STATUS', ret.GL_DELETE_STATUS

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_LINK_STATUS, params);
		#params returns GL_TRUE if the last link operation on program was successful, and GL_FALSE otherwise.
	ret.GL_LINK_STATUS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_VALIDATE_STATUS, params);
		#params returns GL_TRUE or if the last validation operation on program was successful, and GL_FALSE otherwise.
	ret.GL_VALIDATE_STATUS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_INFO_LOG_LENGTH, params);
		#params returns the number of characters in the information log for program including the null termination character (i.e., the size of the character buffer required to store the information log). If program has no information log, a value of 0 is returned.
	ret.GL_INFO_LOG_LENGTH = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_ATTACHED_SHADERS, params);
		#params returns the number of shader objects attached to program.
	ret.GL_ATTACHED_SHADERS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_ACTIVE_ATOMIC_COUNTER_BUFFERS, params);
		#params returns the number of active attribute atomic counter buffers used by program.
	ret.GL_ACTIVE_ATOMIC_COUNTER_BUFFERS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_ACTIVE_ATTRIBUTES, params);
		#params returns the number of active attribute variables for program.
	ret.GL_ACTIVE_ATTRIBUTES = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, params);
		#params returns the length of the longest active attribute name for program, including the null termination character (i.e., the size of the character buffer required to store the longest attribute name). If no active attributes exist, 0 is returned.
	ret.GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_ACTIVE_UNIFORMS, params);
		#params returns the number of active uniform variables for program.
	ret.GL_ACTIVE_UNIFORMS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_ACTIVE_UNIFORM_MAX_LENGTH, params);
		#params returns the length of the longest active uniform variable name for program, including the null termination character (i.e., the size of the character buffer required to store the longest uniform variable name). If no active uniform variables exist, 0 is returned.
	ret.GL_ACTIVE_UNIFORM_MAX_LENGTH = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_PROGRAM_BINARY_LENGTH, params);
		#params returns the length of the program binary, in bytes that will be returned by a call to glGetProgramBinary. When a progam's GL_LINK_STATUS is GL_FALSE, its program binary length is zero.
	ret.GL_PROGRAM_BINARY_LENGTH = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_COMPUTE_WORK_GROUP_SIZE, params)
		#params returns an array of three integers containing the local work group size of the compute program as specified by its input layout qualifier(s). program must be the name of a program object that has been previously linked successfully and contains a binary for the compute shader stage.
	ret.GL_COMPUTE_WORK_GROUP_SIZE = {x: params[0], y: params[1], z: params[2]} unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_TRANSFORM_FEEDBACK_BUFFER_MODE, params)
		#params returns a symbolic constant indicating the buffer mode used when transform feedback is active. This may be GL_SEPARATE_ATTRIBS or GL_INTERLEAVED_ATTRIBS.
	ret.GL_TRANSFORM_FEEDBACK_BUFFER_MODE = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_TRANSFORM_FEEDBACK_VARYINGS, params)
		#params returns the number of varying variables to capture in transform feedback mode for the program.
	ret.GL_TRANSFORM_FEEDBACK_VARYINGS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH, params)
		#params returns the length of the longest variable name to be used for transform feedback, including the null-terminator.
	ret.GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_GEOMETRY_VERTICES_OUT, params)
		#params returns the maximum number of vertices that the geometry shader in program will output.
	ret.GL_GEOMETRY_VERTICES_OUT = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_GEOMETRY_INPUT_TYPE, params)
		#params returns a symbolic constant indicating the primitive type accepted as input to the geometry shader contained in program.
	ret.GL_GEOMETRY_INPUT_TYPE = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramiv(programName, gl.GL_GEOMETRY_OUTPUT_TYPE, params)
		#params returns a symbolic constant indicating the primitive type that will be output by the geometry shader contained in program.
	ret.GL_GEOMETRY_OUTPUT_TYPE = params[0] unless gl.glGetError()

	if debugShader
		console.log 'GetProgramAll', ret

	return ret

exports.GetProgramPipelineAll = GetProgramPipelineAll = (ProgramPipelineName)->
	params = new Uint32Array(1)
	ret = {}

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_ACTIVE_PROGRAM, params)
	ret.GL_ACTIVE_PROGRAM = params[0] unless gl.glGetError()
	
	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_VALIDATE_STATUS, params)
	ret.GL_VALIDATE_STATUS = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_VERTEX_SHADER, params)
	ret.GL_VERTEX_SHADER = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_TESS_CONTROL_SHADER, params)
	ret.GL_TESS_CONTROL_SHADER = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_TESS_EVALUATION_SHADER, params)
	ret.GL_TESS_EVALUATION_SHADER = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_GEOMETRY_SHADER, params)
	ret.GL_GEOMETRY_SHADER = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_FRAGMENT_SHADER, params)
	ret.GL_FRAGMENT_SHADER = params[0] unless gl.glGetError()

	gl.glGetError()
	gl.glGetProgramPipelineiv(ProgramPipelineName, gl.GL_INFO_LOG_LENGTH, params)
	ret.GL_INFO_LOG_LENGTH = params[0] unless gl.glGetError()

	if debugShader
		console.log 'GetProgramPipelineAll', ret

	return ret

exports.NamedString = (type, name, string)->
	#void glNamedStringARB(enum type, int namelen, const char *name, int stringlen, const char *string)

exports.DeleteNamedStringARB = (name)->
	#void glDeleteNamedStringARB(int namelen, const char *name)

exports.CompileShaderIncludeARB = (shader, count, path, length)->
	#void glCompileShaderIncludeARB(uint shader, sizei count, const char *const *path, const int *length)

exports.IsNamedStringARB = (name)->
	#boolean glIsNamedStringARB(int namelen, const char *name)

exports.GetNamedStringARB = (name, string)->
	#void glGetNamedStringARB(int namelen, const char *name, sizei bufSize, int *stringlen, char *string)

exports.GetNamedStringivARB = (name, pname)->
	#void glGetNamedStringivARB(int namelen, const char *name, enum pname, int *params)

exports.TestThings = ->
	console.log
		GenBuffers: Shader.GenBuffers(5)
		GenFramebuffers: Shader.GenFramebuffers(5)
		GenPrograms: Shader.GenPrograms(5)
		GenProgramPipelines: Shader.GenProgramPipelines(5)
		GenQueries: Shader.GenQueries(5)
		GenRenderbuffers: Shader.GenRenderbuffers(5)
		GenSamplers: Shader.GenSamplers(5)
		GenShaders: Shader.GenShaders(gl.GL_COMPUTE_SHADER, gl.GL_VERTEX_SHADER, gl.GL_TESS_CONTROL_SHADER, gl.GL_TESS_EVALUATION_SHADER, gl.GL_GEOMETRY_SHADER, gl.GL_FRAGMENT_SHADER)
		GenTextures: Shader.GenTextures(5)
		GenTransformFeedbacks: Shader.GenTransformFeedbacks(5)
		GenVertexArrays: Shader.GenVertexArrays(5)

	console.log
		GenBuffer: Shader.GenBuffer()
		GenFramebuffer: Shader.GenFramebuffer()
		GenProgramPipeline: Shader.GenProgramPipeline()
		GenQuery: Shader.GenQuery()
		GenRenderbuffer: Shader.GenRenderbuffer()
		GenSampler: Shader.GenSampler()
		GenShader: Shader.GenShader(gl.GL_VERTEX_SHADER)
		GenTexture: Shader.GenTexture()
		GenTransformFeedback: Shader.GenTransformFeedback()
		GenVertexArray: Shader.GenVertexArray()

#	tetxures = Uint32Array(10)
#	gl.glGenTextures(tetxures.length + 1, tetxures)#when given a size too big, it returns before calling real command
#	console.log 'tetxures', tetxures
#
#	gl.glGenTextures(tetxures.length, tetxures)#when given a size correct, it works
#	console.log 'tetxures', tetxures

	Shader.CreateProgramPipelineFromFiles
		INCLUDE_IN_ALL: 'simple.include.glsl'
		#GL_COMPUTE_SHADER: 'simple.compute.glsl'
		GL_VERTEX_SHADER: 'simple.vertex.glsl'
		#GL_TESS_CONTROL_SHADER: 'simple.control.glsl'
		#GL_TESS_EVALUATION_SHADER: 'simple.evaluation.glsl'
		#GL_GEOMETRY_SHADER: 'simple.geometry.glsl'
		GL_FRAGMENT_SHADER: 'simple.fragment.glsl'
