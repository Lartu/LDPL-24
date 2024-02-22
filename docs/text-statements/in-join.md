# IN - JOIN

The `IN JOIN` statement concatenates two or more values and stores them in a TEXT variable. If any of those values is a number, it is converted to a string before concatenation.

#### Syntax:

```c
IN <TEXT-VAR> JOIN <multiple NUMBER, TEXT, TEXT-VAR, NUMBER-VAR or CRLF>
```

#### Example:

```c
IN myTextVariable JOIN "Hello World!" " " "Welcome to LDPL!" crlf
```

will store

```c
"Hello World! Welcome to LDPL!\n"
```

in `myTextVariable`.

