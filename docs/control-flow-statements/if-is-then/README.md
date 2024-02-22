# IF - IS - THEN

The `IF` statement evaluates if the condition given by the relational operator between the first and second values is positive. If it is, the code in the positive branch is executed. If it is not, the code in the negative branch is executed \(if available\). Execution then continues normally.

#### Syntax:

```python
IF <NUMBER-VAR or NUMBER> IS <REL-OP-NUM> <NUMBER-VAR or NUMBER> THEN
 #Code goes here (positive branch)
ELSE
 #Code goes here (negative branch)
END IF 
```

or

```python
IF <TEXT-VAR or TEXT> IS <REL-OP-TEXT> <TEXT-VAR or TEXT> THEN
 #Code goes here (positive branch)
ELSE
 #Code goes here (negative branch)
END IF 
```

or

```python
IF <NUMBER-VAR or NUMBER> IS <REL-OP-NUM> <NUMBER-VAR or NUMBER> THEN
 #Code goes here (positive branch)
END IF 
```

or

```python
IF <TEXT-VAR or TEXT> IS <REL-OP-TEXT> <TEXT-VAR or TEXT> THEN
 #Code goes here (positive branch)
END IF 
```

**Possible values of `REL-OP-NUM` \(number relational operator\):**

* `EQUAL TO`
* `NOT EQUAL TO`
* `GREATER THAN`
* `LESS THAN`
* `GREATER THAN OR EQUAL TO`
* `LESS THAN OR EQUAL TO`

**Possible values of `REL-OP-TEXT` \(text relational operator\):**

* `EQUAL TO`
* `NOT EQUAL TO`

