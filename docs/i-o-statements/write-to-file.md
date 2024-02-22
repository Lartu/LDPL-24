# WRITE - TO FILE

The `WRITE x TO FILE y` statement writes the value of `x` to the file called `y`. If the file already exists, everything in it will be overwritten by `x`.

#### Syntax:

```c
WRITE <NUMBER or NUMBER-VAR or TEXT or TEXT-VAR> TO FILE <TEXT or TEXT-VAR>
```

#### Example:

```python
WRITE "Hello there!" TO FILE "hello.txt"
```

