# SUB-PROCEDUREs

A SUB-PROCEDURE is a piece of code that can be called and executed from other parts of the script. SUB-PROCEDURE subsections must be declared within the [PROCEDURE](procedure-section.md) section of the code using a `SUB-PROCEDURE <name>` statement and end with an `END SUB-PROCEDURE` statement. Bear in mind that you can't define a SUB-PROCEDURE within a SUB-PROCEDURE. Also bear in mind that a SUB-PROCEDURE has to be declared **before** it can be [CALL](../control-flow-statements/call-sub-procedure.md)ed.

The syntax for declaring sub-procedures is this one:

```coffeescript
DATA:
  # ...
PROCEDURE:
  # ...
  SUB-PROCEDURE mySubprocedure
    # Sub procedure code
    # goes here.
  END SUB-PROCEDURE
```

Of course, you cannot have two sub-procedures with the same name. Sub-procedure names follow the same naming guidelines variable names [follow](../naming-rules.md).

