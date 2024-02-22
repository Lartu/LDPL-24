# Command Line Arguments

Every LDPL program comes with two variables declared by default: `argc`, of the NUMBER type, and `argv`, a TEXT VECTOR. If you pass command line arguments to your LDPL compiled program \(running, for example, something like `myBinary argument1 argument2)`, the value stored in the variable `argc` \(_argument count_\) will reflect the number of arguments passed to the script \(in this case, two\), while the `argv` vector \(_argument vector_\) will store in its 0-based natural number positions \(that is 0, 1, 2, 3, etc.\) the values of each argument passed \(in this case, `"argument1"` will be stored in `argv:0` and `"argument2"` in `argv:1`\).

{% hint style="info" %}
Given that `argv` is a TEXT VECTOR, the values passed as arguments are always stored as TEXT.
{% endhint %}

Naturally, if no arguments are passed to the program, the value of `argc` will be zero and `argv` will be empty.

