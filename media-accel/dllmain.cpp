//#define BUILD_WITHOUT_AUTO
#pragma comment(lib, "Node.lib")
#pragma comment(lib, "Shlwapi.lib")


#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <Windowsx.h>
#include <tchar.h>
#include <v8.h>
#include <node.h>
#include <node_buffer.h>
#include <intrin.h>
#include <cstdint>
#include <string>
//#include <vector>


LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

#define setPrototypeGetter(prop)       tpl->PrototypeTemplate()->SetAccessor(v8::String::NewSymbol(#prop), get_##prop);
#define setPrototypeGetterSetter(prop) tpl->PrototypeTemplate()->SetAccessor(v8::String::NewSymbol(#prop), get_##prop, set_##prop);
#define setPrototypeMethod(func)       tpl->PrototypeTemplate()->Set(v8::String::NewSymbol(#func), v8::FunctionTemplate::New(method_##func)->GetFunction());

#include "class_User32.h"
#include "class_Gdi32.h"

const int64_t sizeOfExternalArrayType[10]{0i64, 1i64, 1i64, 2i64, 2i64, 4i64, 4i64, 4i64, 8i64, 4i64};


#include "class_Destructor.h"
v8::Persistent<v8::Function> class_Destructor::constructor;

#include "class_WNDCLASSW.h"
v8::Persistent<v8::Function> class_WNDCLASSW::constructor;
v8::Persistent<v8::ObjectTemplate> class_WNDCLASSW::retTpl;

#include "class_GDIPLUS.h"
v8::Persistent<v8::Function> class_GDIPLUS::constructor;
v8::Persistent<v8::ObjectTemplate> class_GDIPLUS::retTpl;

#include "class_GDIPLUS_IMAGE.h"
v8::Persistent<v8::Function> class_GDIPLUS_IMAGE::constructor;
v8::Persistent<v8::ObjectTemplate> class_GDIPLUS_IMAGE::retTpl;

#include "class_GDIPLUS_BITMAP.h"
v8::Persistent<v8::Function> class_GDIPLUS_BITMAP::constructor;
v8::Persistent<v8::ObjectTemplate> class_GDIPLUS_BITMAP::retTpl;

#include "class_intrinsics.h"

#pragma comment(lib, "OpenGL32.lib")
#ifndef BUILD_WITHOUT_AUTO

#include "autogen_OpenGL.h"
v8::Persistent<v8::Function> class_OpenGL::constructor;
v8::Persistent<v8::ObjectTemplate> class_OpenGL::retTpl;

#include "autogen_WGL.h"
v8::Persistent<v8::Function> class_WGL::constructor;
v8::Persistent<v8::ObjectTemplate> class_WGL::retTpl;
#endif


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

v8::Handle<v8::Value> func_OutputDebugString(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 1){
		return v8::Undefined();
	}

	v8::String::Value arg0(args[0]);
	LPCWSTR lpFileName = (LPCWSTR)*arg0;
	OutputDebugString(lpFileName);

	return v8::Undefined();
}

v8::Handle<v8::Value> func_rdtsc(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 1){
		return scope.Close(v8::Number::New(static_cast<double>(__rdtsc())));
	}
	uint64_t ret{__rdtsc() - static_cast<uint64_t>(args[0]->NumberValue())};
	return scope.Close(v8::Number::New(static_cast<double>(ret)));
}


v8::Handle<v8::Value> func_SwapBuffers(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 1){
		return v8::Undefined();
	}

	int64_t arg0 = static_cast<int64_t>(args[0]->NumberValue());
	BOOL ret = SwapBuffers((HDC)arg0);

	return scope.Close(v8::Integer::New(ret));
}

v8::Handle<v8::Value> func_MessageBox(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 4){
		return v8::Undefined();
	}

	int64_t arg0 = static_cast<int64_t>(args[0]->NumberValue());
	v8::String::Value arg1(args[1]);
	v8::String::Value arg2(args[2]);
	LPCWSTR arg1lp = (LPCWSTR)*arg1;
	LPCWSTR arg2lp = (LPCWSTR)*arg2;
	uint32_t arg3 = args[3]->Uint32Value();
	auto ret = MessageBox((HWND)arg0, arg1lp, arg2lp, arg3);

	return scope.Close(v8::Integer::New(ret));
}

