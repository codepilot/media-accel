switch global.NeHeLesson
	when 2 then exports.DrawGLScene = require('./DrawGLScene_02').DrawGLScene
	when 3 then exports.DrawGLScene = require('./DrawGLScene_03').DrawGLScene
	when 4 then exports.DrawGLScene = require('./DrawGLScene_04').DrawGLScene
	when 5 then exports.DrawGLScene = require('./DrawGLScene_05').DrawGLScene