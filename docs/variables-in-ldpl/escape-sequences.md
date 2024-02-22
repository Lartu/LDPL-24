# Escape Sequences

LDPL strings can contain multiple escape sequences / control characters in them. Each escape sequence counts as only one character. The available escape sequences are:

* `\a` = alert \(bell\)
* `\b` = backspace
* `\t` = horizontal tab
* `\n` = newline / line feed
* `\v` = vertical tab
* `\f` = form feed
* `\r` = carriage return
* `\e` = non-standard GCC escape
* `\0` = null byte
* `\\` = \ character
* `\"` = " character

For example, the string `"hello,\nworld"` will be displayed as

```text
hello,
world
```

when printed to the console.

