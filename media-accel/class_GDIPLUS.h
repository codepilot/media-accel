#include <objidl.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

class class_GDIPLUS: public node::ObjectWrap {
public:
#define NODE_STATIC_GETTER_SETTER_uint32_t(name) \
		static v8::Handle<v8::Value> class_GDIPLUS::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		return scope.Close(v8::Uint32::NewFromUnsigned(obj->data.##name)); \
	} \
	 \
	static void class_GDIPLUS::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		obj->data.##name = value->Uint32Value(); \
	}

#define NODE_STATIC_GETTER_SETTER_int32_t(name) \
		static v8::Handle<v8::Value> class_GDIPLUS::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		return scope.Close(v8::Int32::New(obj->data.##name)); \
	} \
	 \
	static void class_GDIPLUS::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		obj->data.##name = value->Int32Value(); \
	}

#define NODE_STATIC_GETTER_SETTER_int64_t(name) \
		static v8::Handle<v8::Value> class_GDIPLUS::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		return scope.Close(v8::Number::New((int64_t)(obj->data.##name)));\
	} \
	 \
	static void class_GDIPLUS::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		obj->data.##name = (decltype(obj->data.##name))((int64_t)value->NumberValue()); \
	}

#define NODE_STATIC_GETTER_SETTER_LPCWSTR(name) \
	static v8::Handle<v8::Value> class_GDIPLUS::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		if(!obj->data.##name) { \
			return v8::Undefined(); \
		} \
		return scope.Close(v8::String::New((const uint16_t*)obj->data.##name));\
	} \
	 \
	static void class_GDIPLUS::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS* obj = class_GDIPLUS::Unwrap<class_GDIPLUS>(info.This()); \
		v8::String::Value arg0(value); \
		LPCWSTR arg0lp = (LPCWSTR)*arg0; \
		obj->str_##name = arg0lp; \
		obj->data.##name = (decltype(obj->data.##name))(obj->str_##name.c_str()); \
	}

//	NODE_STATIC_GETTER_SETTER_uint32_t(style)          // UINT        style;
//  NODE_STATIC_GETTER_SETTER_int64_t(lpfnWndProc)     //  WNDPROC     lpfnWndProc;
//	NODE_STATIC_GETTER_SETTER_int32_t(cbClsExtra)      //int         cbClsExtra;
//	NODE_STATIC_GETTER_SETTER_int32_t(cbWndExtra)      //int         cbWndExtra;
//  NODE_STATIC_GETTER_SETTER_int64_t(hInstance)       //  HINSTANCE   hInstance;
//  NODE_STATIC_GETTER_SETTER_int64_t(hIcon)           //  HICON       hIcon;
//  NODE_STATIC_GETTER_SETTER_int64_t(hCursor)         //  HCURSOR     hCursor;
//  NODE_STATIC_GETTER_SETTER_int64_t(hbrBackground)   //  HBRUSH      hbrBackground;
//  NODE_STATIC_GETTER_SETTER_LPCWSTR(lpszMenuName)    //  LPCWSTR     lpszMenuName;
//  NODE_STATIC_GETTER_SETTER_LPCWSTR(lpszClassName)   //  LPCWSTR     lpszClassName;
//	GDIPLUS data;
	class_GDIPLUS *THIS_PTR;
	std::wstring str_lpszMenuName;
	std::wstring str_lpszClassName;
	ATOM ClassATOM{0};
	v8::Persistent<v8::Function> cb;

	static void class_GDIPLUS::Init(v8::Handle<v8::Object> target) {

		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
		tpl->SetClassName(v8::String::NewSymbol("GDIPLUS"));
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

		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatIndexed"), v8::Uint32::NewFromUnsigned(PixelFormatIndexed));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatGDI"), v8::Uint32::NewFromUnsigned(PixelFormatGDI));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatAlpha"), v8::Uint32::NewFromUnsigned(PixelFormatAlpha));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatPAlpha"), v8::Uint32::NewFromUnsigned(PixelFormatPAlpha));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatExtended"), v8::Uint32::NewFromUnsigned(PixelFormatExtended));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatCanonical"), v8::Uint32::NewFromUnsigned(PixelFormatCanonical));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatUndefined"), v8::Uint32::NewFromUnsigned(PixelFormatUndefined));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatDontCare"), v8::Uint32::NewFromUnsigned(PixelFormatDontCare));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat1bppIndexed"), v8::Uint32::NewFromUnsigned(PixelFormat1bppIndexed));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat4bppIndexed"), v8::Uint32::NewFromUnsigned(PixelFormat4bppIndexed));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat8bppIndexed"), v8::Uint32::NewFromUnsigned(PixelFormat8bppIndexed));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat16bppGrayScale"), v8::Uint32::NewFromUnsigned(PixelFormat16bppGrayScale));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat16bppRGB555"), v8::Uint32::NewFromUnsigned(PixelFormat16bppRGB555));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat16bppRGB565"), v8::Uint32::NewFromUnsigned(PixelFormat16bppRGB565));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat16bppARGB1555"), v8::Uint32::NewFromUnsigned(PixelFormat16bppARGB1555));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat24bppRGB"), v8::Uint32::NewFromUnsigned(PixelFormat24bppRGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat32bppRGB"), v8::Uint32::NewFromUnsigned(PixelFormat32bppRGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat32bppARGB"), v8::Uint32::NewFromUnsigned(PixelFormat32bppARGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat32bppPARGB"), v8::Uint32::NewFromUnsigned(PixelFormat32bppPARGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat48bppRGB"), v8::Uint32::NewFromUnsigned(PixelFormat48bppRGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat64bppARGB"), v8::Uint32::NewFromUnsigned(PixelFormat64bppARGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat64bppPARGB"), v8::Uint32::NewFromUnsigned(PixelFormat64bppPARGB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormat32bppCMYK"), v8::Uint32::NewFromUnsigned(PixelFormat32bppCMYK));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("PixelFormatMax"), v8::Uint32::NewFromUnsigned(PixelFormatMax));

		v8::HandleScope scope;
		constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
		retTpl = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
		retTpl->SetInternalFieldCount(1);

		target->Set(v8::String::NewSymbol("GDIPLUS"), constructor);

	}
