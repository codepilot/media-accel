class class_Destructor: public node::ObjectWrap {
public:

	class_Destructor *THIS_PTR;
	static void class_Destructor::Init(v8::Handle<v8::Object> target) {
		v8::HandleScope scope;
		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(New);
		tpl->SetClassName(v8::String::NewSymbol("Destructor"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);
		constructor = v8::Persistent<v8::Function>::New(tpl->GetFunction());
		target->Set(v8::String::NewSymbol("Destructor"), constructor);
	}

	static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args) {
		v8::HandleScope scope;

		const unsigned argc = 1;
		v8::Handle<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Object> instance = constructor->NewInstance(argc, argv);

		return scope.Close(instance);
	}
//private:
	class_Destructor() {
		#if 1
			OutputDebugString(L"Destructor()\n");
		#else
			puts("Destructor()");
		#endif
		THIS_PTR = this;

	}
	~class_Destructor() {
		#if 1
			OutputDebugString(L"~Destructor() before callback\n");
		#else
			puts("~Destructor() before callback");
		#endif
		v8::HandleScope scope;
		cb->Call(v8::Context::GetCurrent()->Global(), 0, nullptr);
		#if 1
			OutputDebugString(L"~Destructor() callback completed\n");
		#else
			puts("~Destructor() callback completed");
		#endif
	}
private:
	v8::Persistent<v8::Function> cb;
	static v8::Handle<v8::Value> New(const v8::Arguments& args) {
		v8::HandleScope scope;
		if(args.Length() < 1){
			return v8::Undefined();
		}
		class_Destructor* obj = new class_Destructor();
		obj->Wrap(args.This());
		obj->cb = v8::Persistent<v8::Function>::New(v8::Handle<v8::Function>::Cast(args[0]));
		return args.This();
	}
	static v8::Persistent<v8::Function> constructor;
};