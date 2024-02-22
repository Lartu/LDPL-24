

<p align="center">
  <img src="https://github.com/Lartu/LDPL-24/blob/main/images/header.png">
  <br><br>
  <img src="https://img.shields.io/badge/stable_release-No!!-red.svg">
  <img src="https://img.shields.io/badge/license-Apache_2.0-yellow">
</p>

The readme below is updated (for now!!) This is a fork of [LDPL](http://github.com/lartu/ldpl/) 1.1.2, from March 6,
2019.

## Old Readme

[LDPL](http://ldpl.lartu.net/) is a programming language designed to be very easy to read and understand.
Also as a joke, as its syntax is based on that from COBOL.

This repository contains the source for the LDPL interpreter.
Check http://ldpl.lartu.net/ for more information on the language, tutorials and examples.

## About the language

LDPL is standarized [here](http://ldpl.lartu.net/reference).
That's both the language documentation and the compiler writting standard.

## How to use this interpreter

First, download the latest release.
Then `make` LDPL in the `src` folder. LDPL requires only C++11 to compile.
Then write some LDPL source code, say `source.lsc`.
Then compile and run said source code using `ldpl source.lsc`.
Done! For more info on the interpreter run `ldpl -h`.
Example code can be found on [the LDPL website](http://ldpl.lartu.net).

## Interpreter options

 * You can import files to your LDPL compilation by using the `-i` flag. For example, say you have a library `mylib.ldpl` and a source file `mysource.ldpl`, you can compile both and include the library by running `ldpl -i=mylibrary.ldpl mysource.ldpl`. Multiple `-i=` can be used to import multiple files.
 * By using `-r` you can just compile the project and print LDPL's internal representation for that code.
 * `-v` and `--version` print out version info and release details.
 * `-h` and `--help` print this list of options.

## License

LDPL is distributed under the GNU General Public License 3.0.
