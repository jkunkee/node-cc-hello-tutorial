#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

static Handle<Value> func1(const Arguments& args) {
	HandleScope scope;
	if (args.Length() == 1 && args[0]->IsInt32())
		return scope.Close(Number::New(5));
	else
		return ThrowException(Exception::TypeError(String::New("non-integer argument")));
}

extern "C" void
init (Handle<Object> target)
{
  HandleScope scope;
	target->Set(String::New("hello"), String::New("world"));
	target->Set(String::New("1"), String::New("2"));
	
	//Local<FunctionTemplate> newFunc = FunctionTemplate::New();
	//newFunc->Inherit();
	//newFunc->SetAccessor(String::NewSymbol("position"));
	//target->Set(String::NewSymbol("func1"), newFunc->GetFunction());
	NODE_SET_METHOD(target, "potato", func1);
	
}

