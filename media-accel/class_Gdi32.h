#define argToPointerType(n, t) reinterpret_cast<t>(static_cast<int64_t>(args[n]->NumberValue()))

class class_Gdi32 {
public:

	static v8::Handle<v8::Value> func_FreeConsole(const v8::Arguments& args) {
		BOOL ret = FreeConsole();
		v8::HandleScope scope;
		return scope.Close(v8::Int32::New(ret));
	}

	static v8::Handle<v8::Value> func_ChangeDisplaySettingsW(const v8::Arguments& args) {
		if(args.Length() >= 2){
			BOOL ret = ChangeDisplaySettingsW(
				(LPDEVMODEW)args[0]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData(),
				args[1]->Uint32Value()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_ShowCursor(const v8::Arguments& args) {
		if(args.Length() >= 1){
			int ret = ShowCursor(
				args[0]->Int32Value()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_UnregisterClassW(const v8::Arguments& args) {
		if(args.Length() >= 2){
			BOOL ret = UnregisterClassW(
				reinterpret_cast<LPCWSTR>(v8::String::Value(args[0]).operator*()),
				argToPointerType(1, HINSTANCE)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_SetWindowLongPtr(const v8::Arguments& args) {
		if(args.Length() >= 3){
			LONG_PTR ret = SetWindowLongPtr(
				argToPointerType(0, HWND),
				args[1]->Int32Value(),
				args[2]->NumberValue()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Number::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_SetWindowLong(const v8::Arguments& args) {
		if(args.Length() >= 3){
			LONG ret = SetWindowLong(
				argToPointerType(0, HWND),
				args[1]->Int32Value(),
				args[2]->Int32Value()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_DestroyWindow(const v8::Arguments& args) {
		if(args.Length() >= 1){
			BOOL ret = DestroyWindow(
				argToPointerType(0, HWND)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_wglMakeCurrent(const v8::Arguments& args) {
		if(args.Length() >= 2){
			BOOL ret = wglMakeCurrent(
				argToPointerType(0, HDC),
				argToPointerType(1, HGLRC)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_wglDeleteContext(const v8::Arguments& args) {
		if(args.Length() >= 1){
			BOOL ret = wglDeleteContext(
				argToPointerType(0, HGLRC)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_ReleaseDC(const v8::Arguments& args) {
		if(args.Length() >= 2){
			int ret = ReleaseDC(
				argToPointerType(0, HWND),
				argToPointerType(1, HDC)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}


		//SetFunctionSymbolStatic(Gdi32, MoveWindow)
		//SetFunctionSymbolStatic(Gdi32, GetClientRect)
		//SetFunctionSymbolStatic(Gdi32, GetWindowRect)

	static v8::Handle<v8::Value> func_MoveWindow(const v8::Arguments& args) {
		if(args.Length() >= 6){
			BOOL ret = MoveWindow(
				argToPointerType(0, HWND),
				args[1]->Int32Value(),
				args[2]->Int32Value(),
				args[3]->Int32Value(),
				args[4]->Int32Value(),
				args[5]->Int32Value());
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_GetClientRect(const v8::Arguments& args) {
		if(args.Length() >= 2){
			BOOL ret = GetClientRect(
				argToPointerType(0, HWND),
				(LPRECT)args[1]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_GetWindowRect(const v8::Arguments& args) {
		if(args.Length() >= 2){
			BOOL ret = GetWindowRect(
				argToPointerType(0, HWND),
				(LPRECT)args[1]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_AdjustWindowRectEx(const v8::Arguments& args) {
		if(args.Length() >= 4){
			BOOL ret = AdjustWindowRectEx(
				(LPRECT)args[0]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData(),
				args[1]->Uint32Value(),
				args[2]->Uint32Value(),
				args[3]->Uint32Value());
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static ATOM bounce_RegisterClassW(_In_ CONST WNDCLASSW *lpWndClass) {
		puts("bounce_RegisterClassW");
		printf("lpWndClass:      %p\n", lpWndClass);

		printf("->style:         %u\n", lpWndClass->style);
		printf("->lpfnWndProc:   %p\n", lpWndClass->lpfnWndProc);
		printf("->cbClsExtra:    %d\n", lpWndClass->cbClsExtra);
		printf("->cbWndExtra:    %d\n", lpWndClass->cbWndExtra);
		printf("->hInstance:     %p\n", lpWndClass->hInstance);
		printf("->hIcon:         %p\n", lpWndClass->hIcon);
		printf("->hCursor:       %p\n", lpWndClass->hCursor);
		printf("->hbrBackground: %p\n", lpWndClass->hbrBackground);
		wprintf(L"->lpszMenuName:  %s\n", lpWndClass->lpszMenuName);
		wprintf(L"->lpszClassName: %s\n", lpWndClass->lpszClassName);

		ATOM ret = RegisterClassW(lpWndClass);

		printf("ret: %p\n\n", ret);
		return ret;
	}
	static HWND bounce_CreateWindowExW(
		_In_ DWORD dwExStyle,
		_In_opt_ LPCWSTR lpClassName,
		_In_opt_ LPCWSTR lpWindowName,
		_In_ DWORD dwStyle,
		_In_ int X,
		_In_ int Y,
		_In_ int nWidth,
		_In_ int nHeight,
		_In_opt_ HWND hWndParent,
		_In_opt_ HMENU hMenu,
		_In_opt_ HINSTANCE hInstance,
		_In_opt_ LPVOID lpParam) {

		puts("bounce_CreateWindowExW");
		printf("dwExStyle: %u\n", dwExStyle);
		wprintf(L"lpClassName: %s\n", lpClassName);
		wprintf(L"lpWindowName: %s\n", lpWindowName);
		printf("dwStyle: %u\n", dwStyle);
		printf("X: %d\n", X);
		printf("Y: %d\n", Y);
		printf("nWidth: %d\n", nWidth);
		printf("nHeight: %d\n", nHeight);
		printf("hWndParent: %p\n", hWndParent);
		printf("hMenu: %p\n", hMenu);
		printf("hInstance: %p\n", hInstance);
		printf("realInstance: %p\n", GetModuleHandle(nullptr));
		printf("lpParam: %p\n", lpParam);

		HWND ret = CreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);

		printf("ret: %p\n\n", ret);

		return ret;
	}

	static v8::Handle<v8::Value> func_CreateWindowEx(const v8::Arguments& args) {
		if(args.Length() >= 12){
			//HWND ret = bounce_CreateWindowExW(
			HWND ret = CreateWindowExW(
				args[0]->Uint32Value(), // _In_      DWORD dwExStyle,
				reinterpret_cast<LPCWSTR>(v8::String::Value(args[1]).operator*()), // _In_opt_  LPCTSTR lpClassName,
				reinterpret_cast<LPCWSTR>(v8::String::Value(args[2]).operator*()), // _In_opt_  LPCTSTR lpWindowName,
				args[3]->Uint32Value(), // _In_      DWORD dwStyle,
				args[4]->Int32Value(), // _In_      int x,
				args[5]->Int32Value(), // _In_      int y,
				args[6]->Int32Value(), // _In_      int nWidth,
				args[7]->Int32Value(), // _In_      int nHeight,
				reinterpret_cast<HWND>(static_cast<int64_t>(args[8]->NumberValue())), // _In_opt_  HWND hWndParent,
				reinterpret_cast<HMENU>(static_cast<int64_t>(args[9]->NumberValue())), // _In_opt_  HMENU hMenu,
				reinterpret_cast<HINSTANCE>(static_cast<int64_t>(args[10]->NumberValue())), // _In_opt_  HINSTANCE hInstance,
				reinterpret_cast<LPVOID>(static_cast<int64_t>(args[11]->NumberValue()))// _In_opt_  LPVOID lpParam
			);
			v8::HandleScope scope;
			return scope.Close(v8::Number::New(reinterpret_cast<int64_t>(ret)));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_GetDC(const v8::Arguments& args) {
		if(args.Length() >= 1){
			HDC ret = GetDC(
				argToPointerType(0, HWND) //reinterpret_cast<HWND>(static_cast<int64_t>(args[0]->NumberValue())) // _In_opt_ HWND hWnd
			);
			v8::HandleScope scope;
			return scope.Close(v8::Number::New(reinterpret_cast<int64_t>(ret)));
		}
		return v8::Undefined();
	}


	static v8::Handle<v8::Value> func_ChoosePixelFormat(const v8::Arguments& args) {
		if(args.Length() >= 2){
			int ret = ChoosePixelFormat(
				argToPointerType(0, HDC),
				(const LPPIXELFORMATDESCRIPTOR)args[1]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_SetPixelFormat(const v8::Arguments& args) {
		if(args.Length() >= 3){
			BOOL ret = SetPixelFormat(
				argToPointerType(0, HDC),
				args[1]->Int32Value(),
				(const LPPIXELFORMATDESCRIPTOR)args[2]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_wglCreateContext(const v8::Arguments& args) {
		if(args.Length() >= 1){
			HGLRC ret = wglCreateContext(
				argToPointerType(0, HDC)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Number::New(reinterpret_cast<int64_t>(ret)));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_PostQuitMessage(const v8::Arguments& args) {
		v8::HandleScope scope;
		if(args.Length() >= 1){
			PostQuitMessage(
				args[0]->Int32Value()
			);
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_LOWORD(const v8::Arguments& args) {
		v8::HandleScope scope;
		if(args.Length() >= 1){
			const auto ret = LOWORD(
				args[0]->NumberValue()
			);
			return scope.Close(v8::Number::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_HIWORD(const v8::Arguments& args) {
		v8::HandleScope scope;
		if(args.Length() >= 1){
			const auto ret = HIWORD(
				args[0]->NumberValue()
			);
			return scope.Close(v8::Number::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_DefWindowProc(const v8::Arguments& args) {
			v8::HandleScope scope;
		if(args.Length() >= 4){
			LRESULT ret = DefWindowProc(
				argToPointerType(0, HWND),
				args[1]->Uint32Value(),
				(WPARAM)args[2]->NumberValue(),
				(LPARAM)args[3]->NumberValue()
			);
			return scope.Close(v8::Number::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_ShowWindow(const v8::Arguments& args) {
			v8::HandleScope scope;
		if(args.Length() >= 2){
			BOOL ret = ShowWindow(
				argToPointerType(0, HWND),
				args[1]->Int32Value()
			);
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_SetForegroundWindow(const v8::Arguments& args) {
		if(args.Length() >= 1){
			BOOL ret = SetForegroundWindow(
				argToPointerType(0, HWND)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Int32::New(ret));
		}
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> func_SetFocus(const v8::Arguments& args) {
		if(args.Length() >= 1){
			HWND ret = SetFocus(
				argToPointerType(0, HWND)
			);
			v8::HandleScope scope;
			return scope.Close(v8::Number::New(reinterpret_cast<int64_t>(ret)));
		}
		return v8::Undefined();
	}

#if 0
	WINUSERAPI
BOOL
WINAPI
ShowWindow(
    _In_ HWND hWnd,
    _In_ int nCmdShow);


	WINUSERAPI
BOOL
WINAPI
SetForegroundWindow(
    _In_ HWND hWnd);


	WINUSERAPI
HWND
WINAPI
SetFocus(
    _In_opt_ HWND hWnd);

		SetFunctionSymbolStatic(func_Gdi32, ShowWindow)
		SetFunctionSymbolStatic(func_Gdi32, SetForegroundWindow)
		SetFunctionSymbolStatic(func_Gdi32, SetFocus)
#endif

#if 0
	static v8::Handle<v8::Value> func_glBegin(const v8::Arguments& args) { if(args.Length() >= 1){ glBegin(args[0]->Uint32Value()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glEnd(const v8::Arguments& args) { glEnd(); return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glColor3f(const v8::Arguments& args) { if(args.Length() >= 3){ glColor3f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glColor3d(const v8::Arguments& args) { if(args.Length() >= 3){ glColor3d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()); } return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glColor4f(const v8::Arguments& args) { if(args.Length() >= 4){ glColor4f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glColor4d(const v8::Arguments& args) { if(args.Length() >= 4){ glColor4d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()); } return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glVertex2f(const v8::Arguments& args) { if(args.Length() >= 2){ glVertex2f(args[0]->NumberValue(), args[1]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glVertex2d(const v8::Arguments& args) { if(args.Length() >= 2){ glVertex2d(args[0]->NumberValue(), args[1]->NumberValue()); } return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glVertex3f(const v8::Arguments& args) { if(args.Length() >= 3){ glVertex3f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glVertex3d(const v8::Arguments& args) { if(args.Length() >= 3){ glVertex3d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()); } return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glVertex4f(const v8::Arguments& args) { if(args.Length() >= 4){ glVertex4f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glVertex4d(const v8::Arguments& args) { if(args.Length() >= 4){ glVertex4d(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()); } return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glLoadIdentity(const v8::Arguments& args) { glLoadIdentity(); return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glTranslatef(const v8::Arguments& args) { if(args.Length() >= 3){ glTranslatef(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glTranslated(const v8::Arguments& args) { if(args.Length() >= 3){ glTranslated(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()); } return v8::Undefined(); }

	static v8::Handle<v8::Value> func_glRotatef(const v8::Arguments& args) { if(args.Length() >= 4){ glRotatef(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()); } return v8::Undefined(); }
	static v8::Handle<v8::Value> func_glRotated(const v8::Arguments& args) { if(args.Length() >= 4){ glRotated(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue(), args[3]->NumberValue()); } return v8::Undefined(); }

};
SetFunctionSymbol(AdjustWindowRectEx)
	SetFunctionSymbol(CreateWindowEx)
	SetFunctionSymbol(GetDC)
	SetFunctionSymbol(ChoosePixelFormat)
	SetFunctionSymbol(SetPixelFormat)
	SetFunctionSymbol(wglCreateContext)
	SetFunctionSymbol(wglMakeCurrent)
	SetFunctionSymbol(ShowWindow)
	SetFunctionSymbol(SetForegroundWindow)
	SetFunctionSymbol(SetFocus)
#endif
};