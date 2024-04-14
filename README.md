

<p align="center">
  <img src="https://github.com/Lartu/LDPL-24/blob/main/images/header.png">
  <br><br>
  <img src="https://img.shields.io/badge/stable_release-No!!-red.svg">
  <img src="https://img.shields.io/badge/license-Apache_2.0-yellow">
</p>

### 🎇 LDPL 24: the language of the past, *today*!

![](https://github.com/Lartu/ldpl/blob/master/images/ldplsaur.png?raw=true)

This is a fork of **[LDPL](http://github.com/lartu/ldpl/) 1.1.2**, from March 6, 2019.
**LDPL 1.1.2** is the last version to run as an interpreter on the NariVM. All subsequent versions transpile LDPL code to C++.

### 🔎 Missing NariVM features
These are features that were present when LDPL 1.1.2 ran on the NariVM. The current version doesn't and favours an execution tree instead, which is faster.
- [X] `STORE` for TEXT values
- [X] `ACCEPT` using ldplnoise
- [X] `ABS ... IN ...`
- [X] `CEIL ... IN ...`
- [X] `FLOOR ... IN ...`
- [ ] `JOIN ... AND ... IN ...`
- [ ] `GET CHARACTER AT ... FROM ... IN ...`
- [ ] `GET LENGTH OF ... IN ...`
- [ ] `SUB-PROCEDURES`
- [ ] `IF` blocks
- [ ] `WHILE` blocks
- [ ] Update documentation removing removed parts and adding new commands.

All other features present in LDPL 1.1.2 have already been updated.

### 🚀 Missing features not present in LDPL 1.1.2
- [ ] Fix `WHILE string IS NOT EQUAL TO string DO` (backport from LDPL 2.1.2)
- [ ] Backport bugfixes from versions newer than 1.1.2
- [ ] `CALL` from LDPL 2.2.0
- [ ] A file writing / loading library
- [ ] UI support via FLTK embedded into the language
- [ ] `ELSE IF` (backport from LDPL 3.0.0)
- [x] `LABEL` and `GOTO` support
- [ ] Fix this readme!

### ❇️ Contributors are welcome! ❇️

![](https://github.com/Lartu/ldpl/raw/master/images/tutorial-logo.png)

To learn how to contribute, please read the [Contributors Guide](https://github.com/Lartu/ldpl/blob/master/CONTRIBUTING.md) on the old LDPL repository. Most contributions are welcome, come join us!

## 📜 License

The LDPL Compiler is distributed under the Apache 2.0 License. All LDPL Dinosaur logos were created by [Lartu](https://www.lartu.net) and are released under a Creative Commons Attribution 4.0 International (CC BY 4.0) license.

## 💀 Old Readme (outdated and probably wrong!)

[LDPL](http://ldpl.lartu.net/) is a programming language designed to be very easy to read and understand.
Also as a joke, as its syntax is based on that from COBOL.

This repository contains the source for the LDPL interpreter.
Check http://ldpl.lartu.net/ for more information on the language, tutorials and examples.

### About the language

LDPL is standarized [here](http://ldpl.lartu.net/reference).
That's both the language documentation and the compiler writting standard.

### How to use this interpreter

First, download the latest release.
Then `make` LDPL in the `src` folder. LDPL requires only C++11 to compile.
Then write some LDPL source code, say `source.lsc`.
Then compile and run said source code using `ldpl source.lsc`.
Done! For more info on the interpreter run `ldpl -h`.
Example code can be found on [the LDPL website](http://ldpl.lartu.net).

### Interpreter options

 * You can import files to your LDPL compilation by using the `-i` flag. For example, say you have a library `mylib.ldpl` and a source file `mysource.ldpl`, you can compile both and include the library by running `ldpl -i=mylibrary.ldpl mysource.ldpl`. Multiple `-i=` can be used to import multiple files.
 * By using `-r` you can just compile the project and print LDPL's internal representation for that code.
 * `-v` and `--version` print out version info and release details.
 * `-h` and `--help` print this list of options.
