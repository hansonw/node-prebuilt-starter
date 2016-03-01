#include <nan.h>
#include <string>

class TestObject : public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports) {
    // Create a constructor function.
    auto tpl = Nan::New<v8::FunctionTemplate>(TestObject::Create);
    tpl->SetClassName(Nan::New("TestObject").ToLocalChecked());

    // Store a pointer to a TestObject inside.
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Declare prototype methods.
    Nan::SetPrototypeMethod(tpl, "test", TestObject::Test);

    exports->Set(Nan::New("TestObject").ToLocalChecked(), tpl->GetFunction());
  }

  static void Create(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    auto obj = new TestObject();
    obj->Wrap(info.This());
    obj->value = "hello world";
    info.GetReturnValue().Set(info.This());
  }

  static void Test(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    auto obj = Unwrap<TestObject>(info.This());
    info.GetReturnValue().Set(Nan::New(obj->value).ToLocalChecked());
  }

private:
  std::string value;
};

void test(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  info.GetReturnValue().Set(Nan::New("hello world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("test").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(test)->GetFunction());

  TestObject::Init(exports);
}

NODE_MODULE(addon, Init)
