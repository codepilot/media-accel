#include <Shlwapi.h>

class class_GDIPLUS_BITMAP: public node::ObjectWrap {
public:
#define NODE_STATIC_GETTER_SETTER_uint32_t(name) \
		static v8::Handle<v8::Value> class_GDIPLUS_BITMAP::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS_BITMAP* obj = class_GDIPLUS_BITMAP::Unwrap<class_GDIPLUS_BITMAP>(info.This()); \
		return scope.Close(v8::Uint32::NewFromUnsigned(obj->bitmapData->##name)); \
	} \
	 \
	static void class_GDIPLUS_BITMAP::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS_BITMAP* obj = class_GDIPLUS_BITMAP::Unwrap<class_GDIPLUS_BITMAP>(info.This()); \
		obj->bitmapData->##name = value->Uint32Value(); \
	}

#define NODE_STATIC_GETTER_SETTER_int32_t(name) \
		static v8::Handle<v8::Value> class_GDIPLUS_BITMAP::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS_BITMAP* obj = class_GDIPLUS_BITMAP::Unwrap<class_GDIPLUS_BITMAP>(info.This()); \
		return scope.Close(v8::Int32::New(obj->bitmapData->##name)); \
	} \
	 \
	static void class_GDIPLUS_BITMAP::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS_BITMAP* obj = class_GDIPLUS_BITMAP::Unwrap<class_GDIPLUS_BITMAP>(info.This()); \
		obj->bitmapData->##name = value->Int32Value(); \
	}

#define NODE_STATIC_GETTER_SETTER_int64_t(name) \
		static v8::Handle<v8::Value> class_GDIPLUS_BITMAP::get_##name(v8::Local<v8::String> property, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS_BITMAP* obj = class_GDIPLUS_BITMAP::Unwrap<class_GDIPLUS_BITMAP>(info.This()); \
		return scope.Close(v8::Number::New((int64_t)(obj->bitmapData->##name)));\
	} \
	 \
	static void class_GDIPLUS_BITMAP::set_##name(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo &info) { \
		v8::HandleScope scope; \
		class_GDIPLUS_BITMAP* obj = class_GDIPLUS_BITMAP::Unwrap<class_GDIPLUS_BITMAP>(info.This()); \
		obj->bitmapData->##name = (decltype(obj->bitmapData->##name))((int64_t)value->NumberValue()); \
	}

	NODE_STATIC_GETTER_SETTER_uint32_t(Width)
	NODE_STATIC_GETTER_SETTER_uint32_t(Height)
	NODE_STATIC_GETTER_SETTER_int32_t(Stride)
	NODE_STATIC_GETTER_SETTER_int32_t(PixelFormat)
  NODE_STATIC_GETTER_SETTER_int64_t(Scan0)

	class_GDIPLUS_BITMAP *THIS_PTR;
	static void class_GDIPLUS_BITMAP::Init(v8::Handle<v8::Object> target) {

		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
		tpl->SetClassName(v8::String::NewSymbol("GDIPLUS_BITMAP"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);
		// Prototype
//		setPrototypeMethod(RegisterClass)
//		setPrototypeMethod(SetCallback)
//		setPrototypeMethod(GetPointer)
		//#define MakeMethod setPrototypeFunc
		//#include "OpenGL_MethodMaker.h"
		//#undef MakeMethod 
		//setPrototypeGetter(swapBuffersPending);



		setPrototypeGetterSetter(Width);
    setPrototypeGetterSetter(Height);
    setPrototypeGetterSetter(Stride);
    setPrototypeGetterSetter(PixelFormat);
    setPrototypeGetterSetter(Scan0);
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

		target->Set(v8::String::NewSymbol("GDIPLUS_BITMAP"), constructor);

	}

	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		v8::HandleScope scope;

		const unsigned argc = 1;
		v8::Handle<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

		return scope.Close(instance);
	}
//private:
	Gdiplus::Bitmap* bitmap;
	Gdiplus::BitmapData* bitmapData;

	class_GDIPLUS_BITMAP(const BYTE *pInit, UINT cbInit, Gdiplus::PixelFormat pixelFormat) {
		OutputDebugString(L"GDIPLUS_BITMAP()\n");

		THIS_PTR = this;
		wprintf(L"GDIPLUS_BITMAP(%u, %d)\n", cbInit, pixelFormat);

		auto comIn = SHCreateMemStream(pInit, cbInit);

		bitmap = new Gdiplus::Bitmap(comIn);
		bitmapData = new Gdiplus::BitmapData;
   // Lock a 5x3 rectangular portion of the bitmap for reading.
//		Gdiplus::Rect rect(20, 30, 5, 3);
#if 0
#define    PixelFormat1bppIndexed     (1 | ( 1 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat4bppIndexed     (2 | ( 4 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat8bppIndexed     (3 | ( 8 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat16bppGrayScale  (4 | (16 << 8) | PixelFormatExtended)
#define    PixelFormat16bppRGB555     (5 | (16 << 8) | PixelFormatGDI)
#define    PixelFormat16bppRGB565     (6 | (16 << 8) | PixelFormatGDI)
#define    PixelFormat16bppARGB1555   (7 | (16 << 8) | PixelFormatAlpha | PixelFormatGDI)
#define    PixelFormat24bppRGB        (8 | (24 << 8) | PixelFormatGDI)
#define    PixelFormat32bppRGB        (9 | (32 << 8) | PixelFormatGDI)
#define    PixelFormat32bppARGB       (10 | (32 << 8) | PixelFormatAlpha | PixelFormatGDI | PixelFormatCanonical)
#define    PixelFormat32bppPARGB      (11 | (32 << 8) | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatGDI)
#define    PixelFormat48bppRGB        (12 | (48 << 8) | PixelFormatExtended)
#define    PixelFormat64bppARGB       (13 | (64 << 8) | PixelFormatAlpha  | PixelFormatCanonical | PixelFormatExtended)
#define    PixelFormat64bppPARGB      (14 | (64 << 8) | PixelFormatAlpha  | PixelFormatPAlpha | PixelFormatExtended)
#define    PixelFormat32bppCMYK       (15 | (32 << 8))
#endif
   bitmap->LockBits(
      nullptr,//&rect,
      Gdiplus::ImageLockModeRead,
      pixelFormat,//PixelFormat32bppARGB,//PixelFormat64bppARGB,
      bitmapData);
		printf("The Width of the bitmap is %u.\n", bitmapData->Width);
		printf("The Height of the bitmap is %u.\n", bitmapData->Height); 
		printf("The Stride is %d.\n", bitmapData->Stride);
		printf("The PixelFormat is %d.\n", bitmapData->PixelFormat);
		printf("The Scan0 is %p.\n\n", bitmapData->Scan0);

#if 0
   // Display the hexadecimal value of each pixel in the 5x3 rectangle.
   //UINT* pixels = (UINT*)bitmapData->Scan0;
   uint64_t* pixels = (uint64_t*)bitmapData->Scan0;

   for(UINT row = 0; row < 3; ++row)
   {
      for(UINT col = 0; col < 5; ++col)
      {
         //printf("%x\n", pixels[row * bitmapData->Stride / 4 + col]);
         printf("%I64x\n", pixels[row * bitmapData->Stride / 8 + col]);
      }
      printf("- - - - - - - - - - \n");
   }
#endif
	}

	class_GDIPLUS_BITMAP(const WCHAR *filename, Gdiplus::PixelFormat pixelFormat) {
		OutputDebugString(L"GDIPLUS_BITMAP()\n");

		THIS_PTR = this;
		wprintf(L"GDIPLUS_BITMAP(%s, %d)\n", filename, pixelFormat);

		bitmap = new Gdiplus::Bitmap(filename);
		bitmapData = new Gdiplus::BitmapData;
   // Lock a 5x3 rectangular portion of the bitmap for reading.
//		Gdiplus::Rect rect(20, 30, 5, 3);
#if 0
#define    PixelFormat1bppIndexed     (1 | ( 1 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat4bppIndexed     (2 | ( 4 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat8bppIndexed     (3 | ( 8 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define    PixelFormat16bppGrayScale  (4 | (16 << 8) | PixelFormatExtended)
#define    PixelFormat16bppRGB555     (5 | (16 << 8) | PixelFormatGDI)
#define    PixelFormat16bppRGB565     (6 | (16 << 8) | PixelFormatGDI)
#define    PixelFormat16bppARGB1555   (7 | (16 << 8) | PixelFormatAlpha | PixelFormatGDI)
#define    PixelFormat24bppRGB        (8 | (24 << 8) | PixelFormatGDI)
#define    PixelFormat32bppRGB        (9 | (32 << 8) | PixelFormatGDI)
#define    PixelFormat32bppARGB       (10 | (32 << 8) | PixelFormatAlpha | PixelFormatGDI | PixelFormatCanonical)
#define    PixelFormat32bppPARGB      (11 | (32 << 8) | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatGDI)
#define    PixelFormat48bppRGB        (12 | (48 << 8) | PixelFormatExtended)
#define    PixelFormat64bppARGB       (13 | (64 << 8) | PixelFormatAlpha  | PixelFormatCanonical | PixelFormatExtended)
#define    PixelFormat64bppPARGB      (14 | (64 << 8) | PixelFormatAlpha  | PixelFormatPAlpha | PixelFormatExtended)
#define    PixelFormat32bppCMYK       (15 | (32 << 8))
#endif
   bitmap->LockBits(
      nullptr,//&rect,
      Gdiplus::ImageLockModeRead,
      pixelFormat,//PixelFormat32bppARGB,//PixelFormat64bppARGB,
      bitmapData);
		printf("The Width of the bitmap is %u.\n", bitmapData->Width);
		printf("The Height of the bitmap is %u.\n", bitmapData->Height); 
		printf("The Stride is %d.\n", bitmapData->Stride);
		printf("The PixelFormat is %d.\n", bitmapData->PixelFormat);
		printf("The Scan0 is %p.\n\n", bitmapData->Scan0);

#if 0
   // Display the hexadecimal value of each pixel in the 5x3 rectangle.
   //UINT* pixels = (UINT*)bitmapData->Scan0;
   uint64_t* pixels = (uint64_t*)bitmapData->Scan0;

   for(UINT row = 0; row < 3; ++row)
   {
      for(UINT col = 0; col < 5; ++col)
      {
         //printf("%x\n", pixels[row * bitmapData->Stride / 4 + col]);
         printf("%I64x\n", pixels[row * bitmapData->Stride / 8 + col]);
      }
      printf("- - - - - - - - - - \n");
   }
#endif
	}
	~class_GDIPLUS_BITMAP() {
		OutputDebugString(L"~GDIPLUS_BITMAP()\n");
		bitmap->UnlockBits(bitmapData);
		delete bitmapData;
		delete bitmap;
	}
private:
	static v8::Handle<v8::Value> New(const v8::Arguments& args) {
		v8::HandleScope scope;
		if(args.Length() < 2) {
			return v8::Undefined();
		}
		class_GDIPLUS_BITMAP* obj{nullptr};
		if(args[0]->IsObject()) {
			auto arg0obj = args[0]->ToObject();
			obj = new class_GDIPLUS_BITMAP((const BYTE *)arg0obj->GetIndexedPropertiesExternalArrayData(), arg0obj->GetIndexedPropertiesExternalArrayDataLength(), args[1]->Int32Value());
		} else {
			obj = new class_GDIPLUS_BITMAP((const WCHAR *)v8::String::Value(args[0]).operator*(), args[1]->Int32Value());
		}
		obj->Wrap(args.This());
		switch(args[1]->Int32Value()) {
		case PixelFormat16bppRGB555:
		case PixelFormat16bppRGB565:
		case PixelFormat16bppARGB1555:
		case PixelFormat16bppGrayScale:
			args.This()->Set(v8::String::NewSymbol("length"), v8::Number::New((obj->bitmapData->Height * obj->bitmapData->Stride) >> 1));
			args.This()->SetIndexedPropertiesToExternalArrayData(obj->bitmapData->Scan0, v8::ExternalArrayType::kExternalUnsignedShortArray, (obj->bitmapData->Height * obj->bitmapData->Stride) >> 1);
			break;

		case PixelFormat32bppRGB:
		case PixelFormat32bppARGB:
		case PixelFormat32bppPARGB:
		case PixelFormat32bppCMYK:
			args.This()->Set(v8::String::NewSymbol("length"), v8::Number::New((obj->bitmapData->Height * obj->bitmapData->Stride) >> 2));
			args.This()->SetIndexedPropertiesToExternalArrayData(obj->bitmapData->Scan0, v8::ExternalArrayType::kExternalUnsignedIntArray, (obj->bitmapData->Height * obj->bitmapData->Stride) >> 2);
			break;

		case PixelFormat1bppIndexed:
		case PixelFormat4bppIndexed:
		case PixelFormat8bppIndexed:
		case PixelFormat24bppRGB:
		case PixelFormat48bppRGB:
		case PixelFormat64bppARGB:
		case PixelFormat64bppPARGB:
		default:
			args.This()->Set(v8::String::NewSymbol("length"), v8::Number::New((obj->bitmapData->Height * obj->bitmapData->Stride)));
			args.This()->SetIndexedPropertiesToExternalArrayData(obj->bitmapData->Scan0, v8::ExternalArrayType::kExternalUnsignedByteArray, (obj->bitmapData->Height * obj->bitmapData->Stride));
			break;
		}

		return args.This();
	}
	static v8::Persistent<v8::Function> constructor;
	static v8::Persistent<v8::ObjectTemplate> retTpl;
};