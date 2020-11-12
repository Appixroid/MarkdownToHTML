# MarkdownToHTML

A simple command line tool to simply convert _Markdown_ to _HTML_ for visualization.

## Compiling

A _makefile_ is provided to easily compile the soft.
Simply use ```make```. A clean target is also available.

## Usage

The command takes one required parameter and one optional.
```SHELL
mdtohtml SOURCE [TARGET]
```
The source is the _Markdown_ input file and the target is the output _HTML_ file. The target is optional, if no target specified the output file will be named by the input file name appended with ".html".