v8::Handle<v8::Value> func_GetModuleHandle(const v8::Arguments& args) {
	v8::HandleScope scope;

	LPCWSTR arg0lp{nullptr};
	HMODULE ret{nullptr};

	if(args.Length() >= 1){
		v8::String::Value arg0(args[0]);
		arg0lp = (LPCWSTR)*arg0;
	}
	ret = GetModuleHandle(arg0lp);
	//printf("GetModuleHandle = %Iu, %p\n", ret, ret);
	return scope.Close(v8::Number::New((int64_t)(ret)));
}

v8::Handle<v8::Value> func_PeekMessage(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 5){
		return v8::Undefined();
	}

	LPMSG arg0{(LPMSG)args[0]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()};
	HWND arg1{(HWND)((uint64_t)args[1]->NumberValue())};
	UINT arg2{args[2]->Uint32Value()};
	UINT arg3{args[3]->Uint32Value()};
	UINT arg4{args[4]->Uint32Value()};

	BOOL ret{PeekMessage(arg0, arg1, arg2, arg3, arg4)};

	return scope.Close(v8::Int32::New(ret));
}

v8::Handle<v8::Value> func_GetMessage(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 4){
		return v8::Undefined();
	}

	LPMSG arg0{(LPMSG)args[0]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()};
	HWND arg1{(HWND)((uint64_t)args[1]->NumberValue())};
	UINT arg2{args[2]->Uint32Value()};
	UINT arg3{args[3]->Uint32Value()};

	BOOL ret{GetMessage(arg0, arg1, arg2, arg3)};

	return scope.Close(v8::Int32::New(ret));
}

v8::Handle<v8::Value> func_TranslateMessage(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 1){
		return v8::Undefined();
	}

	LPMSG arg0{(LPMSG)args[0]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()};

	BOOL ret{TranslateMessage(arg0)};

	return scope.Close(v8::Int32::New(ret));
}

v8::Handle<v8::Value> func_DispatchMessage(const v8::Arguments& args) {
	v8::HandleScope scope;

	if(args.Length() < 1){
		return v8::Undefined();
	}

	LPMSG arg0{(LPMSG)args[0]->ToObject()->Get(v8::String::NewSymbol("buf"))->ToObject()->GetIndexedPropertiesExternalArrayData()};

	LRESULT ret{DispatchMessage(arg0)};

	return scope.Close(v8::Number::New(ret));
}



