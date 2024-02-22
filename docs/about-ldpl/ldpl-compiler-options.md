# LDPL Compiler Switches

You can **import** files to your LDPL compilation by using the `-i` flag. For example, say you have a library `mylib.ldpl` and a source file `mysource.ldpl`, you can compile both and include the library by running `ldpl -i=mylibrary.ldpl mysource.ldpl`. Multiple `-i=` can be used to import multiple files. Extensions can also be imported by using this flag; see the [Extensions](../extensions/c++-extensions/) section.

By using `-r` you can just compile the project and print the **C++ representation** for that code.

You can set the **output file** for the compiled binary with the `-o` flag. For example, if you want to name your program "dog", you could compile it with `ldpl -o=dog main.ldpl`.

On **Linux** and **Windows** platforms, LDPL builds static binaries by default. If you want to build non-static ones use the `-n` flag \(or the alternative `--non-static` flag\).

The `-c` flag tells LDPL to accept source code from the **standard input**.

`-v` and `--version` print out **version** info and release details.

`-h` and `--help` print this list of options.

The `-f` flag can be used to add flags to the C++ compilation line. See the [Building C++ Extensions](../extensions/c++-extensions/building-c++-extensions.md) section for more information.

