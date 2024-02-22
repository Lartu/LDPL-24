# IN - SOLVE

The `IN - SOLVE` statement will solve a simple arithmetic expression and place the result in a NUMBER variable. Only `+`, `-`, `/`, `*` operators, NUMBER values, and TEXT values can be used in a MATH-EXPRESSION. Other LDPL arithmetic functions, like [CEIL](ceil.md) and [MODULO](modulo-by-in.md), are not supported by this statement and should be used as standalone statements. TEXT values will be implicitly converted to NUMBERs using the same algorithm as [STORE - IN](../control-flow-statements/store-in.md).

Spaces **must** be used to separate numbers, variables and operators.

As in actual arithmetic, `*` and `/` have higher precedence than `+` and `-` , while parens `()` can be used to group expressions. 

**Syntax**:

```coffeescript
IN <NUMBER-VAR> SOLVE <MATH-EXPRESSION>
```

**Example:**

```coffeescript
IN myNumVariable SOLVE 1 + 1
```

Will set the value of `myNumVariable` to `2`.

**Area of Circle:**

```coffeescript
DATA:
Radius is NUMBER
Area is NUMBER

PROCEDURE:
DISPLAY "Enter Radius: " 
ACCEPT Radius

IN Area SOLVE 3.14159 * (Radius * Radius)
DISPLAY "Area is: " Area CRLF
```

Outputs:

```text
Enter Radius: .5
Area is: 0.7853975
```

