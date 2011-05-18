
(function () {
	"use strict";

	var hello = require("./build/default/hello");

	console.log(hello);
	console.log(hello[1]);
	console.log(hello.potato(55));
}());