void init(v8::Handle<v8::Object> target) {
#if 0
	{
		//HBITMAP bitmap = CreateBitmap(128, 128, 1, 32, nullptr);
		uint8_t defaultBuffer[16 * 1024]{0};
		auto hdc = CreateDC(TEXT("DISPLAY"),NULL,NULL,NULL);
		HFONT font = CreateFont(
			0,
			0,
			0,
			0,
			FW_DONTCARE,
			FALSE,
			FALSE,
			FALSE,
			DEFAULT_CHARSET,
			OUT_TT_ONLY_PRECIS,
			CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY,
			FF_SWISS | FIXED_PITCH,
			TEXT("Anonymous Pro"));
		GLYPHMETRICS gm{0,0,{0,0},0,0};
		MAT2 mat2{{0,2}, {0,0}, {0,0}, {0,2}};
		HFONT oldFont = (HFONT)SelectObject(hdc, font);
		for(int i = 0; i <= 255; i++) {

			const auto bufferSize = GetGlyphOutline(
				hdc,
				i,
				GGO_GRAY8_BITMAP,
				&gm,
				0,
				nullptr,
				&mat2);
			if(GDI_ERROR == bufferSize) {
				printf("GetGlyphOutline GDI_ERROR\n");
			}
			uint8_t *buf = bufferSize > sizeof(defaultBuffer)?new uint8_t[bufferSize]():defaultBuffer;


			const auto outlineStatus = GetGlyphOutline(
				hdc,
				i,
				GGO_GRAY8_BITMAP,
				&gm,
				bufferSize,
				buf,
				&mat2);

			puts("");
			puts("");
			int scan = gm.gmBlackBoxX;
			while(scan & 3) { scan++; }
			printf("BoxX: %3d BoxY: %3d Scan: %3d\n\n", gm.gmBlackBoxX, gm.gmBlackBoxY, scan);
			for(int y = 0; y < gm.gmBlackBoxY; y++) {
				printf("%3d\t\t", y);
				for(int x = 0; x < gm.gmBlackBoxX; x++) {
					auto cur = buf[(x + (scan * y))];
					if(!cur) { printf("   "); continue; }
					printf("%2d ", cur);
				}
				puts("");
			}
			puts("");

			if(buf!=defaultBuffer) {
				delete[] buf;
			}
		}
		(HFONT)SelectObject(hdc, oldFont);
		auto deleteStatus = DeleteDC(hdc);
		DeleteObject(font);
		printf("deleteStatus %d", deleteStatus);
	}
#endif

	class_Destructor::Init(target);
	class_WNDCLASSW::Init(target);
	class_GDIPLUS::Init(target);
	class_GDIPLUS_IMAGE::Init(target);
	class_GDIPLUS_BITMAP::Init(target);
#ifndef BUILD_WITHOUT_AUTO
	class_OpenGL::Init(target);
	class_WGL::Init(target);
#endif
#define SetFunctionSymbol(func) { target->Set(v8::String::NewSymbol(#func), v8::FunctionTemplate::New(func_##func)->GetFunction()); }

#if 0
	{
		class_GDIPLUS test;
		class_GDIPLUS_IMAGE test_image;
		class_GDIPLUS_BITMAP test_bitmap;
	}
#endif

	//SetFunctionSymbol(RdRand32)
	
	SetFunctionSymbol(OutputDebugString)
	SetFunctionSymbol(rdtsc)
	SetFunctionSymbol(MessageBox)
	SetFunctionSymbol(GetModuleHandle)
	SetFunctionSymbol(PeekMessage)
	SetFunctionSymbol(GetMessage)
	SetFunctionSymbol(TranslateMessage)
	SetFunctionSymbol(DispatchMessage)
	SetFunctionSymbol(SwapBuffers)

	#define SetFunctionSymbolStatic(cls, func) { target->Set(v8::String::NewSymbol(#func), v8::FunctionTemplate::New(class_##cls::func_##func)->GetFunction()); }

	SetFunctionSymbolStatic(Intrinsics, RdRand32)

	{ //Gdi32
		SetFunctionSymbolStatic(Gdi32, wglMakeCurrent)
		SetFunctionSymbolStatic(Gdi32, wglDeleteContext)
		SetFunctionSymbolStatic(Gdi32, wglCreateContext)
		SetFunctionSymbolStatic(Gdi32, wglMakeCurrent)
		GET_Y_LPARAM(0);
		SetFunctionSymbolStatic(Gdi32, MoveWindow)
		SetFunctionSymbolStatic(Gdi32, ValidateRect)
		SetFunctionSymbolStatic(Gdi32, GetClientRect)
		SetFunctionSymbolStatic(Gdi32, GetWindowRect)
		SetFunctionSymbolStatic(Gdi32, SetWindowLong)
		SetFunctionSymbolStatic(Gdi32, SetWindowLongPtr)
		SetFunctionSymbolStatic(Gdi32, FreeConsole)
		SetFunctionSymbolStatic(Gdi32, ChangeDisplaySettingsW)
		SetFunctionSymbolStatic(Gdi32, ShowCursor)
		SetFunctionSymbolStatic(Gdi32, UnregisterClassW)
		SetFunctionSymbolStatic(Gdi32, DestroyWindow)
		SetFunctionSymbolStatic(Gdi32, ReleaseDC)
		SetFunctionSymbolStatic(Gdi32, AdjustWindowRectEx)
		SetFunctionSymbolStatic(Gdi32, CreateWindowEx)
		SetFunctionSymbolStatic(Gdi32, GetDC)
		SetFunctionSymbolStatic(Gdi32, ChoosePixelFormat)
		SetFunctionSymbolStatic(Gdi32, SetPixelFormat)
		SetFunctionSymbolStatic(Gdi32, ShowWindow)
		SetFunctionSymbolStatic(Gdi32, SetForegroundWindow)
		SetFunctionSymbolStatic(Gdi32, SetFocus)
		SetFunctionSymbolStatic(Gdi32, DefWindowProc)
		SetFunctionSymbolStatic(Gdi32, PostQuitMessage)
		SetFunctionSymbolStatic(Gdi32, LOWORD)
		SetFunctionSymbolStatic(Gdi32, HIWORD)
	}

#undef SetFunctionSymbol
#define SetConstantSymbol(constant) { target->Set(v8::String::NewSymbol(#constant), v8::Uint32::NewFromUnsigned(constant)); }
	SetConstantSymbol(NULL)
	SetConstantSymbol(TRUE)
	SetConstantSymbol(FALSE)

#if 1 //from user32
	#include "User32Keyboard.h"
#else
		SetConstantSymbol(WM_ACTIVATE)
		//SetConstantSymbol(LOWORD)
		//SetConstantSymbol(HIWORD)
		SetConstantSymbol(WA_INACTIVE)
		SetConstantSymbol(WM_SYSCOMMAND)
		SetConstantSymbol(SC_SCREENSAVE)
		SetConstantSymbol(SC_MONITORPOWER)
		SetConstantSymbol(WM_CLOSE)
		SetConstantSymbol(WM_KEYDOWN)
		SetConstantSymbol(WM_KEYUP)
		SetConstantSymbol(WM_SIZE)
#endif

	{ //From WinUser.h
		SetConstantSymbol(MB_OK)
		SetConstantSymbol(MB_OKCANCEL)
		SetConstantSymbol(MB_ABORTRETRYIGNORE)
		SetConstantSymbol(MB_YESNOCANCEL)
		SetConstantSymbol(MB_YESNO)
		SetConstantSymbol(MB_RETRYCANCEL)
		#if(WINVER >= 0x0500)
		SetConstantSymbol(MB_CANCELTRYCONTINUE)
		#endif /* WINVER >= 0x0500 */


		SetConstantSymbol(MB_ICONHAND)
		SetConstantSymbol(MB_ICONQUESTION)
		SetConstantSymbol(MB_ICONEXCLAMATION)
		SetConstantSymbol(MB_ICONASTERISK)

		#if(WINVER >= 0x0400)
		SetConstantSymbol(MB_USERICON)
		SetConstantSymbol(MB_ICONWARNING)
		SetConstantSymbol(MB_ICONERROR)
		#endif /* WINVER >= 0x0400 */

		SetConstantSymbol(MB_ICONINFORMATION)
		SetConstantSymbol(MB_ICONSTOP)

		SetConstantSymbol(MB_DEFBUTTON1)
		SetConstantSymbol(MB_DEFBUTTON2)
		SetConstantSymbol(MB_DEFBUTTON3)
		#if(WINVER >= 0x0400)
		SetConstantSymbol(MB_DEFBUTTON4)
		#endif /* WINVER >= 0x0400 */

		SetConstantSymbol(MB_APPLMODAL)
		SetConstantSymbol(MB_SYSTEMMODAL)
		SetConstantSymbol(MB_TASKMODAL)
		#if(WINVER >= 0x0400)
		SetConstantSymbol(MB_HELP)
		#endif /* WINVER >= 0x0400 */

		SetConstantSymbol(MB_NOFOCUS)
		SetConstantSymbol(MB_SETFOREGROUND)
		SetConstantSymbol(MB_DEFAULT_DESKTOP_ONLY)

		#if(WINVER >= 0x0400)
		SetConstantSymbol(MB_TOPMOST)
		SetConstantSymbol(MB_RIGHT)
		SetConstantSymbol(MB_RTLREADING)

		#endif /* WINVER >= 0x0400 */

		#ifdef _WIN32_WINNT
		#if (_WIN32_WINNT >= 0x0400)
		SetConstantSymbol(MB_SERVICE_NOTIFICATION)
		#else
		SetConstantSymbol(MB_SERVICE_NOTIFICATION)
		#endif
		SetConstantSymbol(MB_SERVICE_NOTIFICATION_NT3X)
		#endif

		SetConstantSymbol(MB_TYPEMASK)
		SetConstantSymbol(MB_ICONMASK)
		SetConstantSymbol(MB_DEFMASK)
		SetConstantSymbol(MB_MODEMASK)
		SetConstantSymbol(MB_MISCMASK)
	}

	{//From WinUser.h
		/*
		 * Dialog Box Command IDs
		 */
		SetConstantSymbol(IDOK)
		SetConstantSymbol(IDCANCEL)
		SetConstantSymbol(IDABORT)
		SetConstantSymbol(IDRETRY)
		SetConstantSymbol(IDIGNORE)
		SetConstantSymbol(IDYES)
		SetConstantSymbol(IDNO)
		#if(WINVER >= 0x0400)
		SetConstantSymbol(IDCLOSE)
		SetConstantSymbol(IDHELP)
		#endif /* WINVER >= 0x0400 */

		#if(WINVER >= 0x0500)
		SetConstantSymbol(IDTRYAGAIN)
		SetConstantSymbol(IDCONTINUE)
		#endif /* WINVER >= 0x0500 */

		#if(WINVER >= 0x0501)
		#ifndef IDTIMEOUT
		SetConstantSymbol(IDTIMEOUT)
		#endif
		#endif /* WINVER >= 0x0501 */

	}
	//SetConstantSymbol(CS_HREDRAW)
	//SetConstantSymbol(CS_VREDRAW)
	//SetConstantSymbol(CS_OWNDC)

	//SetConstantSymbol(WS_EX_APPWINDOW)
	//SetConstantSymbol(WS_POPUP)
	//SetConstantSymbol(WS_EX_APPWINDOW)
	//SetConstantSymbol(WS_EX_WINDOWEDGE)
	//SetConstantSymbol(WS_OVERLAPPEDWINDOW)
	//SetConstantSymbol(WS_CLIPSIBLINGS)
	//SetConstantSymbol(WS_CLIPCHILDREN)

	{//from winuser.h

/*
 * Window Styles
 */
		SetConstantSymbol(WS_OVERLAPPED)
		SetConstantSymbol(WS_POPUP)
		SetConstantSymbol(WS_CHILD)
		SetConstantSymbol(WS_MINIMIZE)
		SetConstantSymbol(WS_VISIBLE)
		SetConstantSymbol(WS_DISABLED)
		SetConstantSymbol(WS_CLIPSIBLINGS)
		SetConstantSymbol(WS_CLIPCHILDREN)
		SetConstantSymbol(WS_MAXIMIZE)
		SetConstantSymbol(WS_CAPTION)
		SetConstantSymbol(WS_BORDER)
		SetConstantSymbol(WS_DLGFRAME)
		SetConstantSymbol(WS_VSCROLL)
		SetConstantSymbol(WS_HSCROLL)
		SetConstantSymbol(WS_SYSMENU)
		SetConstantSymbol(WS_THICKFRAME)
		SetConstantSymbol(WS_GROUP)
		SetConstantSymbol(WS_TABSTOP)

		SetConstantSymbol(WS_MINIMIZEBOX)
		SetConstantSymbol(WS_MAXIMIZEBOX)


		SetConstantSymbol(WS_TILED)
		SetConstantSymbol(WS_ICONIC)
		SetConstantSymbol(WS_SIZEBOX)
		SetConstantSymbol(WS_TILEDWINDOW)

/*
 * Common Window Styles
 */
		SetConstantSymbol(WS_OVERLAPPEDWINDOW)

		SetConstantSymbol(WS_POPUPWINDOW)

		SetConstantSymbol(WS_CHILDWINDOW)

/*
 * Extended Window Styles
 */
		SetConstantSymbol(WS_EX_DLGMODALFRAME)
		SetConstantSymbol(WS_EX_NOPARENTNOTIFY)
		SetConstantSymbol(WS_EX_TOPMOST)
		SetConstantSymbol(WS_EX_ACCEPTFILES)
		SetConstantSymbol(WS_EX_TRANSPARENT)
#if(WINVER >= 0x0400)
		SetConstantSymbol(WS_EX_MDICHILD)
		SetConstantSymbol(WS_EX_TOOLWINDOW)
		SetConstantSymbol(WS_EX_WINDOWEDGE)
		SetConstantSymbol(WS_EX_CLIENTEDGE)
		SetConstantSymbol(WS_EX_CONTEXTHELP)

#endif /* WINVER >= 0x0400 */
#if(WINVER >= 0x0400)

		SetConstantSymbol(WS_EX_RIGHT)
		SetConstantSymbol(WS_EX_LEFT)
		SetConstantSymbol(WS_EX_RTLREADING)
		SetConstantSymbol(WS_EX_LTRREADING)
		SetConstantSymbol(WS_EX_LEFTSCROLLBAR)
		SetConstantSymbol(WS_EX_RIGHTSCROLLBAR)

		SetConstantSymbol(WS_EX_CONTROLPARENT)
		SetConstantSymbol(WS_EX_STATICEDGE)
		SetConstantSymbol(WS_EX_APPWINDOW)


		SetConstantSymbol(WS_EX_OVERLAPPEDWINDOW)
		SetConstantSymbol(WS_EX_PALETTEWINDOW)

#endif /* WINVER >= 0x0400 */

#if(_WIN32_WINNT >= 0x0500)
		SetConstantSymbol(WS_EX_LAYERED)

#endif /* _WIN32_WINNT >= 0x0500 */


#if(WINVER >= 0x0500)
		SetConstantSymbol(WS_EX_NOINHERITLAYOUT)
#endif /* WINVER >= 0x0500 */

#if(WINVER >= 0x0602)
		SetConstantSymbol(WS_EX_NOREDIRECTIONBITMAP)
#endif /* WINVER >= 0x0602 */

#if(WINVER >= 0x0500)
		SetConstantSymbol(WS_EX_LAYOUTRTL)
#endif /* WINVER >= 0x0500 */

#if(_WIN32_WINNT >= 0x0501)
		SetConstantSymbol(WS_EX_COMPOSITED)
#endif /* _WIN32_WINNT >= 0x0501 */
#if(_WIN32_WINNT >= 0x0500)
		SetConstantSymbol(WS_EX_NOACTIVATE)
#endif /* _WIN32_WINNT >= 0x0500 */

/*
 * Class styles
 */
		SetConstantSymbol(CS_VREDRAW)
		SetConstantSymbol(CS_HREDRAW)
		SetConstantSymbol(CS_DBLCLKS)
		SetConstantSymbol(CS_OWNDC)
		SetConstantSymbol(CS_CLASSDC)
		SetConstantSymbol(CS_PARENTDC)
		SetConstantSymbol(CS_NOCLOSE)
		SetConstantSymbol(CS_SAVEBITS)
		SetConstantSymbol(CS_BYTEALIGNCLIENT)
		SetConstantSymbol(CS_BYTEALIGNWINDOW)
		SetConstantSymbol(CS_GLOBALCLASS)

		SetConstantSymbol(CS_IME)
#if(_WIN32_WINNT >= 0x0501)
		SetConstantSymbol(CS_DROPSHADOW)
#endif /* _WIN32_WINNT >= 0x0501 */

#ifndef NOSHOWWINDOW


/*
 * ShowWindow() Commands
 */
		SetConstantSymbol(SW_HIDE)
		SetConstantSymbol(SW_SHOWNORMAL)
		SetConstantSymbol(SW_NORMAL)
		SetConstantSymbol(SW_SHOWMINIMIZED)
		SetConstantSymbol(SW_SHOWMAXIMIZED)
		SetConstantSymbol(SW_MAXIMIZE)
		SetConstantSymbol(SW_SHOWNOACTIVATE)
		SetConstantSymbol(SW_SHOW)
		SetConstantSymbol(SW_MINIMIZE)
		SetConstantSymbol(SW_SHOWMINNOACTIVE)
		SetConstantSymbol(SW_SHOWNA)
		SetConstantSymbol(SW_RESTORE)
		SetConstantSymbol(SW_SHOWDEFAULT)
		SetConstantSymbol(SW_FORCEMINIMIZE)
		SetConstantSymbol(SW_MAX)


/*
 * Old ShowWindow() Commands
 */
		SetConstantSymbol(HIDE_WINDOW)
		SetConstantSymbol(SHOW_OPENWINDOW)
		SetConstantSymbol(SHOW_ICONWINDOW)
		SetConstantSymbol(SHOW_FULLSCREEN)
		SetConstantSymbol(SHOW_OPENNOACTIVATE)

/*
 * Identifiers for the WM_SHOWWINDOW message
 */
		SetConstantSymbol(SW_PARENTCLOSING)
		SetConstantSymbol(SW_OTHERZOOM)
		SetConstantSymbol(SW_PARENTOPENING)
		SetConstantSymbol(SW_OTHERUNZOOM)


#endif /* !NOSHOWWINDOW */

		SetConstantSymbol(GWL_EXSTYLE)
		SetConstantSymbol(GWL_STYLE)
	}

	SetConstantSymbol(PM_REMOVE)
	SetConstantSymbol(WM_QUIT)
	SetConstantSymbol(VK_ESCAPE)
	SetConstantSymbol(VK_F1)



	{//from wingdi.h
/* pixel types */
	SetConstantSymbol(PFD_TYPE_RGBA)
	SetConstantSymbol(PFD_TYPE_COLORINDEX)

/* layer types */
	SetConstantSymbol(PFD_MAIN_PLANE)
	SetConstantSymbol(PFD_OVERLAY_PLANE)
	SetConstantSymbol(PFD_UNDERLAY_PLANE)

/* PIXELFORMATDESCRIPTOR flags */
	SetConstantSymbol(PFD_DOUBLEBUFFER)
	SetConstantSymbol(PFD_STEREO)
	SetConstantSymbol(PFD_DRAW_TO_WINDOW)
	SetConstantSymbol(PFD_DRAW_TO_BITMAP)
	SetConstantSymbol(PFD_SUPPORT_GDI)
	SetConstantSymbol(PFD_SUPPORT_OPENGL)
	SetConstantSymbol(PFD_GENERIC_FORMAT)
	SetConstantSymbol(PFD_NEED_PALETTE)
	SetConstantSymbol(PFD_NEED_SYSTEM_PALETTE)
	SetConstantSymbol(PFD_SWAP_EXCHANGE)
	SetConstantSymbol(PFD_SWAP_COPY)
	SetConstantSymbol(PFD_SWAP_LAYER_BUFFERS)
	SetConstantSymbol(PFD_GENERIC_ACCELERATED)
	SetConstantSymbol(PFD_SUPPORT_DIRECTDRAW)
	SetConstantSymbol(PFD_DIRECT3D_ACCELERATED)
	SetConstantSymbol(PFD_SUPPORT_COMPOSITION)

/* PIXELFORMATDESCRIPTOR flags for use in ChoosePixelFormat only */
	SetConstantSymbol(PFD_DEPTH_DONTCARE)
	SetConstantSymbol(PFD_DOUBLEBUFFER_DONTCARE)
	SetConstantSymbol(PFD_STEREO_DONTCARE)

	}
#undef SetConstantSymbol



	target->Set(v8::String::NewSymbol("sizeof_MSG"), v8::Uint32::NewFromUnsigned(sizeof(MSG)));
	target->Set(v8::String::NewSymbol("sizeof_RECT"), v8::Uint32::NewFromUnsigned(sizeof(RECT)));
	target->Set(v8::String::NewSymbol("sizeof_WNDCLASSW"), v8::Uint32::NewFromUnsigned(sizeof(WNDCLASSW)));
	target->Set(v8::String::NewSymbol("sizeof_PIXELFORMATDESCRIPTOR"), v8::Uint32::NewFromUnsigned(sizeof(PIXELFORMATDESCRIPTOR)));
	
}



NODE_MODULE(media_accel, init);
//NODE_MODULE(media_accel_media_accel_x64_Debug, init);