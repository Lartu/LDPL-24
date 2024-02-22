# LOAD FILE - IN

The `LOAD FILE` statement loads the contents of a file into a text variable.

#### Syntax:

```c
LOAD FILE <TEXT or TEXT-VAR> IN <TEXT-VAR>
```

#### Example:

```c
LOAD FILE "myFolder/myTextFile.txt" IN myVariable
```

#### Error codes:

If the LOAD operation should fail, the following values will be returned into the `ERRORCODE` and `ERRORTEXT` variables:

* `ERRORCODE`: 1
* `ERRORTEXT`: "Error: The file '&lt;filename&gt;' couldn't be opened."

