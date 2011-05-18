
(function () {
	"use strict";

	//require the module like any other module
	var hello = require("./build/default/hello")
	//The first argument is at array index 2.
	  , n = 2;
	
	console.log("The .exports from the module you wrote:");
	console.log(hello);
	console.log("Your input: " + process.argv[n]);
	console.log("Your function's result: " + hello.func(process.argv[n]));

}());

