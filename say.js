
(function () {
	"use strict";

	var hello = require("./build/default/hello");
	
	console.log("The .exports from the module you wrote:");
	console.log(hello);
	var n = 2;
	console.log("Your input: " + process.argv[n]);
	console.log("Your function's result: " + hello.func(process.argv[n]));

}());

