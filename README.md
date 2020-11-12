# MarkdownToHTML

A simple command line tool to convert _Markdown_ to _HTML_ for visualization.

## Compiling

Only one dependency is required for compiling. It needs _libcurl_ installed to compile.

A _Makefile_ is provided to easily compile the soft.
Just use ```make```.

Additional avalaible directives :
* The ```clean``` directive remove all binaries and the executable.
* The ```install``` directive, in addition to build the executable, place a copy of the executable into the __/usr/bin__ directory.

## Usage

The command takes one required parameter and one optional.

```SHELL
mdtohtml SOURCE [TARGET]
```

The source is the _Markdown_ input file and the target is the output _HTML_ file. The target is optional, if no target specified the output file will be named by the input file name appended with ".html".
