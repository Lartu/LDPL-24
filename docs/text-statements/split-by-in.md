# SPLIT - BY - IN

The `SPLIT` statement breaks up a single TEXT variable into multiple parts based on another TEXT variable and puts those parts into sub-indexes of a TEXT vector, starting at the NUMBER `0` and incrementing by whole numbers. This allows you to break up a text sentence into multiple parts by splitting on spaces, for example. Or to split a file into lines by splitting on `"\n"`.

To break TEXT into individual characters, split by the empty string of `""`.

#### Syntax:

```c
SPLIT TEXT-VAR or TEXT> BY TEXT-VAR or TEXT> IN <TEXT-VECTOR>
```

**Example:**

```coffeescript
SPLIT "Hello there!" BY " " IN parts
display parts:0 crlf parts:1 crlf
```

will output:

```text
Hello
there!
```

**Example:**

```coffeescript
SPLIT "onomatopoeia" BY "" IN parts
DISPLAY parts:3 " is M " crlf 
```

will output:

```text
m is M
```

