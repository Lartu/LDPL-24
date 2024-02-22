# INCR & DECR

The `INCR` and `DECR`statements add or subtract from a NUMBER variable by one. The variable is updated with the new value in place.

#### Syntax:

```python
INCR <NUMBER-VAR>
```

```python
DECR <NUMBER-VAR>
```

**Example:**

```coffeescript
DATA:
x is number

PROCEDURE:
STORE 0 IN x
WHILE x IS LESS THAN 5 DO
  DISPLAY "x: " x crlf
  INCR x
REPEAT
```

**Output:**

```text
x: 0
x: 1
x: 2
x: 3
x: 4
```

