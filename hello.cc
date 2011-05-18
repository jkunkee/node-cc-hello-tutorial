#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

// The hard part of writing your own function is inerfacing it with Node.
//  The function prototype must match.
//  HandleScope scope; is important for returning values, though it's 
//    true functions probably have much deeper potential.
//  args is allowed to be an arbitrary argument list, as Javascript allows.
//  Each kind of literal in Node/Javascript has a Type::New() operator. 
//    see v8.h and node.h for specifics.
static Handle<Value> functionName(const Arguments& args) {
	// Have Node/V8 keep track of scope for us
	HandleScope scope;

	// Argument validation (TypeError is probably not what we want here.
	if (args.Length() > 1) {
		return ThrowException(Exception::TypeError(String::New("More than one argument")));
	} else if (args.Length() < 1) {
	  return ThrowException(Exception::TypeError(String::New("No argument")));
	// Node provides several methods on Data items for
	//   determining their composition. Grep is your friend...
	//} else if (!args[0]->IsNumber()) {
	//	return ThrowException(Exception::TypeError(String::New("Argument !IsNumber()")));
	} else {
		// It seems that Node treats all numbers as doubles internally.
		// Any quantity of C++ logic could be used here, though global/class
		//   variables ought to be operated via the scope and target...I think.
		double result = args[0]->NumberValue() + 2;
		// This syntax is borrowed from other example code.
		// It seems that keeping scope straight with threads involved is 
		//  accomplished like this.
		// Note that the return value is rewrapped into a Javascript primitive.
		return scope.Close(Number::New(result));
	}
}

//This function -- which requires this exact prototype -- is run upon requiring
// the module.
//Notice that 'target' is the object representing the module.
extern "C" void
init (Handle<Object> target)
{
	// Invoke the Node.js internals for tracking scope
  HandleScope scope;

	// exports.hello = "world";
	target->Set(String::New("hello"), String::New("world"));
	// exports[3] = 2;
	target->Set(String::New("3"), String::New("2"));
	
	//Local<FunctionTemplate> newFunc = FunctionTemplate::New();
	//newFunc->Inherit();
	//newFunc->SetAccessor(String::NewSymbol("position"));
	//target->Set(String::NewSymbol("func1"), newFunc->GetFunction());
	
	//exports.func = function (anything) {stuff up there};
	NODE_SET_METHOD(target, "func", functionName);
	
}

