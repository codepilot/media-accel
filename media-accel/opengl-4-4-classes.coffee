compute
	GLAPI void APIENTRY glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
	GLAPI void APIENTRY glDispatchComputeIndirect (GLintptr indirect);

drawing
	GLAPI void APIENTRY glLineWidth (GLfloat width);
	GLAPI void APIENTRY glLogicOp (GLenum opcode);
	GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
	GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
	GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
	GLAPI void APIENTRY glPatchParameterfv (GLenum pname, const GLfloat *values);
	GLAPI void APIENTRY glPatchParameteri (GLenum pname, GLint value);
	GLAPI void APIENTRY glMinSampleShading (GLfloat value);
	GLAPI void APIENTRY glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
	GLAPI void APIENTRY glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
	GLAPI void APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
	GLAPI void APIENTRY glPointParameteriv (GLenum pname, const GLint *params);
	GLAPI void APIENTRY glPointSize (GLfloat size);
	GLAPI void APIENTRY glPolygonMode (GLenum face, GLenum mode);
	GLAPI void APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
	GLAPI void APIENTRY glPrimitiveRestartIndex (GLuint index);
	GLAPI void APIENTRY glProvokingVertex (GLenum mode);
	GLAPI void APIENTRY glSampleCoverage (GLfloat value, GLboolean invert);
	GLAPI void APIENTRY glSampleMaski (GLuint maskNumber, GLbitfield mask);

enable-disable
	GLAPI void APIENTRY glDisable (GLenum cap);
	GLAPI void APIENTRY glDisablei (GLenum target, GLuint index);
	GLAPI void APIENTRY glEnable (GLenum cap);
	GLAPI void APIENTRY glEnablei (GLenum target, GLuint index);

face
	GLAPI void APIENTRY glCullFace (GLenum mode);
	GLAPI void APIENTRY glFrontFace (GLenum mode);

****

blend
	GLAPI void APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	GLAPI void APIENTRY glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	GLAPI void APIENTRY glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

buffer
	GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
	GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
	GLAPI void APIENTRY glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
	GLAPI void APIENTRY glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
	GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
	GLAPI void APIENTRY glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
	GLAPI void APIENTRY glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
	GLAPI void APIENTRY glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
	GLAPI void APIENTRY glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
	GLAPI void APIENTRY glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	GLAPI void APIENTRY glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
#	GLAPI void APIENTRY glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
	GLAPI void APIENTRY glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	GLAPI void APIENTRY glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
	GLAPI void APIENTRY glInvalidateBufferData (GLuint buffer);
	GLAPI void APIENTRY glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length);
	GLAPI void *APIENTRY glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);

conditional
	GLAPI void APIENTRY glBeginConditionalRender (GLuint id, GLenum mode);
	GLAPI void APIENTRY glEndConditionalRender (void);

framebuffer
	GLAPI void APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers);
	GLAPI void APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
	GLAPI void APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
	GLAPI void APIENTRY glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	GLAPI void APIENTRY glFramebufferParameteri (GLenum target, GLenum pname, GLint param);
	GLAPI void APIENTRY glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
#	GLAPI void APIENTRY glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#	GLAPI void APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#	GLAPI void APIENTRY glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	GLAPI void APIENTRY glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	GLAPI void APIENTRY glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
	GLAPI void APIENTRY glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
	GLAPI void APIENTRY glReadBuffer (GLenum mode);
	GLAPI void APIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
	GLAPI void APIENTRY glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v);
	GLAPI void APIENTRY glScissorArrayv (GLuint first, GLsizei count, const GLint *v);
	GLAPI void APIENTRY glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v);
	GLAPI void APIENTRY glDepthFunc (GLenum func);
	GLAPI void APIENTRY glDepthMask (GLboolean flag);
	GLAPI void APIENTRY glClampColor (GLenum target, GLenum clamp);
	GLAPI void APIENTRY glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	GLAPI void APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
	GLAPI void APIENTRY glPixelStoref (GLenum pname, GLfloat param);
	GLAPI void APIENTRY glPixelStorei (GLenum pname, GLint param);
	GLAPI void APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
	GLAPI void APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
	GLAPI void APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);

