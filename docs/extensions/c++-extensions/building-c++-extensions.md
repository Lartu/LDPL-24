# Building C++ Extensions

Extensions are easy to build: when compiling your LDPL program, use the `-i=` flag to pass in `.cpp` files, `.o` files, or `.a` files to the LDPL compiler. They'll get included in your program and be available using the `EXTERNAL` statements.

For example, if your LDPL source file is called `mySource.ldpl` and you want to include `otherFile.cpp` to your project, you just do

```text
$ ldpl -i=otherFile.cpp mySource.ldpl
```

If your C++ extension files require extra flags to be passed to the C++ compiler in order to compile \(for example, `-lSDL` when working with SDL\) you can use the `-f=` flag to pass those flags to it. Following the SDL example, you could do

```text
$ ldpl -i=mySDLSource.cpp mySource.ldpl -f=-lSDL
```

and the C++ compiler will be executed with the `-lSDL` flag.

```text
$ ldpl -i=<extension file> code.ldpl
```



