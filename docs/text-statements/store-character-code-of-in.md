# STORE CHARACTER CODE OF - IN

The `STORE CHARACTER CODE OF` statement stores the ASCII code of the character passed in TEXT or TEXT-VAR in NUMBER-VAR. Will fail if the length of the string passed in TEXT or TEXT-VAR is not 1.

#### Syntax:

```c
STORE CHARACTER CODE OF <TEXT or TEXT-VAR> IN <NUMBER-VAR>
```

#### Error codes:

Multi-byte characters \(like emojis and non-ASCII characters\) cannot be parsed by this statement. When trying to do so, the operation will fail and the following values will be returned into the `ERRORCODE` and `ERRORTEXT` variables:

* `ERRORCODE`: 1
* `ERRORTEXT`: "Multibyte character received \(probably UTF-8\). Can't be parsed into a single number."