#if 0
	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		/* srcPicPath, dstPicPath, srcX, srcY, srcWidth, srcHeight, dstX, dstY, dstWidth, dstHeight */
		v8::HandleScope scope;
		if(args.Length() < 10) {
			return v8::Undefined();
		}
		auto srcImage = new Gdiplus::Image(L"./png/AlphaBall.png");
		//auto dstImage = new Gdiplus::Image(L"./png/AlphaBall.png");
//		auto dstImage = new Gdiplus::Image();
	
		Gdiplus::RectF srcRect(args[2]->NumberValue(), args[3]->NumberValue(), args[4]->NumberValue(), args[5]->NumberValue());
		Gdiplus::RectF dstRect(args[6]->NumberValue(), args[7]->NumberValue(), args[8]->NumberValue(), args[9]->NumberValue());

		auto dstGraphics = new Gdiplus::Graphics(srcImage);
#if 0
		Status DrawImage(
  [in]       Image *image,
  [in, ref]  dstRect,
  [in, ref]  srcRect,
  [in]       Unit srcUnit,
  [in]       ImageAttributes *imageAttributes
)
#endif
	}
#endif

	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		v8::HandleScope scope;

		const unsigned argc = 1;
		v8::Handle<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

		return scope.Close(instance);
	}
	ULONG_PTR           gdiplusToken;
//private:
	class_GDIPLUS() {
		OutputDebugString(L"GDIPLUS()\n");
   // Initialize GDI+.
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		THIS_PTR = this;
	}
	~class_GDIPLUS() {
		OutputDebugString(L"~GDIPLUS()\n");
		 Gdiplus::GdiplusShutdown(gdiplusToken);
	}
private:
	static v8::Handle<v8::Value> New(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_GDIPLUS* obj = new class_GDIPLUS();
		obj->Wrap(args.This());
		return args.This();
	}
	static v8::Persistent<v8::Function> constructor;
	static v8::Persistent<v8::ObjectTemplate> retTpl;
};