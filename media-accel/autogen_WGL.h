#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI /*extern*/
#endif































struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
};
DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
typedef struct _GPU_DEVICE GPU_DEVICE;
typedef struct _GPU_DEVICE *PGPU_DEVICE;


class class_WGL: public node::ObjectWrap {
public:





//GLAPI int APIENTRY ChoosePixelFormat (HDC hDc, const PIXELFORMATDESCRIPTOR *pPfd);
	typedef int (APIENTRYP PFNCHOOSEPIXELFORMATPROC) (HDC hDc, const PIXELFORMATDESCRIPTOR *pPfd);
	PFNCHOOSEPIXELFORMATPROC methodp_ChoosePixelFormat{nullptr};
	static v8::Handle<v8::Value> method_ChoosePixelFormat(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_ChoosePixelFormat && args.Length() >= 2){


			int ret = obj->methodp_ChoosePixelFormat(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				(const PIXELFORMATDESCRIPTOR *)((int64_t)args[1]->NumberValue())/* const PIXELFORMATDESCRIPTOR *pPfd */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY DescribePixelFormat (HDC hdc, int ipfd, UINT cjpfd, const PIXELFORMATDESCRIPTOR *ppfd);
	typedef int (APIENTRYP PFNDESCRIBEPIXELFORMATPROC) (HDC hdc, int ipfd, UINT cjpfd, const PIXELFORMATDESCRIPTOR *ppfd);
	PFNDESCRIBEPIXELFORMATPROC methodp_DescribePixelFormat{nullptr};
	static v8::Handle<v8::Value> method_DescribePixelFormat(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_DescribePixelFormat && args.Length() >= 4){
			int  arg1{ (int )(args[1]->Int32Value())};
			UINT  arg2{ (UINT )(args[2]->Uint32Value())};

			int ret = obj->methodp_DescribePixelFormat(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				(const PIXELFORMATDESCRIPTOR *)((int64_t)args[3]->NumberValue())/* const PIXELFORMATDESCRIPTOR *ppfd */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY GetPixelFormat (HDC hdc);
	typedef int (APIENTRYP PFNGETPIXELFORMATPROC) (HDC hdc);
	PFNGETPIXELFORMATPROC methodp_GetPixelFormat{nullptr};
	static v8::Handle<v8::Value> method_GetPixelFormat(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_GetPixelFormat && args.Length() >= 1){


			int ret = obj->methodp_GetPixelFormat(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY SetPixelFormat (HDC hdc, int ipfd, const PIXELFORMATDESCRIPTOR *ppfd);
	typedef BOOL (APIENTRYP PFNSETPIXELFORMATPROC) (HDC hdc, int ipfd, const PIXELFORMATDESCRIPTOR *ppfd);
	PFNSETPIXELFORMATPROC methodp_SetPixelFormat{nullptr};
	static v8::Handle<v8::Value> method_SetPixelFormat(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_SetPixelFormat && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_SetPixelFormat(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				(const PIXELFORMATDESCRIPTOR *)((int64_t)args[2]->NumberValue())/* const PIXELFORMATDESCRIPTOR *ppfd */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY SwapBuffers (HDC hdc);
	typedef BOOL (APIENTRYP PFNSWAPBUFFERSPROC) (HDC hdc);
	PFNSWAPBUFFERSPROC methodp_SwapBuffers{nullptr};
	static v8::Handle<v8::Value> method_SwapBuffers(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_SwapBuffers && args.Length() >= 1){


			BOOL ret = obj->methodp_SwapBuffers(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI void *APIENTRY wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
	typedef void *(APIENTRYP PFNWGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
	PFNWGLALLOCATEMEMORYNVPROC methodp_wglAllocateMemoryNV{nullptr};
	static v8::Handle<v8::Value> method_wglAllocateMemoryNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglAllocateMemoryNV && args.Length() >= 4){
			GLsizei  arg0{ (GLsizei )(args[0]->NumberValue())};
			GLfloat  arg1{ (GLfloat )(args[1]->NumberValue())};
			GLfloat  arg2{ (GLfloat )(args[2]->NumberValue())};
			GLfloat  arg3{ (GLfloat )(args[3]->NumberValue())};

			void *ret = obj->methodp_wglAllocateMemoryNV(
				arg0,
				arg1,
				arg2,
				arg3);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglAssociateImageBufferEventsI3D (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
	typedef BOOL (APIENTRYP PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
	PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC methodp_wglAssociateImageBufferEventsI3D{nullptr};
	static v8::Handle<v8::Value> method_wglAssociateImageBufferEventsI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglAssociateImageBufferEventsI3D && args.Length() >= 5){
			UINT  arg4{ (UINT )(args[4]->Uint32Value())};

			BOOL ret = obj->methodp_wglAssociateImageBufferEventsI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(const HANDLE *)((int64_t)args[1]->NumberValue())/* const HANDLE *pEvent */,
				(const LPVOID *)((int64_t)args[2]->NumberValue())/* const LPVOID *pAddress */,
				(args[3]->IsObject()?((const DWORD *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const DWORD *)((int64_t)args[3]->NumberValue())))/* const DWORD *pSize */,
				arg4);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglBeginFrameTrackingI3D ();
	typedef BOOL (APIENTRYP PFNWGLBEGINFRAMETRACKINGI3DPROC) ();
	PFNWGLBEGINFRAMETRACKINGI3DPROC methodp_wglBeginFrameTrackingI3D{nullptr};
	static v8::Handle<v8::Value> method_wglBeginFrameTrackingI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBeginFrameTrackingI3D && args.Length() >= 0){


			BOOL ret = obj->methodp_wglBeginFrameTrackingI3D();
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI GLboolean APIENTRY wglBindDisplayColorTableEXT (GLushort id);
	typedef GLboolean (APIENTRYP PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
	PFNWGLBINDDISPLAYCOLORTABLEEXTPROC methodp_wglBindDisplayColorTableEXT{nullptr};
	static v8::Handle<v8::Value> method_wglBindDisplayColorTableEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBindDisplayColorTableEXT && args.Length() >= 1){
			GLushort  arg0{ (GLushort )(args[0]->Uint32Value())};

			GLboolean ret = obj->methodp_wglBindDisplayColorTableEXT(
				arg0);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglBindSwapBarrierNV (GLuint group, GLuint barrier);
	typedef BOOL (APIENTRYP PFNWGLBINDSWAPBARRIERNVPROC) (GLuint group, GLuint barrier);
	PFNWGLBINDSWAPBARRIERNVPROC methodp_wglBindSwapBarrierNV{nullptr};
	static v8::Handle<v8::Value> method_wglBindSwapBarrierNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBindSwapBarrierNV && args.Length() >= 2){
			GLuint  arg0{ (GLuint )(args[0]->Uint32Value())};
			GLuint  arg1{ (GLuint )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglBindSwapBarrierNV(
				arg0,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglBindTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
	typedef BOOL (APIENTRYP PFNWGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
	PFNWGLBINDTEXIMAGEARBPROC methodp_wglBindTexImageARB{nullptr};
	static v8::Handle<v8::Value> method_wglBindTexImageARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBindTexImageARB && args.Length() >= 2){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglBindTexImageARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglBindVideoCaptureDeviceNV (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL (APIENTRYP PFNWGLBINDVIDEOCAPTUREDEVICENVPROC) (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
	PFNWGLBINDVIDEOCAPTUREDEVICENVPROC methodp_wglBindVideoCaptureDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglBindVideoCaptureDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBindVideoCaptureDeviceNV && args.Length() >= 2){
			UINT  arg0{ (UINT )(args[0]->Uint32Value())};

			BOOL ret = obj->methodp_wglBindVideoCaptureDeviceNV(
				arg0,
				(HVIDEOINPUTDEVICENV )((int64_t)args[1]->NumberValue())/* HVIDEOINPUTDEVICENV hDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglBindVideoDeviceNV (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
	typedef BOOL (APIENTRYP PFNWGLBINDVIDEODEVICENVPROC) (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
	PFNWGLBINDVIDEODEVICENVPROC methodp_wglBindVideoDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglBindVideoDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBindVideoDeviceNV && args.Length() >= 4){
			unsigned int  arg1{ (unsigned int )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglBindVideoDeviceNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(HVIDEOOUTPUTDEVICENV )((int64_t)args[2]->NumberValue())/* HVIDEOOUTPUTDEVICENV hVideoDevice */,
				(args[3]->IsObject()?((const int *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[3]->NumberValue())))/* const int *piAttribList */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglBindVideoImageNV (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
	typedef BOOL (APIENTRYP PFNWGLBINDVIDEOIMAGENVPROC) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
	PFNWGLBINDVIDEOIMAGENVPROC methodp_wglBindVideoImageNV{nullptr};
	static v8::Handle<v8::Value> method_wglBindVideoImageNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBindVideoImageNV && args.Length() >= 3){
			int  arg2{ (int )(args[2]->Int32Value())};

			BOOL ret = obj->methodp_wglBindVideoImageNV(
				(HPVIDEODEV )((int64_t)args[0]->NumberValue())/* HPVIDEODEV hVideoDevice */,
				(HPBUFFERARB )((int64_t)args[1]->NumberValue())/* HPBUFFERARB hPbuffer */,
				arg2);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI VOID APIENTRY wglBlitContextFramebufferAMD (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	typedef VOID (APIENTRYP PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC) (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC methodp_wglBlitContextFramebufferAMD{nullptr};
	static v8::Handle<v8::Value> method_wglBlitContextFramebufferAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglBlitContextFramebufferAMD && args.Length() >= 11){
			GLint  arg1{ (GLint )(args[1]->Int32Value())};
			GLint  arg2{ (GLint )(args[2]->Int32Value())};
			GLint  arg3{ (GLint )(args[3]->Int32Value())};
			GLint  arg4{ (GLint )(args[4]->Int32Value())};
			GLint  arg5{ (GLint )(args[5]->Int32Value())};
			GLint  arg6{ (GLint )(args[6]->Int32Value())};
			GLint  arg7{ (GLint )(args[7]->Int32Value())};
			GLint  arg8{ (GLint )(args[8]->Int32Value())};
			GLbitfield  arg9{ (GLbitfield )(args[9]->Uint32Value())};
			GLenum  arg10{ (GLenum )(args[10]->Uint32Value())};

			obj->methodp_wglBlitContextFramebufferAMD(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC dstCtx */,
				arg1,
				arg2,
				arg3,
				arg4,
				arg5,
				arg6,
				arg7,
				arg8,
				arg9,
				arg10);
			

			return v8::Undefined();
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglChoosePixelFormatARB (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	typedef BOOL (APIENTRYP PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	PFNWGLCHOOSEPIXELFORMATARBPROC methodp_wglChoosePixelFormatARB{nullptr};
	static v8::Handle<v8::Value> method_wglChoosePixelFormatARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglChoosePixelFormatARB && args.Length() >= 6){
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglChoosePixelFormatARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				(args[1]->IsObject()?((const int *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[1]->NumberValue())))/* const int *piAttribIList */,
				(args[2]->IsObject()?((const FLOAT *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const FLOAT *)((int64_t)args[2]->NumberValue())))/* const FLOAT *pfAttribFList */,
				arg3,
				(args[4]->IsObject()?((int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[4]->NumberValue())))/* int *piFormats */,
				(args[5]->IsObject()?((UINT *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[5]->NumberValue())))/* UINT *nNumFormats */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglChoosePixelFormatEXT (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	typedef BOOL (APIENTRYP PFNWGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	PFNWGLCHOOSEPIXELFORMATEXTPROC methodp_wglChoosePixelFormatEXT{nullptr};
	static v8::Handle<v8::Value> method_wglChoosePixelFormatEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglChoosePixelFormatEXT && args.Length() >= 6){
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglChoosePixelFormatEXT(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				(args[1]->IsObject()?((const int *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[1]->NumberValue())))/* const int *piAttribIList */,
				(args[2]->IsObject()?((const FLOAT *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const FLOAT *)((int64_t)args[2]->NumberValue())))/* const FLOAT *pfAttribFList */,
				arg3,
				(args[4]->IsObject()?((int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[4]->NumberValue())))/* int *piFormats */,
				(args[5]->IsObject()?((UINT *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[5]->NumberValue())))/* UINT *nNumFormats */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglCopyContext (HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask);
	typedef BOOL (APIENTRYP PFNWGLCOPYCONTEXTPROC) (HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask);
	PFNWGLCOPYCONTEXTPROC methodp_wglCopyContext{nullptr};
	static v8::Handle<v8::Value> method_wglCopyContext(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCopyContext && args.Length() >= 3){
			UINT  arg2{ (UINT )(args[2]->Uint32Value())};

			BOOL ret = obj->methodp_wglCopyContext(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC hglrcSrc */,
				(HGLRC )((int64_t)args[1]->NumberValue())/* HGLRC hglrcDst */,
				arg2);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglCopyImageSubDataNV (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	typedef BOOL (APIENTRYP PFNWGLCOPYIMAGESUBDATANVPROC) (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	PFNWGLCOPYIMAGESUBDATANVPROC methodp_wglCopyImageSubDataNV{nullptr};
	static v8::Handle<v8::Value> method_wglCopyImageSubDataNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCopyImageSubDataNV && args.Length() >= 17){
			GLuint  arg1{ (GLuint )(args[1]->Uint32Value())};
			GLenum  arg2{ (GLenum )(args[2]->Uint32Value())};
			GLint  arg3{ (GLint )(args[3]->Int32Value())};
			GLint  arg4{ (GLint )(args[4]->Int32Value())};
			GLint  arg5{ (GLint )(args[5]->Int32Value())};
			GLint  arg6{ (GLint )(args[6]->Int32Value())};
			GLuint  arg8{ (GLuint )(args[8]->Uint32Value())};
			GLenum  arg9{ (GLenum )(args[9]->Uint32Value())};
			GLint  arg10{ (GLint )(args[10]->Int32Value())};
			GLint  arg11{ (GLint )(args[11]->Int32Value())};
			GLint  arg12{ (GLint )(args[12]->Int32Value())};
			GLint  arg13{ (GLint )(args[13]->Int32Value())};
			GLsizei  arg14{ (GLsizei )(args[14]->NumberValue())};
			GLsizei  arg15{ (GLsizei )(args[15]->NumberValue())};
			GLsizei  arg16{ (GLsizei )(args[16]->NumberValue())};

			BOOL ret = obj->methodp_wglCopyImageSubDataNV(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC hSrcRC */,
				arg1,
				arg2,
				arg3,
				arg4,
				arg5,
				arg6,
				(HGLRC )((int64_t)args[7]->NumberValue())/* HGLRC hDstRC */,
				arg8,
				arg9,
				arg10,
				arg11,
				arg12,
				arg13,
				arg14,
				arg15,
				arg16);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HDC APIENTRY wglCreateAffinityDCNV (const HGPUNV *phGpuList);
	typedef HDC (APIENTRYP PFNWGLCREATEAFFINITYDCNVPROC) (const HGPUNV *phGpuList);
	PFNWGLCREATEAFFINITYDCNVPROC methodp_wglCreateAffinityDCNV{nullptr};
	static v8::Handle<v8::Value> method_wglCreateAffinityDCNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateAffinityDCNV && args.Length() >= 1){


			HDC ret = obj->methodp_wglCreateAffinityDCNV(
				(const HGPUNV *)((int64_t)args[0]->NumberValue())/* const HGPUNV *phGpuList */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglCreateAssociatedContextAMD (UINT id);
	typedef HGLRC (APIENTRYP PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC) (UINT id);
	PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC methodp_wglCreateAssociatedContextAMD{nullptr};
	static v8::Handle<v8::Value> method_wglCreateAssociatedContextAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateAssociatedContextAMD && args.Length() >= 1){
			UINT  arg0{ (UINT )(args[0]->Uint32Value())};

			HGLRC ret = obj->methodp_wglCreateAssociatedContextAMD(
				arg0);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglCreateAssociatedContextAttribsAMD (UINT id, HGLRC hShareContext, const int *attribList);
	typedef HGLRC (APIENTRYP PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC) (UINT id, HGLRC hShareContext, const int *attribList);
	PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC methodp_wglCreateAssociatedContextAttribsAMD{nullptr};
	static v8::Handle<v8::Value> method_wglCreateAssociatedContextAttribsAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateAssociatedContextAttribsAMD && args.Length() >= 3){
			UINT  arg0{ (UINT )(args[0]->Uint32Value())};

			HGLRC ret = obj->methodp_wglCreateAssociatedContextAttribsAMD(
				arg0,
				(HGLRC )((int64_t)args[1]->NumberValue())/* HGLRC hShareContext */,
				(args[2]->IsObject()?((const int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[2]->NumberValue())))/* const int *attribList */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HANDLE APIENTRY wglCreateBufferRegionARB (HDC hDC, int iLayerPlane, UINT uType);
	typedef HANDLE (APIENTRYP PFNWGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
	PFNWGLCREATEBUFFERREGIONARBPROC methodp_wglCreateBufferRegionARB{nullptr};
	static v8::Handle<v8::Value> method_wglCreateBufferRegionARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateBufferRegionARB && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};
			UINT  arg2{ (UINT )(args[2]->Uint32Value())};

			HANDLE ret = obj->methodp_wglCreateBufferRegionARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglCreateContext (HDC hDc);
	typedef HGLRC (APIENTRYP PFNWGLCREATECONTEXTPROC) (HDC hDc);
	PFNWGLCREATECONTEXTPROC methodp_wglCreateContext{nullptr};
	static v8::Handle<v8::Value> method_wglCreateContext(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateContext && args.Length() >= 1){


			HGLRC ret = obj->methodp_wglCreateContext(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglCreateContextAttribsARB (HDC hDC, HGLRC hShareContext, const int *attribList);
	typedef HGLRC (APIENTRYP PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int *attribList);
	PFNWGLCREATECONTEXTATTRIBSARBPROC methodp_wglCreateContextAttribsARB{nullptr};
	static v8::Handle<v8::Value> method_wglCreateContextAttribsARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateContextAttribsARB && args.Length() >= 3){


			HGLRC ret = obj->methodp_wglCreateContextAttribsARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(HGLRC )((int64_t)args[1]->NumberValue())/* HGLRC hShareContext */,
				(args[2]->IsObject()?((const int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[2]->NumberValue())))/* const int *attribList */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI GLboolean APIENTRY wglCreateDisplayColorTableEXT (GLushort id);
	typedef GLboolean (APIENTRYP PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
	PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC methodp_wglCreateDisplayColorTableEXT{nullptr};
	static v8::Handle<v8::Value> method_wglCreateDisplayColorTableEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateDisplayColorTableEXT && args.Length() >= 1){
			GLushort  arg0{ (GLushort )(args[0]->Uint32Value())};

			GLboolean ret = obj->methodp_wglCreateDisplayColorTableEXT(
				arg0);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI LPVOID APIENTRY wglCreateImageBufferI3D (HDC hDC, DWORD dwSize, UINT uFlags);
	typedef LPVOID (APIENTRYP PFNWGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
	PFNWGLCREATEIMAGEBUFFERI3DPROC methodp_wglCreateImageBufferI3D{nullptr};
	static v8::Handle<v8::Value> method_wglCreateImageBufferI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateImageBufferI3D && args.Length() >= 3){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			UINT  arg2{ (UINT )(args[2]->Uint32Value())};

			LPVOID ret = obj->methodp_wglCreateImageBufferI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglCreateLayerContext (HDC hDc, int level);
	typedef HGLRC (APIENTRYP PFNWGLCREATELAYERCONTEXTPROC) (HDC hDc, int level);
	PFNWGLCREATELAYERCONTEXTPROC methodp_wglCreateLayerContext{nullptr};
	static v8::Handle<v8::Value> method_wglCreateLayerContext(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreateLayerContext && args.Length() >= 2){
			int  arg1{ (int )(args[1]->Int32Value())};

			HGLRC ret = obj->methodp_wglCreateLayerContext(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				arg1);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HPBUFFERARB APIENTRY wglCreatePbufferARB (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	typedef HPBUFFERARB (APIENTRYP PFNWGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	PFNWGLCREATEPBUFFERARBPROC methodp_wglCreatePbufferARB{nullptr};
	static v8::Handle<v8::Value> method_wglCreatePbufferARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreatePbufferARB && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			int  arg3{ (int )(args[3]->Int32Value())};

			HPBUFFERARB ret = obj->methodp_wglCreatePbufferARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((const int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[4]->NumberValue())))/* const int *piAttribList */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HPBUFFEREXT APIENTRY wglCreatePbufferEXT (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	typedef HPBUFFEREXT (APIENTRYP PFNWGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	PFNWGLCREATEPBUFFEREXTPROC methodp_wglCreatePbufferEXT{nullptr};
	static v8::Handle<v8::Value> method_wglCreatePbufferEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglCreatePbufferEXT && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			int  arg3{ (int )(args[3]->Int32Value())};

			HPBUFFEREXT ret = obj->methodp_wglCreatePbufferEXT(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((const int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[4]->NumberValue())))/* const int *piAttribList */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDelayBeforeSwapNV (HDC hDC, GLfloat seconds);
	typedef BOOL (APIENTRYP PFNWGLDELAYBEFORESWAPNVPROC) (HDC hDC, GLfloat seconds);
	PFNWGLDELAYBEFORESWAPNVPROC methodp_wglDelayBeforeSwapNV{nullptr};
	static v8::Handle<v8::Value> method_wglDelayBeforeSwapNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDelayBeforeSwapNV && args.Length() >= 2){
			GLfloat  arg1{ (GLfloat )(args[1]->NumberValue())};

			BOOL ret = obj->methodp_wglDelayBeforeSwapNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDeleteAssociatedContextAMD (HGLRC hglrc);
	typedef BOOL (APIENTRYP PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC) (HGLRC hglrc);
	PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC methodp_wglDeleteAssociatedContextAMD{nullptr};
	static v8::Handle<v8::Value> method_wglDeleteAssociatedContextAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDeleteAssociatedContextAMD && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDeleteAssociatedContextAMD(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC hglrc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI VOID APIENTRY wglDeleteBufferRegionARB (HANDLE hRegion);
	typedef VOID (APIENTRYP PFNWGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
	PFNWGLDELETEBUFFERREGIONARBPROC methodp_wglDeleteBufferRegionARB{nullptr};
	static v8::Handle<v8::Value> method_wglDeleteBufferRegionARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDeleteBufferRegionARB && args.Length() >= 1){


			obj->methodp_wglDeleteBufferRegionARB(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hRegion */);
			

			return v8::Undefined();
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDeleteContext (HGLRC oldContext);
	typedef BOOL (APIENTRYP PFNWGLDELETECONTEXTPROC) (HGLRC oldContext);
	PFNWGLDELETECONTEXTPROC methodp_wglDeleteContext{nullptr};
	static v8::Handle<v8::Value> method_wglDeleteContext(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDeleteContext && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDeleteContext(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC oldContext */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDeleteDCNV (HDC hdc);
	typedef BOOL (APIENTRYP PFNWGLDELETEDCNVPROC) (HDC hdc);
	PFNWGLDELETEDCNVPROC methodp_wglDeleteDCNV{nullptr};
	static v8::Handle<v8::Value> method_wglDeleteDCNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDeleteDCNV && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDeleteDCNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDescribeLayerPlane (HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR *plpd);
	typedef BOOL (APIENTRYP PFNWGLDESCRIBELAYERPLANEPROC) (HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR *plpd);
	PFNWGLDESCRIBELAYERPLANEPROC methodp_wglDescribeLayerPlane{nullptr};
	static v8::Handle<v8::Value> method_wglDescribeLayerPlane(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDescribeLayerPlane && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglDescribeLayerPlane(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				arg1,
				arg2,
				arg3,
				(const LAYERPLANEDESCRIPTOR *)((int64_t)args[4]->NumberValue())/* const LAYERPLANEDESCRIPTOR *plpd */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI VOID APIENTRY wglDestroyDisplayColorTableEXT (GLushort id);
	typedef VOID (APIENTRYP PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
	PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC methodp_wglDestroyDisplayColorTableEXT{nullptr};
	static v8::Handle<v8::Value> method_wglDestroyDisplayColorTableEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDestroyDisplayColorTableEXT && args.Length() >= 1){
			GLushort  arg0{ (GLushort )(args[0]->Uint32Value())};

			obj->methodp_wglDestroyDisplayColorTableEXT(
				arg0);
			

			return v8::Undefined();
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDestroyImageBufferI3D (HDC hDC, LPVOID pAddress);
	typedef BOOL (APIENTRYP PFNWGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
	PFNWGLDESTROYIMAGEBUFFERI3DPROC methodp_wglDestroyImageBufferI3D{nullptr};
	static v8::Handle<v8::Value> method_wglDestroyImageBufferI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDestroyImageBufferI3D && args.Length() >= 2){
			LPVOID  arg1{ (LPVOID )((int64_t)args[1]->NumberValue())};

			BOOL ret = obj->methodp_wglDestroyImageBufferI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((LPVOID )args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):arg1)/* LPVOID pAddress */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDestroyPbufferARB (HPBUFFERARB hPbuffer);
	typedef BOOL (APIENTRYP PFNWGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
	PFNWGLDESTROYPBUFFERARBPROC methodp_wglDestroyPbufferARB{nullptr};
	static v8::Handle<v8::Value> method_wglDestroyPbufferARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDestroyPbufferARB && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDestroyPbufferARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDestroyPbufferEXT (HPBUFFEREXT hPbuffer);
	typedef BOOL (APIENTRYP PFNWGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
	PFNWGLDESTROYPBUFFEREXTPROC methodp_wglDestroyPbufferEXT{nullptr};
	static v8::Handle<v8::Value> method_wglDestroyPbufferEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDestroyPbufferEXT && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDestroyPbufferEXT(
				(HPBUFFEREXT )((int64_t)args[0]->NumberValue())/* HPBUFFEREXT hPbuffer */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDisableFrameLockI3D ();
	typedef BOOL (APIENTRYP PFNWGLDISABLEFRAMELOCKI3DPROC) ();
	PFNWGLDISABLEFRAMELOCKI3DPROC methodp_wglDisableFrameLockI3D{nullptr};
	static v8::Handle<v8::Value> method_wglDisableFrameLockI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDisableFrameLockI3D && args.Length() >= 0){


			BOOL ret = obj->methodp_wglDisableFrameLockI3D();
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDisableGenlockI3D (HDC hDC);
	typedef BOOL (APIENTRYP PFNWGLDISABLEGENLOCKI3DPROC) (HDC hDC);
	PFNWGLDISABLEGENLOCKI3DPROC methodp_wglDisableGenlockI3D{nullptr};
	static v8::Handle<v8::Value> method_wglDisableGenlockI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDisableGenlockI3D && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDisableGenlockI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDXCloseDeviceNV (HANDLE hDevice);
	typedef BOOL (APIENTRYP PFNWGLDXCLOSEDEVICENVPROC) (HANDLE hDevice);
	PFNWGLDXCLOSEDEVICENVPROC methodp_wglDXCloseDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXCloseDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXCloseDeviceNV && args.Length() >= 1){


			BOOL ret = obj->methodp_wglDXCloseDeviceNV(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDXLockObjectsNV (HANDLE hDevice, GLint count, HANDLE *hObjects);
	typedef BOOL (APIENTRYP PFNWGLDXLOCKOBJECTSNVPROC) (HANDLE hDevice, GLint count, HANDLE *hObjects);
	PFNWGLDXLOCKOBJECTSNVPROC methodp_wglDXLockObjectsNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXLockObjectsNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXLockObjectsNV && args.Length() >= 3){
			GLint  arg1{ (GLint )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglDXLockObjectsNV(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hDevice */,
				arg1,
				(HANDLE *)((int64_t)args[2]->NumberValue())/* HANDLE *hObjects */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDXObjectAccessNV (HANDLE hObject, GLenum access);
	typedef BOOL (APIENTRYP PFNWGLDXOBJECTACCESSNVPROC) (HANDLE hObject, GLenum access);
	PFNWGLDXOBJECTACCESSNVPROC methodp_wglDXObjectAccessNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXObjectAccessNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXObjectAccessNV && args.Length() >= 2){
			GLenum  arg1{ (GLenum )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglDXObjectAccessNV(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hObject */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HANDLE APIENTRY wglDXOpenDeviceNV (void *dxDevice);
	typedef HANDLE (APIENTRYP PFNWGLDXOPENDEVICENVPROC) (void *dxDevice);
	PFNWGLDXOPENDEVICENVPROC methodp_wglDXOpenDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXOpenDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXOpenDeviceNV && args.Length() >= 1){
			void * arg0{ (void *)((int64_t)args[0]->NumberValue())};

			HANDLE ret = obj->methodp_wglDXOpenDeviceNV(
				(args[0]->IsObject()?((void *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):arg0)/* void *dxDevice */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HANDLE APIENTRY wglDXRegisterObjectNV (HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
	typedef HANDLE (APIENTRYP PFNWGLDXREGISTEROBJECTNVPROC) (HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
	PFNWGLDXREGISTEROBJECTNVPROC methodp_wglDXRegisterObjectNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXRegisterObjectNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXRegisterObjectNV && args.Length() >= 5){
			void * arg1{ (void *)((int64_t)args[1]->NumberValue())};
			GLuint  arg2{ (GLuint )(args[2]->Uint32Value())};
			GLenum  arg3{ (GLenum )(args[3]->Uint32Value())};
			GLenum  arg4{ (GLenum )(args[4]->Uint32Value())};

			HANDLE ret = obj->methodp_wglDXRegisterObjectNV(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hDevice */,
				(args[1]->IsObject()?((void *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):arg1)/* void *dxObject */,
				arg2,
				arg3,
				arg4);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDXSetResourceShareHandleNV (void *dxObject, HANDLE shareHandle);
	typedef BOOL (APIENTRYP PFNWGLDXSETRESOURCESHAREHANDLENVPROC) (void *dxObject, HANDLE shareHandle);
	PFNWGLDXSETRESOURCESHAREHANDLENVPROC methodp_wglDXSetResourceShareHandleNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXSetResourceShareHandleNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXSetResourceShareHandleNV && args.Length() >= 2){
			void * arg0{ (void *)((int64_t)args[0]->NumberValue())};

			BOOL ret = obj->methodp_wglDXSetResourceShareHandleNV(
				(args[0]->IsObject()?((void *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):arg0)/* void *dxObject */,
				(HANDLE )((int64_t)args[1]->NumberValue())/* HANDLE shareHandle */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDXUnlockObjectsNV (HANDLE hDevice, GLint count, HANDLE *hObjects);
	typedef BOOL (APIENTRYP PFNWGLDXUNLOCKOBJECTSNVPROC) (HANDLE hDevice, GLint count, HANDLE *hObjects);
	PFNWGLDXUNLOCKOBJECTSNVPROC methodp_wglDXUnlockObjectsNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXUnlockObjectsNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXUnlockObjectsNV && args.Length() >= 3){
			GLint  arg1{ (GLint )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglDXUnlockObjectsNV(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hDevice */,
				arg1,
				(HANDLE *)((int64_t)args[2]->NumberValue())/* HANDLE *hObjects */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglDXUnregisterObjectNV (HANDLE hDevice, HANDLE hObject);
	typedef BOOL (APIENTRYP PFNWGLDXUNREGISTEROBJECTNVPROC) (HANDLE hDevice, HANDLE hObject);
	PFNWGLDXUNREGISTEROBJECTNVPROC methodp_wglDXUnregisterObjectNV{nullptr};
	static v8::Handle<v8::Value> method_wglDXUnregisterObjectNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglDXUnregisterObjectNV && args.Length() >= 2){


			BOOL ret = obj->methodp_wglDXUnregisterObjectNV(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hDevice */,
				(HANDLE )((int64_t)args[1]->NumberValue())/* HANDLE hObject */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglEnableFrameLockI3D ();
	typedef BOOL (APIENTRYP PFNWGLENABLEFRAMELOCKI3DPROC) ();
	PFNWGLENABLEFRAMELOCKI3DPROC methodp_wglEnableFrameLockI3D{nullptr};
	static v8::Handle<v8::Value> method_wglEnableFrameLockI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnableFrameLockI3D && args.Length() >= 0){


			BOOL ret = obj->methodp_wglEnableFrameLockI3D();
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglEnableGenlockI3D (HDC hDC);
	typedef BOOL (APIENTRYP PFNWGLENABLEGENLOCKI3DPROC) (HDC hDC);
	PFNWGLENABLEGENLOCKI3DPROC methodp_wglEnableGenlockI3D{nullptr};
	static v8::Handle<v8::Value> method_wglEnableGenlockI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnableGenlockI3D && args.Length() >= 1){


			BOOL ret = obj->methodp_wglEnableGenlockI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglEndFrameTrackingI3D ();
	typedef BOOL (APIENTRYP PFNWGLENDFRAMETRACKINGI3DPROC) ();
	PFNWGLENDFRAMETRACKINGI3DPROC methodp_wglEndFrameTrackingI3D{nullptr};
	static v8::Handle<v8::Value> method_wglEndFrameTrackingI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEndFrameTrackingI3D && args.Length() >= 0){


			BOOL ret = obj->methodp_wglEndFrameTrackingI3D();
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI UINT APIENTRY wglEnumerateVideoCaptureDevicesNV (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
	typedef UINT (APIENTRYP PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC) (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
	PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC methodp_wglEnumerateVideoCaptureDevicesNV{nullptr};
	static v8::Handle<v8::Value> method_wglEnumerateVideoCaptureDevicesNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnumerateVideoCaptureDevicesNV && args.Length() >= 2){


			UINT ret = obj->methodp_wglEnumerateVideoCaptureDevicesNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				(HVIDEOINPUTDEVICENV *)((int64_t)args[1]->NumberValue())/* HVIDEOINPUTDEVICENV *phDeviceList */);
			

			return scope.Close(v8::Uint32::NewFromUnsigned(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY wglEnumerateVideoDevicesNV (HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
	typedef int (APIENTRYP PFNWGLENUMERATEVIDEODEVICESNVPROC) (HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
	PFNWGLENUMERATEVIDEODEVICESNVPROC methodp_wglEnumerateVideoDevicesNV{nullptr};
	static v8::Handle<v8::Value> method_wglEnumerateVideoDevicesNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnumerateVideoDevicesNV && args.Length() >= 2){


			int ret = obj->methodp_wglEnumerateVideoDevicesNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(HVIDEOOUTPUTDEVICENV *)((int64_t)args[1]->NumberValue())/* HVIDEOOUTPUTDEVICENV *phDeviceList */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglEnumGpuDevicesNV (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
	typedef BOOL (APIENTRYP PFNWGLENUMGPUDEVICESNVPROC) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
	PFNWGLENUMGPUDEVICESNVPROC methodp_wglEnumGpuDevicesNV{nullptr};
	static v8::Handle<v8::Value> method_wglEnumGpuDevicesNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnumGpuDevicesNV && args.Length() >= 3){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglEnumGpuDevicesNV(
				(HGPUNV )((int64_t)args[0]->NumberValue())/* HGPUNV hGpu */,
				arg1,
				(PGPU_DEVICE )((int64_t)args[2]->NumberValue())/* PGPU_DEVICE lpGpuDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglEnumGpusFromAffinityDCNV (HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
	typedef BOOL (APIENTRYP PFNWGLENUMGPUSFROMAFFINITYDCNVPROC) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
	PFNWGLENUMGPUSFROMAFFINITYDCNVPROC methodp_wglEnumGpusFromAffinityDCNV{nullptr};
	static v8::Handle<v8::Value> method_wglEnumGpusFromAffinityDCNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnumGpusFromAffinityDCNV && args.Length() >= 3){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglEnumGpusFromAffinityDCNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hAffinityDC */,
				arg1,
				(HGPUNV *)((int64_t)args[2]->NumberValue())/* HGPUNV *hGpu */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglEnumGpusNV (UINT iGpuIndex, HGPUNV *phGpu);
	typedef BOOL (APIENTRYP PFNWGLENUMGPUSNVPROC) (UINT iGpuIndex, HGPUNV *phGpu);
	PFNWGLENUMGPUSNVPROC methodp_wglEnumGpusNV{nullptr};
	static v8::Handle<v8::Value> method_wglEnumGpusNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglEnumGpusNV && args.Length() >= 2){
			UINT  arg0{ (UINT )(args[0]->Uint32Value())};

			BOOL ret = obj->methodp_wglEnumGpusNV(
				arg0,
				(HGPUNV *)((int64_t)args[1]->NumberValue())/* HGPUNV *phGpu */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI void APIENTRY wglFreeMemoryNV (void *pointer);
	typedef void (APIENTRYP PFNWGLFREEMEMORYNVPROC) (void *pointer);
	PFNWGLFREEMEMORYNVPROC methodp_wglFreeMemoryNV{nullptr};
	static v8::Handle<v8::Value> method_wglFreeMemoryNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglFreeMemoryNV && args.Length() >= 1){
			void * arg0{ (void *)((int64_t)args[0]->NumberValue())};

			obj->methodp_wglFreeMemoryNV(
				(args[0]->IsObject()?((void *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):arg0)/* void *pointer */);
			

			return v8::Undefined();
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGenlockSampleRateI3D (HDC hDC, UINT uRate);
	typedef BOOL (APIENTRYP PFNWGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
	PFNWGLGENLOCKSAMPLERATEI3DPROC methodp_wglGenlockSampleRateI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGenlockSampleRateI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGenlockSampleRateI3D && args.Length() >= 2){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglGenlockSampleRateI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGenlockSourceDelayI3D (HDC hDC, UINT uDelay);
	typedef BOOL (APIENTRYP PFNWGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
	PFNWGLGENLOCKSOURCEDELAYI3DPROC methodp_wglGenlockSourceDelayI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGenlockSourceDelayI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGenlockSourceDelayI3D && args.Length() >= 2){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglGenlockSourceDelayI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGenlockSourceEdgeI3D (HDC hDC, UINT uEdge);
	typedef BOOL (APIENTRYP PFNWGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
	PFNWGLGENLOCKSOURCEEDGEI3DPROC methodp_wglGenlockSourceEdgeI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGenlockSourceEdgeI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGenlockSourceEdgeI3D && args.Length() >= 2){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglGenlockSourceEdgeI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGenlockSourceI3D (HDC hDC, UINT uSource);
	typedef BOOL (APIENTRYP PFNWGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
	PFNWGLGENLOCKSOURCEI3DPROC methodp_wglGenlockSourceI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGenlockSourceI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGenlockSourceI3D && args.Length() >= 2){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglGenlockSourceI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI UINT APIENTRY wglGetContextGPUIDAMD (HGLRC hglrc);
	typedef UINT (APIENTRYP PFNWGLGETCONTEXTGPUIDAMDPROC) (HGLRC hglrc);
	PFNWGLGETCONTEXTGPUIDAMDPROC methodp_wglGetContextGPUIDAMD{nullptr};
	static v8::Handle<v8::Value> method_wglGetContextGPUIDAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetContextGPUIDAMD && args.Length() >= 1){


			UINT ret = obj->methodp_wglGetContextGPUIDAMD(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC hglrc */);
			

			return scope.Close(v8::Uint32::NewFromUnsigned(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglGetCurrentAssociatedContextAMD ();
	typedef HGLRC (APIENTRYP PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC) ();
	PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC methodp_wglGetCurrentAssociatedContextAMD{nullptr};
	static v8::Handle<v8::Value> method_wglGetCurrentAssociatedContextAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetCurrentAssociatedContextAMD && args.Length() >= 0){


			HGLRC ret = obj->methodp_wglGetCurrentAssociatedContextAMD();
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HGLRC APIENTRY wglGetCurrentContext ();
	typedef HGLRC (APIENTRYP PFNWGLGETCURRENTCONTEXTPROC) ();
	PFNWGLGETCURRENTCONTEXTPROC methodp_wglGetCurrentContext{nullptr};
	static v8::Handle<v8::Value> method_wglGetCurrentContext(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetCurrentContext && args.Length() >= 0){


			HGLRC ret = obj->methodp_wglGetCurrentContext();
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HDC APIENTRY wglGetCurrentDC ();
	typedef HDC (APIENTRYP PFNWGLGETCURRENTDCPROC) ();
	PFNWGLGETCURRENTDCPROC methodp_wglGetCurrentDC{nullptr};
	static v8::Handle<v8::Value> method_wglGetCurrentDC(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetCurrentDC && args.Length() >= 0){


			HDC ret = obj->methodp_wglGetCurrentDC();
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HDC APIENTRY wglGetCurrentReadDCARB ();
	typedef HDC (APIENTRYP PFNWGLGETCURRENTREADDCARBPROC) ();
	PFNWGLGETCURRENTREADDCARBPROC methodp_wglGetCurrentReadDCARB{nullptr};
	static v8::Handle<v8::Value> method_wglGetCurrentReadDCARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetCurrentReadDCARB && args.Length() >= 0){


			HDC ret = obj->methodp_wglGetCurrentReadDCARB();
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HDC APIENTRY wglGetCurrentReadDCEXT ();
	typedef HDC (APIENTRYP PFNWGLGETCURRENTREADDCEXTPROC) ();
	PFNWGLGETCURRENTREADDCEXTPROC methodp_wglGetCurrentReadDCEXT{nullptr};
	static v8::Handle<v8::Value> method_wglGetCurrentReadDCEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetCurrentReadDCEXT && args.Length() >= 0){


			HDC ret = obj->methodp_wglGetCurrentReadDCEXT();
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI PROC APIENTRY wglGetDefaultProcAddress (LPCSTR lpszProc);
	typedef PROC (APIENTRYP PFNWGLGETDEFAULTPROCADDRESSPROC) (LPCSTR lpszProc);
	PFNWGLGETDEFAULTPROCADDRESSPROC methodp_wglGetDefaultProcAddress{nullptr};
	static v8::Handle<v8::Value> method_wglGetDefaultProcAddress(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetDefaultProcAddress && args.Length() >= 1){


			PROC ret = obj->methodp_wglGetDefaultProcAddress(
				(LPCSTR )(v8::String::Utf8Value(args[0]).operator*())/* LPCSTR lpszProc */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetDigitalVideoParametersI3D (HDC hDC, int iAttribute, int *piValue);
	typedef BOOL (APIENTRYP PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
	PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC methodp_wglGetDigitalVideoParametersI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetDigitalVideoParametersI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetDigitalVideoParametersI3D && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglGetDigitalVideoParametersI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(args[2]->IsObject()?((int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[2]->NumberValue())))/* int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI UINT APIENTRY GetEnhMetaFilePixelFormat (HENHMETAFILE hemf, const PIXELFORMATDESCRIPTOR *ppfd);
	typedef UINT (APIENTRYP PFNGETENHMETAFILEPIXELFORMATPROC) (HENHMETAFILE hemf, const PIXELFORMATDESCRIPTOR *ppfd);
	PFNGETENHMETAFILEPIXELFORMATPROC methodp_GetEnhMetaFilePixelFormat{nullptr};
	static v8::Handle<v8::Value> method_GetEnhMetaFilePixelFormat(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_GetEnhMetaFilePixelFormat && args.Length() >= 2){


			UINT ret = obj->methodp_GetEnhMetaFilePixelFormat(
				(HENHMETAFILE )((int64_t)args[0]->NumberValue())/* HENHMETAFILE hemf */,
				(const PIXELFORMATDESCRIPTOR *)((int64_t)args[1]->NumberValue())/* const PIXELFORMATDESCRIPTOR *ppfd */);
			

			return scope.Close(v8::Uint32::NewFromUnsigned(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI const char *APIENTRY wglGetExtensionsStringARB (HDC hdc);
	typedef const char *(APIENTRYP PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
	PFNWGLGETEXTENSIONSSTRINGARBPROC methodp_wglGetExtensionsStringARB{nullptr};
	static v8::Handle<v8::Value> method_wglGetExtensionsStringARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetExtensionsStringARB && args.Length() >= 1){


			const char *ret = obj->methodp_wglGetExtensionsStringARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */);
			

			return ret?scope.Close(v8::String::New((const char *)ret)):v8::Undefined();
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI const char *APIENTRY wglGetExtensionsStringEXT ();
	typedef const char *(APIENTRYP PFNWGLGETEXTENSIONSSTRINGEXTPROC) ();
	PFNWGLGETEXTENSIONSSTRINGEXTPROC methodp_wglGetExtensionsStringEXT{nullptr};
	static v8::Handle<v8::Value> method_wglGetExtensionsStringEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetExtensionsStringEXT && args.Length() >= 0){


			const char *ret = obj->methodp_wglGetExtensionsStringEXT();
			

			return ret?scope.Close(v8::String::New((const char *)ret)):v8::Undefined();
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetFrameUsageI3D (float *pUsage);
	typedef BOOL (APIENTRYP PFNWGLGETFRAMEUSAGEI3DPROC) (float *pUsage);
	PFNWGLGETFRAMEUSAGEI3DPROC methodp_wglGetFrameUsageI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetFrameUsageI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetFrameUsageI3D && args.Length() >= 1){


			BOOL ret = obj->methodp_wglGetFrameUsageI3D(
				(args[0]->IsObject()?((float *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):((float *)((int64_t)args[0]->NumberValue())))/* float *pUsage */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetGammaTableI3D (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
	typedef BOOL (APIENTRYP PFNWGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
	PFNWGLGETGAMMATABLEI3DPROC methodp_wglGetGammaTableI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetGammaTableI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGammaTableI3D && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglGetGammaTableI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(args[2]->IsObject()?((USHORT *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((USHORT *)((int64_t)args[2]->NumberValue())))/* USHORT *puRed */,
				(args[3]->IsObject()?((USHORT *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((USHORT *)((int64_t)args[3]->NumberValue())))/* USHORT *puGreen */,
				(args[4]->IsObject()?((USHORT *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((USHORT *)((int64_t)args[4]->NumberValue())))/* USHORT *puBlue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetGammaTableParametersI3D (HDC hDC, int iAttribute, int *piValue);
	typedef BOOL (APIENTRYP PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
	PFNWGLGETGAMMATABLEPARAMETERSI3DPROC methodp_wglGetGammaTableParametersI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetGammaTableParametersI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGammaTableParametersI3D && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglGetGammaTableParametersI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(args[2]->IsObject()?((int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[2]->NumberValue())))/* int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetGenlockSampleRateI3D (HDC hDC, UINT *uRate);
	typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT *uRate);
	PFNWGLGETGENLOCKSAMPLERATEI3DPROC methodp_wglGetGenlockSampleRateI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetGenlockSampleRateI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGenlockSampleRateI3D && args.Length() >= 2){


			BOOL ret = obj->methodp_wglGetGenlockSampleRateI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((UINT *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[1]->NumberValue())))/* UINT *uRate */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetGenlockSourceDelayI3D (HDC hDC, UINT *uDelay);
	typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT *uDelay);
	PFNWGLGETGENLOCKSOURCEDELAYI3DPROC methodp_wglGetGenlockSourceDelayI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetGenlockSourceDelayI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGenlockSourceDelayI3D && args.Length() >= 2){


			BOOL ret = obj->methodp_wglGetGenlockSourceDelayI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((UINT *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[1]->NumberValue())))/* UINT *uDelay */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetGenlockSourceEdgeI3D (HDC hDC, UINT *uEdge);
	typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT *uEdge);
	PFNWGLGETGENLOCKSOURCEEDGEI3DPROC methodp_wglGetGenlockSourceEdgeI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetGenlockSourceEdgeI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGenlockSourceEdgeI3D && args.Length() >= 2){


			BOOL ret = obj->methodp_wglGetGenlockSourceEdgeI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((UINT *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[1]->NumberValue())))/* UINT *uEdge */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetGenlockSourceI3D (HDC hDC, UINT *uSource);
	typedef BOOL (APIENTRYP PFNWGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT *uSource);
	PFNWGLGETGENLOCKSOURCEI3DPROC methodp_wglGetGenlockSourceI3D{nullptr};
	static v8::Handle<v8::Value> method_wglGetGenlockSourceI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGenlockSourceI3D && args.Length() >= 2){


			BOOL ret = obj->methodp_wglGetGenlockSourceI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((UINT *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[1]->NumberValue())))/* UINT *uSource */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI UINT APIENTRY wglGetGPUIDsAMD (UINT maxCount, UINT *ids);
	typedef UINT (APIENTRYP PFNWGLGETGPUIDSAMDPROC) (UINT maxCount, UINT *ids);
	PFNWGLGETGPUIDSAMDPROC methodp_wglGetGPUIDsAMD{nullptr};
	static v8::Handle<v8::Value> method_wglGetGPUIDsAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGPUIDsAMD && args.Length() >= 2){
			UINT  arg0{ (UINT )(args[0]->Uint32Value())};

			UINT ret = obj->methodp_wglGetGPUIDsAMD(
				arg0,
				(args[1]->IsObject()?((UINT *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[1]->NumberValue())))/* UINT *ids */);
			

			return scope.Close(v8::Uint32::NewFromUnsigned(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI INT APIENTRY wglGetGPUInfoAMD (UINT id, int property, GLenum dataType, UINT size, void *data);
	typedef INT (APIENTRYP PFNWGLGETGPUINFOAMDPROC) (UINT id, int property, GLenum dataType, UINT size, void *data);
	PFNWGLGETGPUINFOAMDPROC methodp_wglGetGPUInfoAMD{nullptr};
	static v8::Handle<v8::Value> method_wglGetGPUInfoAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetGPUInfoAMD && args.Length() >= 5){
			UINT  arg0{ (UINT )(args[0]->Uint32Value())};
			int  arg1{ (int )(args[1]->Int32Value())};
			GLenum  arg2{ (GLenum )(args[2]->Uint32Value())};
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};
			void * arg4{ (void *)((int64_t)args[4]->NumberValue())};

			INT ret = obj->methodp_wglGetGPUInfoAMD(
				arg0,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((void *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):arg4)/* void *data */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY wglGetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF *pcr);
	typedef int (APIENTRYP PFNWGLGETLAYERPALETTEENTRIESPROC) (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF *pcr);
	PFNWGLGETLAYERPALETTEENTRIESPROC methodp_wglGetLayerPaletteEntries{nullptr};
	static v8::Handle<v8::Value> method_wglGetLayerPaletteEntries(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetLayerPaletteEntries && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			int  arg3{ (int )(args[3]->Int32Value())};

			int ret = obj->methodp_wglGetLayerPaletteEntries(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((const COLORREF *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const COLORREF *)((int64_t)args[4]->NumberValue())))/* const COLORREF *pcr */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetMscRateOML (HDC hdc, INT32 *numerator, INT32 *denominator);
	typedef BOOL (APIENTRYP PFNWGLGETMSCRATEOMLPROC) (HDC hdc, INT32 *numerator, INT32 *denominator);
	PFNWGLGETMSCRATEOMLPROC methodp_wglGetMscRateOML{nullptr};
	static v8::Handle<v8::Value> method_wglGetMscRateOML(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetMscRateOML && args.Length() >= 3){


			BOOL ret = obj->methodp_wglGetMscRateOML(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				(args[1]->IsObject()?((INT32 *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT32 *)((int64_t)args[1]->NumberValue())))/* INT32 *numerator */,
				(args[2]->IsObject()?((INT32 *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT32 *)((int64_t)args[2]->NumberValue())))/* INT32 *denominator */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HDC APIENTRY wglGetPbufferDCARB (HPBUFFERARB hPbuffer);
	typedef HDC (APIENTRYP PFNWGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
	PFNWGLGETPBUFFERDCARBPROC methodp_wglGetPbufferDCARB{nullptr};
	static v8::Handle<v8::Value> method_wglGetPbufferDCARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetPbufferDCARB && args.Length() >= 1){


			HDC ret = obj->methodp_wglGetPbufferDCARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI HDC APIENTRY wglGetPbufferDCEXT (HPBUFFEREXT hPbuffer);
	typedef HDC (APIENTRYP PFNWGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
	PFNWGLGETPBUFFERDCEXTPROC methodp_wglGetPbufferDCEXT{nullptr};
	static v8::Handle<v8::Value> method_wglGetPbufferDCEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetPbufferDCEXT && args.Length() >= 1){


			HDC ret = obj->methodp_wglGetPbufferDCEXT(
				(HPBUFFEREXT )((int64_t)args[0]->NumberValue())/* HPBUFFEREXT hPbuffer */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetPixelFormatAttribfvARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
	typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
	PFNWGLGETPIXELFORMATATTRIBFVARBPROC methodp_wglGetPixelFormatAttribfvARB{nullptr};
	static v8::Handle<v8::Value> method_wglGetPixelFormatAttribfvARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetPixelFormatAttribfvARB && args.Length() >= 6){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglGetPixelFormatAttribfvARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((const int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[4]->NumberValue())))/* const int *piAttributes */,
				(args[5]->IsObject()?((FLOAT *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((FLOAT *)((int64_t)args[5]->NumberValue())))/* FLOAT *pfValues */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetPixelFormatAttribfvEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
	typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
	PFNWGLGETPIXELFORMATATTRIBFVEXTPROC methodp_wglGetPixelFormatAttribfvEXT{nullptr};
	static v8::Handle<v8::Value> method_wglGetPixelFormatAttribfvEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetPixelFormatAttribfvEXT && args.Length() >= 6){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglGetPixelFormatAttribfvEXT(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[4]->NumberValue())))/* int *piAttributes */,
				(args[5]->IsObject()?((FLOAT *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((FLOAT *)((int64_t)args[5]->NumberValue())))/* FLOAT *pfValues */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetPixelFormatAttribivARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
	typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
	PFNWGLGETPIXELFORMATATTRIBIVARBPROC methodp_wglGetPixelFormatAttribivARB{nullptr};
	static v8::Handle<v8::Value> method_wglGetPixelFormatAttribivARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetPixelFormatAttribivARB && args.Length() >= 6){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglGetPixelFormatAttribivARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((const int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[4]->NumberValue())))/* const int *piAttributes */,
				(args[5]->IsObject()?((int *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[5]->NumberValue())))/* int *piValues */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetPixelFormatAttribivEXT (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
	typedef BOOL (APIENTRYP PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
	PFNWGLGETPIXELFORMATATTRIBIVEXTPROC methodp_wglGetPixelFormatAttribivEXT{nullptr};
	static v8::Handle<v8::Value> method_wglGetPixelFormatAttribivEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetPixelFormatAttribivEXT && args.Length() >= 6){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			UINT  arg3{ (UINT )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglGetPixelFormatAttribivEXT(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((int *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[4]->NumberValue())))/* int *piAttributes */,
				(args[5]->IsObject()?((int *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[5]->NumberValue())))/* int *piValues */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI PROC APIENTRY wglGetProcAddress (LPCSTR lpszProc);
	typedef PROC (APIENTRYP PFNWGLGETPROCADDRESSPROC) (LPCSTR lpszProc);
	PFNWGLGETPROCADDRESSPROC methodp_wglGetProcAddress{nullptr};
	static v8::Handle<v8::Value> method_wglGetProcAddress(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetProcAddress && args.Length() >= 1){


			PROC ret = obj->methodp_wglGetProcAddress(
				(LPCSTR )(v8::String::Utf8Value(args[0]).operator*())/* LPCSTR lpszProc */);
			

			return scope.Close(v8::Number::New((int64_t)ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY wglGetSwapIntervalEXT ();
	typedef int (APIENTRYP PFNWGLGETSWAPINTERVALEXTPROC) ();
	PFNWGLGETSWAPINTERVALEXTPROC methodp_wglGetSwapIntervalEXT{nullptr};
	static v8::Handle<v8::Value> method_wglGetSwapIntervalEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetSwapIntervalEXT && args.Length() >= 0){


			int ret = obj->methodp_wglGetSwapIntervalEXT();
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetSyncValuesOML (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
	typedef BOOL (APIENTRYP PFNWGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
	PFNWGLGETSYNCVALUESOMLPROC methodp_wglGetSyncValuesOML{nullptr};
	static v8::Handle<v8::Value> method_wglGetSyncValuesOML(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetSyncValuesOML && args.Length() >= 4){


			BOOL ret = obj->methodp_wglGetSyncValuesOML(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				(args[1]->IsObject()?((INT64 *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[1]->NumberValue())))/* INT64 *ust */,
				(args[2]->IsObject()?((INT64 *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[2]->NumberValue())))/* INT64 *msc */,
				(args[3]->IsObject()?((INT64 *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[3]->NumberValue())))/* INT64 *sbc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetVideoDeviceNV (HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
	typedef BOOL (APIENTRYP PFNWGLGETVIDEODEVICENVPROC) (HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
	PFNWGLGETVIDEODEVICENVPROC methodp_wglGetVideoDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglGetVideoDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetVideoDeviceNV && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglGetVideoDeviceNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(HPVIDEODEV *)((int64_t)args[2]->NumberValue())/* HPVIDEODEV *hVideoDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglGetVideoInfoNV (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
	typedef BOOL (APIENTRYP PFNWGLGETVIDEOINFONVPROC) (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
	PFNWGLGETVIDEOINFONVPROC methodp_wglGetVideoInfoNV{nullptr};
	static v8::Handle<v8::Value> method_wglGetVideoInfoNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglGetVideoInfoNV && args.Length() >= 3){


			BOOL ret = obj->methodp_wglGetVideoInfoNV(
				(HPVIDEODEV )((int64_t)args[0]->NumberValue())/* HPVIDEODEV hpVideoDevice */,
				(args[1]->IsObject()?((unsigned long *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((unsigned long *)((int64_t)args[1]->NumberValue())))/* unsigned long *pulCounterOutputPbuffer */,
				(args[2]->IsObject()?((unsigned long *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((unsigned long *)((int64_t)args[2]->NumberValue())))/* unsigned long *pulCounterOutputVideo */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglIsEnabledFrameLockI3D (BOOL *pFlag);
	typedef BOOL (APIENTRYP PFNWGLISENABLEDFRAMELOCKI3DPROC) (BOOL *pFlag);
	PFNWGLISENABLEDFRAMELOCKI3DPROC methodp_wglIsEnabledFrameLockI3D{nullptr};
	static v8::Handle<v8::Value> method_wglIsEnabledFrameLockI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglIsEnabledFrameLockI3D && args.Length() >= 1){


			BOOL ret = obj->methodp_wglIsEnabledFrameLockI3D(
				(args[0]->IsObject()?((BOOL *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):((BOOL *)((int64_t)args[0]->NumberValue())))/* BOOL *pFlag */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglIsEnabledGenlockI3D (HDC hDC, BOOL *pFlag);
	typedef BOOL (APIENTRYP PFNWGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL *pFlag);
	PFNWGLISENABLEDGENLOCKI3DPROC methodp_wglIsEnabledGenlockI3D{nullptr};
	static v8::Handle<v8::Value> method_wglIsEnabledGenlockI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglIsEnabledGenlockI3D && args.Length() >= 2){


			BOOL ret = obj->methodp_wglIsEnabledGenlockI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((BOOL *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((BOOL *)((int64_t)args[1]->NumberValue())))/* BOOL *pFlag */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglJoinSwapGroupNV (HDC hDC, GLuint group);
	typedef BOOL (APIENTRYP PFNWGLJOINSWAPGROUPNVPROC) (HDC hDC, GLuint group);
	PFNWGLJOINSWAPGROUPNVPROC methodp_wglJoinSwapGroupNV{nullptr};
	static v8::Handle<v8::Value> method_wglJoinSwapGroupNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglJoinSwapGroupNV && args.Length() >= 2){
			GLuint  arg1{ (GLuint )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglJoinSwapGroupNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI GLboolean APIENTRY wglLoadDisplayColorTableEXT (const GLushort *table, GLuint length);
	typedef GLboolean (APIENTRYP PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort *table, GLuint length);
	PFNWGLLOADDISPLAYCOLORTABLEEXTPROC methodp_wglLoadDisplayColorTableEXT{nullptr};
	static v8::Handle<v8::Value> method_wglLoadDisplayColorTableEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglLoadDisplayColorTableEXT && args.Length() >= 2){
			GLuint  arg1{ (GLuint )(args[1]->Uint32Value())};

			GLboolean ret = obj->methodp_wglLoadDisplayColorTableEXT(
				(args[0]->IsObject()?((const GLushort *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const GLushort *)((int64_t)args[0]->NumberValue())))/* const GLushort *table */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglLockVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL (APIENTRYP PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC methodp_wglLockVideoCaptureDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglLockVideoCaptureDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglLockVideoCaptureDeviceNV && args.Length() >= 2){


			BOOL ret = obj->methodp_wglLockVideoCaptureDeviceNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				(HVIDEOINPUTDEVICENV )((int64_t)args[1]->NumberValue())/* HVIDEOINPUTDEVICENV hDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglMakeAssociatedContextCurrentAMD (HGLRC hglrc);
	typedef BOOL (APIENTRYP PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC) (HGLRC hglrc);
	PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC methodp_wglMakeAssociatedContextCurrentAMD{nullptr};
	static v8::Handle<v8::Value> method_wglMakeAssociatedContextCurrentAMD(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglMakeAssociatedContextCurrentAMD && args.Length() >= 1){


			BOOL ret = obj->methodp_wglMakeAssociatedContextCurrentAMD(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC hglrc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglMakeContextCurrentARB (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	typedef BOOL (APIENTRYP PFNWGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	PFNWGLMAKECONTEXTCURRENTARBPROC methodp_wglMakeContextCurrentARB{nullptr};
	static v8::Handle<v8::Value> method_wglMakeContextCurrentARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglMakeContextCurrentARB && args.Length() >= 3){


			BOOL ret = obj->methodp_wglMakeContextCurrentARB(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDrawDC */,
				(HDC )((int64_t)args[1]->NumberValue())/* HDC hReadDC */,
				(HGLRC )((int64_t)args[2]->NumberValue())/* HGLRC hglrc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglMakeContextCurrentEXT (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	typedef BOOL (APIENTRYP PFNWGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	PFNWGLMAKECONTEXTCURRENTEXTPROC methodp_wglMakeContextCurrentEXT{nullptr};
	static v8::Handle<v8::Value> method_wglMakeContextCurrentEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglMakeContextCurrentEXT && args.Length() >= 3){


			BOOL ret = obj->methodp_wglMakeContextCurrentEXT(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDrawDC */,
				(HDC )((int64_t)args[1]->NumberValue())/* HDC hReadDC */,
				(HGLRC )((int64_t)args[2]->NumberValue())/* HGLRC hglrc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglMakeCurrent (HDC hDc, HGLRC newContext);
	typedef BOOL (APIENTRYP PFNWGLMAKECURRENTPROC) (HDC hDc, HGLRC newContext);
	PFNWGLMAKECURRENTPROC methodp_wglMakeCurrent{nullptr};
	static v8::Handle<v8::Value> method_wglMakeCurrent(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglMakeCurrent && args.Length() >= 2){


			BOOL ret = obj->methodp_wglMakeCurrent(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				(HGLRC )((int64_t)args[1]->NumberValue())/* HGLRC newContext */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryCurrentContextNV (int iAttribute, int *piValue);
	typedef BOOL (APIENTRYP PFNWGLQUERYCURRENTCONTEXTNVPROC) (int iAttribute, int *piValue);
	PFNWGLQUERYCURRENTCONTEXTNVPROC methodp_wglQueryCurrentContextNV{nullptr};
	static v8::Handle<v8::Value> method_wglQueryCurrentContextNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryCurrentContextNV && args.Length() >= 2){
			int  arg0{ (int )(args[0]->Int32Value())};

			BOOL ret = obj->methodp_wglQueryCurrentContextNV(
				arg0,
				(args[1]->IsObject()?((int *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[1]->NumberValue())))/* int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryFrameCountNV (HDC hDC, GLuint *count);
	typedef BOOL (APIENTRYP PFNWGLQUERYFRAMECOUNTNVPROC) (HDC hDC, GLuint *count);
	PFNWGLQUERYFRAMECOUNTNVPROC methodp_wglQueryFrameCountNV{nullptr};
	static v8::Handle<v8::Value> method_wglQueryFrameCountNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryFrameCountNV && args.Length() >= 2){


			BOOL ret = obj->methodp_wglQueryFrameCountNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((GLuint *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((GLuint *)((int64_t)args[1]->NumberValue())))/* GLuint *count */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryFrameLockMasterI3D (BOOL *pFlag);
	typedef BOOL (APIENTRYP PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL *pFlag);
	PFNWGLQUERYFRAMELOCKMASTERI3DPROC methodp_wglQueryFrameLockMasterI3D{nullptr};
	static v8::Handle<v8::Value> method_wglQueryFrameLockMasterI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryFrameLockMasterI3D && args.Length() >= 1){


			BOOL ret = obj->methodp_wglQueryFrameLockMasterI3D(
				(args[0]->IsObject()?((BOOL *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):((BOOL *)((int64_t)args[0]->NumberValue())))/* BOOL *pFlag */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryFrameTrackingI3D (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
	typedef BOOL (APIENTRYP PFNWGLQUERYFRAMETRACKINGI3DPROC) (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
	PFNWGLQUERYFRAMETRACKINGI3DPROC methodp_wglQueryFrameTrackingI3D{nullptr};
	static v8::Handle<v8::Value> method_wglQueryFrameTrackingI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryFrameTrackingI3D && args.Length() >= 3){


			BOOL ret = obj->methodp_wglQueryFrameTrackingI3D(
				(args[0]->IsObject()?((DWORD *)args[0]->ToObject()->GetIndexedPropertiesExternalArrayData()):((DWORD *)((int64_t)args[0]->NumberValue())))/* DWORD *pFrameCount */,
				(args[1]->IsObject()?((DWORD *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((DWORD *)((int64_t)args[1]->NumberValue())))/* DWORD *pMissedFrames */,
				(args[2]->IsObject()?((float *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((float *)((int64_t)args[2]->NumberValue())))/* float *pLastMissedUsage */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryGenlockMaxSourceDelayI3D (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
	typedef BOOL (APIENTRYP PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
	PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC methodp_wglQueryGenlockMaxSourceDelayI3D{nullptr};
	static v8::Handle<v8::Value> method_wglQueryGenlockMaxSourceDelayI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryGenlockMaxSourceDelayI3D && args.Length() >= 3){


			BOOL ret = obj->methodp_wglQueryGenlockMaxSourceDelayI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((UINT *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[1]->NumberValue())))/* UINT *uMaxLineDelay */,
				(args[2]->IsObject()?((UINT *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((UINT *)((int64_t)args[2]->NumberValue())))/* UINT *uMaxPixelDelay */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryMaxSwapGroupsNV (HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
	typedef BOOL (APIENTRYP PFNWGLQUERYMAXSWAPGROUPSNVPROC) (HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
	PFNWGLQUERYMAXSWAPGROUPSNVPROC methodp_wglQueryMaxSwapGroupsNV{nullptr};
	static v8::Handle<v8::Value> method_wglQueryMaxSwapGroupsNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryMaxSwapGroupsNV && args.Length() >= 3){


			BOOL ret = obj->methodp_wglQueryMaxSwapGroupsNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((GLuint *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((GLuint *)((int64_t)args[1]->NumberValue())))/* GLuint *maxGroups */,
				(args[2]->IsObject()?((GLuint *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((GLuint *)((int64_t)args[2]->NumberValue())))/* GLuint *maxBarriers */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryPbufferARB (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
	typedef BOOL (APIENTRYP PFNWGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
	PFNWGLQUERYPBUFFERARBPROC methodp_wglQueryPbufferARB{nullptr};
	static v8::Handle<v8::Value> method_wglQueryPbufferARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryPbufferARB && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglQueryPbufferARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				arg1,
				(args[2]->IsObject()?((int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[2]->NumberValue())))/* int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryPbufferEXT (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
	typedef BOOL (APIENTRYP PFNWGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
	PFNWGLQUERYPBUFFEREXTPROC methodp_wglQueryPbufferEXT{nullptr};
	static v8::Handle<v8::Value> method_wglQueryPbufferEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryPbufferEXT && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglQueryPbufferEXT(
				(HPBUFFEREXT )((int64_t)args[0]->NumberValue())/* HPBUFFEREXT hPbuffer */,
				arg1,
				(args[2]->IsObject()?((int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[2]->NumberValue())))/* int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQuerySwapGroupNV (HDC hDC, GLuint *group, GLuint *barrier);
	typedef BOOL (APIENTRYP PFNWGLQUERYSWAPGROUPNVPROC) (HDC hDC, GLuint *group, GLuint *barrier);
	PFNWGLQUERYSWAPGROUPNVPROC methodp_wglQuerySwapGroupNV{nullptr};
	static v8::Handle<v8::Value> method_wglQuerySwapGroupNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQuerySwapGroupNV && args.Length() >= 3){


			BOOL ret = obj->methodp_wglQuerySwapGroupNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(args[1]->IsObject()?((GLuint *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((GLuint *)((int64_t)args[1]->NumberValue())))/* GLuint *group */,
				(args[2]->IsObject()?((GLuint *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((GLuint *)((int64_t)args[2]->NumberValue())))/* GLuint *barrier */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglQueryVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
	typedef BOOL (APIENTRYP PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
	PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC methodp_wglQueryVideoCaptureDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglQueryVideoCaptureDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglQueryVideoCaptureDeviceNV && args.Length() >= 4){
			int  arg2{ (int )(args[2]->Int32Value())};

			BOOL ret = obj->methodp_wglQueryVideoCaptureDeviceNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				(HVIDEOINPUTDEVICENV )((int64_t)args[1]->NumberValue())/* HVIDEOINPUTDEVICENV hDevice */,
				arg2,
				(args[3]->IsObject()?((int *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((int *)((int64_t)args[3]->NumberValue())))/* int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglRealizeLayerPalette (HDC hdc, int iLayerPlane, BOOL bRealize);
	typedef BOOL (APIENTRYP PFNWGLREALIZELAYERPALETTEPROC) (HDC hdc, int iLayerPlane, BOOL bRealize);
	PFNWGLREALIZELAYERPALETTEPROC methodp_wglRealizeLayerPalette{nullptr};
	static v8::Handle<v8::Value> method_wglRealizeLayerPalette(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglRealizeLayerPalette && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};
			BOOL  arg2{ (BOOL )(args[2]->Int32Value())};

			BOOL ret = obj->methodp_wglRealizeLayerPalette(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglReleaseImageBufferEventsI3D (HDC hDC, const LPVOID *pAddress, UINT count);
	typedef BOOL (APIENTRYP PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID *pAddress, UINT count);
	PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC methodp_wglReleaseImageBufferEventsI3D{nullptr};
	static v8::Handle<v8::Value> method_wglReleaseImageBufferEventsI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleaseImageBufferEventsI3D && args.Length() >= 3){
			UINT  arg2{ (UINT )(args[2]->Uint32Value())};

			BOOL ret = obj->methodp_wglReleaseImageBufferEventsI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				(const LPVOID *)((int64_t)args[1]->NumberValue())/* const LPVOID *pAddress */,
				arg2);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY wglReleasePbufferDCARB (HPBUFFERARB hPbuffer, HDC hDC);
	typedef int (APIENTRYP PFNWGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
	PFNWGLRELEASEPBUFFERDCARBPROC methodp_wglReleasePbufferDCARB{nullptr};
	static v8::Handle<v8::Value> method_wglReleasePbufferDCARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleasePbufferDCARB && args.Length() >= 2){


			int ret = obj->methodp_wglReleasePbufferDCARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				(HDC )((int64_t)args[1]->NumberValue())/* HDC hDC */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY wglReleasePbufferDCEXT (HPBUFFEREXT hPbuffer, HDC hDC);
	typedef int (APIENTRYP PFNWGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
	PFNWGLRELEASEPBUFFERDCEXTPROC methodp_wglReleasePbufferDCEXT{nullptr};
	static v8::Handle<v8::Value> method_wglReleasePbufferDCEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleasePbufferDCEXT && args.Length() >= 2){


			int ret = obj->methodp_wglReleasePbufferDCEXT(
				(HPBUFFEREXT )((int64_t)args[0]->NumberValue())/* HPBUFFEREXT hPbuffer */,
				(HDC )((int64_t)args[1]->NumberValue())/* HDC hDC */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglReleaseTexImageARB (HPBUFFERARB hPbuffer, int iBuffer);
	typedef BOOL (APIENTRYP PFNWGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
	PFNWGLRELEASETEXIMAGEARBPROC methodp_wglReleaseTexImageARB{nullptr};
	static v8::Handle<v8::Value> method_wglReleaseTexImageARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleaseTexImageARB && args.Length() >= 2){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglReleaseTexImageARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglReleaseVideoCaptureDeviceNV (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL (APIENTRYP PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC methodp_wglReleaseVideoCaptureDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglReleaseVideoCaptureDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleaseVideoCaptureDeviceNV && args.Length() >= 2){


			BOOL ret = obj->methodp_wglReleaseVideoCaptureDeviceNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDc */,
				(HVIDEOINPUTDEVICENV )((int64_t)args[1]->NumberValue())/* HVIDEOINPUTDEVICENV hDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglReleaseVideoDeviceNV (HPVIDEODEV hVideoDevice);
	typedef BOOL (APIENTRYP PFNWGLRELEASEVIDEODEVICENVPROC) (HPVIDEODEV hVideoDevice);
	PFNWGLRELEASEVIDEODEVICENVPROC methodp_wglReleaseVideoDeviceNV{nullptr};
	static v8::Handle<v8::Value> method_wglReleaseVideoDeviceNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleaseVideoDeviceNV && args.Length() >= 1){


			BOOL ret = obj->methodp_wglReleaseVideoDeviceNV(
				(HPVIDEODEV )((int64_t)args[0]->NumberValue())/* HPVIDEODEV hVideoDevice */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglReleaseVideoImageNV (HPBUFFERARB hPbuffer, int iVideoBuffer);
	typedef BOOL (APIENTRYP PFNWGLRELEASEVIDEOIMAGENVPROC) (HPBUFFERARB hPbuffer, int iVideoBuffer);
	PFNWGLRELEASEVIDEOIMAGENVPROC methodp_wglReleaseVideoImageNV{nullptr};
	static v8::Handle<v8::Value> method_wglReleaseVideoImageNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglReleaseVideoImageNV && args.Length() >= 2){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglReleaseVideoImageNV(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglResetFrameCountNV (HDC hDC);
	typedef BOOL (APIENTRYP PFNWGLRESETFRAMECOUNTNVPROC) (HDC hDC);
	PFNWGLRESETFRAMECOUNTNVPROC methodp_wglResetFrameCountNV{nullptr};
	static v8::Handle<v8::Value> method_wglResetFrameCountNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglResetFrameCountNV && args.Length() >= 1){


			BOOL ret = obj->methodp_wglResetFrameCountNV(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglRestoreBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
	typedef BOOL (APIENTRYP PFNWGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
	PFNWGLRESTOREBUFFERREGIONARBPROC methodp_wglRestoreBufferRegionARB{nullptr};
	static v8::Handle<v8::Value> method_wglRestoreBufferRegionARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglRestoreBufferRegionARB && args.Length() >= 7){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			int  arg3{ (int )(args[3]->Int32Value())};
			int  arg4{ (int )(args[4]->Int32Value())};
			int  arg5{ (int )(args[5]->Int32Value())};
			int  arg6{ (int )(args[6]->Int32Value())};

			BOOL ret = obj->methodp_wglRestoreBufferRegionARB(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hRegion */,
				arg1,
				arg2,
				arg3,
				arg4,
				arg5,
				arg6);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSaveBufferRegionARB (HANDLE hRegion, int x, int y, int width, int height);
	typedef BOOL (APIENTRYP PFNWGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
	PFNWGLSAVEBUFFERREGIONARBPROC methodp_wglSaveBufferRegionARB{nullptr};
	static v8::Handle<v8::Value> method_wglSaveBufferRegionARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSaveBufferRegionARB && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			int  arg3{ (int )(args[3]->Int32Value())};
			int  arg4{ (int )(args[4]->Int32Value())};

			BOOL ret = obj->methodp_wglSaveBufferRegionARB(
				(HANDLE )((int64_t)args[0]->NumberValue())/* HANDLE hRegion */,
				arg1,
				arg2,
				arg3,
				arg4);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSendPbufferToVideoNV (HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
	typedef BOOL (APIENTRYP PFNWGLSENDPBUFFERTOVIDEONVPROC) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
	PFNWGLSENDPBUFFERTOVIDEONVPROC methodp_wglSendPbufferToVideoNV{nullptr};
	static v8::Handle<v8::Value> method_wglSendPbufferToVideoNV(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSendPbufferToVideoNV && args.Length() >= 4){
			int  arg1{ (int )(args[1]->Int32Value())};
			BOOL  arg3{ (BOOL )(args[3]->Int32Value())};

			BOOL ret = obj->methodp_wglSendPbufferToVideoNV(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				arg1,
				(args[2]->IsObject()?((unsigned long *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((unsigned long *)((int64_t)args[2]->NumberValue())))/* unsigned long *pulCounterPbuffer */,
				arg3);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSetDigitalVideoParametersI3D (HDC hDC, int iAttribute, const int *piValue);
	typedef BOOL (APIENTRYP PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
	PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC methodp_wglSetDigitalVideoParametersI3D{nullptr};
	static v8::Handle<v8::Value> method_wglSetDigitalVideoParametersI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSetDigitalVideoParametersI3D && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglSetDigitalVideoParametersI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(args[2]->IsObject()?((const int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[2]->NumberValue())))/* const int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSetGammaTableI3D (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
	typedef BOOL (APIENTRYP PFNWGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
	PFNWGLSETGAMMATABLEI3DPROC methodp_wglSetGammaTableI3D{nullptr};
	static v8::Handle<v8::Value> method_wglSetGammaTableI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSetGammaTableI3D && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglSetGammaTableI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(args[2]->IsObject()?((const USHORT *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const USHORT *)((int64_t)args[2]->NumberValue())))/* const USHORT *puRed */,
				(args[3]->IsObject()?((const USHORT *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const USHORT *)((int64_t)args[3]->NumberValue())))/* const USHORT *puGreen */,
				(args[4]->IsObject()?((const USHORT *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const USHORT *)((int64_t)args[4]->NumberValue())))/* const USHORT *puBlue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSetGammaTableParametersI3D (HDC hDC, int iAttribute, const int *piValue);
	typedef BOOL (APIENTRYP PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
	PFNWGLSETGAMMATABLEPARAMETERSI3DPROC methodp_wglSetGammaTableParametersI3D{nullptr};
	static v8::Handle<v8::Value> method_wglSetGammaTableParametersI3D(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSetGammaTableParametersI3D && args.Length() >= 3){
			int  arg1{ (int )(args[1]->Int32Value())};

			BOOL ret = obj->methodp_wglSetGammaTableParametersI3D(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				(args[2]->IsObject()?((const int *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[2]->NumberValue())))/* const int *piValue */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI int APIENTRY wglSetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF *pcr);
	typedef int (APIENTRYP PFNWGLSETLAYERPALETTEENTRIESPROC) (HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF *pcr);
	PFNWGLSETLAYERPALETTEENTRIESPROC methodp_wglSetLayerPaletteEntries{nullptr};
	static v8::Handle<v8::Value> method_wglSetLayerPaletteEntries(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSetLayerPaletteEntries && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			int  arg2{ (int )(args[2]->Int32Value())};
			int  arg3{ (int )(args[3]->Int32Value())};

			int ret = obj->methodp_wglSetLayerPaletteEntries(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((const COLORREF *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const COLORREF *)((int64_t)args[4]->NumberValue())))/* const COLORREF *pcr */);
			

			return scope.Close(v8::Int32::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSetPbufferAttribARB (HPBUFFERARB hPbuffer, const int *piAttribList);
	typedef BOOL (APIENTRYP PFNWGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int *piAttribList);
	PFNWGLSETPBUFFERATTRIBARBPROC methodp_wglSetPbufferAttribARB{nullptr};
	static v8::Handle<v8::Value> method_wglSetPbufferAttribARB(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSetPbufferAttribARB && args.Length() >= 2){


			BOOL ret = obj->methodp_wglSetPbufferAttribARB(
				(HPBUFFERARB )((int64_t)args[0]->NumberValue())/* HPBUFFERARB hPbuffer */,
				(args[1]->IsObject()?((const int *)args[1]->ToObject()->GetIndexedPropertiesExternalArrayData()):((const int *)((int64_t)args[1]->NumberValue())))/* const int *piAttribList */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSetStereoEmitterState3DL (HDC hDC, UINT uState);
	typedef BOOL (APIENTRYP PFNWGLSETSTEREOEMITTERSTATE3DLPROC) (HDC hDC, UINT uState);
	PFNWGLSETSTEREOEMITTERSTATE3DLPROC methodp_wglSetStereoEmitterState3DL{nullptr};
	static v8::Handle<v8::Value> method_wglSetStereoEmitterState3DL(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSetStereoEmitterState3DL && args.Length() >= 2){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglSetStereoEmitterState3DL(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglShareLists (HGLRC hrcSrvShare, HGLRC hrcSrvSource);
	typedef BOOL (APIENTRYP PFNWGLSHARELISTSPROC) (HGLRC hrcSrvShare, HGLRC hrcSrvSource);
	PFNWGLSHARELISTSPROC methodp_wglShareLists{nullptr};
	static v8::Handle<v8::Value> method_wglShareLists(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglShareLists && args.Length() >= 2){


			BOOL ret = obj->methodp_wglShareLists(
				(HGLRC )((int64_t)args[0]->NumberValue())/* HGLRC hrcSrvShare */,
				(HGLRC )((int64_t)args[1]->NumberValue())/* HGLRC hrcSrvSource */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI INT64 APIENTRY wglSwapBuffersMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
	typedef INT64 (APIENTRYP PFNWGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
	PFNWGLSWAPBUFFERSMSCOMLPROC methodp_wglSwapBuffersMscOML{nullptr};
	static v8::Handle<v8::Value> method_wglSwapBuffersMscOML(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSwapBuffersMscOML && args.Length() >= 4){
			INT64  arg1{ (INT64 )(args[1]->NumberValue())};
			INT64  arg2{ (INT64 )(args[2]->NumberValue())};
			INT64  arg3{ (INT64 )(args[3]->NumberValue())};

			INT64 ret = obj->methodp_wglSwapBuffersMscOML(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3);
			

			return scope.Close(v8::Number::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSwapLayerBuffers (HDC hdc, UINT fuFlags);
	typedef BOOL (APIENTRYP PFNWGLSWAPLAYERBUFFERSPROC) (HDC hdc, UINT fuFlags);
	PFNWGLSWAPLAYERBUFFERSPROC methodp_wglSwapLayerBuffers{nullptr};
	static v8::Handle<v8::Value> method_wglSwapLayerBuffers(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSwapLayerBuffers && args.Length() >= 2){
			UINT  arg1{ (UINT )(args[1]->Uint32Value())};

			BOOL ret = obj->methodp_wglSwapLayerBuffers(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglSwapIntervalEXT (int interval);
	typedef BOOL (APIENTRYP PFNWGLSWAPINTERVALEXTPROC) (int interval);
	PFNWGLSWAPINTERVALEXTPROC methodp_wglSwapIntervalEXT{nullptr};
	static v8::Handle<v8::Value> method_wglSwapIntervalEXT(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSwapIntervalEXT && args.Length() >= 1){
			int  arg0{ (int )(args[0]->Int32Value())};

			BOOL ret = obj->methodp_wglSwapIntervalEXT(
				arg0);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI INT64 APIENTRY wglSwapLayerBuffersMscOML (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
	typedef INT64 (APIENTRYP PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
	PFNWGLSWAPLAYERBUFFERSMSCOMLPROC methodp_wglSwapLayerBuffersMscOML{nullptr};
	static v8::Handle<v8::Value> method_wglSwapLayerBuffersMscOML(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglSwapLayerBuffersMscOML && args.Length() >= 5){
			int  arg1{ (int )(args[1]->Int32Value())};
			INT64  arg2{ (INT64 )(args[2]->NumberValue())};
			INT64  arg3{ (INT64 )(args[3]->NumberValue())};
			INT64  arg4{ (INT64 )(args[4]->NumberValue())};

			INT64 ret = obj->methodp_wglSwapLayerBuffersMscOML(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				arg4);
			

			return scope.Close(v8::Number::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglUseFontBitmaps (HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (APIENTRYP PFNWGLUSEFONTBITMAPSPROC) (HDC hDC, DWORD first, DWORD count, DWORD listBase);
	PFNWGLUSEFONTBITMAPSPROC methodp_wglUseFontBitmaps{nullptr};
	static v8::Handle<v8::Value> method_wglUseFontBitmaps(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglUseFontBitmaps && args.Length() >= 4){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			DWORD  arg2{ (DWORD )(args[2]->Uint32Value())};
			DWORD  arg3{ (DWORD )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglUseFontBitmaps(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglUseFontBitmapsA (HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (APIENTRYP PFNWGLUSEFONTBITMAPSAPROC) (HDC hDC, DWORD first, DWORD count, DWORD listBase);
	PFNWGLUSEFONTBITMAPSAPROC methodp_wglUseFontBitmapsA{nullptr};
	static v8::Handle<v8::Value> method_wglUseFontBitmapsA(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglUseFontBitmapsA && args.Length() >= 4){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			DWORD  arg2{ (DWORD )(args[2]->Uint32Value())};
			DWORD  arg3{ (DWORD )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglUseFontBitmapsA(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglUseFontBitmapsW (HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (APIENTRYP PFNWGLUSEFONTBITMAPSWPROC) (HDC hDC, DWORD first, DWORD count, DWORD listBase);
	PFNWGLUSEFONTBITMAPSWPROC methodp_wglUseFontBitmapsW{nullptr};
	static v8::Handle<v8::Value> method_wglUseFontBitmapsW(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglUseFontBitmapsW && args.Length() >= 4){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			DWORD  arg2{ (DWORD )(args[2]->Uint32Value())};
			DWORD  arg3{ (DWORD )(args[3]->Uint32Value())};

			BOOL ret = obj->methodp_wglUseFontBitmapsW(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglUseFontOutlines (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (APIENTRYP PFNWGLUSEFONTOUTLINESPROC) (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	PFNWGLUSEFONTOUTLINESPROC methodp_wglUseFontOutlines{nullptr};
	static v8::Handle<v8::Value> method_wglUseFontOutlines(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglUseFontOutlines && args.Length() >= 8){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			DWORD  arg2{ (DWORD )(args[2]->Uint32Value())};
			DWORD  arg3{ (DWORD )(args[3]->Uint32Value())};
			FLOAT  arg4{ (FLOAT )(args[4]->NumberValue())};
			FLOAT  arg5{ (FLOAT )(args[5]->NumberValue())};
			int  arg6{ (int )(args[6]->Int32Value())};

			BOOL ret = obj->methodp_wglUseFontOutlines(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3,
				arg4,
				arg5,
				arg6,
				(LPGLYPHMETRICSFLOAT )((int64_t)args[7]->NumberValue())/* LPGLYPHMETRICSFLOAT lpgmf */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglUseFontOutlinesA (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (APIENTRYP PFNWGLUSEFONTOUTLINESAPROC) (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	PFNWGLUSEFONTOUTLINESAPROC methodp_wglUseFontOutlinesA{nullptr};
	static v8::Handle<v8::Value> method_wglUseFontOutlinesA(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglUseFontOutlinesA && args.Length() >= 8){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			DWORD  arg2{ (DWORD )(args[2]->Uint32Value())};
			DWORD  arg3{ (DWORD )(args[3]->Uint32Value())};
			FLOAT  arg4{ (FLOAT )(args[4]->NumberValue())};
			FLOAT  arg5{ (FLOAT )(args[5]->NumberValue())};
			int  arg6{ (int )(args[6]->Int32Value())};

			BOOL ret = obj->methodp_wglUseFontOutlinesA(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3,
				arg4,
				arg5,
				arg6,
				(LPGLYPHMETRICSFLOAT )((int64_t)args[7]->NumberValue())/* LPGLYPHMETRICSFLOAT lpgmf */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglUseFontOutlinesW (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (APIENTRYP PFNWGLUSEFONTOUTLINESWPROC) (HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	PFNWGLUSEFONTOUTLINESWPROC methodp_wglUseFontOutlinesW{nullptr};
	static v8::Handle<v8::Value> method_wglUseFontOutlinesW(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglUseFontOutlinesW && args.Length() >= 8){
			DWORD  arg1{ (DWORD )(args[1]->Uint32Value())};
			DWORD  arg2{ (DWORD )(args[2]->Uint32Value())};
			DWORD  arg3{ (DWORD )(args[3]->Uint32Value())};
			FLOAT  arg4{ (FLOAT )(args[4]->NumberValue())};
			FLOAT  arg5{ (FLOAT )(args[5]->NumberValue())};
			int  arg6{ (int )(args[6]->Int32Value())};

			BOOL ret = obj->methodp_wglUseFontOutlinesW(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hDC */,
				arg1,
				arg2,
				arg3,
				arg4,
				arg5,
				arg6,
				(LPGLYPHMETRICSFLOAT )((int64_t)args[7]->NumberValue())/* LPGLYPHMETRICSFLOAT lpgmf */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglWaitForMscOML (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
	typedef BOOL (APIENTRYP PFNWGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
	PFNWGLWAITFORMSCOMLPROC methodp_wglWaitForMscOML{nullptr};
	static v8::Handle<v8::Value> method_wglWaitForMscOML(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglWaitForMscOML && args.Length() >= 7){
			INT64  arg1{ (INT64 )(args[1]->NumberValue())};
			INT64  arg2{ (INT64 )(args[2]->NumberValue())};
			INT64  arg3{ (INT64 )(args[3]->NumberValue())};

			BOOL ret = obj->methodp_wglWaitForMscOML(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				arg2,
				arg3,
				(args[4]->IsObject()?((INT64 *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[4]->NumberValue())))/* INT64 *ust */,
				(args[5]->IsObject()?((INT64 *)args[5]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[5]->NumberValue())))/* INT64 *msc */,
				(args[6]->IsObject()?((INT64 *)args[6]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[6]->NumberValue())))/* INT64 *sbc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}

//GLAPI BOOL APIENTRY wglWaitForSbcOML (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
	typedef BOOL (APIENTRYP PFNWGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
	PFNWGLWAITFORSBCOMLPROC methodp_wglWaitForSbcOML{nullptr};
	static v8::Handle<v8::Value> method_wglWaitForSbcOML(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = class_WGL::Unwrap<class_WGL>(args.This());
		if(obj && obj->methodp_wglWaitForSbcOML && args.Length() >= 5){
			INT64  arg1{ (INT64 )(args[1]->NumberValue())};

			BOOL ret = obj->methodp_wglWaitForSbcOML(
				(HDC )((int64_t)args[0]->NumberValue())/* HDC hdc */,
				arg1,
				(args[2]->IsObject()?((INT64 *)args[2]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[2]->NumberValue())))/* INT64 *ust */,
				(args[3]->IsObject()?((INT64 *)args[3]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[3]->NumberValue())))/* INT64 *msc */,
				(args[4]->IsObject()?((INT64 *)args[4]->ToObject()->GetIndexedPropertiesExternalArrayData()):((INT64 *)((int64_t)args[4]->NumberValue())))/* INT64 *sbc */);
			

			return scope.Close(v8::Boolean::New(ret));
		} else {DebugBreak(); }
		return v8::Undefined();
	}


	static void Init(v8::Handle<v8::Object> target) {
		v8::HandleScope scope;

		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
		tpl->SetClassName(v8::String::NewSymbol("WGL"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);
		setPrototypeMethod(ChoosePixelFormat)
		setPrototypeMethod(DescribePixelFormat)
		setPrototypeMethod(GetPixelFormat)
		setPrototypeMethod(SetPixelFormat)
		setPrototypeMethod(SwapBuffers)
		setPrototypeMethod(wglAllocateMemoryNV)
		setPrototypeMethod(wglAssociateImageBufferEventsI3D)
		setPrototypeMethod(wglBeginFrameTrackingI3D)
		setPrototypeMethod(wglBindDisplayColorTableEXT)
		setPrototypeMethod(wglBindSwapBarrierNV)
		setPrototypeMethod(wglBindTexImageARB)
		setPrototypeMethod(wglBindVideoCaptureDeviceNV)
		setPrototypeMethod(wglBindVideoDeviceNV)
		setPrototypeMethod(wglBindVideoImageNV)
		setPrototypeMethod(wglBlitContextFramebufferAMD)
		setPrototypeMethod(wglChoosePixelFormatARB)
		setPrototypeMethod(wglChoosePixelFormatEXT)
		setPrototypeMethod(wglCopyContext)
		setPrototypeMethod(wglCopyImageSubDataNV)
		setPrototypeMethod(wglCreateAffinityDCNV)
		setPrototypeMethod(wglCreateAssociatedContextAMD)
		setPrototypeMethod(wglCreateAssociatedContextAttribsAMD)
		setPrototypeMethod(wglCreateBufferRegionARB)
		setPrototypeMethod(wglCreateContext)
		setPrototypeMethod(wglCreateContextAttribsARB)
		setPrototypeMethod(wglCreateDisplayColorTableEXT)
		setPrototypeMethod(wglCreateImageBufferI3D)
		setPrototypeMethod(wglCreateLayerContext)
		setPrototypeMethod(wglCreatePbufferARB)
		setPrototypeMethod(wglCreatePbufferEXT)
		setPrototypeMethod(wglDelayBeforeSwapNV)
		setPrototypeMethod(wglDeleteAssociatedContextAMD)
		setPrototypeMethod(wglDeleteBufferRegionARB)
		setPrototypeMethod(wglDeleteContext)
		setPrototypeMethod(wglDeleteDCNV)
		setPrototypeMethod(wglDescribeLayerPlane)
		setPrototypeMethod(wglDestroyDisplayColorTableEXT)
		setPrototypeMethod(wglDestroyImageBufferI3D)
		setPrototypeMethod(wglDestroyPbufferARB)
		setPrototypeMethod(wglDestroyPbufferEXT)
		setPrototypeMethod(wglDisableFrameLockI3D)
		setPrototypeMethod(wglDisableGenlockI3D)
		setPrototypeMethod(wglDXCloseDeviceNV)
		setPrototypeMethod(wglDXLockObjectsNV)
		setPrototypeMethod(wglDXObjectAccessNV)
		setPrototypeMethod(wglDXOpenDeviceNV)
		setPrototypeMethod(wglDXRegisterObjectNV)
		setPrototypeMethod(wglDXSetResourceShareHandleNV)
		setPrototypeMethod(wglDXUnlockObjectsNV)
		setPrototypeMethod(wglDXUnregisterObjectNV)
		setPrototypeMethod(wglEnableFrameLockI3D)
		setPrototypeMethod(wglEnableGenlockI3D)
		setPrototypeMethod(wglEndFrameTrackingI3D)
		setPrototypeMethod(wglEnumerateVideoCaptureDevicesNV)
		setPrototypeMethod(wglEnumerateVideoDevicesNV)
		setPrototypeMethod(wglEnumGpuDevicesNV)
		setPrototypeMethod(wglEnumGpusFromAffinityDCNV)
		setPrototypeMethod(wglEnumGpusNV)
		setPrototypeMethod(wglFreeMemoryNV)
		setPrototypeMethod(wglGenlockSampleRateI3D)
		setPrototypeMethod(wglGenlockSourceDelayI3D)
		setPrototypeMethod(wglGenlockSourceEdgeI3D)
		setPrototypeMethod(wglGenlockSourceI3D)
		setPrototypeMethod(wglGetContextGPUIDAMD)
		setPrototypeMethod(wglGetCurrentAssociatedContextAMD)
		setPrototypeMethod(wglGetCurrentContext)
		setPrototypeMethod(wglGetCurrentDC)
		setPrototypeMethod(wglGetCurrentReadDCARB)
		setPrototypeMethod(wglGetCurrentReadDCEXT)
		setPrototypeMethod(wglGetDefaultProcAddress)
		setPrototypeMethod(wglGetDigitalVideoParametersI3D)
		setPrototypeMethod(GetEnhMetaFilePixelFormat)
		setPrototypeMethod(wglGetExtensionsStringARB)
		setPrototypeMethod(wglGetExtensionsStringEXT)
		setPrototypeMethod(wglGetFrameUsageI3D)
		setPrototypeMethod(wglGetGammaTableI3D)
		setPrototypeMethod(wglGetGammaTableParametersI3D)
		setPrototypeMethod(wglGetGenlockSampleRateI3D)
		setPrototypeMethod(wglGetGenlockSourceDelayI3D)
		setPrototypeMethod(wglGetGenlockSourceEdgeI3D)
		setPrototypeMethod(wglGetGenlockSourceI3D)
		setPrototypeMethod(wglGetGPUIDsAMD)
		setPrototypeMethod(wglGetGPUInfoAMD)
		setPrototypeMethod(wglGetLayerPaletteEntries)
		setPrototypeMethod(wglGetMscRateOML)
		setPrototypeMethod(wglGetPbufferDCARB)
		setPrototypeMethod(wglGetPbufferDCEXT)
		setPrototypeMethod(wglGetPixelFormatAttribfvARB)
		setPrototypeMethod(wglGetPixelFormatAttribfvEXT)
		setPrototypeMethod(wglGetPixelFormatAttribivARB)
		setPrototypeMethod(wglGetPixelFormatAttribivEXT)
		setPrototypeMethod(wglGetProcAddress)
		setPrototypeMethod(wglGetSwapIntervalEXT)
		setPrototypeMethod(wglGetSyncValuesOML)
		setPrototypeMethod(wglGetVideoDeviceNV)
		setPrototypeMethod(wglGetVideoInfoNV)
		setPrototypeMethod(wglIsEnabledFrameLockI3D)
		setPrototypeMethod(wglIsEnabledGenlockI3D)
		setPrototypeMethod(wglJoinSwapGroupNV)
		setPrototypeMethod(wglLoadDisplayColorTableEXT)
		setPrototypeMethod(wglLockVideoCaptureDeviceNV)
		setPrototypeMethod(wglMakeAssociatedContextCurrentAMD)
		setPrototypeMethod(wglMakeContextCurrentARB)
		setPrototypeMethod(wglMakeContextCurrentEXT)
		setPrototypeMethod(wglMakeCurrent)
		setPrototypeMethod(wglQueryCurrentContextNV)
		setPrototypeMethod(wglQueryFrameCountNV)
		setPrototypeMethod(wglQueryFrameLockMasterI3D)
		setPrototypeMethod(wglQueryFrameTrackingI3D)
		setPrototypeMethod(wglQueryGenlockMaxSourceDelayI3D)
		setPrototypeMethod(wglQueryMaxSwapGroupsNV)
		setPrototypeMethod(wglQueryPbufferARB)
		setPrototypeMethod(wglQueryPbufferEXT)
		setPrototypeMethod(wglQuerySwapGroupNV)
		setPrototypeMethod(wglQueryVideoCaptureDeviceNV)
		setPrototypeMethod(wglRealizeLayerPalette)
		setPrototypeMethod(wglReleaseImageBufferEventsI3D)
		setPrototypeMethod(wglReleasePbufferDCARB)
		setPrototypeMethod(wglReleasePbufferDCEXT)
		setPrototypeMethod(wglReleaseTexImageARB)
		setPrototypeMethod(wglReleaseVideoCaptureDeviceNV)
		setPrototypeMethod(wglReleaseVideoDeviceNV)
		setPrototypeMethod(wglReleaseVideoImageNV)
		setPrototypeMethod(wglResetFrameCountNV)
		setPrototypeMethod(wglRestoreBufferRegionARB)
		setPrototypeMethod(wglSaveBufferRegionARB)
		setPrototypeMethod(wglSendPbufferToVideoNV)
		setPrototypeMethod(wglSetDigitalVideoParametersI3D)
		setPrototypeMethod(wglSetGammaTableI3D)
		setPrototypeMethod(wglSetGammaTableParametersI3D)
		setPrototypeMethod(wglSetLayerPaletteEntries)
		setPrototypeMethod(wglSetPbufferAttribARB)
		setPrototypeMethod(wglSetStereoEmitterState3DL)
		setPrototypeMethod(wglShareLists)
		setPrototypeMethod(wglSwapBuffersMscOML)
		setPrototypeMethod(wglSwapLayerBuffers)
		setPrototypeMethod(wglSwapIntervalEXT)
		setPrototypeMethod(wglSwapLayerBuffersMscOML)
		setPrototypeMethod(wglUseFontBitmaps)
		setPrototypeMethod(wglUseFontBitmapsA)
		setPrototypeMethod(wglUseFontBitmapsW)
		setPrototypeMethod(wglUseFontOutlines)
		setPrototypeMethod(wglUseFontOutlinesA)
		setPrototypeMethod(wglUseFontOutlinesW)
		setPrototypeMethod(wglWaitForMscOML)
		setPrototypeMethod(wglWaitForSbcOML)

		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_MAIN_PLANE"), v8::Uint32::NewFromUnsigned(0x00000001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY1"), v8::Uint32::NewFromUnsigned(0x00000002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY2"), v8::Uint32::NewFromUnsigned(0x00000004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY3"), v8::Uint32::NewFromUnsigned(0x00000008));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY4"), v8::Uint32::NewFromUnsigned(0x00000010));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY5"), v8::Uint32::NewFromUnsigned(0x00000020));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY6"), v8::Uint32::NewFromUnsigned(0x00000040));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY7"), v8::Uint32::NewFromUnsigned(0x00000080));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY8"), v8::Uint32::NewFromUnsigned(0x00000100));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY9"), v8::Uint32::NewFromUnsigned(0x00000200));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY10"), v8::Uint32::NewFromUnsigned(0x00000400));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY11"), v8::Uint32::NewFromUnsigned(0x00000800));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY12"), v8::Uint32::NewFromUnsigned(0x00001000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY13"), v8::Uint32::NewFromUnsigned(0x00002000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY14"), v8::Uint32::NewFromUnsigned(0x00004000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_OVERLAY15"), v8::Uint32::NewFromUnsigned(0x00008000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY1"), v8::Uint32::NewFromUnsigned(0x00010000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY2"), v8::Uint32::NewFromUnsigned(0x00020000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY3"), v8::Uint32::NewFromUnsigned(0x00040000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY4"), v8::Uint32::NewFromUnsigned(0x00080000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY5"), v8::Uint32::NewFromUnsigned(0x00100000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY6"), v8::Uint32::NewFromUnsigned(0x00200000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY7"), v8::Uint32::NewFromUnsigned(0x00400000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY8"), v8::Uint32::NewFromUnsigned(0x00800000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY9"), v8::Uint32::NewFromUnsigned(0x01000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY10"), v8::Uint32::NewFromUnsigned(0x02000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY11"), v8::Uint32::NewFromUnsigned(0x04000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY12"), v8::Uint32::NewFromUnsigned(0x08000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY13"), v8::Uint32::NewFromUnsigned(0x10000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY14"), v8::Uint32::NewFromUnsigned(0x20000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDERLAY15"), v8::Uint32::NewFromUnsigned(0x40000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FRONT_COLOR_BUFFER_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BACK_COLOR_BUFFER_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DEPTH_BUFFER_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STENCIL_BUFFER_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000008));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_DEBUG_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_RESET_ISOLATION_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000008));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_CORE_PROFILE_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB"), v8::Uint32::NewFromUnsigned(0x00000002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_ES_PROFILE_BIT_EXT"), v8::Uint32::NewFromUnsigned(0x00000004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_ES2_PROFILE_BIT_EXT"), v8::Uint32::NewFromUnsigned(0x00000004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_IMAGE_BUFFER_MIN_ACCESS_I3D"), v8::Uint32::NewFromUnsigned(0x00000001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_IMAGE_BUFFER_LOCK_I3D"), v8::Uint32::NewFromUnsigned(0x00000002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCESS_READ_ONLY_NV"), v8::Uint32::NewFromUnsigned(0x00000000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCESS_READ_WRITE_NV"), v8::Uint32::NewFromUnsigned(0x00000001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCESS_WRITE_DISCARD_NV"), v8::Uint32::NewFromUnsigned(0x00000002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FONT_LINES"), v8::Uint32::NewFromUnsigned(0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FONT_POLYGONS"), v8::Uint32::NewFromUnsigned(1));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_VENDOR_AMD"), v8::Uint32::NewFromUnsigned(0x1F00));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_RENDERER_STRING_AMD"), v8::Uint32::NewFromUnsigned(0x1F01));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_OPENGL_VERSION_STRING_AMD"), v8::Uint32::NewFromUnsigned(0x1F02));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUMBER_PIXEL_FORMATS_ARB"), v8::Uint32::NewFromUnsigned(0x2000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUMBER_PIXEL_FORMATS_EXT"), v8::Uint32::NewFromUnsigned(0x2000));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DRAW_TO_WINDOW_ARB"), v8::Uint32::NewFromUnsigned(0x2001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DRAW_TO_WINDOW_EXT"), v8::Uint32::NewFromUnsigned(0x2001));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DRAW_TO_BITMAP_ARB"), v8::Uint32::NewFromUnsigned(0x2002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DRAW_TO_BITMAP_EXT"), v8::Uint32::NewFromUnsigned(0x2002));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCELERATION_ARB"), v8::Uint32::NewFromUnsigned(0x2003));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCELERATION_EXT"), v8::Uint32::NewFromUnsigned(0x2003));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NEED_PALETTE_ARB"), v8::Uint32::NewFromUnsigned(0x2004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NEED_PALETTE_EXT"), v8::Uint32::NewFromUnsigned(0x2004));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NEED_SYSTEM_PALETTE_ARB"), v8::Uint32::NewFromUnsigned(0x2005));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NEED_SYSTEM_PALETTE_EXT"), v8::Uint32::NewFromUnsigned(0x2005));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_LAYER_BUFFERS_ARB"), v8::Uint32::NewFromUnsigned(0x2006));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_LAYER_BUFFERS_EXT"), v8::Uint32::NewFromUnsigned(0x2006));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_METHOD_ARB"), v8::Uint32::NewFromUnsigned(0x2007));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_METHOD_EXT"), v8::Uint32::NewFromUnsigned(0x2007));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUMBER_OVERLAYS_ARB"), v8::Uint32::NewFromUnsigned(0x2008));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUMBER_OVERLAYS_EXT"), v8::Uint32::NewFromUnsigned(0x2008));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUMBER_UNDERLAYS_ARB"), v8::Uint32::NewFromUnsigned(0x2009));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUMBER_UNDERLAYS_EXT"), v8::Uint32::NewFromUnsigned(0x2009));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_ARB"), v8::Uint32::NewFromUnsigned(0x200A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_EXT"), v8::Uint32::NewFromUnsigned(0x200A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_VALUE_EXT"), v8::Uint32::NewFromUnsigned(0x200B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SHARE_DEPTH_ARB"), v8::Uint32::NewFromUnsigned(0x200C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SHARE_DEPTH_EXT"), v8::Uint32::NewFromUnsigned(0x200C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SHARE_STENCIL_ARB"), v8::Uint32::NewFromUnsigned(0x200D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SHARE_STENCIL_EXT"), v8::Uint32::NewFromUnsigned(0x200D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SHARE_ACCUM_ARB"), v8::Uint32::NewFromUnsigned(0x200E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SHARE_ACCUM_EXT"), v8::Uint32::NewFromUnsigned(0x200E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SUPPORT_GDI_ARB"), v8::Uint32::NewFromUnsigned(0x200F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SUPPORT_GDI_EXT"), v8::Uint32::NewFromUnsigned(0x200F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SUPPORT_OPENGL_ARB"), v8::Uint32::NewFromUnsigned(0x2010));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SUPPORT_OPENGL_EXT"), v8::Uint32::NewFromUnsigned(0x2010));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DOUBLE_BUFFER_ARB"), v8::Uint32::NewFromUnsigned(0x2011));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DOUBLE_BUFFER_EXT"), v8::Uint32::NewFromUnsigned(0x2011));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STEREO_ARB"), v8::Uint32::NewFromUnsigned(0x2012));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STEREO_EXT"), v8::Uint32::NewFromUnsigned(0x2012));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PIXEL_TYPE_ARB"), v8::Uint32::NewFromUnsigned(0x2013));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PIXEL_TYPE_EXT"), v8::Uint32::NewFromUnsigned(0x2013));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_COLOR_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2014));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_COLOR_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2014));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_RED_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2015));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_RED_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2015));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_RED_SHIFT_ARB"), v8::Uint32::NewFromUnsigned(0x2016));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_RED_SHIFT_EXT"), v8::Uint32::NewFromUnsigned(0x2016));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GREEN_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2017));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GREEN_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2017));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GREEN_SHIFT_ARB"), v8::Uint32::NewFromUnsigned(0x2018));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GREEN_SHIFT_EXT"), v8::Uint32::NewFromUnsigned(0x2018));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BLUE_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2019));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BLUE_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2019));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BLUE_SHIFT_ARB"), v8::Uint32::NewFromUnsigned(0x201A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BLUE_SHIFT_EXT"), v8::Uint32::NewFromUnsigned(0x201A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ALPHA_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x201B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ALPHA_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x201B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ALPHA_SHIFT_ARB"), v8::Uint32::NewFromUnsigned(0x201C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ALPHA_SHIFT_EXT"), v8::Uint32::NewFromUnsigned(0x201C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x201D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x201D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_RED_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x201E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_RED_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x201E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_GREEN_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x201F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_GREEN_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x201F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_BLUE_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2020));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_BLUE_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2020));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_ALPHA_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2021));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_ACCUM_ALPHA_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2021));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DEPTH_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2022));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DEPTH_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2022));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STENCIL_BITS_ARB"), v8::Uint32::NewFromUnsigned(0x2023));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STENCIL_BITS_EXT"), v8::Uint32::NewFromUnsigned(0x2023));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX_BUFFERS_ARB"), v8::Uint32::NewFromUnsigned(0x2024));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX_BUFFERS_EXT"), v8::Uint32::NewFromUnsigned(0x2024));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NO_ACCELERATION_ARB"), v8::Uint32::NewFromUnsigned(0x2025));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NO_ACCELERATION_EXT"), v8::Uint32::NewFromUnsigned(0x2025));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENERIC_ACCELERATION_ARB"), v8::Uint32::NewFromUnsigned(0x2026));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENERIC_ACCELERATION_EXT"), v8::Uint32::NewFromUnsigned(0x2026));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FULL_ACCELERATION_ARB"), v8::Uint32::NewFromUnsigned(0x2027));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FULL_ACCELERATION_EXT"), v8::Uint32::NewFromUnsigned(0x2027));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_EXCHANGE_ARB"), v8::Uint32::NewFromUnsigned(0x2028));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_EXCHANGE_EXT"), v8::Uint32::NewFromUnsigned(0x2028));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_COPY_ARB"), v8::Uint32::NewFromUnsigned(0x2029));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_COPY_EXT"), v8::Uint32::NewFromUnsigned(0x2029));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDEFINED_ARB"), v8::Uint32::NewFromUnsigned(0x202A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SWAP_UNDEFINED_EXT"), v8::Uint32::NewFromUnsigned(0x202A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_RGBA_ARB"), v8::Uint32::NewFromUnsigned(0x202B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_RGBA_EXT"), v8::Uint32::NewFromUnsigned(0x202B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_COLORINDEX_ARB"), v8::Uint32::NewFromUnsigned(0x202C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_COLORINDEX_EXT"), v8::Uint32::NewFromUnsigned(0x202C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DRAW_TO_PBUFFER_ARB"), v8::Uint32::NewFromUnsigned(0x202D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DRAW_TO_PBUFFER_EXT"), v8::Uint32::NewFromUnsigned(0x202D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MAX_PBUFFER_PIXELS_ARB"), v8::Uint32::NewFromUnsigned(0x202E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MAX_PBUFFER_PIXELS_EXT"), v8::Uint32::NewFromUnsigned(0x202E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MAX_PBUFFER_WIDTH_ARB"), v8::Uint32::NewFromUnsigned(0x202F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MAX_PBUFFER_WIDTH_EXT"), v8::Uint32::NewFromUnsigned(0x202F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MAX_PBUFFER_HEIGHT_ARB"), v8::Uint32::NewFromUnsigned(0x2030));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MAX_PBUFFER_HEIGHT_EXT"), v8::Uint32::NewFromUnsigned(0x2030));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_OPTIMAL_PBUFFER_WIDTH_EXT"), v8::Uint32::NewFromUnsigned(0x2031));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_OPTIMAL_PBUFFER_HEIGHT_EXT"), v8::Uint32::NewFromUnsigned(0x2032));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_LARGEST_ARB"), v8::Uint32::NewFromUnsigned(0x2033));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_LARGEST_EXT"), v8::Uint32::NewFromUnsigned(0x2033));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_WIDTH_ARB"), v8::Uint32::NewFromUnsigned(0x2034));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_WIDTH_EXT"), v8::Uint32::NewFromUnsigned(0x2034));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_HEIGHT_ARB"), v8::Uint32::NewFromUnsigned(0x2035));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_HEIGHT_EXT"), v8::Uint32::NewFromUnsigned(0x2035));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_PBUFFER_LOST_ARB"), v8::Uint32::NewFromUnsigned(0x2036));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_RED_VALUE_ARB"), v8::Uint32::NewFromUnsigned(0x2037));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_GREEN_VALUE_ARB"), v8::Uint32::NewFromUnsigned(0x2038));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_BLUE_VALUE_ARB"), v8::Uint32::NewFromUnsigned(0x2039));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_ALPHA_VALUE_ARB"), v8::Uint32::NewFromUnsigned(0x203A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TRANSPARENT_INDEX_VALUE_ARB"), v8::Uint32::NewFromUnsigned(0x203B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DEPTH_FLOAT_EXT"), v8::Uint32::NewFromUnsigned(0x2040));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SAMPLE_BUFFERS_ARB"), v8::Uint32::NewFromUnsigned(0x2041));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SAMPLE_BUFFERS_EXT"), v8::Uint32::NewFromUnsigned(0x2041));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_COVERAGE_SAMPLES_NV"), v8::Uint32::NewFromUnsigned(0x2042));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SAMPLES_ARB"), v8::Uint32::NewFromUnsigned(0x2042));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SAMPLES_EXT"), v8::Uint32::NewFromUnsigned(0x2042));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_INVALID_PIXEL_TYPE_ARB"), v8::Uint32::NewFromUnsigned(0x2043));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_INVALID_PIXEL_TYPE_EXT"), v8::Uint32::NewFromUnsigned(0x2043));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_MULTIVIEW_I3D"), v8::Uint32::NewFromUnsigned(0x2044));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D"), v8::Uint32::NewFromUnsigned(0x2045));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D"), v8::Uint32::NewFromUnsigned(0x2046));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D"), v8::Uint32::NewFromUnsigned(0x2047));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D"), v8::Uint32::NewFromUnsigned(0x2048));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D"), v8::Uint32::NewFromUnsigned(0x2049));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D"), v8::Uint32::NewFromUnsigned(0x204A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_EDGE_RISING_I3D"), v8::Uint32::NewFromUnsigned(0x204B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D"), v8::Uint32::NewFromUnsigned(0x204C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GAMMA_TABLE_SIZE_I3D"), v8::Uint32::NewFromUnsigned(0x204E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GAMMA_EXCLUDE_DESKTOP_I3D"), v8::Uint32::NewFromUnsigned(0x204F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D"), v8::Uint32::NewFromUnsigned(0x2050));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D"), v8::Uint32::NewFromUnsigned(0x2051));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D"), v8::Uint32::NewFromUnsigned(0x2052));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D"), v8::Uint32::NewFromUnsigned(0x2053));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB"), v8::Uint32::NewFromUnsigned(0x2054));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STEREO_EMITTER_ENABLE_3DL"), v8::Uint32::NewFromUnsigned(0x2055));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STEREO_EMITTER_DISABLE_3DL"), v8::Uint32::NewFromUnsigned(0x2056));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STEREO_POLARITY_NORMAL_3DL"), v8::Uint32::NewFromUnsigned(0x2057));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_STEREO_POLARITY_INVERT_3DL"), v8::Uint32::NewFromUnsigned(0x2058));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SAMPLE_BUFFERS_3DFX"), v8::Uint32::NewFromUnsigned(0x2060));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_SAMPLES_3DFX"), v8::Uint32::NewFromUnsigned(0x2061));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RGB_ARB"), v8::Uint32::NewFromUnsigned(0x2070));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RGBA_ARB"), v8::Uint32::NewFromUnsigned(0x2071));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_FORMAT_ARB"), v8::Uint32::NewFromUnsigned(0x2072));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_TARGET_ARB"), v8::Uint32::NewFromUnsigned(0x2073));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MIPMAP_TEXTURE_ARB"), v8::Uint32::NewFromUnsigned(0x2074));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_RGB_ARB"), v8::Uint32::NewFromUnsigned(0x2075));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_RGBA_ARB"), v8::Uint32::NewFromUnsigned(0x2076));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NO_TEXTURE_ARB"), v8::Uint32::NewFromUnsigned(0x2077));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_ARB"), v8::Uint32::NewFromUnsigned(0x2078));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_1D_ARB"), v8::Uint32::NewFromUnsigned(0x2079));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_2D_ARB"), v8::Uint32::NewFromUnsigned(0x207A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_MIPMAP_LEVEL_ARB"), v8::Uint32::NewFromUnsigned(0x207B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CUBE_MAP_FACE_ARB"), v8::Uint32::NewFromUnsigned(0x207C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB"), v8::Uint32::NewFromUnsigned(0x207D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB"), v8::Uint32::NewFromUnsigned(0x207E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB"), v8::Uint32::NewFromUnsigned(0x207F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB"), v8::Uint32::NewFromUnsigned(0x2080));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB"), v8::Uint32::NewFromUnsigned(0x2081));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB"), v8::Uint32::NewFromUnsigned(0x2082));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FRONT_LEFT_ARB"), v8::Uint32::NewFromUnsigned(0x2083));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FRONT_RIGHT_ARB"), v8::Uint32::NewFromUnsigned(0x2084));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BACK_LEFT_ARB"), v8::Uint32::NewFromUnsigned(0x2085));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BACK_RIGHT_ARB"), v8::Uint32::NewFromUnsigned(0x2086));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX0_ARB"), v8::Uint32::NewFromUnsigned(0x2087));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX1_ARB"), v8::Uint32::NewFromUnsigned(0x2088));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX2_ARB"), v8::Uint32::NewFromUnsigned(0x2089));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX3_ARB"), v8::Uint32::NewFromUnsigned(0x208A));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX4_ARB"), v8::Uint32::NewFromUnsigned(0x208B));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX5_ARB"), v8::Uint32::NewFromUnsigned(0x208C));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX6_ARB"), v8::Uint32::NewFromUnsigned(0x208D));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX7_ARB"), v8::Uint32::NewFromUnsigned(0x208E));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX8_ARB"), v8::Uint32::NewFromUnsigned(0x208F));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_AUX9_ARB"), v8::Uint32::NewFromUnsigned(0x2090));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_MAJOR_VERSION_ARB"), v8::Uint32::NewFromUnsigned(0x2091));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_MINOR_VERSION_ARB"), v8::Uint32::NewFromUnsigned(0x2092));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_LAYER_PLANE_ARB"), v8::Uint32::NewFromUnsigned(0x2093));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_FLAGS_ARB"), v8::Uint32::NewFromUnsigned(0x2094));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_INVALID_VERSION_ARB"), v8::Uint32::NewFromUnsigned(0x2095));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_INVALID_PROFILE_ARB"), v8::Uint32::NewFromUnsigned(0x2096));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV"), v8::Uint32::NewFromUnsigned(0x20A0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV"), v8::Uint32::NewFromUnsigned(0x20A1));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_RECTANGLE_NV"), v8::Uint32::NewFromUnsigned(0x20A2));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_DEPTH_NV"), v8::Uint32::NewFromUnsigned(0x20A3));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV"), v8::Uint32::NewFromUnsigned(0x20A4));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DEPTH_TEXTURE_FORMAT_NV"), v8::Uint32::NewFromUnsigned(0x20A5));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_DEPTH_COMPONENT_NV"), v8::Uint32::NewFromUnsigned(0x20A6));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_DEPTH_COMPONENT_NV"), v8::Uint32::NewFromUnsigned(0x20A7));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT"), v8::Uint32::NewFromUnsigned(0x20A8));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB"), v8::Uint32::NewFromUnsigned(0x20A9));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT"), v8::Uint32::NewFromUnsigned(0x20A9));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_FLOAT_COMPONENTS_NV"), v8::Uint32::NewFromUnsigned(0x20B0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV"), v8::Uint32::NewFromUnsigned(0x20B1));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV"), v8::Uint32::NewFromUnsigned(0x20B2));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV"), v8::Uint32::NewFromUnsigned(0x20B3));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV"), v8::Uint32::NewFromUnsigned(0x20B4));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_FLOAT_R_NV"), v8::Uint32::NewFromUnsigned(0x20B5));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_FLOAT_RG_NV"), v8::Uint32::NewFromUnsigned(0x20B6));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_FLOAT_RGB_NV"), v8::Uint32::NewFromUnsigned(0x20B7));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TEXTURE_FLOAT_RGBA_NV"), v8::Uint32::NewFromUnsigned(0x20B8));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_COLOR_SAMPLES_NV"), v8::Uint32::NewFromUnsigned(0x20B9));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_VIDEO_RGB_NV"), v8::Uint32::NewFromUnsigned(0x20C0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_VIDEO_RGBA_NV"), v8::Uint32::NewFromUnsigned(0x20C1));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV"), v8::Uint32::NewFromUnsigned(0x20C2));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_COLOR_NV"), v8::Uint32::NewFromUnsigned(0x20C3));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_ALPHA_NV"), v8::Uint32::NewFromUnsigned(0x20C4));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_DEPTH_NV"), v8::Uint32::NewFromUnsigned(0x20C5));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV"), v8::Uint32::NewFromUnsigned(0x20C6));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV"), v8::Uint32::NewFromUnsigned(0x20C7));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_FRAME"), v8::Uint32::NewFromUnsigned(0x20C8));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_FIELD_1"), v8::Uint32::NewFromUnsigned(0x20C9));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_FIELD_2"), v8::Uint32::NewFromUnsigned(0x20CA));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_STACKED_FIELDS_1_2"), v8::Uint32::NewFromUnsigned(0x20CB));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_VIDEO_OUT_STACKED_FIELDS_2_1"), v8::Uint32::NewFromUnsigned(0x20CC));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_UNIQUE_ID_NV"), v8::Uint32::NewFromUnsigned(0x20CE));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUM_VIDEO_CAPTURE_SLOTS_NV"), v8::Uint32::NewFromUnsigned(0x20CF));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV"), v8::Uint32::NewFromUnsigned(0x20D0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("ERROR_MISSING_AFFINITY_MASK_NV"), v8::Uint32::NewFromUnsigned(0x20D1));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NUM_VIDEO_SLOTS_NV"), v8::Uint32::NewFromUnsigned(0x20F0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_RGBA_FLOAT_ARB"), v8::Uint32::NewFromUnsigned(0x21A0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_TYPE_RGBA_FLOAT_ATI"), v8::Uint32::NewFromUnsigned(0x21A0));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_FASTEST_TARGET_GPUS_AMD"), v8::Uint32::NewFromUnsigned(0x21A2));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_RAM_AMD"), v8::Uint32::NewFromUnsigned(0x21A3));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_CLOCK_AMD"), v8::Uint32::NewFromUnsigned(0x21A4));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_NUM_PIPES_AMD"), v8::Uint32::NewFromUnsigned(0x21A5));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_NUM_SIMD_AMD"), v8::Uint32::NewFromUnsigned(0x21A6));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_NUM_RB_AMD"), v8::Uint32::NewFromUnsigned(0x21A7));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_GPU_NUM_SPI_AMD"), v8::Uint32::NewFromUnsigned(0x21A8));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_LOSE_CONTEXT_ON_RESET_ARB"), v8::Uint32::NewFromUnsigned(0x8252));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB"), v8::Uint32::NewFromUnsigned(0x8256));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_NO_RESET_NOTIFICATION_ARB"), v8::Uint32::NewFromUnsigned(0x8261));
		tpl->PrototypeTemplate()->Set(v8::String::NewSymbol("WGL_CONTEXT_PROFILE_MASK_ARB"), v8::Uint32::NewFromUnsigned(0x9126));

		constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
		retTpl = v8::Persistent<v8::ObjectTemplate>::New(v8::ObjectTemplate::New());
		retTpl->SetInternalFieldCount(1);

		target->Set(v8::String::NewSymbol("WGL"), constructor);

	}

	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		v8::HandleScope scope;

		const unsigned argc = 1;
		v8::Handle<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

		return scope.Close(instance);
	}
private:
	class_WGL() {
		OutputDebugString(L"WGL()");
	}
	~class_WGL() {
		OutputDebugString(L"~WGL()");
	}
	static v8::Handle<v8::Value> New(const v8::Arguments& args) {
		v8::HandleScope scope;
		class_WGL* obj = new class_WGL();
		obj->Wrap(args.This());
		HMODULE modOpenGL32{nullptr};
		HMODULE modGdi32{nullptr};
		BOOL getModOpenGL32Status = GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, L"OpenGL32", &modOpenGL32);
		BOOL getModGdi32Status = GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, L"Gdi32", &modGdi32);
		if(!obj->methodp_ChoosePixelFormat) { obj->methodp_ChoosePixelFormat = (PFNCHOOSEPIXELFORMATPROC)wglGetProcAddress("ChoosePixelFormat"); }
		if(!obj->methodp_ChoosePixelFormat) { obj->methodp_ChoosePixelFormat = (PFNCHOOSEPIXELFORMATPROC)GetProcAddress(modOpenGL32, "ChoosePixelFormat"); }
		if(!obj->methodp_ChoosePixelFormat) { obj->methodp_ChoosePixelFormat = (PFNCHOOSEPIXELFORMATPROC)GetProcAddress(modGdi32, "ChoosePixelFormat"); }
		if(!obj->methodp_ChoosePixelFormat) { args.This()->Set(v8::String::NewSymbol("ChoosePixelFormat"), v8::Undefined()); }
		if(!obj->methodp_DescribePixelFormat) { obj->methodp_DescribePixelFormat = (PFNDESCRIBEPIXELFORMATPROC)wglGetProcAddress("DescribePixelFormat"); }
		if(!obj->methodp_DescribePixelFormat) { obj->methodp_DescribePixelFormat = (PFNDESCRIBEPIXELFORMATPROC)GetProcAddress(modOpenGL32, "DescribePixelFormat"); }
		if(!obj->methodp_DescribePixelFormat) { obj->methodp_DescribePixelFormat = (PFNDESCRIBEPIXELFORMATPROC)GetProcAddress(modGdi32, "DescribePixelFormat"); }
		if(!obj->methodp_DescribePixelFormat) { args.This()->Set(v8::String::NewSymbol("DescribePixelFormat"), v8::Undefined()); }
		if(!obj->methodp_GetPixelFormat) { obj->methodp_GetPixelFormat = (PFNGETPIXELFORMATPROC)wglGetProcAddress("GetPixelFormat"); }
		if(!obj->methodp_GetPixelFormat) { obj->methodp_GetPixelFormat = (PFNGETPIXELFORMATPROC)GetProcAddress(modOpenGL32, "GetPixelFormat"); }
		if(!obj->methodp_GetPixelFormat) { obj->methodp_GetPixelFormat = (PFNGETPIXELFORMATPROC)GetProcAddress(modGdi32, "GetPixelFormat"); }
		if(!obj->methodp_GetPixelFormat) { args.This()->Set(v8::String::NewSymbol("GetPixelFormat"), v8::Undefined()); }
		if(!obj->methodp_SetPixelFormat) { obj->methodp_SetPixelFormat = (PFNSETPIXELFORMATPROC)wglGetProcAddress("SetPixelFormat"); }
		if(!obj->methodp_SetPixelFormat) { obj->methodp_SetPixelFormat = (PFNSETPIXELFORMATPROC)GetProcAddress(modOpenGL32, "SetPixelFormat"); }
		if(!obj->methodp_SetPixelFormat) { obj->methodp_SetPixelFormat = (PFNSETPIXELFORMATPROC)GetProcAddress(modGdi32, "SetPixelFormat"); }
		if(!obj->methodp_SetPixelFormat) { args.This()->Set(v8::String::NewSymbol("SetPixelFormat"), v8::Undefined()); }
		if(!obj->methodp_SwapBuffers) { obj->methodp_SwapBuffers = (PFNSWAPBUFFERSPROC)wglGetProcAddress("SwapBuffers"); }
		if(!obj->methodp_SwapBuffers) { obj->methodp_SwapBuffers = (PFNSWAPBUFFERSPROC)GetProcAddress(modOpenGL32, "SwapBuffers"); }
		if(!obj->methodp_SwapBuffers) { obj->methodp_SwapBuffers = (PFNSWAPBUFFERSPROC)GetProcAddress(modGdi32, "SwapBuffers"); }
		if(!obj->methodp_SwapBuffers) { args.This()->Set(v8::String::NewSymbol("SwapBuffers"), v8::Undefined()); }
		if(!obj->methodp_wglAllocateMemoryNV) { obj->methodp_wglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC)wglGetProcAddress("wglAllocateMemoryNV"); }
		if(!obj->methodp_wglAllocateMemoryNV) { obj->methodp_wglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC)GetProcAddress(modOpenGL32, "wglAllocateMemoryNV"); }
		if(!obj->methodp_wglAllocateMemoryNV) { obj->methodp_wglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC)GetProcAddress(modGdi32, "wglAllocateMemoryNV"); }
		if(!obj->methodp_wglAllocateMemoryNV) { args.This()->Set(v8::String::NewSymbol("wglAllocateMemoryNV"), v8::Undefined()); }
		if(!obj->methodp_wglAssociateImageBufferEventsI3D) { obj->methodp_wglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)wglGetProcAddress("wglAssociateImageBufferEventsI3D"); }
		if(!obj->methodp_wglAssociateImageBufferEventsI3D) { obj->methodp_wglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)GetProcAddress(modOpenGL32, "wglAssociateImageBufferEventsI3D"); }
		if(!obj->methodp_wglAssociateImageBufferEventsI3D) { obj->methodp_wglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)GetProcAddress(modGdi32, "wglAssociateImageBufferEventsI3D"); }
		if(!obj->methodp_wglAssociateImageBufferEventsI3D) { args.This()->Set(v8::String::NewSymbol("wglAssociateImageBufferEventsI3D"), v8::Undefined()); }
		if(!obj->methodp_wglBeginFrameTrackingI3D) { obj->methodp_wglBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3DPROC)wglGetProcAddress("wglBeginFrameTrackingI3D"); }
		if(!obj->methodp_wglBeginFrameTrackingI3D) { obj->methodp_wglBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3DPROC)GetProcAddress(modOpenGL32, "wglBeginFrameTrackingI3D"); }
		if(!obj->methodp_wglBeginFrameTrackingI3D) { obj->methodp_wglBeginFrameTrackingI3D = (PFNWGLBEGINFRAMETRACKINGI3DPROC)GetProcAddress(modGdi32, "wglBeginFrameTrackingI3D"); }
		if(!obj->methodp_wglBeginFrameTrackingI3D) { args.This()->Set(v8::String::NewSymbol("wglBeginFrameTrackingI3D"), v8::Undefined()); }
		if(!obj->methodp_wglBindDisplayColorTableEXT) { obj->methodp_wglBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglBindDisplayColorTableEXT"); }
		if(!obj->methodp_wglBindDisplayColorTableEXT) { obj->methodp_wglBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modOpenGL32, "wglBindDisplayColorTableEXT"); }
		if(!obj->methodp_wglBindDisplayColorTableEXT) { obj->methodp_wglBindDisplayColorTableEXT = (PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modGdi32, "wglBindDisplayColorTableEXT"); }
		if(!obj->methodp_wglBindDisplayColorTableEXT) { args.This()->Set(v8::String::NewSymbol("wglBindDisplayColorTableEXT"), v8::Undefined()); }
		if(!obj->methodp_wglBindSwapBarrierNV) { obj->methodp_wglBindSwapBarrierNV = (PFNWGLBINDSWAPBARRIERNVPROC)wglGetProcAddress("wglBindSwapBarrierNV"); }
		if(!obj->methodp_wglBindSwapBarrierNV) { obj->methodp_wglBindSwapBarrierNV = (PFNWGLBINDSWAPBARRIERNVPROC)GetProcAddress(modOpenGL32, "wglBindSwapBarrierNV"); }
		if(!obj->methodp_wglBindSwapBarrierNV) { obj->methodp_wglBindSwapBarrierNV = (PFNWGLBINDSWAPBARRIERNVPROC)GetProcAddress(modGdi32, "wglBindSwapBarrierNV"); }
		if(!obj->methodp_wglBindSwapBarrierNV) { args.This()->Set(v8::String::NewSymbol("wglBindSwapBarrierNV"), v8::Undefined()); }
		if(!obj->methodp_wglBindTexImageARB) { obj->methodp_wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC)wglGetProcAddress("wglBindTexImageARB"); }
		if(!obj->methodp_wglBindTexImageARB) { obj->methodp_wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC)GetProcAddress(modOpenGL32, "wglBindTexImageARB"); }
		if(!obj->methodp_wglBindTexImageARB) { obj->methodp_wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC)GetProcAddress(modGdi32, "wglBindTexImageARB"); }
		if(!obj->methodp_wglBindTexImageARB) { args.This()->Set(v8::String::NewSymbol("wglBindTexImageARB"), v8::Undefined()); }
		if(!obj->methodp_wglBindVideoCaptureDeviceNV) { obj->methodp_wglBindVideoCaptureDeviceNV = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglBindVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglBindVideoCaptureDeviceNV) { obj->methodp_wglBindVideoCaptureDeviceNV = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modOpenGL32, "wglBindVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglBindVideoCaptureDeviceNV) { obj->methodp_wglBindVideoCaptureDeviceNV = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modGdi32, "wglBindVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglBindVideoCaptureDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglBindVideoCaptureDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglBindVideoDeviceNV) { obj->methodp_wglBindVideoDeviceNV = (PFNWGLBINDVIDEODEVICENVPROC)wglGetProcAddress("wglBindVideoDeviceNV"); }
		if(!obj->methodp_wglBindVideoDeviceNV) { obj->methodp_wglBindVideoDeviceNV = (PFNWGLBINDVIDEODEVICENVPROC)GetProcAddress(modOpenGL32, "wglBindVideoDeviceNV"); }
		if(!obj->methodp_wglBindVideoDeviceNV) { obj->methodp_wglBindVideoDeviceNV = (PFNWGLBINDVIDEODEVICENVPROC)GetProcAddress(modGdi32, "wglBindVideoDeviceNV"); }
		if(!obj->methodp_wglBindVideoDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglBindVideoDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglBindVideoImageNV) { obj->methodp_wglBindVideoImageNV = (PFNWGLBINDVIDEOIMAGENVPROC)wglGetProcAddress("wglBindVideoImageNV"); }
		if(!obj->methodp_wglBindVideoImageNV) { obj->methodp_wglBindVideoImageNV = (PFNWGLBINDVIDEOIMAGENVPROC)GetProcAddress(modOpenGL32, "wglBindVideoImageNV"); }
		if(!obj->methodp_wglBindVideoImageNV) { obj->methodp_wglBindVideoImageNV = (PFNWGLBINDVIDEOIMAGENVPROC)GetProcAddress(modGdi32, "wglBindVideoImageNV"); }
		if(!obj->methodp_wglBindVideoImageNV) { args.This()->Set(v8::String::NewSymbol("wglBindVideoImageNV"), v8::Undefined()); }
		if(!obj->methodp_wglBlitContextFramebufferAMD) { obj->methodp_wglBlitContextFramebufferAMD = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)wglGetProcAddress("wglBlitContextFramebufferAMD"); }
		if(!obj->methodp_wglBlitContextFramebufferAMD) { obj->methodp_wglBlitContextFramebufferAMD = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)GetProcAddress(modOpenGL32, "wglBlitContextFramebufferAMD"); }
		if(!obj->methodp_wglBlitContextFramebufferAMD) { obj->methodp_wglBlitContextFramebufferAMD = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)GetProcAddress(modGdi32, "wglBlitContextFramebufferAMD"); }
		if(!obj->methodp_wglBlitContextFramebufferAMD) { args.This()->Set(v8::String::NewSymbol("wglBlitContextFramebufferAMD"), v8::Undefined()); }
		if(!obj->methodp_wglChoosePixelFormatARB) { obj->methodp_wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB"); }
		if(!obj->methodp_wglChoosePixelFormatARB) { obj->methodp_wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)GetProcAddress(modOpenGL32, "wglChoosePixelFormatARB"); }
		if(!obj->methodp_wglChoosePixelFormatARB) { obj->methodp_wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)GetProcAddress(modGdi32, "wglChoosePixelFormatARB"); }
		if(!obj->methodp_wglChoosePixelFormatARB) { args.This()->Set(v8::String::NewSymbol("wglChoosePixelFormatARB"), v8::Undefined()); }
		if(!obj->methodp_wglChoosePixelFormatEXT) { obj->methodp_wglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC)wglGetProcAddress("wglChoosePixelFormatEXT"); }
		if(!obj->methodp_wglChoosePixelFormatEXT) { obj->methodp_wglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC)GetProcAddress(modOpenGL32, "wglChoosePixelFormatEXT"); }
		if(!obj->methodp_wglChoosePixelFormatEXT) { obj->methodp_wglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC)GetProcAddress(modGdi32, "wglChoosePixelFormatEXT"); }
		if(!obj->methodp_wglChoosePixelFormatEXT) { args.This()->Set(v8::String::NewSymbol("wglChoosePixelFormatEXT"), v8::Undefined()); }
		if(!obj->methodp_wglCopyContext) { obj->methodp_wglCopyContext = (PFNWGLCOPYCONTEXTPROC)wglGetProcAddress("wglCopyContext"); }
		if(!obj->methodp_wglCopyContext) { obj->methodp_wglCopyContext = (PFNWGLCOPYCONTEXTPROC)GetProcAddress(modOpenGL32, "wglCopyContext"); }
		if(!obj->methodp_wglCopyContext) { obj->methodp_wglCopyContext = (PFNWGLCOPYCONTEXTPROC)GetProcAddress(modGdi32, "wglCopyContext"); }
		if(!obj->methodp_wglCopyContext) { args.This()->Set(v8::String::NewSymbol("wglCopyContext"), v8::Undefined()); }
		if(!obj->methodp_wglCopyImageSubDataNV) { obj->methodp_wglCopyImageSubDataNV = (PFNWGLCOPYIMAGESUBDATANVPROC)wglGetProcAddress("wglCopyImageSubDataNV"); }
		if(!obj->methodp_wglCopyImageSubDataNV) { obj->methodp_wglCopyImageSubDataNV = (PFNWGLCOPYIMAGESUBDATANVPROC)GetProcAddress(modOpenGL32, "wglCopyImageSubDataNV"); }
		if(!obj->methodp_wglCopyImageSubDataNV) { obj->methodp_wglCopyImageSubDataNV = (PFNWGLCOPYIMAGESUBDATANVPROC)GetProcAddress(modGdi32, "wglCopyImageSubDataNV"); }
		if(!obj->methodp_wglCopyImageSubDataNV) { args.This()->Set(v8::String::NewSymbol("wglCopyImageSubDataNV"), v8::Undefined()); }
		if(!obj->methodp_wglCreateAffinityDCNV) { obj->methodp_wglCreateAffinityDCNV = (PFNWGLCREATEAFFINITYDCNVPROC)wglGetProcAddress("wglCreateAffinityDCNV"); }
		if(!obj->methodp_wglCreateAffinityDCNV) { obj->methodp_wglCreateAffinityDCNV = (PFNWGLCREATEAFFINITYDCNVPROC)GetProcAddress(modOpenGL32, "wglCreateAffinityDCNV"); }
		if(!obj->methodp_wglCreateAffinityDCNV) { obj->methodp_wglCreateAffinityDCNV = (PFNWGLCREATEAFFINITYDCNVPROC)GetProcAddress(modGdi32, "wglCreateAffinityDCNV"); }
		if(!obj->methodp_wglCreateAffinityDCNV) { args.This()->Set(v8::String::NewSymbol("wglCreateAffinityDCNV"), v8::Undefined()); }
		if(!obj->methodp_wglCreateAssociatedContextAMD) { obj->methodp_wglCreateAssociatedContextAMD = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglCreateAssociatedContextAMD"); }
		if(!obj->methodp_wglCreateAssociatedContextAMD) { obj->methodp_wglCreateAssociatedContextAMD = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)GetProcAddress(modOpenGL32, "wglCreateAssociatedContextAMD"); }
		if(!obj->methodp_wglCreateAssociatedContextAMD) { obj->methodp_wglCreateAssociatedContextAMD = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)GetProcAddress(modGdi32, "wglCreateAssociatedContextAMD"); }
		if(!obj->methodp_wglCreateAssociatedContextAMD) { args.This()->Set(v8::String::NewSymbol("wglCreateAssociatedContextAMD"), v8::Undefined()); }
		if(!obj->methodp_wglCreateAssociatedContextAttribsAMD) { obj->methodp_wglCreateAssociatedContextAttribsAMD = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)wglGetProcAddress("wglCreateAssociatedContextAttribsAMD"); }
		if(!obj->methodp_wglCreateAssociatedContextAttribsAMD) { obj->methodp_wglCreateAssociatedContextAttribsAMD = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)GetProcAddress(modOpenGL32, "wglCreateAssociatedContextAttribsAMD"); }
		if(!obj->methodp_wglCreateAssociatedContextAttribsAMD) { obj->methodp_wglCreateAssociatedContextAttribsAMD = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)GetProcAddress(modGdi32, "wglCreateAssociatedContextAttribsAMD"); }
		if(!obj->methodp_wglCreateAssociatedContextAttribsAMD) { args.This()->Set(v8::String::NewSymbol("wglCreateAssociatedContextAttribsAMD"), v8::Undefined()); }
		if(!obj->methodp_wglCreateBufferRegionARB) { obj->methodp_wglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC)wglGetProcAddress("wglCreateBufferRegionARB"); }
		if(!obj->methodp_wglCreateBufferRegionARB) { obj->methodp_wglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC)GetProcAddress(modOpenGL32, "wglCreateBufferRegionARB"); }
		if(!obj->methodp_wglCreateBufferRegionARB) { obj->methodp_wglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC)GetProcAddress(modGdi32, "wglCreateBufferRegionARB"); }
		if(!obj->methodp_wglCreateBufferRegionARB) { args.This()->Set(v8::String::NewSymbol("wglCreateBufferRegionARB"), v8::Undefined()); }
		if(!obj->methodp_wglCreateContext) { obj->methodp_wglCreateContext = (PFNWGLCREATECONTEXTPROC)wglGetProcAddress("wglCreateContext"); }
		if(!obj->methodp_wglCreateContext) { obj->methodp_wglCreateContext = (PFNWGLCREATECONTEXTPROC)GetProcAddress(modOpenGL32, "wglCreateContext"); }
		if(!obj->methodp_wglCreateContext) { obj->methodp_wglCreateContext = (PFNWGLCREATECONTEXTPROC)GetProcAddress(modGdi32, "wglCreateContext"); }
		if(!obj->methodp_wglCreateContext) { args.This()->Set(v8::String::NewSymbol("wglCreateContext"), v8::Undefined()); }
		if(!obj->methodp_wglCreateContextAttribsARB) { obj->methodp_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB"); }
		if(!obj->methodp_wglCreateContextAttribsARB) { obj->methodp_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)GetProcAddress(modOpenGL32, "wglCreateContextAttribsARB"); }
		if(!obj->methodp_wglCreateContextAttribsARB) { obj->methodp_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)GetProcAddress(modGdi32, "wglCreateContextAttribsARB"); }
		if(!obj->methodp_wglCreateContextAttribsARB) { args.This()->Set(v8::String::NewSymbol("wglCreateContextAttribsARB"), v8::Undefined()); }
		if(!obj->methodp_wglCreateDisplayColorTableEXT) { obj->methodp_wglCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglCreateDisplayColorTableEXT"); }
		if(!obj->methodp_wglCreateDisplayColorTableEXT) { obj->methodp_wglCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modOpenGL32, "wglCreateDisplayColorTableEXT"); }
		if(!obj->methodp_wglCreateDisplayColorTableEXT) { obj->methodp_wglCreateDisplayColorTableEXT = (PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modGdi32, "wglCreateDisplayColorTableEXT"); }
		if(!obj->methodp_wglCreateDisplayColorTableEXT) { args.This()->Set(v8::String::NewSymbol("wglCreateDisplayColorTableEXT"), v8::Undefined()); }
		if(!obj->methodp_wglCreateImageBufferI3D) { obj->methodp_wglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC)wglGetProcAddress("wglCreateImageBufferI3D"); }
		if(!obj->methodp_wglCreateImageBufferI3D) { obj->methodp_wglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC)GetProcAddress(modOpenGL32, "wglCreateImageBufferI3D"); }
		if(!obj->methodp_wglCreateImageBufferI3D) { obj->methodp_wglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC)GetProcAddress(modGdi32, "wglCreateImageBufferI3D"); }
		if(!obj->methodp_wglCreateImageBufferI3D) { args.This()->Set(v8::String::NewSymbol("wglCreateImageBufferI3D"), v8::Undefined()); }
		if(!obj->methodp_wglCreateLayerContext) { obj->methodp_wglCreateLayerContext = (PFNWGLCREATELAYERCONTEXTPROC)wglGetProcAddress("wglCreateLayerContext"); }
		if(!obj->methodp_wglCreateLayerContext) { obj->methodp_wglCreateLayerContext = (PFNWGLCREATELAYERCONTEXTPROC)GetProcAddress(modOpenGL32, "wglCreateLayerContext"); }
		if(!obj->methodp_wglCreateLayerContext) { obj->methodp_wglCreateLayerContext = (PFNWGLCREATELAYERCONTEXTPROC)GetProcAddress(modGdi32, "wglCreateLayerContext"); }
		if(!obj->methodp_wglCreateLayerContext) { args.This()->Set(v8::String::NewSymbol("wglCreateLayerContext"), v8::Undefined()); }
		if(!obj->methodp_wglCreatePbufferARB) { obj->methodp_wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC)wglGetProcAddress("wglCreatePbufferARB"); }
		if(!obj->methodp_wglCreatePbufferARB) { obj->methodp_wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC)GetProcAddress(modOpenGL32, "wglCreatePbufferARB"); }
		if(!obj->methodp_wglCreatePbufferARB) { obj->methodp_wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC)GetProcAddress(modGdi32, "wglCreatePbufferARB"); }
		if(!obj->methodp_wglCreatePbufferARB) { args.This()->Set(v8::String::NewSymbol("wglCreatePbufferARB"), v8::Undefined()); }
		if(!obj->methodp_wglCreatePbufferEXT) { obj->methodp_wglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC)wglGetProcAddress("wglCreatePbufferEXT"); }
		if(!obj->methodp_wglCreatePbufferEXT) { obj->methodp_wglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC)GetProcAddress(modOpenGL32, "wglCreatePbufferEXT"); }
		if(!obj->methodp_wglCreatePbufferEXT) { obj->methodp_wglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC)GetProcAddress(modGdi32, "wglCreatePbufferEXT"); }
		if(!obj->methodp_wglCreatePbufferEXT) { args.This()->Set(v8::String::NewSymbol("wglCreatePbufferEXT"), v8::Undefined()); }
		if(!obj->methodp_wglDelayBeforeSwapNV) { obj->methodp_wglDelayBeforeSwapNV = (PFNWGLDELAYBEFORESWAPNVPROC)wglGetProcAddress("wglDelayBeforeSwapNV"); }
		if(!obj->methodp_wglDelayBeforeSwapNV) { obj->methodp_wglDelayBeforeSwapNV = (PFNWGLDELAYBEFORESWAPNVPROC)GetProcAddress(modOpenGL32, "wglDelayBeforeSwapNV"); }
		if(!obj->methodp_wglDelayBeforeSwapNV) { obj->methodp_wglDelayBeforeSwapNV = (PFNWGLDELAYBEFORESWAPNVPROC)GetProcAddress(modGdi32, "wglDelayBeforeSwapNV"); }
		if(!obj->methodp_wglDelayBeforeSwapNV) { args.This()->Set(v8::String::NewSymbol("wglDelayBeforeSwapNV"), v8::Undefined()); }
		if(!obj->methodp_wglDeleteAssociatedContextAMD) { obj->methodp_wglDeleteAssociatedContextAMD = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglDeleteAssociatedContextAMD"); }
		if(!obj->methodp_wglDeleteAssociatedContextAMD) { obj->methodp_wglDeleteAssociatedContextAMD = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)GetProcAddress(modOpenGL32, "wglDeleteAssociatedContextAMD"); }
		if(!obj->methodp_wglDeleteAssociatedContextAMD) { obj->methodp_wglDeleteAssociatedContextAMD = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)GetProcAddress(modGdi32, "wglDeleteAssociatedContextAMD"); }
		if(!obj->methodp_wglDeleteAssociatedContextAMD) { args.This()->Set(v8::String::NewSymbol("wglDeleteAssociatedContextAMD"), v8::Undefined()); }
		if(!obj->methodp_wglDeleteBufferRegionARB) { obj->methodp_wglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC)wglGetProcAddress("wglDeleteBufferRegionARB"); }
		if(!obj->methodp_wglDeleteBufferRegionARB) { obj->methodp_wglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC)GetProcAddress(modOpenGL32, "wglDeleteBufferRegionARB"); }
		if(!obj->methodp_wglDeleteBufferRegionARB) { obj->methodp_wglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC)GetProcAddress(modGdi32, "wglDeleteBufferRegionARB"); }
		if(!obj->methodp_wglDeleteBufferRegionARB) { args.This()->Set(v8::String::NewSymbol("wglDeleteBufferRegionARB"), v8::Undefined()); }
		if(!obj->methodp_wglDeleteContext) { obj->methodp_wglDeleteContext = (PFNWGLDELETECONTEXTPROC)wglGetProcAddress("wglDeleteContext"); }
		if(!obj->methodp_wglDeleteContext) { obj->methodp_wglDeleteContext = (PFNWGLDELETECONTEXTPROC)GetProcAddress(modOpenGL32, "wglDeleteContext"); }
		if(!obj->methodp_wglDeleteContext) { obj->methodp_wglDeleteContext = (PFNWGLDELETECONTEXTPROC)GetProcAddress(modGdi32, "wglDeleteContext"); }
		if(!obj->methodp_wglDeleteContext) { args.This()->Set(v8::String::NewSymbol("wglDeleteContext"), v8::Undefined()); }
		if(!obj->methodp_wglDeleteDCNV) { obj->methodp_wglDeleteDCNV = (PFNWGLDELETEDCNVPROC)wglGetProcAddress("wglDeleteDCNV"); }
		if(!obj->methodp_wglDeleteDCNV) { obj->methodp_wglDeleteDCNV = (PFNWGLDELETEDCNVPROC)GetProcAddress(modOpenGL32, "wglDeleteDCNV"); }
		if(!obj->methodp_wglDeleteDCNV) { obj->methodp_wglDeleteDCNV = (PFNWGLDELETEDCNVPROC)GetProcAddress(modGdi32, "wglDeleteDCNV"); }
		if(!obj->methodp_wglDeleteDCNV) { args.This()->Set(v8::String::NewSymbol("wglDeleteDCNV"), v8::Undefined()); }
		if(!obj->methodp_wglDescribeLayerPlane) { obj->methodp_wglDescribeLayerPlane = (PFNWGLDESCRIBELAYERPLANEPROC)wglGetProcAddress("wglDescribeLayerPlane"); }
		if(!obj->methodp_wglDescribeLayerPlane) { obj->methodp_wglDescribeLayerPlane = (PFNWGLDESCRIBELAYERPLANEPROC)GetProcAddress(modOpenGL32, "wglDescribeLayerPlane"); }
		if(!obj->methodp_wglDescribeLayerPlane) { obj->methodp_wglDescribeLayerPlane = (PFNWGLDESCRIBELAYERPLANEPROC)GetProcAddress(modGdi32, "wglDescribeLayerPlane"); }
		if(!obj->methodp_wglDescribeLayerPlane) { args.This()->Set(v8::String::NewSymbol("wglDescribeLayerPlane"), v8::Undefined()); }
		if(!obj->methodp_wglDestroyDisplayColorTableEXT) { obj->methodp_wglDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglDestroyDisplayColorTableEXT"); }
		if(!obj->methodp_wglDestroyDisplayColorTableEXT) { obj->methodp_wglDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modOpenGL32, "wglDestroyDisplayColorTableEXT"); }
		if(!obj->methodp_wglDestroyDisplayColorTableEXT) { obj->methodp_wglDestroyDisplayColorTableEXT = (PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modGdi32, "wglDestroyDisplayColorTableEXT"); }
		if(!obj->methodp_wglDestroyDisplayColorTableEXT) { args.This()->Set(v8::String::NewSymbol("wglDestroyDisplayColorTableEXT"), v8::Undefined()); }
		if(!obj->methodp_wglDestroyImageBufferI3D) { obj->methodp_wglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)wglGetProcAddress("wglDestroyImageBufferI3D"); }
		if(!obj->methodp_wglDestroyImageBufferI3D) { obj->methodp_wglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)GetProcAddress(modOpenGL32, "wglDestroyImageBufferI3D"); }
		if(!obj->methodp_wglDestroyImageBufferI3D) { obj->methodp_wglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)GetProcAddress(modGdi32, "wglDestroyImageBufferI3D"); }
		if(!obj->methodp_wglDestroyImageBufferI3D) { args.This()->Set(v8::String::NewSymbol("wglDestroyImageBufferI3D"), v8::Undefined()); }
		if(!obj->methodp_wglDestroyPbufferARB) { obj->methodp_wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC)wglGetProcAddress("wglDestroyPbufferARB"); }
		if(!obj->methodp_wglDestroyPbufferARB) { obj->methodp_wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC)GetProcAddress(modOpenGL32, "wglDestroyPbufferARB"); }
		if(!obj->methodp_wglDestroyPbufferARB) { obj->methodp_wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC)GetProcAddress(modGdi32, "wglDestroyPbufferARB"); }
		if(!obj->methodp_wglDestroyPbufferARB) { args.This()->Set(v8::String::NewSymbol("wglDestroyPbufferARB"), v8::Undefined()); }
		if(!obj->methodp_wglDestroyPbufferEXT) { obj->methodp_wglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC)wglGetProcAddress("wglDestroyPbufferEXT"); }
		if(!obj->methodp_wglDestroyPbufferEXT) { obj->methodp_wglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC)GetProcAddress(modOpenGL32, "wglDestroyPbufferEXT"); }
		if(!obj->methodp_wglDestroyPbufferEXT) { obj->methodp_wglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC)GetProcAddress(modGdi32, "wglDestroyPbufferEXT"); }
		if(!obj->methodp_wglDestroyPbufferEXT) { args.This()->Set(v8::String::NewSymbol("wglDestroyPbufferEXT"), v8::Undefined()); }
		if(!obj->methodp_wglDisableFrameLockI3D) { obj->methodp_wglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC)wglGetProcAddress("wglDisableFrameLockI3D"); }
		if(!obj->methodp_wglDisableFrameLockI3D) { obj->methodp_wglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC)GetProcAddress(modOpenGL32, "wglDisableFrameLockI3D"); }
		if(!obj->methodp_wglDisableFrameLockI3D) { obj->methodp_wglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC)GetProcAddress(modGdi32, "wglDisableFrameLockI3D"); }
		if(!obj->methodp_wglDisableFrameLockI3D) { args.This()->Set(v8::String::NewSymbol("wglDisableFrameLockI3D"), v8::Undefined()); }
		if(!obj->methodp_wglDisableGenlockI3D) { obj->methodp_wglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC)wglGetProcAddress("wglDisableGenlockI3D"); }
		if(!obj->methodp_wglDisableGenlockI3D) { obj->methodp_wglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC)GetProcAddress(modOpenGL32, "wglDisableGenlockI3D"); }
		if(!obj->methodp_wglDisableGenlockI3D) { obj->methodp_wglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC)GetProcAddress(modGdi32, "wglDisableGenlockI3D"); }
		if(!obj->methodp_wglDisableGenlockI3D) { args.This()->Set(v8::String::NewSymbol("wglDisableGenlockI3D"), v8::Undefined()); }
		if(!obj->methodp_wglDXCloseDeviceNV) { obj->methodp_wglDXCloseDeviceNV = (PFNWGLDXCLOSEDEVICENVPROC)wglGetProcAddress("wglDXCloseDeviceNV"); }
		if(!obj->methodp_wglDXCloseDeviceNV) { obj->methodp_wglDXCloseDeviceNV = (PFNWGLDXCLOSEDEVICENVPROC)GetProcAddress(modOpenGL32, "wglDXCloseDeviceNV"); }
		if(!obj->methodp_wglDXCloseDeviceNV) { obj->methodp_wglDXCloseDeviceNV = (PFNWGLDXCLOSEDEVICENVPROC)GetProcAddress(modGdi32, "wglDXCloseDeviceNV"); }
		if(!obj->methodp_wglDXCloseDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglDXCloseDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXLockObjectsNV) { obj->methodp_wglDXLockObjectsNV = (PFNWGLDXLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXLockObjectsNV"); }
		if(!obj->methodp_wglDXLockObjectsNV) { obj->methodp_wglDXLockObjectsNV = (PFNWGLDXLOCKOBJECTSNVPROC)GetProcAddress(modOpenGL32, "wglDXLockObjectsNV"); }
		if(!obj->methodp_wglDXLockObjectsNV) { obj->methodp_wglDXLockObjectsNV = (PFNWGLDXLOCKOBJECTSNVPROC)GetProcAddress(modGdi32, "wglDXLockObjectsNV"); }
		if(!obj->methodp_wglDXLockObjectsNV) { args.This()->Set(v8::String::NewSymbol("wglDXLockObjectsNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXObjectAccessNV) { obj->methodp_wglDXObjectAccessNV = (PFNWGLDXOBJECTACCESSNVPROC)wglGetProcAddress("wglDXObjectAccessNV"); }
		if(!obj->methodp_wglDXObjectAccessNV) { obj->methodp_wglDXObjectAccessNV = (PFNWGLDXOBJECTACCESSNVPROC)GetProcAddress(modOpenGL32, "wglDXObjectAccessNV"); }
		if(!obj->methodp_wglDXObjectAccessNV) { obj->methodp_wglDXObjectAccessNV = (PFNWGLDXOBJECTACCESSNVPROC)GetProcAddress(modGdi32, "wglDXObjectAccessNV"); }
		if(!obj->methodp_wglDXObjectAccessNV) { args.This()->Set(v8::String::NewSymbol("wglDXObjectAccessNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXOpenDeviceNV) { obj->methodp_wglDXOpenDeviceNV = (PFNWGLDXOPENDEVICENVPROC)wglGetProcAddress("wglDXOpenDeviceNV"); }
		if(!obj->methodp_wglDXOpenDeviceNV) { obj->methodp_wglDXOpenDeviceNV = (PFNWGLDXOPENDEVICENVPROC)GetProcAddress(modOpenGL32, "wglDXOpenDeviceNV"); }
		if(!obj->methodp_wglDXOpenDeviceNV) { obj->methodp_wglDXOpenDeviceNV = (PFNWGLDXOPENDEVICENVPROC)GetProcAddress(modGdi32, "wglDXOpenDeviceNV"); }
		if(!obj->methodp_wglDXOpenDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglDXOpenDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXRegisterObjectNV) { obj->methodp_wglDXRegisterObjectNV = (PFNWGLDXREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXRegisterObjectNV"); }
		if(!obj->methodp_wglDXRegisterObjectNV) { obj->methodp_wglDXRegisterObjectNV = (PFNWGLDXREGISTEROBJECTNVPROC)GetProcAddress(modOpenGL32, "wglDXRegisterObjectNV"); }
		if(!obj->methodp_wglDXRegisterObjectNV) { obj->methodp_wglDXRegisterObjectNV = (PFNWGLDXREGISTEROBJECTNVPROC)GetProcAddress(modGdi32, "wglDXRegisterObjectNV"); }
		if(!obj->methodp_wglDXRegisterObjectNV) { args.This()->Set(v8::String::NewSymbol("wglDXRegisterObjectNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXSetResourceShareHandleNV) { obj->methodp_wglDXSetResourceShareHandleNV = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)wglGetProcAddress("wglDXSetResourceShareHandleNV"); }
		if(!obj->methodp_wglDXSetResourceShareHandleNV) { obj->methodp_wglDXSetResourceShareHandleNV = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)GetProcAddress(modOpenGL32, "wglDXSetResourceShareHandleNV"); }
		if(!obj->methodp_wglDXSetResourceShareHandleNV) { obj->methodp_wglDXSetResourceShareHandleNV = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)GetProcAddress(modGdi32, "wglDXSetResourceShareHandleNV"); }
		if(!obj->methodp_wglDXSetResourceShareHandleNV) { args.This()->Set(v8::String::NewSymbol("wglDXSetResourceShareHandleNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXUnlockObjectsNV) { obj->methodp_wglDXUnlockObjectsNV = (PFNWGLDXUNLOCKOBJECTSNVPROC)wglGetProcAddress("wglDXUnlockObjectsNV"); }
		if(!obj->methodp_wglDXUnlockObjectsNV) { obj->methodp_wglDXUnlockObjectsNV = (PFNWGLDXUNLOCKOBJECTSNVPROC)GetProcAddress(modOpenGL32, "wglDXUnlockObjectsNV"); }
		if(!obj->methodp_wglDXUnlockObjectsNV) { obj->methodp_wglDXUnlockObjectsNV = (PFNWGLDXUNLOCKOBJECTSNVPROC)GetProcAddress(modGdi32, "wglDXUnlockObjectsNV"); }
		if(!obj->methodp_wglDXUnlockObjectsNV) { args.This()->Set(v8::String::NewSymbol("wglDXUnlockObjectsNV"), v8::Undefined()); }
		if(!obj->methodp_wglDXUnregisterObjectNV) { obj->methodp_wglDXUnregisterObjectNV = (PFNWGLDXUNREGISTEROBJECTNVPROC)wglGetProcAddress("wglDXUnregisterObjectNV"); }
		if(!obj->methodp_wglDXUnregisterObjectNV) { obj->methodp_wglDXUnregisterObjectNV = (PFNWGLDXUNREGISTEROBJECTNVPROC)GetProcAddress(modOpenGL32, "wglDXUnregisterObjectNV"); }
		if(!obj->methodp_wglDXUnregisterObjectNV) { obj->methodp_wglDXUnregisterObjectNV = (PFNWGLDXUNREGISTEROBJECTNVPROC)GetProcAddress(modGdi32, "wglDXUnregisterObjectNV"); }
		if(!obj->methodp_wglDXUnregisterObjectNV) { args.This()->Set(v8::String::NewSymbol("wglDXUnregisterObjectNV"), v8::Undefined()); }
		if(!obj->methodp_wglEnableFrameLockI3D) { obj->methodp_wglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC)wglGetProcAddress("wglEnableFrameLockI3D"); }
		if(!obj->methodp_wglEnableFrameLockI3D) { obj->methodp_wglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC)GetProcAddress(modOpenGL32, "wglEnableFrameLockI3D"); }
		if(!obj->methodp_wglEnableFrameLockI3D) { obj->methodp_wglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC)GetProcAddress(modGdi32, "wglEnableFrameLockI3D"); }
		if(!obj->methodp_wglEnableFrameLockI3D) { args.This()->Set(v8::String::NewSymbol("wglEnableFrameLockI3D"), v8::Undefined()); }
		if(!obj->methodp_wglEnableGenlockI3D) { obj->methodp_wglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC)wglGetProcAddress("wglEnableGenlockI3D"); }
		if(!obj->methodp_wglEnableGenlockI3D) { obj->methodp_wglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC)GetProcAddress(modOpenGL32, "wglEnableGenlockI3D"); }
		if(!obj->methodp_wglEnableGenlockI3D) { obj->methodp_wglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC)GetProcAddress(modGdi32, "wglEnableGenlockI3D"); }
		if(!obj->methodp_wglEnableGenlockI3D) { args.This()->Set(v8::String::NewSymbol("wglEnableGenlockI3D"), v8::Undefined()); }
		if(!obj->methodp_wglEndFrameTrackingI3D) { obj->methodp_wglEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3DPROC)wglGetProcAddress("wglEndFrameTrackingI3D"); }
		if(!obj->methodp_wglEndFrameTrackingI3D) { obj->methodp_wglEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3DPROC)GetProcAddress(modOpenGL32, "wglEndFrameTrackingI3D"); }
		if(!obj->methodp_wglEndFrameTrackingI3D) { obj->methodp_wglEndFrameTrackingI3D = (PFNWGLENDFRAMETRACKINGI3DPROC)GetProcAddress(modGdi32, "wglEndFrameTrackingI3D"); }
		if(!obj->methodp_wglEndFrameTrackingI3D) { args.This()->Set(v8::String::NewSymbol("wglEndFrameTrackingI3D"), v8::Undefined()); }
		if(!obj->methodp_wglEnumerateVideoCaptureDevicesNV) { obj->methodp_wglEnumerateVideoCaptureDevicesNV = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)wglGetProcAddress("wglEnumerateVideoCaptureDevicesNV"); }
		if(!obj->methodp_wglEnumerateVideoCaptureDevicesNV) { obj->methodp_wglEnumerateVideoCaptureDevicesNV = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)GetProcAddress(modOpenGL32, "wglEnumerateVideoCaptureDevicesNV"); }
		if(!obj->methodp_wglEnumerateVideoCaptureDevicesNV) { obj->methodp_wglEnumerateVideoCaptureDevicesNV = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)GetProcAddress(modGdi32, "wglEnumerateVideoCaptureDevicesNV"); }
		if(!obj->methodp_wglEnumerateVideoCaptureDevicesNV) { args.This()->Set(v8::String::NewSymbol("wglEnumerateVideoCaptureDevicesNV"), v8::Undefined()); }
		if(!obj->methodp_wglEnumerateVideoDevicesNV) { obj->methodp_wglEnumerateVideoDevicesNV = (PFNWGLENUMERATEVIDEODEVICESNVPROC)wglGetProcAddress("wglEnumerateVideoDevicesNV"); }
		if(!obj->methodp_wglEnumerateVideoDevicesNV) { obj->methodp_wglEnumerateVideoDevicesNV = (PFNWGLENUMERATEVIDEODEVICESNVPROC)GetProcAddress(modOpenGL32, "wglEnumerateVideoDevicesNV"); }
		if(!obj->methodp_wglEnumerateVideoDevicesNV) { obj->methodp_wglEnumerateVideoDevicesNV = (PFNWGLENUMERATEVIDEODEVICESNVPROC)GetProcAddress(modGdi32, "wglEnumerateVideoDevicesNV"); }
		if(!obj->methodp_wglEnumerateVideoDevicesNV) { args.This()->Set(v8::String::NewSymbol("wglEnumerateVideoDevicesNV"), v8::Undefined()); }
		if(!obj->methodp_wglEnumGpuDevicesNV) { obj->methodp_wglEnumGpuDevicesNV = (PFNWGLENUMGPUDEVICESNVPROC)wglGetProcAddress("wglEnumGpuDevicesNV"); }
		if(!obj->methodp_wglEnumGpuDevicesNV) { obj->methodp_wglEnumGpuDevicesNV = (PFNWGLENUMGPUDEVICESNVPROC)GetProcAddress(modOpenGL32, "wglEnumGpuDevicesNV"); }
		if(!obj->methodp_wglEnumGpuDevicesNV) { obj->methodp_wglEnumGpuDevicesNV = (PFNWGLENUMGPUDEVICESNVPROC)GetProcAddress(modGdi32, "wglEnumGpuDevicesNV"); }
		if(!obj->methodp_wglEnumGpuDevicesNV) { args.This()->Set(v8::String::NewSymbol("wglEnumGpuDevicesNV"), v8::Undefined()); }
		if(!obj->methodp_wglEnumGpusFromAffinityDCNV) { obj->methodp_wglEnumGpusFromAffinityDCNV = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)wglGetProcAddress("wglEnumGpusFromAffinityDCNV"); }
		if(!obj->methodp_wglEnumGpusFromAffinityDCNV) { obj->methodp_wglEnumGpusFromAffinityDCNV = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)GetProcAddress(modOpenGL32, "wglEnumGpusFromAffinityDCNV"); }
		if(!obj->methodp_wglEnumGpusFromAffinityDCNV) { obj->methodp_wglEnumGpusFromAffinityDCNV = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)GetProcAddress(modGdi32, "wglEnumGpusFromAffinityDCNV"); }
		if(!obj->methodp_wglEnumGpusFromAffinityDCNV) { args.This()->Set(v8::String::NewSymbol("wglEnumGpusFromAffinityDCNV"), v8::Undefined()); }
		if(!obj->methodp_wglEnumGpusNV) { obj->methodp_wglEnumGpusNV = (PFNWGLENUMGPUSNVPROC)wglGetProcAddress("wglEnumGpusNV"); }
		if(!obj->methodp_wglEnumGpusNV) { obj->methodp_wglEnumGpusNV = (PFNWGLENUMGPUSNVPROC)GetProcAddress(modOpenGL32, "wglEnumGpusNV"); }
		if(!obj->methodp_wglEnumGpusNV) { obj->methodp_wglEnumGpusNV = (PFNWGLENUMGPUSNVPROC)GetProcAddress(modGdi32, "wglEnumGpusNV"); }
		if(!obj->methodp_wglEnumGpusNV) { args.This()->Set(v8::String::NewSymbol("wglEnumGpusNV"), v8::Undefined()); }
		if(!obj->methodp_wglFreeMemoryNV) { obj->methodp_wglFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC)wglGetProcAddress("wglFreeMemoryNV"); }
		if(!obj->methodp_wglFreeMemoryNV) { obj->methodp_wglFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC)GetProcAddress(modOpenGL32, "wglFreeMemoryNV"); }
		if(!obj->methodp_wglFreeMemoryNV) { obj->methodp_wglFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC)GetProcAddress(modGdi32, "wglFreeMemoryNV"); }
		if(!obj->methodp_wglFreeMemoryNV) { args.This()->Set(v8::String::NewSymbol("wglFreeMemoryNV"), v8::Undefined()); }
		if(!obj->methodp_wglGenlockSampleRateI3D) { obj->methodp_wglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC)wglGetProcAddress("wglGenlockSampleRateI3D"); }
		if(!obj->methodp_wglGenlockSampleRateI3D) { obj->methodp_wglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC)GetProcAddress(modOpenGL32, "wglGenlockSampleRateI3D"); }
		if(!obj->methodp_wglGenlockSampleRateI3D) { obj->methodp_wglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC)GetProcAddress(modGdi32, "wglGenlockSampleRateI3D"); }
		if(!obj->methodp_wglGenlockSampleRateI3D) { args.This()->Set(v8::String::NewSymbol("wglGenlockSampleRateI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGenlockSourceDelayI3D) { obj->methodp_wglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)wglGetProcAddress("wglGenlockSourceDelayI3D"); }
		if(!obj->methodp_wglGenlockSourceDelayI3D) { obj->methodp_wglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)GetProcAddress(modOpenGL32, "wglGenlockSourceDelayI3D"); }
		if(!obj->methodp_wglGenlockSourceDelayI3D) { obj->methodp_wglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)GetProcAddress(modGdi32, "wglGenlockSourceDelayI3D"); }
		if(!obj->methodp_wglGenlockSourceDelayI3D) { args.This()->Set(v8::String::NewSymbol("wglGenlockSourceDelayI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGenlockSourceEdgeI3D) { obj->methodp_wglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)wglGetProcAddress("wglGenlockSourceEdgeI3D"); }
		if(!obj->methodp_wglGenlockSourceEdgeI3D) { obj->methodp_wglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)GetProcAddress(modOpenGL32, "wglGenlockSourceEdgeI3D"); }
		if(!obj->methodp_wglGenlockSourceEdgeI3D) { obj->methodp_wglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)GetProcAddress(modGdi32, "wglGenlockSourceEdgeI3D"); }
		if(!obj->methodp_wglGenlockSourceEdgeI3D) { args.This()->Set(v8::String::NewSymbol("wglGenlockSourceEdgeI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGenlockSourceI3D) { obj->methodp_wglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC)wglGetProcAddress("wglGenlockSourceI3D"); }
		if(!obj->methodp_wglGenlockSourceI3D) { obj->methodp_wglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC)GetProcAddress(modOpenGL32, "wglGenlockSourceI3D"); }
		if(!obj->methodp_wglGenlockSourceI3D) { obj->methodp_wglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC)GetProcAddress(modGdi32, "wglGenlockSourceI3D"); }
		if(!obj->methodp_wglGenlockSourceI3D) { args.This()->Set(v8::String::NewSymbol("wglGenlockSourceI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetContextGPUIDAMD) { obj->methodp_wglGetContextGPUIDAMD = (PFNWGLGETCONTEXTGPUIDAMDPROC)wglGetProcAddress("wglGetContextGPUIDAMD"); }
		if(!obj->methodp_wglGetContextGPUIDAMD) { obj->methodp_wglGetContextGPUIDAMD = (PFNWGLGETCONTEXTGPUIDAMDPROC)GetProcAddress(modOpenGL32, "wglGetContextGPUIDAMD"); }
		if(!obj->methodp_wglGetContextGPUIDAMD) { obj->methodp_wglGetContextGPUIDAMD = (PFNWGLGETCONTEXTGPUIDAMDPROC)GetProcAddress(modGdi32, "wglGetContextGPUIDAMD"); }
		if(!obj->methodp_wglGetContextGPUIDAMD) { args.This()->Set(v8::String::NewSymbol("wglGetContextGPUIDAMD"), v8::Undefined()); }
		if(!obj->methodp_wglGetCurrentAssociatedContextAMD) { obj->methodp_wglGetCurrentAssociatedContextAMD = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)wglGetProcAddress("wglGetCurrentAssociatedContextAMD"); }
		if(!obj->methodp_wglGetCurrentAssociatedContextAMD) { obj->methodp_wglGetCurrentAssociatedContextAMD = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)GetProcAddress(modOpenGL32, "wglGetCurrentAssociatedContextAMD"); }
		if(!obj->methodp_wglGetCurrentAssociatedContextAMD) { obj->methodp_wglGetCurrentAssociatedContextAMD = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)GetProcAddress(modGdi32, "wglGetCurrentAssociatedContextAMD"); }
		if(!obj->methodp_wglGetCurrentAssociatedContextAMD) { args.This()->Set(v8::String::NewSymbol("wglGetCurrentAssociatedContextAMD"), v8::Undefined()); }
		if(!obj->methodp_wglGetCurrentContext) { obj->methodp_wglGetCurrentContext = (PFNWGLGETCURRENTCONTEXTPROC)wglGetProcAddress("wglGetCurrentContext"); }
		if(!obj->methodp_wglGetCurrentContext) { obj->methodp_wglGetCurrentContext = (PFNWGLGETCURRENTCONTEXTPROC)GetProcAddress(modOpenGL32, "wglGetCurrentContext"); }
		if(!obj->methodp_wglGetCurrentContext) { obj->methodp_wglGetCurrentContext = (PFNWGLGETCURRENTCONTEXTPROC)GetProcAddress(modGdi32, "wglGetCurrentContext"); }
		if(!obj->methodp_wglGetCurrentContext) { args.This()->Set(v8::String::NewSymbol("wglGetCurrentContext"), v8::Undefined()); }
		if(!obj->methodp_wglGetCurrentDC) { obj->methodp_wglGetCurrentDC = (PFNWGLGETCURRENTDCPROC)wglGetProcAddress("wglGetCurrentDC"); }
		if(!obj->methodp_wglGetCurrentDC) { obj->methodp_wglGetCurrentDC = (PFNWGLGETCURRENTDCPROC)GetProcAddress(modOpenGL32, "wglGetCurrentDC"); }
		if(!obj->methodp_wglGetCurrentDC) { obj->methodp_wglGetCurrentDC = (PFNWGLGETCURRENTDCPROC)GetProcAddress(modGdi32, "wglGetCurrentDC"); }
		if(!obj->methodp_wglGetCurrentDC) { args.This()->Set(v8::String::NewSymbol("wglGetCurrentDC"), v8::Undefined()); }
		if(!obj->methodp_wglGetCurrentReadDCARB) { obj->methodp_wglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC)wglGetProcAddress("wglGetCurrentReadDCARB"); }
		if(!obj->methodp_wglGetCurrentReadDCARB) { obj->methodp_wglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC)GetProcAddress(modOpenGL32, "wglGetCurrentReadDCARB"); }
		if(!obj->methodp_wglGetCurrentReadDCARB) { obj->methodp_wglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC)GetProcAddress(modGdi32, "wglGetCurrentReadDCARB"); }
		if(!obj->methodp_wglGetCurrentReadDCARB) { args.This()->Set(v8::String::NewSymbol("wglGetCurrentReadDCARB"), v8::Undefined()); }
		if(!obj->methodp_wglGetCurrentReadDCEXT) { obj->methodp_wglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC)wglGetProcAddress("wglGetCurrentReadDCEXT"); }
		if(!obj->methodp_wglGetCurrentReadDCEXT) { obj->methodp_wglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC)GetProcAddress(modOpenGL32, "wglGetCurrentReadDCEXT"); }
		if(!obj->methodp_wglGetCurrentReadDCEXT) { obj->methodp_wglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC)GetProcAddress(modGdi32, "wglGetCurrentReadDCEXT"); }
		if(!obj->methodp_wglGetCurrentReadDCEXT) { args.This()->Set(v8::String::NewSymbol("wglGetCurrentReadDCEXT"), v8::Undefined()); }
		if(!obj->methodp_wglGetDefaultProcAddress) { obj->methodp_wglGetDefaultProcAddress = (PFNWGLGETDEFAULTPROCADDRESSPROC)wglGetProcAddress("wglGetDefaultProcAddress"); }
		if(!obj->methodp_wglGetDefaultProcAddress) { obj->methodp_wglGetDefaultProcAddress = (PFNWGLGETDEFAULTPROCADDRESSPROC)GetProcAddress(modOpenGL32, "wglGetDefaultProcAddress"); }
		if(!obj->methodp_wglGetDefaultProcAddress) { obj->methodp_wglGetDefaultProcAddress = (PFNWGLGETDEFAULTPROCADDRESSPROC)GetProcAddress(modGdi32, "wglGetDefaultProcAddress"); }
		if(!obj->methodp_wglGetDefaultProcAddress) { args.This()->Set(v8::String::NewSymbol("wglGetDefaultProcAddress"), v8::Undefined()); }
		if(!obj->methodp_wglGetDigitalVideoParametersI3D) { obj->methodp_wglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)wglGetProcAddress("wglGetDigitalVideoParametersI3D"); }
		if(!obj->methodp_wglGetDigitalVideoParametersI3D) { obj->methodp_wglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)GetProcAddress(modOpenGL32, "wglGetDigitalVideoParametersI3D"); }
		if(!obj->methodp_wglGetDigitalVideoParametersI3D) { obj->methodp_wglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)GetProcAddress(modGdi32, "wglGetDigitalVideoParametersI3D"); }
		if(!obj->methodp_wglGetDigitalVideoParametersI3D) { args.This()->Set(v8::String::NewSymbol("wglGetDigitalVideoParametersI3D"), v8::Undefined()); }
		if(!obj->methodp_GetEnhMetaFilePixelFormat) { obj->methodp_GetEnhMetaFilePixelFormat = (PFNGETENHMETAFILEPIXELFORMATPROC)wglGetProcAddress("GetEnhMetaFilePixelFormat"); }
		if(!obj->methodp_GetEnhMetaFilePixelFormat) { obj->methodp_GetEnhMetaFilePixelFormat = (PFNGETENHMETAFILEPIXELFORMATPROC)GetProcAddress(modOpenGL32, "GetEnhMetaFilePixelFormat"); }
		if(!obj->methodp_GetEnhMetaFilePixelFormat) { obj->methodp_GetEnhMetaFilePixelFormat = (PFNGETENHMETAFILEPIXELFORMATPROC)GetProcAddress(modGdi32, "GetEnhMetaFilePixelFormat"); }
		if(!obj->methodp_GetEnhMetaFilePixelFormat) { args.This()->Set(v8::String::NewSymbol("GetEnhMetaFilePixelFormat"), v8::Undefined()); }
		if(!obj->methodp_wglGetExtensionsStringARB) { obj->methodp_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB"); }
		if(!obj->methodp_wglGetExtensionsStringARB) { obj->methodp_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)GetProcAddress(modOpenGL32, "wglGetExtensionsStringARB"); }
		if(!obj->methodp_wglGetExtensionsStringARB) { obj->methodp_wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)GetProcAddress(modGdi32, "wglGetExtensionsStringARB"); }
		if(!obj->methodp_wglGetExtensionsStringARB) { args.This()->Set(v8::String::NewSymbol("wglGetExtensionsStringARB"), v8::Undefined()); }
		if(!obj->methodp_wglGetExtensionsStringEXT) { obj->methodp_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)wglGetProcAddress("wglGetExtensionsStringEXT"); }
		if(!obj->methodp_wglGetExtensionsStringEXT) { obj->methodp_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)GetProcAddress(modOpenGL32, "wglGetExtensionsStringEXT"); }
		if(!obj->methodp_wglGetExtensionsStringEXT) { obj->methodp_wglGetExtensionsStringEXT = (PFNWGLGETEXTENSIONSSTRINGEXTPROC)GetProcAddress(modGdi32, "wglGetExtensionsStringEXT"); }
		if(!obj->methodp_wglGetExtensionsStringEXT) { args.This()->Set(v8::String::NewSymbol("wglGetExtensionsStringEXT"), v8::Undefined()); }
		if(!obj->methodp_wglGetFrameUsageI3D) { obj->methodp_wglGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3DPROC)wglGetProcAddress("wglGetFrameUsageI3D"); }
		if(!obj->methodp_wglGetFrameUsageI3D) { obj->methodp_wglGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3DPROC)GetProcAddress(modOpenGL32, "wglGetFrameUsageI3D"); }
		if(!obj->methodp_wglGetFrameUsageI3D) { obj->methodp_wglGetFrameUsageI3D = (PFNWGLGETFRAMEUSAGEI3DPROC)GetProcAddress(modGdi32, "wglGetFrameUsageI3D"); }
		if(!obj->methodp_wglGetFrameUsageI3D) { args.This()->Set(v8::String::NewSymbol("wglGetFrameUsageI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGammaTableI3D) { obj->methodp_wglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC)wglGetProcAddress("wglGetGammaTableI3D"); }
		if(!obj->methodp_wglGetGammaTableI3D) { obj->methodp_wglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC)GetProcAddress(modOpenGL32, "wglGetGammaTableI3D"); }
		if(!obj->methodp_wglGetGammaTableI3D) { obj->methodp_wglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC)GetProcAddress(modGdi32, "wglGetGammaTableI3D"); }
		if(!obj->methodp_wglGetGammaTableI3D) { args.This()->Set(v8::String::NewSymbol("wglGetGammaTableI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGammaTableParametersI3D) { obj->methodp_wglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)wglGetProcAddress("wglGetGammaTableParametersI3D"); }
		if(!obj->methodp_wglGetGammaTableParametersI3D) { obj->methodp_wglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)GetProcAddress(modOpenGL32, "wglGetGammaTableParametersI3D"); }
		if(!obj->methodp_wglGetGammaTableParametersI3D) { obj->methodp_wglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)GetProcAddress(modGdi32, "wglGetGammaTableParametersI3D"); }
		if(!obj->methodp_wglGetGammaTableParametersI3D) { args.This()->Set(v8::String::NewSymbol("wglGetGammaTableParametersI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGenlockSampleRateI3D) { obj->methodp_wglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)wglGetProcAddress("wglGetGenlockSampleRateI3D"); }
		if(!obj->methodp_wglGetGenlockSampleRateI3D) { obj->methodp_wglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)GetProcAddress(modOpenGL32, "wglGetGenlockSampleRateI3D"); }
		if(!obj->methodp_wglGetGenlockSampleRateI3D) { obj->methodp_wglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)GetProcAddress(modGdi32, "wglGetGenlockSampleRateI3D"); }
		if(!obj->methodp_wglGetGenlockSampleRateI3D) { args.This()->Set(v8::String::NewSymbol("wglGetGenlockSampleRateI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGenlockSourceDelayI3D) { obj->methodp_wglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)wglGetProcAddress("wglGetGenlockSourceDelayI3D"); }
		if(!obj->methodp_wglGetGenlockSourceDelayI3D) { obj->methodp_wglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)GetProcAddress(modOpenGL32, "wglGetGenlockSourceDelayI3D"); }
		if(!obj->methodp_wglGetGenlockSourceDelayI3D) { obj->methodp_wglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)GetProcAddress(modGdi32, "wglGetGenlockSourceDelayI3D"); }
		if(!obj->methodp_wglGetGenlockSourceDelayI3D) { args.This()->Set(v8::String::NewSymbol("wglGetGenlockSourceDelayI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGenlockSourceEdgeI3D) { obj->methodp_wglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)wglGetProcAddress("wglGetGenlockSourceEdgeI3D"); }
		if(!obj->methodp_wglGetGenlockSourceEdgeI3D) { obj->methodp_wglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)GetProcAddress(modOpenGL32, "wglGetGenlockSourceEdgeI3D"); }
		if(!obj->methodp_wglGetGenlockSourceEdgeI3D) { obj->methodp_wglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)GetProcAddress(modGdi32, "wglGetGenlockSourceEdgeI3D"); }
		if(!obj->methodp_wglGetGenlockSourceEdgeI3D) { args.This()->Set(v8::String::NewSymbol("wglGetGenlockSourceEdgeI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGenlockSourceI3D) { obj->methodp_wglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC)wglGetProcAddress("wglGetGenlockSourceI3D"); }
		if(!obj->methodp_wglGetGenlockSourceI3D) { obj->methodp_wglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC)GetProcAddress(modOpenGL32, "wglGetGenlockSourceI3D"); }
		if(!obj->methodp_wglGetGenlockSourceI3D) { obj->methodp_wglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC)GetProcAddress(modGdi32, "wglGetGenlockSourceI3D"); }
		if(!obj->methodp_wglGetGenlockSourceI3D) { args.This()->Set(v8::String::NewSymbol("wglGetGenlockSourceI3D"), v8::Undefined()); }
		if(!obj->methodp_wglGetGPUIDsAMD) { obj->methodp_wglGetGPUIDsAMD = (PFNWGLGETGPUIDSAMDPROC)wglGetProcAddress("wglGetGPUIDsAMD"); }
		if(!obj->methodp_wglGetGPUIDsAMD) { obj->methodp_wglGetGPUIDsAMD = (PFNWGLGETGPUIDSAMDPROC)GetProcAddress(modOpenGL32, "wglGetGPUIDsAMD"); }
		if(!obj->methodp_wglGetGPUIDsAMD) { obj->methodp_wglGetGPUIDsAMD = (PFNWGLGETGPUIDSAMDPROC)GetProcAddress(modGdi32, "wglGetGPUIDsAMD"); }
		if(!obj->methodp_wglGetGPUIDsAMD) { args.This()->Set(v8::String::NewSymbol("wglGetGPUIDsAMD"), v8::Undefined()); }
		if(!obj->methodp_wglGetGPUInfoAMD) { obj->methodp_wglGetGPUInfoAMD = (PFNWGLGETGPUINFOAMDPROC)wglGetProcAddress("wglGetGPUInfoAMD"); }
		if(!obj->methodp_wglGetGPUInfoAMD) { obj->methodp_wglGetGPUInfoAMD = (PFNWGLGETGPUINFOAMDPROC)GetProcAddress(modOpenGL32, "wglGetGPUInfoAMD"); }
		if(!obj->methodp_wglGetGPUInfoAMD) { obj->methodp_wglGetGPUInfoAMD = (PFNWGLGETGPUINFOAMDPROC)GetProcAddress(modGdi32, "wglGetGPUInfoAMD"); }
		if(!obj->methodp_wglGetGPUInfoAMD) { args.This()->Set(v8::String::NewSymbol("wglGetGPUInfoAMD"), v8::Undefined()); }
		if(!obj->methodp_wglGetLayerPaletteEntries) { obj->methodp_wglGetLayerPaletteEntries = (PFNWGLGETLAYERPALETTEENTRIESPROC)wglGetProcAddress("wglGetLayerPaletteEntries"); }
		if(!obj->methodp_wglGetLayerPaletteEntries) { obj->methodp_wglGetLayerPaletteEntries = (PFNWGLGETLAYERPALETTEENTRIESPROC)GetProcAddress(modOpenGL32, "wglGetLayerPaletteEntries"); }
		if(!obj->methodp_wglGetLayerPaletteEntries) { obj->methodp_wglGetLayerPaletteEntries = (PFNWGLGETLAYERPALETTEENTRIESPROC)GetProcAddress(modGdi32, "wglGetLayerPaletteEntries"); }
		if(!obj->methodp_wglGetLayerPaletteEntries) { args.This()->Set(v8::String::NewSymbol("wglGetLayerPaletteEntries"), v8::Undefined()); }
		if(!obj->methodp_wglGetMscRateOML) { obj->methodp_wglGetMscRateOML = (PFNWGLGETMSCRATEOMLPROC)wglGetProcAddress("wglGetMscRateOML"); }
		if(!obj->methodp_wglGetMscRateOML) { obj->methodp_wglGetMscRateOML = (PFNWGLGETMSCRATEOMLPROC)GetProcAddress(modOpenGL32, "wglGetMscRateOML"); }
		if(!obj->methodp_wglGetMscRateOML) { obj->methodp_wglGetMscRateOML = (PFNWGLGETMSCRATEOMLPROC)GetProcAddress(modGdi32, "wglGetMscRateOML"); }
		if(!obj->methodp_wglGetMscRateOML) { args.This()->Set(v8::String::NewSymbol("wglGetMscRateOML"), v8::Undefined()); }
		if(!obj->methodp_wglGetPbufferDCARB) { obj->methodp_wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC)wglGetProcAddress("wglGetPbufferDCARB"); }
		if(!obj->methodp_wglGetPbufferDCARB) { obj->methodp_wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC)GetProcAddress(modOpenGL32, "wglGetPbufferDCARB"); }
		if(!obj->methodp_wglGetPbufferDCARB) { obj->methodp_wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC)GetProcAddress(modGdi32, "wglGetPbufferDCARB"); }
		if(!obj->methodp_wglGetPbufferDCARB) { args.This()->Set(v8::String::NewSymbol("wglGetPbufferDCARB"), v8::Undefined()); }
		if(!obj->methodp_wglGetPbufferDCEXT) { obj->methodp_wglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC)wglGetProcAddress("wglGetPbufferDCEXT"); }
		if(!obj->methodp_wglGetPbufferDCEXT) { obj->methodp_wglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC)GetProcAddress(modOpenGL32, "wglGetPbufferDCEXT"); }
		if(!obj->methodp_wglGetPbufferDCEXT) { obj->methodp_wglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC)GetProcAddress(modGdi32, "wglGetPbufferDCEXT"); }
		if(!obj->methodp_wglGetPbufferDCEXT) { args.This()->Set(v8::String::NewSymbol("wglGetPbufferDCEXT"), v8::Undefined()); }
		if(!obj->methodp_wglGetPixelFormatAttribfvARB) { obj->methodp_wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribfvARB"); }
		if(!obj->methodp_wglGetPixelFormatAttribfvARB) { obj->methodp_wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)GetProcAddress(modOpenGL32, "wglGetPixelFormatAttribfvARB"); }
		if(!obj->methodp_wglGetPixelFormatAttribfvARB) { obj->methodp_wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)GetProcAddress(modGdi32, "wglGetPixelFormatAttribfvARB"); }
		if(!obj->methodp_wglGetPixelFormatAttribfvARB) { args.This()->Set(v8::String::NewSymbol("wglGetPixelFormatAttribfvARB"), v8::Undefined()); }
		if(!obj->methodp_wglGetPixelFormatAttribfvEXT) { obj->methodp_wglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)wglGetProcAddress("wglGetPixelFormatAttribfvEXT"); }
		if(!obj->methodp_wglGetPixelFormatAttribfvEXT) { obj->methodp_wglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)GetProcAddress(modOpenGL32, "wglGetPixelFormatAttribfvEXT"); }
		if(!obj->methodp_wglGetPixelFormatAttribfvEXT) { obj->methodp_wglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)GetProcAddress(modGdi32, "wglGetPixelFormatAttribfvEXT"); }
		if(!obj->methodp_wglGetPixelFormatAttribfvEXT) { args.This()->Set(v8::String::NewSymbol("wglGetPixelFormatAttribfvEXT"), v8::Undefined()); }
		if(!obj->methodp_wglGetPixelFormatAttribivARB) { obj->methodp_wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)wglGetProcAddress("wglGetPixelFormatAttribivARB"); }
		if(!obj->methodp_wglGetPixelFormatAttribivARB) { obj->methodp_wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)GetProcAddress(modOpenGL32, "wglGetPixelFormatAttribivARB"); }
		if(!obj->methodp_wglGetPixelFormatAttribivARB) { obj->methodp_wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)GetProcAddress(modGdi32, "wglGetPixelFormatAttribivARB"); }
		if(!obj->methodp_wglGetPixelFormatAttribivARB) { args.This()->Set(v8::String::NewSymbol("wglGetPixelFormatAttribivARB"), v8::Undefined()); }
		if(!obj->methodp_wglGetPixelFormatAttribivEXT) { obj->methodp_wglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)wglGetProcAddress("wglGetPixelFormatAttribivEXT"); }
		if(!obj->methodp_wglGetPixelFormatAttribivEXT) { obj->methodp_wglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)GetProcAddress(modOpenGL32, "wglGetPixelFormatAttribivEXT"); }
		if(!obj->methodp_wglGetPixelFormatAttribivEXT) { obj->methodp_wglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)GetProcAddress(modGdi32, "wglGetPixelFormatAttribivEXT"); }
		if(!obj->methodp_wglGetPixelFormatAttribivEXT) { args.This()->Set(v8::String::NewSymbol("wglGetPixelFormatAttribivEXT"), v8::Undefined()); }
		if(!obj->methodp_wglGetProcAddress) { obj->methodp_wglGetProcAddress = (PFNWGLGETPROCADDRESSPROC)wglGetProcAddress("wglGetProcAddress"); }
		if(!obj->methodp_wglGetProcAddress) { obj->methodp_wglGetProcAddress = (PFNWGLGETPROCADDRESSPROC)GetProcAddress(modOpenGL32, "wglGetProcAddress"); }
		if(!obj->methodp_wglGetProcAddress) { obj->methodp_wglGetProcAddress = (PFNWGLGETPROCADDRESSPROC)GetProcAddress(modGdi32, "wglGetProcAddress"); }
		if(!obj->methodp_wglGetProcAddress) { args.This()->Set(v8::String::NewSymbol("wglGetProcAddress"), v8::Undefined()); }
		if(!obj->methodp_wglGetSwapIntervalEXT) { obj->methodp_wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT"); }
		if(!obj->methodp_wglGetSwapIntervalEXT) { obj->methodp_wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)GetProcAddress(modOpenGL32, "wglGetSwapIntervalEXT"); }
		if(!obj->methodp_wglGetSwapIntervalEXT) { obj->methodp_wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)GetProcAddress(modGdi32, "wglGetSwapIntervalEXT"); }
		if(!obj->methodp_wglGetSwapIntervalEXT) { args.This()->Set(v8::String::NewSymbol("wglGetSwapIntervalEXT"), v8::Undefined()); }
		if(!obj->methodp_wglGetSyncValuesOML) { obj->methodp_wglGetSyncValuesOML = (PFNWGLGETSYNCVALUESOMLPROC)wglGetProcAddress("wglGetSyncValuesOML"); }
		if(!obj->methodp_wglGetSyncValuesOML) { obj->methodp_wglGetSyncValuesOML = (PFNWGLGETSYNCVALUESOMLPROC)GetProcAddress(modOpenGL32, "wglGetSyncValuesOML"); }
		if(!obj->methodp_wglGetSyncValuesOML) { obj->methodp_wglGetSyncValuesOML = (PFNWGLGETSYNCVALUESOMLPROC)GetProcAddress(modGdi32, "wglGetSyncValuesOML"); }
		if(!obj->methodp_wglGetSyncValuesOML) { args.This()->Set(v8::String::NewSymbol("wglGetSyncValuesOML"), v8::Undefined()); }
		if(!obj->methodp_wglGetVideoDeviceNV) { obj->methodp_wglGetVideoDeviceNV = (PFNWGLGETVIDEODEVICENVPROC)wglGetProcAddress("wglGetVideoDeviceNV"); }
		if(!obj->methodp_wglGetVideoDeviceNV) { obj->methodp_wglGetVideoDeviceNV = (PFNWGLGETVIDEODEVICENVPROC)GetProcAddress(modOpenGL32, "wglGetVideoDeviceNV"); }
		if(!obj->methodp_wglGetVideoDeviceNV) { obj->methodp_wglGetVideoDeviceNV = (PFNWGLGETVIDEODEVICENVPROC)GetProcAddress(modGdi32, "wglGetVideoDeviceNV"); }
		if(!obj->methodp_wglGetVideoDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglGetVideoDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglGetVideoInfoNV) { obj->methodp_wglGetVideoInfoNV = (PFNWGLGETVIDEOINFONVPROC)wglGetProcAddress("wglGetVideoInfoNV"); }
		if(!obj->methodp_wglGetVideoInfoNV) { obj->methodp_wglGetVideoInfoNV = (PFNWGLGETVIDEOINFONVPROC)GetProcAddress(modOpenGL32, "wglGetVideoInfoNV"); }
		if(!obj->methodp_wglGetVideoInfoNV) { obj->methodp_wglGetVideoInfoNV = (PFNWGLGETVIDEOINFONVPROC)GetProcAddress(modGdi32, "wglGetVideoInfoNV"); }
		if(!obj->methodp_wglGetVideoInfoNV) { args.This()->Set(v8::String::NewSymbol("wglGetVideoInfoNV"), v8::Undefined()); }
		if(!obj->methodp_wglIsEnabledFrameLockI3D) { obj->methodp_wglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC)wglGetProcAddress("wglIsEnabledFrameLockI3D"); }
		if(!obj->methodp_wglIsEnabledFrameLockI3D) { obj->methodp_wglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC)GetProcAddress(modOpenGL32, "wglIsEnabledFrameLockI3D"); }
		if(!obj->methodp_wglIsEnabledFrameLockI3D) { obj->methodp_wglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC)GetProcAddress(modGdi32, "wglIsEnabledFrameLockI3D"); }
		if(!obj->methodp_wglIsEnabledFrameLockI3D) { args.This()->Set(v8::String::NewSymbol("wglIsEnabledFrameLockI3D"), v8::Undefined()); }
		if(!obj->methodp_wglIsEnabledGenlockI3D) { obj->methodp_wglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC)wglGetProcAddress("wglIsEnabledGenlockI3D"); }
		if(!obj->methodp_wglIsEnabledGenlockI3D) { obj->methodp_wglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC)GetProcAddress(modOpenGL32, "wglIsEnabledGenlockI3D"); }
		if(!obj->methodp_wglIsEnabledGenlockI3D) { obj->methodp_wglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC)GetProcAddress(modGdi32, "wglIsEnabledGenlockI3D"); }
		if(!obj->methodp_wglIsEnabledGenlockI3D) { args.This()->Set(v8::String::NewSymbol("wglIsEnabledGenlockI3D"), v8::Undefined()); }
		if(!obj->methodp_wglJoinSwapGroupNV) { obj->methodp_wglJoinSwapGroupNV = (PFNWGLJOINSWAPGROUPNVPROC)wglGetProcAddress("wglJoinSwapGroupNV"); }
		if(!obj->methodp_wglJoinSwapGroupNV) { obj->methodp_wglJoinSwapGroupNV = (PFNWGLJOINSWAPGROUPNVPROC)GetProcAddress(modOpenGL32, "wglJoinSwapGroupNV"); }
		if(!obj->methodp_wglJoinSwapGroupNV) { obj->methodp_wglJoinSwapGroupNV = (PFNWGLJOINSWAPGROUPNVPROC)GetProcAddress(modGdi32, "wglJoinSwapGroupNV"); }
		if(!obj->methodp_wglJoinSwapGroupNV) { args.This()->Set(v8::String::NewSymbol("wglJoinSwapGroupNV"), v8::Undefined()); }
		if(!obj->methodp_wglLoadDisplayColorTableEXT) { obj->methodp_wglLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)wglGetProcAddress("wglLoadDisplayColorTableEXT"); }
		if(!obj->methodp_wglLoadDisplayColorTableEXT) { obj->methodp_wglLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modOpenGL32, "wglLoadDisplayColorTableEXT"); }
		if(!obj->methodp_wglLoadDisplayColorTableEXT) { obj->methodp_wglLoadDisplayColorTableEXT = (PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)GetProcAddress(modGdi32, "wglLoadDisplayColorTableEXT"); }
		if(!obj->methodp_wglLoadDisplayColorTableEXT) { args.This()->Set(v8::String::NewSymbol("wglLoadDisplayColorTableEXT"), v8::Undefined()); }
		if(!obj->methodp_wglLockVideoCaptureDeviceNV) { obj->methodp_wglLockVideoCaptureDeviceNV = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglLockVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglLockVideoCaptureDeviceNV) { obj->methodp_wglLockVideoCaptureDeviceNV = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modOpenGL32, "wglLockVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglLockVideoCaptureDeviceNV) { obj->methodp_wglLockVideoCaptureDeviceNV = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modGdi32, "wglLockVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglLockVideoCaptureDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglLockVideoCaptureDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglMakeAssociatedContextCurrentAMD) { obj->methodp_wglMakeAssociatedContextCurrentAMD = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)wglGetProcAddress("wglMakeAssociatedContextCurrentAMD"); }
		if(!obj->methodp_wglMakeAssociatedContextCurrentAMD) { obj->methodp_wglMakeAssociatedContextCurrentAMD = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)GetProcAddress(modOpenGL32, "wglMakeAssociatedContextCurrentAMD"); }
		if(!obj->methodp_wglMakeAssociatedContextCurrentAMD) { obj->methodp_wglMakeAssociatedContextCurrentAMD = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)GetProcAddress(modGdi32, "wglMakeAssociatedContextCurrentAMD"); }
		if(!obj->methodp_wglMakeAssociatedContextCurrentAMD) { args.This()->Set(v8::String::NewSymbol("wglMakeAssociatedContextCurrentAMD"), v8::Undefined()); }
		if(!obj->methodp_wglMakeContextCurrentARB) { obj->methodp_wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC)wglGetProcAddress("wglMakeContextCurrentARB"); }
		if(!obj->methodp_wglMakeContextCurrentARB) { obj->methodp_wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC)GetProcAddress(modOpenGL32, "wglMakeContextCurrentARB"); }
		if(!obj->methodp_wglMakeContextCurrentARB) { obj->methodp_wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC)GetProcAddress(modGdi32, "wglMakeContextCurrentARB"); }
		if(!obj->methodp_wglMakeContextCurrentARB) { args.This()->Set(v8::String::NewSymbol("wglMakeContextCurrentARB"), v8::Undefined()); }
		if(!obj->methodp_wglMakeContextCurrentEXT) { obj->methodp_wglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC)wglGetProcAddress("wglMakeContextCurrentEXT"); }
		if(!obj->methodp_wglMakeContextCurrentEXT) { obj->methodp_wglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC)GetProcAddress(modOpenGL32, "wglMakeContextCurrentEXT"); }
		if(!obj->methodp_wglMakeContextCurrentEXT) { obj->methodp_wglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC)GetProcAddress(modGdi32, "wglMakeContextCurrentEXT"); }
		if(!obj->methodp_wglMakeContextCurrentEXT) { args.This()->Set(v8::String::NewSymbol("wglMakeContextCurrentEXT"), v8::Undefined()); }
		if(!obj->methodp_wglMakeCurrent) { obj->methodp_wglMakeCurrent = (PFNWGLMAKECURRENTPROC)wglGetProcAddress("wglMakeCurrent"); }
		if(!obj->methodp_wglMakeCurrent) { obj->methodp_wglMakeCurrent = (PFNWGLMAKECURRENTPROC)GetProcAddress(modOpenGL32, "wglMakeCurrent"); }
		if(!obj->methodp_wglMakeCurrent) { obj->methodp_wglMakeCurrent = (PFNWGLMAKECURRENTPROC)GetProcAddress(modGdi32, "wglMakeCurrent"); }
		if(!obj->methodp_wglMakeCurrent) { args.This()->Set(v8::String::NewSymbol("wglMakeCurrent"), v8::Undefined()); }
		if(!obj->methodp_wglQueryCurrentContextNV) { obj->methodp_wglQueryCurrentContextNV = (PFNWGLQUERYCURRENTCONTEXTNVPROC)wglGetProcAddress("wglQueryCurrentContextNV"); }
		if(!obj->methodp_wglQueryCurrentContextNV) { obj->methodp_wglQueryCurrentContextNV = (PFNWGLQUERYCURRENTCONTEXTNVPROC)GetProcAddress(modOpenGL32, "wglQueryCurrentContextNV"); }
		if(!obj->methodp_wglQueryCurrentContextNV) { obj->methodp_wglQueryCurrentContextNV = (PFNWGLQUERYCURRENTCONTEXTNVPROC)GetProcAddress(modGdi32, "wglQueryCurrentContextNV"); }
		if(!obj->methodp_wglQueryCurrentContextNV) { args.This()->Set(v8::String::NewSymbol("wglQueryCurrentContextNV"), v8::Undefined()); }
		if(!obj->methodp_wglQueryFrameCountNV) { obj->methodp_wglQueryFrameCountNV = (PFNWGLQUERYFRAMECOUNTNVPROC)wglGetProcAddress("wglQueryFrameCountNV"); }
		if(!obj->methodp_wglQueryFrameCountNV) { obj->methodp_wglQueryFrameCountNV = (PFNWGLQUERYFRAMECOUNTNVPROC)GetProcAddress(modOpenGL32, "wglQueryFrameCountNV"); }
		if(!obj->methodp_wglQueryFrameCountNV) { obj->methodp_wglQueryFrameCountNV = (PFNWGLQUERYFRAMECOUNTNVPROC)GetProcAddress(modGdi32, "wglQueryFrameCountNV"); }
		if(!obj->methodp_wglQueryFrameCountNV) { args.This()->Set(v8::String::NewSymbol("wglQueryFrameCountNV"), v8::Undefined()); }
		if(!obj->methodp_wglQueryFrameLockMasterI3D) { obj->methodp_wglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)wglGetProcAddress("wglQueryFrameLockMasterI3D"); }
		if(!obj->methodp_wglQueryFrameLockMasterI3D) { obj->methodp_wglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)GetProcAddress(modOpenGL32, "wglQueryFrameLockMasterI3D"); }
		if(!obj->methodp_wglQueryFrameLockMasterI3D) { obj->methodp_wglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)GetProcAddress(modGdi32, "wglQueryFrameLockMasterI3D"); }
		if(!obj->methodp_wglQueryFrameLockMasterI3D) { args.This()->Set(v8::String::NewSymbol("wglQueryFrameLockMasterI3D"), v8::Undefined()); }
		if(!obj->methodp_wglQueryFrameTrackingI3D) { obj->methodp_wglQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3DPROC)wglGetProcAddress("wglQueryFrameTrackingI3D"); }
		if(!obj->methodp_wglQueryFrameTrackingI3D) { obj->methodp_wglQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3DPROC)GetProcAddress(modOpenGL32, "wglQueryFrameTrackingI3D"); }
		if(!obj->methodp_wglQueryFrameTrackingI3D) { obj->methodp_wglQueryFrameTrackingI3D = (PFNWGLQUERYFRAMETRACKINGI3DPROC)GetProcAddress(modGdi32, "wglQueryFrameTrackingI3D"); }
		if(!obj->methodp_wglQueryFrameTrackingI3D) { args.This()->Set(v8::String::NewSymbol("wglQueryFrameTrackingI3D"), v8::Undefined()); }
		if(!obj->methodp_wglQueryGenlockMaxSourceDelayI3D) { obj->methodp_wglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)wglGetProcAddress("wglQueryGenlockMaxSourceDelayI3D"); }
		if(!obj->methodp_wglQueryGenlockMaxSourceDelayI3D) { obj->methodp_wglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)GetProcAddress(modOpenGL32, "wglQueryGenlockMaxSourceDelayI3D"); }
		if(!obj->methodp_wglQueryGenlockMaxSourceDelayI3D) { obj->methodp_wglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)GetProcAddress(modGdi32, "wglQueryGenlockMaxSourceDelayI3D"); }
		if(!obj->methodp_wglQueryGenlockMaxSourceDelayI3D) { args.This()->Set(v8::String::NewSymbol("wglQueryGenlockMaxSourceDelayI3D"), v8::Undefined()); }
		if(!obj->methodp_wglQueryMaxSwapGroupsNV) { obj->methodp_wglQueryMaxSwapGroupsNV = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)wglGetProcAddress("wglQueryMaxSwapGroupsNV"); }
		if(!obj->methodp_wglQueryMaxSwapGroupsNV) { obj->methodp_wglQueryMaxSwapGroupsNV = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)GetProcAddress(modOpenGL32, "wglQueryMaxSwapGroupsNV"); }
		if(!obj->methodp_wglQueryMaxSwapGroupsNV) { obj->methodp_wglQueryMaxSwapGroupsNV = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)GetProcAddress(modGdi32, "wglQueryMaxSwapGroupsNV"); }
		if(!obj->methodp_wglQueryMaxSwapGroupsNV) { args.This()->Set(v8::String::NewSymbol("wglQueryMaxSwapGroupsNV"), v8::Undefined()); }
		if(!obj->methodp_wglQueryPbufferARB) { obj->methodp_wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC)wglGetProcAddress("wglQueryPbufferARB"); }
		if(!obj->methodp_wglQueryPbufferARB) { obj->methodp_wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC)GetProcAddress(modOpenGL32, "wglQueryPbufferARB"); }
		if(!obj->methodp_wglQueryPbufferARB) { obj->methodp_wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC)GetProcAddress(modGdi32, "wglQueryPbufferARB"); }
		if(!obj->methodp_wglQueryPbufferARB) { args.This()->Set(v8::String::NewSymbol("wglQueryPbufferARB"), v8::Undefined()); }
		if(!obj->methodp_wglQueryPbufferEXT) { obj->methodp_wglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC)wglGetProcAddress("wglQueryPbufferEXT"); }
		if(!obj->methodp_wglQueryPbufferEXT) { obj->methodp_wglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC)GetProcAddress(modOpenGL32, "wglQueryPbufferEXT"); }
		if(!obj->methodp_wglQueryPbufferEXT) { obj->methodp_wglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC)GetProcAddress(modGdi32, "wglQueryPbufferEXT"); }
		if(!obj->methodp_wglQueryPbufferEXT) { args.This()->Set(v8::String::NewSymbol("wglQueryPbufferEXT"), v8::Undefined()); }
		if(!obj->methodp_wglQuerySwapGroupNV) { obj->methodp_wglQuerySwapGroupNV = (PFNWGLQUERYSWAPGROUPNVPROC)wglGetProcAddress("wglQuerySwapGroupNV"); }
		if(!obj->methodp_wglQuerySwapGroupNV) { obj->methodp_wglQuerySwapGroupNV = (PFNWGLQUERYSWAPGROUPNVPROC)GetProcAddress(modOpenGL32, "wglQuerySwapGroupNV"); }
		if(!obj->methodp_wglQuerySwapGroupNV) { obj->methodp_wglQuerySwapGroupNV = (PFNWGLQUERYSWAPGROUPNVPROC)GetProcAddress(modGdi32, "wglQuerySwapGroupNV"); }
		if(!obj->methodp_wglQuerySwapGroupNV) { args.This()->Set(v8::String::NewSymbol("wglQuerySwapGroupNV"), v8::Undefined()); }
		if(!obj->methodp_wglQueryVideoCaptureDeviceNV) { obj->methodp_wglQueryVideoCaptureDeviceNV = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglQueryVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglQueryVideoCaptureDeviceNV) { obj->methodp_wglQueryVideoCaptureDeviceNV = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modOpenGL32, "wglQueryVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglQueryVideoCaptureDeviceNV) { obj->methodp_wglQueryVideoCaptureDeviceNV = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modGdi32, "wglQueryVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglQueryVideoCaptureDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglQueryVideoCaptureDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglRealizeLayerPalette) { obj->methodp_wglRealizeLayerPalette = (PFNWGLREALIZELAYERPALETTEPROC)wglGetProcAddress("wglRealizeLayerPalette"); }
		if(!obj->methodp_wglRealizeLayerPalette) { obj->methodp_wglRealizeLayerPalette = (PFNWGLREALIZELAYERPALETTEPROC)GetProcAddress(modOpenGL32, "wglRealizeLayerPalette"); }
		if(!obj->methodp_wglRealizeLayerPalette) { obj->methodp_wglRealizeLayerPalette = (PFNWGLREALIZELAYERPALETTEPROC)GetProcAddress(modGdi32, "wglRealizeLayerPalette"); }
		if(!obj->methodp_wglRealizeLayerPalette) { args.This()->Set(v8::String::NewSymbol("wglRealizeLayerPalette"), v8::Undefined()); }
		if(!obj->methodp_wglReleaseImageBufferEventsI3D) { obj->methodp_wglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)wglGetProcAddress("wglReleaseImageBufferEventsI3D"); }
		if(!obj->methodp_wglReleaseImageBufferEventsI3D) { obj->methodp_wglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)GetProcAddress(modOpenGL32, "wglReleaseImageBufferEventsI3D"); }
		if(!obj->methodp_wglReleaseImageBufferEventsI3D) { obj->methodp_wglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)GetProcAddress(modGdi32, "wglReleaseImageBufferEventsI3D"); }
		if(!obj->methodp_wglReleaseImageBufferEventsI3D) { args.This()->Set(v8::String::NewSymbol("wglReleaseImageBufferEventsI3D"), v8::Undefined()); }
		if(!obj->methodp_wglReleasePbufferDCARB) { obj->methodp_wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)wglGetProcAddress("wglReleasePbufferDCARB"); }
		if(!obj->methodp_wglReleasePbufferDCARB) { obj->methodp_wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)GetProcAddress(modOpenGL32, "wglReleasePbufferDCARB"); }
		if(!obj->methodp_wglReleasePbufferDCARB) { obj->methodp_wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)GetProcAddress(modGdi32, "wglReleasePbufferDCARB"); }
		if(!obj->methodp_wglReleasePbufferDCARB) { args.This()->Set(v8::String::NewSymbol("wglReleasePbufferDCARB"), v8::Undefined()); }
		if(!obj->methodp_wglReleasePbufferDCEXT) { obj->methodp_wglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC)wglGetProcAddress("wglReleasePbufferDCEXT"); }
		if(!obj->methodp_wglReleasePbufferDCEXT) { obj->methodp_wglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC)GetProcAddress(modOpenGL32, "wglReleasePbufferDCEXT"); }
		if(!obj->methodp_wglReleasePbufferDCEXT) { obj->methodp_wglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC)GetProcAddress(modGdi32, "wglReleasePbufferDCEXT"); }
		if(!obj->methodp_wglReleasePbufferDCEXT) { args.This()->Set(v8::String::NewSymbol("wglReleasePbufferDCEXT"), v8::Undefined()); }
		if(!obj->methodp_wglReleaseTexImageARB) { obj->methodp_wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC)wglGetProcAddress("wglReleaseTexImageARB"); }
		if(!obj->methodp_wglReleaseTexImageARB) { obj->methodp_wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC)GetProcAddress(modOpenGL32, "wglReleaseTexImageARB"); }
		if(!obj->methodp_wglReleaseTexImageARB) { obj->methodp_wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC)GetProcAddress(modGdi32, "wglReleaseTexImageARB"); }
		if(!obj->methodp_wglReleaseTexImageARB) { args.This()->Set(v8::String::NewSymbol("wglReleaseTexImageARB"), v8::Undefined()); }
		if(!obj->methodp_wglReleaseVideoCaptureDeviceNV) { obj->methodp_wglReleaseVideoCaptureDeviceNV = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)wglGetProcAddress("wglReleaseVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglReleaseVideoCaptureDeviceNV) { obj->methodp_wglReleaseVideoCaptureDeviceNV = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modOpenGL32, "wglReleaseVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglReleaseVideoCaptureDeviceNV) { obj->methodp_wglReleaseVideoCaptureDeviceNV = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)GetProcAddress(modGdi32, "wglReleaseVideoCaptureDeviceNV"); }
		if(!obj->methodp_wglReleaseVideoCaptureDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglReleaseVideoCaptureDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglReleaseVideoDeviceNV) { obj->methodp_wglReleaseVideoDeviceNV = (PFNWGLRELEASEVIDEODEVICENVPROC)wglGetProcAddress("wglReleaseVideoDeviceNV"); }
		if(!obj->methodp_wglReleaseVideoDeviceNV) { obj->methodp_wglReleaseVideoDeviceNV = (PFNWGLRELEASEVIDEODEVICENVPROC)GetProcAddress(modOpenGL32, "wglReleaseVideoDeviceNV"); }
		if(!obj->methodp_wglReleaseVideoDeviceNV) { obj->methodp_wglReleaseVideoDeviceNV = (PFNWGLRELEASEVIDEODEVICENVPROC)GetProcAddress(modGdi32, "wglReleaseVideoDeviceNV"); }
		if(!obj->methodp_wglReleaseVideoDeviceNV) { args.This()->Set(v8::String::NewSymbol("wglReleaseVideoDeviceNV"), v8::Undefined()); }
		if(!obj->methodp_wglReleaseVideoImageNV) { obj->methodp_wglReleaseVideoImageNV = (PFNWGLRELEASEVIDEOIMAGENVPROC)wglGetProcAddress("wglReleaseVideoImageNV"); }
		if(!obj->methodp_wglReleaseVideoImageNV) { obj->methodp_wglReleaseVideoImageNV = (PFNWGLRELEASEVIDEOIMAGENVPROC)GetProcAddress(modOpenGL32, "wglReleaseVideoImageNV"); }
		if(!obj->methodp_wglReleaseVideoImageNV) { obj->methodp_wglReleaseVideoImageNV = (PFNWGLRELEASEVIDEOIMAGENVPROC)GetProcAddress(modGdi32, "wglReleaseVideoImageNV"); }
		if(!obj->methodp_wglReleaseVideoImageNV) { args.This()->Set(v8::String::NewSymbol("wglReleaseVideoImageNV"), v8::Undefined()); }
		if(!obj->methodp_wglResetFrameCountNV) { obj->methodp_wglResetFrameCountNV = (PFNWGLRESETFRAMECOUNTNVPROC)wglGetProcAddress("wglResetFrameCountNV"); }
		if(!obj->methodp_wglResetFrameCountNV) { obj->methodp_wglResetFrameCountNV = (PFNWGLRESETFRAMECOUNTNVPROC)GetProcAddress(modOpenGL32, "wglResetFrameCountNV"); }
		if(!obj->methodp_wglResetFrameCountNV) { obj->methodp_wglResetFrameCountNV = (PFNWGLRESETFRAMECOUNTNVPROC)GetProcAddress(modGdi32, "wglResetFrameCountNV"); }
		if(!obj->methodp_wglResetFrameCountNV) { args.This()->Set(v8::String::NewSymbol("wglResetFrameCountNV"), v8::Undefined()); }
		if(!obj->methodp_wglRestoreBufferRegionARB) { obj->methodp_wglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC)wglGetProcAddress("wglRestoreBufferRegionARB"); }
		if(!obj->methodp_wglRestoreBufferRegionARB) { obj->methodp_wglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC)GetProcAddress(modOpenGL32, "wglRestoreBufferRegionARB"); }
		if(!obj->methodp_wglRestoreBufferRegionARB) { obj->methodp_wglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC)GetProcAddress(modGdi32, "wglRestoreBufferRegionARB"); }
		if(!obj->methodp_wglRestoreBufferRegionARB) { args.This()->Set(v8::String::NewSymbol("wglRestoreBufferRegionARB"), v8::Undefined()); }
		if(!obj->methodp_wglSaveBufferRegionARB) { obj->methodp_wglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC)wglGetProcAddress("wglSaveBufferRegionARB"); }
		if(!obj->methodp_wglSaveBufferRegionARB) { obj->methodp_wglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC)GetProcAddress(modOpenGL32, "wglSaveBufferRegionARB"); }
		if(!obj->methodp_wglSaveBufferRegionARB) { obj->methodp_wglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC)GetProcAddress(modGdi32, "wglSaveBufferRegionARB"); }
		if(!obj->methodp_wglSaveBufferRegionARB) { args.This()->Set(v8::String::NewSymbol("wglSaveBufferRegionARB"), v8::Undefined()); }
		if(!obj->methodp_wglSendPbufferToVideoNV) { obj->methodp_wglSendPbufferToVideoNV = (PFNWGLSENDPBUFFERTOVIDEONVPROC)wglGetProcAddress("wglSendPbufferToVideoNV"); }
		if(!obj->methodp_wglSendPbufferToVideoNV) { obj->methodp_wglSendPbufferToVideoNV = (PFNWGLSENDPBUFFERTOVIDEONVPROC)GetProcAddress(modOpenGL32, "wglSendPbufferToVideoNV"); }
		if(!obj->methodp_wglSendPbufferToVideoNV) { obj->methodp_wglSendPbufferToVideoNV = (PFNWGLSENDPBUFFERTOVIDEONVPROC)GetProcAddress(modGdi32, "wglSendPbufferToVideoNV"); }
		if(!obj->methodp_wglSendPbufferToVideoNV) { args.This()->Set(v8::String::NewSymbol("wglSendPbufferToVideoNV"), v8::Undefined()); }
		if(!obj->methodp_wglSetDigitalVideoParametersI3D) { obj->methodp_wglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)wglGetProcAddress("wglSetDigitalVideoParametersI3D"); }
		if(!obj->methodp_wglSetDigitalVideoParametersI3D) { obj->methodp_wglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)GetProcAddress(modOpenGL32, "wglSetDigitalVideoParametersI3D"); }
		if(!obj->methodp_wglSetDigitalVideoParametersI3D) { obj->methodp_wglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)GetProcAddress(modGdi32, "wglSetDigitalVideoParametersI3D"); }
		if(!obj->methodp_wglSetDigitalVideoParametersI3D) { args.This()->Set(v8::String::NewSymbol("wglSetDigitalVideoParametersI3D"), v8::Undefined()); }
		if(!obj->methodp_wglSetGammaTableI3D) { obj->methodp_wglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC)wglGetProcAddress("wglSetGammaTableI3D"); }
		if(!obj->methodp_wglSetGammaTableI3D) { obj->methodp_wglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC)GetProcAddress(modOpenGL32, "wglSetGammaTableI3D"); }
		if(!obj->methodp_wglSetGammaTableI3D) { obj->methodp_wglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC)GetProcAddress(modGdi32, "wglSetGammaTableI3D"); }
		if(!obj->methodp_wglSetGammaTableI3D) { args.This()->Set(v8::String::NewSymbol("wglSetGammaTableI3D"), v8::Undefined()); }
		if(!obj->methodp_wglSetGammaTableParametersI3D) { obj->methodp_wglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)wglGetProcAddress("wglSetGammaTableParametersI3D"); }
		if(!obj->methodp_wglSetGammaTableParametersI3D) { obj->methodp_wglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)GetProcAddress(modOpenGL32, "wglSetGammaTableParametersI3D"); }
		if(!obj->methodp_wglSetGammaTableParametersI3D) { obj->methodp_wglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)GetProcAddress(modGdi32, "wglSetGammaTableParametersI3D"); }
		if(!obj->methodp_wglSetGammaTableParametersI3D) { args.This()->Set(v8::String::NewSymbol("wglSetGammaTableParametersI3D"), v8::Undefined()); }
		if(!obj->methodp_wglSetLayerPaletteEntries) { obj->methodp_wglSetLayerPaletteEntries = (PFNWGLSETLAYERPALETTEENTRIESPROC)wglGetProcAddress("wglSetLayerPaletteEntries"); }
		if(!obj->methodp_wglSetLayerPaletteEntries) { obj->methodp_wglSetLayerPaletteEntries = (PFNWGLSETLAYERPALETTEENTRIESPROC)GetProcAddress(modOpenGL32, "wglSetLayerPaletteEntries"); }
		if(!obj->methodp_wglSetLayerPaletteEntries) { obj->methodp_wglSetLayerPaletteEntries = (PFNWGLSETLAYERPALETTEENTRIESPROC)GetProcAddress(modGdi32, "wglSetLayerPaletteEntries"); }
		if(!obj->methodp_wglSetLayerPaletteEntries) { args.This()->Set(v8::String::NewSymbol("wglSetLayerPaletteEntries"), v8::Undefined()); }
		if(!obj->methodp_wglSetPbufferAttribARB) { obj->methodp_wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC)wglGetProcAddress("wglSetPbufferAttribARB"); }
		if(!obj->methodp_wglSetPbufferAttribARB) { obj->methodp_wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC)GetProcAddress(modOpenGL32, "wglSetPbufferAttribARB"); }
		if(!obj->methodp_wglSetPbufferAttribARB) { obj->methodp_wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC)GetProcAddress(modGdi32, "wglSetPbufferAttribARB"); }
		if(!obj->methodp_wglSetPbufferAttribARB) { args.This()->Set(v8::String::NewSymbol("wglSetPbufferAttribARB"), v8::Undefined()); }
		if(!obj->methodp_wglSetStereoEmitterState3DL) { obj->methodp_wglSetStereoEmitterState3DL = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)wglGetProcAddress("wglSetStereoEmitterState3DL"); }
		if(!obj->methodp_wglSetStereoEmitterState3DL) { obj->methodp_wglSetStereoEmitterState3DL = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)GetProcAddress(modOpenGL32, "wglSetStereoEmitterState3DL"); }
		if(!obj->methodp_wglSetStereoEmitterState3DL) { obj->methodp_wglSetStereoEmitterState3DL = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)GetProcAddress(modGdi32, "wglSetStereoEmitterState3DL"); }
		if(!obj->methodp_wglSetStereoEmitterState3DL) { args.This()->Set(v8::String::NewSymbol("wglSetStereoEmitterState3DL"), v8::Undefined()); }
		if(!obj->methodp_wglShareLists) { obj->methodp_wglShareLists = (PFNWGLSHARELISTSPROC)wglGetProcAddress("wglShareLists"); }
		if(!obj->methodp_wglShareLists) { obj->methodp_wglShareLists = (PFNWGLSHARELISTSPROC)GetProcAddress(modOpenGL32, "wglShareLists"); }
		if(!obj->methodp_wglShareLists) { obj->methodp_wglShareLists = (PFNWGLSHARELISTSPROC)GetProcAddress(modGdi32, "wglShareLists"); }
		if(!obj->methodp_wglShareLists) { args.This()->Set(v8::String::NewSymbol("wglShareLists"), v8::Undefined()); }
		if(!obj->methodp_wglSwapBuffersMscOML) { obj->methodp_wglSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOMLPROC)wglGetProcAddress("wglSwapBuffersMscOML"); }
		if(!obj->methodp_wglSwapBuffersMscOML) { obj->methodp_wglSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOMLPROC)GetProcAddress(modOpenGL32, "wglSwapBuffersMscOML"); }
		if(!obj->methodp_wglSwapBuffersMscOML) { obj->methodp_wglSwapBuffersMscOML = (PFNWGLSWAPBUFFERSMSCOMLPROC)GetProcAddress(modGdi32, "wglSwapBuffersMscOML"); }
		if(!obj->methodp_wglSwapBuffersMscOML) { args.This()->Set(v8::String::NewSymbol("wglSwapBuffersMscOML"), v8::Undefined()); }
		if(!obj->methodp_wglSwapLayerBuffers) { obj->methodp_wglSwapLayerBuffers = (PFNWGLSWAPLAYERBUFFERSPROC)wglGetProcAddress("wglSwapLayerBuffers"); }
		if(!obj->methodp_wglSwapLayerBuffers) { obj->methodp_wglSwapLayerBuffers = (PFNWGLSWAPLAYERBUFFERSPROC)GetProcAddress(modOpenGL32, "wglSwapLayerBuffers"); }
		if(!obj->methodp_wglSwapLayerBuffers) { obj->methodp_wglSwapLayerBuffers = (PFNWGLSWAPLAYERBUFFERSPROC)GetProcAddress(modGdi32, "wglSwapLayerBuffers"); }
		if(!obj->methodp_wglSwapLayerBuffers) { args.This()->Set(v8::String::NewSymbol("wglSwapLayerBuffers"), v8::Undefined()); }
		if(!obj->methodp_wglSwapIntervalEXT) { obj->methodp_wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT"); }
		if(!obj->methodp_wglSwapIntervalEXT) { obj->methodp_wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)GetProcAddress(modOpenGL32, "wglSwapIntervalEXT"); }
		if(!obj->methodp_wglSwapIntervalEXT) { obj->methodp_wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)GetProcAddress(modGdi32, "wglSwapIntervalEXT"); }
		if(!obj->methodp_wglSwapIntervalEXT) { args.This()->Set(v8::String::NewSymbol("wglSwapIntervalEXT"), v8::Undefined()); }
		if(!obj->methodp_wglSwapLayerBuffersMscOML) { obj->methodp_wglSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)wglGetProcAddress("wglSwapLayerBuffersMscOML"); }
		if(!obj->methodp_wglSwapLayerBuffersMscOML) { obj->methodp_wglSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)GetProcAddress(modOpenGL32, "wglSwapLayerBuffersMscOML"); }
		if(!obj->methodp_wglSwapLayerBuffersMscOML) { obj->methodp_wglSwapLayerBuffersMscOML = (PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)GetProcAddress(modGdi32, "wglSwapLayerBuffersMscOML"); }
		if(!obj->methodp_wglSwapLayerBuffersMscOML) { args.This()->Set(v8::String::NewSymbol("wglSwapLayerBuffersMscOML"), v8::Undefined()); }
		if(!obj->methodp_wglUseFontBitmaps) { obj->methodp_wglUseFontBitmaps = (PFNWGLUSEFONTBITMAPSPROC)wglGetProcAddress("wglUseFontBitmaps"); }
		if(!obj->methodp_wglUseFontBitmaps) { obj->methodp_wglUseFontBitmaps = (PFNWGLUSEFONTBITMAPSPROC)GetProcAddress(modOpenGL32, "wglUseFontBitmaps"); }
		if(!obj->methodp_wglUseFontBitmaps) { obj->methodp_wglUseFontBitmaps = (PFNWGLUSEFONTBITMAPSPROC)GetProcAddress(modGdi32, "wglUseFontBitmaps"); }
		if(!obj->methodp_wglUseFontBitmaps) { args.This()->Set(v8::String::NewSymbol("wglUseFontBitmaps"), v8::Undefined()); }
		if(!obj->methodp_wglUseFontBitmapsA) { obj->methodp_wglUseFontBitmapsA = (PFNWGLUSEFONTBITMAPSAPROC)wglGetProcAddress("wglUseFontBitmapsA"); }
		if(!obj->methodp_wglUseFontBitmapsA) { obj->methodp_wglUseFontBitmapsA = (PFNWGLUSEFONTBITMAPSAPROC)GetProcAddress(modOpenGL32, "wglUseFontBitmapsA"); }
		if(!obj->methodp_wglUseFontBitmapsA) { obj->methodp_wglUseFontBitmapsA = (PFNWGLUSEFONTBITMAPSAPROC)GetProcAddress(modGdi32, "wglUseFontBitmapsA"); }
		if(!obj->methodp_wglUseFontBitmapsA) { args.This()->Set(v8::String::NewSymbol("wglUseFontBitmapsA"), v8::Undefined()); }
		if(!obj->methodp_wglUseFontBitmapsW) { obj->methodp_wglUseFontBitmapsW = (PFNWGLUSEFONTBITMAPSWPROC)wglGetProcAddress("wglUseFontBitmapsW"); }
		if(!obj->methodp_wglUseFontBitmapsW) { obj->methodp_wglUseFontBitmapsW = (PFNWGLUSEFONTBITMAPSWPROC)GetProcAddress(modOpenGL32, "wglUseFontBitmapsW"); }
		if(!obj->methodp_wglUseFontBitmapsW) { obj->methodp_wglUseFontBitmapsW = (PFNWGLUSEFONTBITMAPSWPROC)GetProcAddress(modGdi32, "wglUseFontBitmapsW"); }
		if(!obj->methodp_wglUseFontBitmapsW) { args.This()->Set(v8::String::NewSymbol("wglUseFontBitmapsW"), v8::Undefined()); }
		if(!obj->methodp_wglUseFontOutlines) { obj->methodp_wglUseFontOutlines = (PFNWGLUSEFONTOUTLINESPROC)wglGetProcAddress("wglUseFontOutlines"); }
		if(!obj->methodp_wglUseFontOutlines) { obj->methodp_wglUseFontOutlines = (PFNWGLUSEFONTOUTLINESPROC)GetProcAddress(modOpenGL32, "wglUseFontOutlines"); }
		if(!obj->methodp_wglUseFontOutlines) { obj->methodp_wglUseFontOutlines = (PFNWGLUSEFONTOUTLINESPROC)GetProcAddress(modGdi32, "wglUseFontOutlines"); }
		if(!obj->methodp_wglUseFontOutlines) { args.This()->Set(v8::String::NewSymbol("wglUseFontOutlines"), v8::Undefined()); }
		if(!obj->methodp_wglUseFontOutlinesA) { obj->methodp_wglUseFontOutlinesA = (PFNWGLUSEFONTOUTLINESAPROC)wglGetProcAddress("wglUseFontOutlinesA"); }
		if(!obj->methodp_wglUseFontOutlinesA) { obj->methodp_wglUseFontOutlinesA = (PFNWGLUSEFONTOUTLINESAPROC)GetProcAddress(modOpenGL32, "wglUseFontOutlinesA"); }
		if(!obj->methodp_wglUseFontOutlinesA) { obj->methodp_wglUseFontOutlinesA = (PFNWGLUSEFONTOUTLINESAPROC)GetProcAddress(modGdi32, "wglUseFontOutlinesA"); }
		if(!obj->methodp_wglUseFontOutlinesA) { args.This()->Set(v8::String::NewSymbol("wglUseFontOutlinesA"), v8::Undefined()); }
		if(!obj->methodp_wglUseFontOutlinesW) { obj->methodp_wglUseFontOutlinesW = (PFNWGLUSEFONTOUTLINESWPROC)wglGetProcAddress("wglUseFontOutlinesW"); }
		if(!obj->methodp_wglUseFontOutlinesW) { obj->methodp_wglUseFontOutlinesW = (PFNWGLUSEFONTOUTLINESWPROC)GetProcAddress(modOpenGL32, "wglUseFontOutlinesW"); }
		if(!obj->methodp_wglUseFontOutlinesW) { obj->methodp_wglUseFontOutlinesW = (PFNWGLUSEFONTOUTLINESWPROC)GetProcAddress(modGdi32, "wglUseFontOutlinesW"); }
		if(!obj->methodp_wglUseFontOutlinesW) { args.This()->Set(v8::String::NewSymbol("wglUseFontOutlinesW"), v8::Undefined()); }
		if(!obj->methodp_wglWaitForMscOML) { obj->methodp_wglWaitForMscOML = (PFNWGLWAITFORMSCOMLPROC)wglGetProcAddress("wglWaitForMscOML"); }
		if(!obj->methodp_wglWaitForMscOML) { obj->methodp_wglWaitForMscOML = (PFNWGLWAITFORMSCOMLPROC)GetProcAddress(modOpenGL32, "wglWaitForMscOML"); }
		if(!obj->methodp_wglWaitForMscOML) { obj->methodp_wglWaitForMscOML = (PFNWGLWAITFORMSCOMLPROC)GetProcAddress(modGdi32, "wglWaitForMscOML"); }
		if(!obj->methodp_wglWaitForMscOML) { args.This()->Set(v8::String::NewSymbol("wglWaitForMscOML"), v8::Undefined()); }
		if(!obj->methodp_wglWaitForSbcOML) { obj->methodp_wglWaitForSbcOML = (PFNWGLWAITFORSBCOMLPROC)wglGetProcAddress("wglWaitForSbcOML"); }
		if(!obj->methodp_wglWaitForSbcOML) { obj->methodp_wglWaitForSbcOML = (PFNWGLWAITFORSBCOMLPROC)GetProcAddress(modOpenGL32, "wglWaitForSbcOML"); }
		if(!obj->methodp_wglWaitForSbcOML) { obj->methodp_wglWaitForSbcOML = (PFNWGLWAITFORSBCOMLPROC)GetProcAddress(modGdi32, "wglWaitForSbcOML"); }
		if(!obj->methodp_wglWaitForSbcOML) { args.This()->Set(v8::String::NewSymbol("wglWaitForSbcOML"), v8::Undefined()); }
		return args.This();
	}
	static v8::Persistent<v8::Function> constructor;
	static v8::Persistent<v8::ObjectTemplate> retTpl;

};

