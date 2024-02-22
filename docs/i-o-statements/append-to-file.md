# APPEND - TO FILE

The `APPEND x TO FILE y` statement appends the value of `x` to the file called `y`. If the file already exists, `x` will be added at the end of its contents.

#### Syntax:

```text
APPEND <NUMBER or NUMBER-VAR or TEXT or TEXT-VAR> TO FILE <TEXT or TEXT-VAR>
```

#### Example:

```c
APPEND "\nHow are you?" TO FILE "hello.txt"
```

in this case, the file `hello.txt`, [created here](write-to-file.md) and modified as stated on that page, will contain the text

```text
Hello there!
How are you?
```

