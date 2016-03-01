#include <nan.h>

void test(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  info.GetReturnValue().Set(Nan::New("hello world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  Nan::Set(exports,
           Nan::New("test").ToLocalChecked(),
           Nan::New<v8::FunctionTemplate>(test)->GetFunction());
}

NODE_MODULE(addon, Init)
