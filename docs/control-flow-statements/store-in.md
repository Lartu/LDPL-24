# STORE - IN

The `STORE` statement assigns a value to a variable.

#### Syntax:

```python
STORE <NUMBER-VAR or NUMBER or TEXT-VAR or TEXT> IN <NUMBER-VAR or TEXT-VAR>
```

**Type Conversion Notes:**

If the value to be stored is NUMBER and it's to be stored in a TEXT variable, the value will be converted to text, so `15` will be turned into `"15"`. If the value to be stored is a TEXT value two things can happen. If it contains any non-numeric characters \(for example letters, or more than one minus sign or more than one decimal point, for example `"--1.2"` or `"15a"`\) the conversion will fail and 0 will be stored in the NUMBER variable. If the TEXT contains a proper number, though, for example `"-416.419"` or `"89"` it will be converted to its number equivalent and stored in the variable. If a string literal depicting a number is preceded by leading zeros, these will be trimmed \(turning `0005` into `5`, `-0002.3` into `-2.3` and `00.23` into `0.23`\).

