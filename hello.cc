#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

static Handle<Value> functionName(const Arguments& args) {
	HandleScope scope;
	if (args.Length() > 1) {
		return ThrowException(Exception::TypeError(String::New("More than one argument")));
	} else if (args.Length() < 1) {
	  return ThrowException(Exception::TypeError(String::New("No argument")));
	//} else if (!args[0]->IsNumber()) {
	//	return ThrowException(Exception::TypeError(String::New("Argument !IsNumber()")));
	} else {
		double result = args[0]->NumberValue() + 2;
		return scope.Close(Number::New(result));
	}
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
	NODE_SET_METHOD(target, "func", functionName);
	
}

