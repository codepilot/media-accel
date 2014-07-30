class class_GDIPLUS_IMAGE: public node::ObjectWrap {
public:

	class_GDIPLUS_IMAGE *THIS_PTR;
	static void class_GDIPLUS_IMAGE::Init(v8::Handle<v8::Object> target) {

		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
		tpl->SetClassName(v8::String::NewSymbol("GDIPLUS_IMAGE"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);
		// Prototype
//		setPrototypeMethod(RegisterClass)
//		setPrototypeMethod(SetCallback)
//		setPrototypeMethod(GetPointer)
		//#define MakeMethod setPrototypeFunc
		//#include "OpenGL_MethodMaker.h"
		//#undef MakeMethod 
		//setPrototypeGetter(swapBuffersPending);



//		setPrototypeGetterSetter(style);
//    setPrototypeGetterSetter(lpfnWndProc);
//    setPrototypeGetterSetter(cbClsExtra);
//    setPrototypeGetterSetter(cbWndExtra);
//    setPrototypeGetterSetter(hInstance);
//    setPrototypeGetterSetter(hIcon);
//    setPrototypeGetterSetter(hCursor);
//    setPrototypeGetterSetter(hbrBackground);
//    setPrototypeGetterSetter(lpszMenuName);
//    setPrototypeGetterSetter(lpszClassName);
//		setPrototypeGetter(ClassATOM);

		v8::HandleScope scope;
		constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
		retTpl = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
		retTpl->SetInternalFieldCount(1);

		target->Set(v8::String::NewSymbol("GDIPLUS_IMAGE"), constructor);

	}

	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		v8::HandleScope scope;

		const unsigned argc = 1;
		v8::Handle<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

		return scope.Close(instance);
	}
//private:
	Gdiplus::Image* image;
	class_GDIPLUS_IMAGE() {
		OutputDebugString(L"GDIPLUS_IMAGE()\n");

		image = new Gdiplus::Image(L"./png/AlphaBall.png");
		printf("The width of the image is %u.\n", image->GetWidth());
		printf("The height of the image is %u.\n", image->GetHeight()); 

		THIS_PTR = this;
	}
	~class_GDIPLUS_IMAGE() {
		OutputDebugString(L"~GDIPLUS_IMAGE()\n");
		delete image;
	}
private:
	static v8::Handle<v8::Value> New(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_GDIPLUS_IMAGE* obj = new class_GDIPLUS_IMAGE();
		obj->Wrap(args.This());
		return args.This();
	}
	static v8::Persistent<v8::Function> constructor;
	static v8::Persistent<v8::ObjectTemplate> retTpl;
};