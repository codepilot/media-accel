class class_OpenGL {
public:
	static v8::Handle<v8::Value> func_glViewport(const v8::Arguments& args) {
		if(args.Length() >= 4){
			glViewport(args[0]->Int32Value(), args[1]->Int32Value(), args[2]->Int32Value(), args[3]->Int32Value());
		} else {DebugBreak(); }
		return v8::Undefined(); 
	}

	static v8::Handle<v8::Value> func_glClear(const v8::Arguments& args) {
		if(args.Length() >= 1){
			glClear(args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glMatrixMode(const v8::Arguments& args) {
		if(args.Length() >= 1){ glMatrixMode(args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glBegin(const v8::Arguments& args) {
		if(args.Length() >= 1){ glBegin(args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glEnd(const v8::Arguments& args) {
		glEnd();
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glColor3f(const v8::Arguments& args) {
		if(args.Length() >= 3){ glColor3f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glColor3d(const v8::Arguments& args) {
		if(args.Length() >= 3){ glColor3d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glColor4f(const v8::Arguments& args) {
		if(args.Length() >= 4){ glColor4f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glColor4d(const v8::Arguments& args) {
		if(args.Length() >= 4){ glColor4d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glVertex2f(const v8::Arguments& args) {
		if(args.Length() >= 2){ glVertex2f(args[0]->NumberValue(), args[1]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glVertex2d(const v8::Arguments& args) {
		if(args.Length() >= 2){ glVertex2d(args[0]->NumberValue(), args[1]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glVertex3f(const v8::Arguments& args) {
		if(args.Length() >= 3){ glVertex3f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glVertex3d(const v8::Arguments& args) {
		if(args.Length() >= 3){ glVertex3d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glVertex4f(const v8::Arguments& args) {
		if(args.Length() >= 4){ glVertex4f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glVertex4d(const v8::Arguments& args) {
		if(args.Length() >= 4){ glVertex4d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glLoadIdentity(const v8::Arguments& args) {
		glLoadIdentity();
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glTranslatef(const v8::Arguments& args) {
		if(args.Length() >= 3){ glTranslatef(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glTranslated(const v8::Arguments& args) {
		if(args.Length() >= 3){ glTranslated(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glRotatef(const v8::Arguments& args) {
		if(args.Length() >= 4){ glRotatef(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glRotated(const v8::Arguments& args) {
		if(args.Length() >= 4){ glRotated(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_gluPerspective(const v8::Arguments& args) {
		if(args.Length() >= 4){ gluPerspective(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glShadeModel(const v8::Arguments& args) {
		if(args.Length() >= 1){ glShadeModel(args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glClearColor(const v8::Arguments& args) {
		if(args.Length() >= 4){ glClearColor(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glClearDepth(const v8::Arguments& args) {
		if(args.Length() >= 1){ glClearDepth(args[0]->NumberValue());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glEnable(const v8::Arguments& args) {
		if(args.Length() >= 1){ glEnable(args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glDepthFunc(const v8::Arguments& args) {
		if(args.Length() >= 1){ glDepthFunc(args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_glHint(const v8::Arguments& args) {
		if(args.Length() >= 2){ glHint(args[0]->Uint32Value(), args[0]->Uint32Value());
		} else {DebugBreak(); }
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_wglSwapIntervalEXT(const v8::Arguments& args) {
		static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT{nullptr};
		if(!wglSwapIntervalEXT) {
			wglSwapIntervalEXT = reinterpret_cast<decltype(wglSwapIntervalEXT)>(wglGetProcAddress("wglSwapIntervalEXT"));
		}
		if(args.Length() >= 1){
			wglSwapIntervalEXT(args[0]->Int32Value());
		} else {
			DebugBreak();
		}
		return v8::Undefined();
	}
	
	//typedef int (WINAPI * PFNWGLGETSWAPINTERVALEXTPROC) (void);
	static v8::Handle<v8::Value> func_wglGetSwapIntervalEXT(const v8::Arguments& args) {
		static PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT{nullptr};
		if(!wglGetSwapIntervalEXT) {
			wglGetSwapIntervalEXT = reinterpret_cast<decltype(wglGetSwapIntervalEXT)>(wglGetProcAddress("wglGetSwapIntervalEXT"));
		}
		int ret = wglGetSwapIntervalEXT();
		v8::HandleScope scope;
		return scope.Close(v8::Int32::New(ret));
	}
	
};