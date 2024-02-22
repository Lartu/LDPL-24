# JOIN - AND - IN

The `JOIN` statement concatenates two values and stores them in a TEXT variable. If any value is a number, it is converted to a string before concatenation.

#### Syntax:

```c
JOIN <NUMBER-VAR or NUMBER or TEXT-VAR or TEXT> AND <NUMBER-VAR or NUMBER or TEXT-VAR or TEXT> IN <TEXT-VAR>
```

**Type Conversion Note:**

If any of the values to be joined is a NUMBER value, the value will be converted to text, so `15` will be turned into `"15"` and `-19.2` into `"-19.2"`.

