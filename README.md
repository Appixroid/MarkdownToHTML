# Markdown To HTML

A simple command line tool to convert _Markdown_ to _HTML_ for visualization.

## Compiling

Only one dependency is required for compiling. It needs _libcurl_ installed to compile.

A _Makefile_ is provided to easily compile the soft.
Just use ```make```.

Additional avaliable directives :
* The ```clean``` directive removes all binaries and the executable.
* The ```install``` directive, in addition to build the executable, places a copy of the executable into the __/usr/bin__ directory.

## Usage

The command takes one required parameter and one optional.

```SHELL
mdtohtml SOURCE [TARGET]
```

The source is the _Markdown_ input file and the target is the _HTML_ output file. The target is optional, if no target is specified, the output file will be named like the input file appended with ".html".
