# Using the LDPL Compiler

To use the compiler, you must have a C++ compiler already installed on your system and have mapped it to `c++`, found on your `PATH`. The LDPL Compiler compiles LDPL code to C++ code and thus this is a requirement for it to work.

{% hint style="info" %}
Compilation under **Windows** has been tested with [MinGW](http://www.mingw.org/wiki/Getting_Started) as installed on the linked guide. MinGW-w64 seems to have some problems compiling LDPL.

Compilation under **Linux** and **Mac OS X** has been tested with the GNU C++ Compiler, G++.
{% endhint %}

In order to use the LDPL Compiler, you must first install it. There are two ways of doing this:

* **If you want to download a compiled binary:** just go to the [Releases](https://github.com/Lartu/ldpl/releases) part of the LDPL repository and download the newest one available.
* **If you want to build LDPL yourself:** first, clone the LDPL [repository](https://github.com/lartu/ldpl). Then `make` LDPL in the `src` folder. LDPL requires only C++11 to compile.

When you are done installing LDPL, go write some LDPL source code, say `source.lsc`. Then compile the source code using `ldpl source.lsc`. The compiled, executable binary file will be saved as `ldpl.out`. Done! For more info on the compiler run `ldpl -h`. Example code can be found on [the LDPL website](http://ldpl.lartu.net).

