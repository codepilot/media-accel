//#version 440 compatibility
#version 440 core
//#version 130

#extension GL_ARB_explicit_uniform_location: require
#extension GL_ARB_explicit_attrib_location: require
#extension GL_ARB_separate_shader_objects: require
#extension GL_ARB_bindless_texture: require
#extension GL_ARB_shading_language_include: enable

//#define USE_SHADER_BUFFER

#ifdef USE_SHADER_BUFFER
	layout(std430, binding = 0) buffer MyBuffer {
		mat4 ProjectionMatrix;
		mat4 ModelViewMatrix;
		vec4 viewport;//x, y, width, height
		sampler2D tex;
	};
#else
	layout(location = 0) uniform mat4 ProjectionMatrix;
	layout(location = 4) uniform mat4 ModelViewMatrix;
	layout(location = 8) uniform sampler2D tex;
	layout(location = 12) uniform vec4 viewport;//x, y, width, height
#endif

#ifdef isGL_VERTEX_SHADER
	layout(location = 0) in vec4 inVertex;
	layout(location = 1) in vec4 inColor;
	layout(location = 2) in vec4 inTexCoord;
	
	out gl_PerVertex {
		vec4 gl_Position;
	};
	
	layout(location = 1) out vec4 outColor;
	layout(location = 2) out vec4 outTexCoord;
#endif

#ifdef isGL_FRAGMENT_SHADER
	layout(location = 1) in vec4 inColor;
	layout(location = 2) in vec4 inTexCoord;

	layout(location = 0) out vec4 color;
#endif

