class class_WNDCLASSW: public node::ObjectWrap {
public:
#define NODE_STATIC_GETTER_SETTER_uint32_t(name) \
		static v8::Handle<v8::Value> class_WNDCLASSW::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		return scope.Close(v8::Uint32::NewFromUnsigned(obj->data.##name)); \
	} \
	 \
	static void class_WNDCLASSW::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		obj->data.##name = value->Uint32Value(); \
	}

#define NODE_STATIC_GETTER_SETTER_int32_t(name) \
		static v8::Handle<v8::Value> class_WNDCLASSW::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		return scope.Close(v8::Int32::New(obj->data.##name)); \
	} \
	 \
	static void class_WNDCLASSW::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		obj->data.##name = value->Int32Value(); \
	}

#define NODE_STATIC_GETTER_SETTER_int64_t(name) \
		static v8::Handle<v8::Value> class_WNDCLASSW::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		return scope.Close(v8::Number::New((int64_t)(obj->data.##name)));\
	} \
	 \
	static void class_WNDCLASSW::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		obj->data.##name = (decltype(obj->data.##name))((int64_t)value->NumberValue()); \
	}

#define NODE_STATIC_GETTER_SETTER_LPCWSTR(name) \
	static v8::Handle<v8::Value> class_WNDCLASSW::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		if(!obj->data.##name) { \
			return v8::Undefined(); \
		} \
		return scope.Close(v8::String::New((const uint16_t*)obj->data.##name));\
	} \
	 \
	static void class_WNDCLASSW::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This()); \
		v8::String::Value arg0(value); \
		LPCWSTR arg0lp = (LPCWSTR)*arg0; \
		obj->str_##name = arg0lp; \
		obj->data.##name = (decltype(obj->data.##name))(obj->str_##name.c_str()); \
	}

	NODE_STATIC_GETTER_SETTER_uint32_t(style)          // UINT        style;
  NODE_STATIC_GETTER_SETTER_int64_t(lpfnWndProc)     //  WNDPROC     lpfnWndProc;
	NODE_STATIC_GETTER_SETTER_int32_t(cbClsExtra)      //int         cbClsExtra;
	NODE_STATIC_GETTER_SETTER_int32_t(cbWndExtra)      //int         cbWndExtra;
  NODE_STATIC_GETTER_SETTER_int64_t(hInstance)       //  HINSTANCE   hInstance;
  NODE_STATIC_GETTER_SETTER_int64_t(hIcon)           //  HICON       hIcon;
  NODE_STATIC_GETTER_SETTER_int64_t(hCursor)         //  HCURSOR     hCursor;
  NODE_STATIC_GETTER_SETTER_int64_t(hbrBackground)   //  HBRUSH      hbrBackground;
  NODE_STATIC_GETTER_SETTER_LPCWSTR(lpszMenuName)    //  LPCWSTR     lpszMenuName;
  NODE_STATIC_GETTER_SETTER_LPCWSTR(lpszClassName)   //  LPCWSTR     lpszClassName;


	static v8::Handle<v8::Value> class_WNDCLASSW::get_ClassATOM(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		v8::HandleScope scope;
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(info.This());
		return scope.Close(v8::Uint32::NewFromUnsigned(obj->ClassATOM));
	}

	static v8::Handle<v8::Value> method_RegisterClass(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(args.This());
		obj->data.cbClsExtra += sizeof(class_WNDCLASSW *);
		//const auto ret = class_Gdi32::bounce_RegisterClassW(&obj->data);
		const auto ret = RegisterClassW(&obj->data);
		if(ret) {
			obj->ClassATOM = ret;
		}
		return scope.Close(v8::Uint32::NewFromUnsigned(ret));
	}
	
	static v8::Handle<v8::Value> method_SetCallback(const v8::Arguments& args) {
		if(args.Length() < 1){
			return v8::Undefined();
		}

		v8::HandleScope scope;
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(args.This());
		obj->cb = v8::Persistent<v8::Function>::New(v8::Handle<v8::Function>::Cast(args[0]));
		//printf("SetCallback threadId = %p\n", GetCurrentThreadId());
		return v8::Undefined();
	}

	static v8::Handle<v8::Value> method_GetPointer(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WNDCLASSW* obj = class_WNDCLASSW::Unwrap<class_WNDCLASSW>(args.This());
		return scope.Close(v8::Number::New((int64_t)obj));
	}

	#define     GetWindowStyle(hwnd)    ((DWORD)GetWindowLong(hwnd, GWL_STYLE))
#define     GetWindowExStyle(hwnd)  ((DWORD)GetWindowLong(hwnd, GWL_EXSTYLE))

