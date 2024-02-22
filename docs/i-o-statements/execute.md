# EXECUTE

The `EXECUTE` statement executes the specified system command.

#### Syntax:

```text
EXECUTE <TEXT or TEXT-VAR>
```

#### Example:

```python
# Prepare the command to execute
IN myTextVar JOIN "echo " myVariable " >> myFile"
# Execute it
EXECUTE myTextVar
```



