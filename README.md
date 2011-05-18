
Greetings!

You are probably here wondering, "How do I extend Node using C++?"

This is a wonderful question. While almost no documentation exists on the subject, combining what little there is with several examples should enable you to accomplish your goal.

Compiling and running node-cc-hello-tutorial:

Make sure Node.js is installed ([see "How to Install Node.js"](http://howtonode.org/how-to-install-nodejs))

In a terminal:

    git clone git://github.com/jkunkee/node-cc-hello-tutorial.git
    cd node-cc-hello-tutorial
    node-waf configure build
    node say.js 55

I have yet to try this on a fresh system, so node-waf may be lacking some python dependencies. 