	static LRESULT CALLBACK WindowProc(_In_  HWND hWnd, _In_  UINT uMsg, _In_  WPARAM wParam, _In_  LPARAM lParam) {
		//printf("WindowProc(%p, %u, %Iu, %Id)\n", hWnd, uMsg, wParam, lParam);

		if(uMsg == WM_CREATE) {
			//puts("WM_CREATE");
			const LPCREATESTRUCT cs{(LPCREATESTRUCT)lParam};
			const auto oldObj = SetClassLongPtr(hWnd, 0, (LONG_PTR)cs->lpCreateParams);
			//printf("oldObj = %p\n", oldObj);
			return DefWindowProc(hWnd,uMsg,wParam,lParam);
		}

		const auto curObj = GetClassLongPtr(hWnd, 0);
		//printf("curObj = %p\n", curObj);
		
		if(curObj == 0xDEADBEEFDEADBEEFui64) {
			return DefWindowProc(hWnd,uMsg,wParam,lParam);
		}
		if(!curObj) {
			const auto oldObj = SetClassLongPtr(hWnd, 0, 0xDEADBEEFDEADBEEFui64);
			//printf("oldObj = %p\n", oldObj);
			return DefWindowProc(hWnd,uMsg,wParam,lParam);
		}

		const class_WNDCLASSW *obj = (class_WNDCLASSW*)curObj;

		const unsigned argc = 4;
		v8::HandleScope scope;
		v8::Local<v8::Value> argv[argc] = {
			v8::Local<v8::Value>::New(v8::Number::New((int64_t)hWnd)),
			v8::Local<v8::Value>::New(v8::Uint32::NewFromUnsigned(uMsg)),
			v8::Local<v8::Value>::New(v8::Number::New((uint64_t)wParam)),
			v8::Local<v8::Value>::New(v8::Number::New((int64_t)lParam))
		};
		//printf("Callback->call threadId = %p\n", GetCurrentThreadId());
		v8::Local<v8::Value> ret = obj->cb->Call(v8::Context::GetCurrent()->Global(), argc, argv);
		return ret->Int32Value();

		//return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}

#undef NODE_STATIC_GETTER_SETTER_int32_t
#undef NODE_STATIC_GETTER_SETTER_int64_t
#undef NODE_STATIC_GETTER_SETTER_uint32_t

	WNDCLASSW data;
	class_WNDCLASSW *THIS_PTR;
	std::wstring str_lpszMenuName;
	std::wstring str_lpszClassName;
	ATOM ClassATOM{0};
	v8::Persistent<v8::Function> cb;

	static void class_WNDCLASSW::Init(v8::Handle<v8::Object> target) {

		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
		tpl->SetClassName(v8::String::NewSymbol("WNDCLASSW"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);
		// Prototype
		setPrototypeMethod(RegisterClass)
		setPrototypeMethod(SetCallback)
		setPrototypeMethod(GetPointer)
		//#define MakeMethod setPrototypeFunc
		//#include "OpenGL_MethodMaker.h"
		//#undef MakeMethod 
		//setPrototypeGetter(swapBuffersPending);



		setPrototypeGetterSetter(style);
    setPrototypeGetterSetter(lpfnWndProc);
    setPrototypeGetterSetter(cbClsExtra);
    setPrototypeGetterSetter(cbWndExtra);
    setPrototypeGetterSetter(hInstance);
    setPrototypeGetterSetter(hIcon);
    setPrototypeGetterSetter(hCursor);
    setPrototypeGetterSetter(hbrBackground);
    setPrototypeGetterSetter(lpszMenuName);
    setPrototypeGetterSetter(lpszClassName);
		setPrototypeGetter(ClassATOM);

		v8::HandleScope scope;
		constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
		retTpl = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
		retTpl->SetInternalFieldCount(1);

		target->Set(v8::String::NewSymbol("WNDCLASSW"), constructor);

	}

	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		v8::HandleScope scope;

		const unsigned argc = 1;
		v8::Handle<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

		return scope.Close(instance);
	}

private:
	class_WNDCLASSW() {
		OutputDebugString(L"WNDCLASSW()\n");
		SecureZeroMemory(&data, sizeof(data));
		data.hInstance = GetModuleHandle(nullptr);
#if 0
		data.lpfnWndProc = WndProc;
#else
		data.lpfnWndProc = WindowProc;
#endif
		THIS_PTR = this;
	}
	~class_WNDCLASSW() {
		OutputDebugString(L"~WNDCLASSW()\n");
	}
	static v8::Handle<v8::Value> New(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WNDCLASSW* obj = new class_WNDCLASSW();
		obj->Wrap(args.This());
		return args.This();
	}
	static v8::Persistent<v8::Function> constructor;
	static v8::Persistent<v8::ObjectTemplate> retTpl;
};