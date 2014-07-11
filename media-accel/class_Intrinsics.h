class class_Intrinsics {
public:
	static v8::Handle<v8::Value> func_RdRand32(const v8::Arguments& args) {
		v8::HandleScope scope;

		uint32_t ret{0};
		if(_rdrand32_step(&ret)) {
			return scope.Close(v8::Uint32::NewFromUnsigned(ret));
		} else {
			return v8::Undefined();
		}
	}
};