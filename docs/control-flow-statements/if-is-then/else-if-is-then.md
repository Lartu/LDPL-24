# ELSE IF - IS - THEN

The `ELSE IF` statement is equivalent to writing an `IF` statement inside the `ELSE` statement of another `IF` statement, but shorter. Must be used after an IF statement and before `END IF` or `ELSE`.

#### Syntax:

All the different `IF` variants of the [IF statement](./) apply, just with `ELSE` added before them.

#### Example:

```python
DATA:
  name IS TEXT
PROCEDURE:
  STORE "Mike" IN name
  IF name IS equal to "John" THEN
    DISPLAY "Hello there, John!" CRLF
  ELSE IF name IS equal to "Mike" THEN
    DISPLAY "Hello there, Mike!" CRLF
  ELSE IF name IS equal to "Robert" THEN
    DISPLAY "Hello there, Robert!" CRLF
  ELSE
    DISPLAY "I don't know you, " name CRLF
  END IF
```