program
	GLAPI GLuint APIENTRY glCreateProgram (void);
	GLAPI void APIENTRY glDeleteProgram (GLuint program);
	GLAPI void APIENTRY glLinkProgram (GLuint program);
	GLAPI void APIENTRY glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
	GLAPI void APIENTRY glProgramParameteri (GLuint program, GLenum pname, GLint value);

program pipline
	GLAPI void APIENTRY glGenProgramPipelines (GLsizei n, GLuint *pipelines);
	GLAPI void APIENTRY glBindProgramPipeline (GLuint pipeline);
	GLAPI void APIENTRY glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines);
	GLAPI void APIENTRY glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);

query
	GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
	GLAPI void APIENTRY glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
	GLAPI void APIENTRY glEndQueryIndexed (GLenum target, GLuint index);
	GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
	GLAPI void APIENTRY glQueryCounter (GLuint id, GLenum target);

samplers
	GLAPI void APIENTRY glGenSamplers (GLsizei count, GLuint *samplers);
	GLAPI void APIENTRY glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers);
	GLAPI void APIENTRY glDeleteSamplers (GLsizei count, const GLuint *samplers);
#	GLAPI void APIENTRY glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
	GLAPI void APIENTRY glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param);
	GLAPI void APIENTRY glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param);
	GLAPI void APIENTRY glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param);
#	GLAPI void APIENTRY glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
	GLAPI void APIENTRY glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param);

shader
	GLAPI GLuint APIENTRY glCreateShader (GLenum type);
	GLAPI void APIENTRY glAttachShader (GLuint program, GLuint shader);
	GLAPI void APIENTRY glDeleteShader (GLuint shader);
	GLAPI void APIENTRY glCompileShader (GLuint shader);
	GLAPI void APIENTRY glDetachShader (GLuint program, GLuint shader);
	GLAPI void APIENTRY glReleaseShaderCompiler (void);
	GLAPI void APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);

sync
	GLAPI GLsync APIENTRY glFenceSync (GLenum condition, GLbitfield flags);
	GLAPI GLenum APIENTRY glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
	GLAPI void APIENTRY glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
	GLAPI void APIENTRY glDeleteSync (GLsync sync);
	GLAPI void APIENTRY glFinish (void);
	GLAPI void APIENTRY glFlush (void);
	GLAPI void APIENTRY glMemoryBarrier (GLbitfield barriers);

textures
	GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
	GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
	GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
	GLAPI void APIENTRY glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
	GLAPI void APIENTRY glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
	GLAPI void APIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
	GLAPI void APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
	GLAPI void APIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
	GLAPI void APIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	GLAPI void APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	GLAPI void APIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	GLAPI void APIENTRY glGenerateMipmap (GLenum target);
	GLAPI void APIENTRY glInvalidateTexImage (GLuint texture, GLint level);
	GLAPI void APIENTRY glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#	GLAPI void APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
	GLAPI void APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
	GLAPI void APIENTRY glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
	GLAPI void APIENTRY glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
#	GLAPI void APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
	GLAPI void APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
	GLAPI void APIENTRY glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	GLAPI void APIENTRY glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	GLAPI void APIENTRY glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	GLAPI void APIENTRY glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	GLAPI void APIENTRY glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	GLAPI void APIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
	GLAPI void APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
	GLAPI void APIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
	GLAPI void APIENTRY glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);

texture-buffer
	GLAPI void APIENTRY glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
	GLAPI void APIENTRY glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);

texture-image
	GLAPI void APIENTRY glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures);
	GLAPI void APIENTRY glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);

transformfeedback
	GLAPI void APIENTRY glGenTransformFeedbacks (GLsizei n, GLuint *ids);
	GLAPI void APIENTRY glBindTransformFeedback (GLenum target, GLuint id);
	GLAPI void APIENTRY glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids);
	GLAPI void APIENTRY glBeginTransformFeedback (GLenum primitiveMode);
	GLAPI void APIENTRY glEndTransformFeedback (void);
	GLAPI void APIENTRY glPauseTransformFeedback (void);
	GLAPI void APIENTRY glResumeTransformFeedback (void);

vertex array
	GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
	GLAPI void APIENTRY glBindVertexArray (GLuint array);
	GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);

***
