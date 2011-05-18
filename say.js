
(function () {
	"use strict";

	var hello = require("./build/default/hello");
	
	console.log(hello);
	var n = 2;
	console.log(process.argv[n]);
	console.log(hello.func(process.argv[n]));

}());

