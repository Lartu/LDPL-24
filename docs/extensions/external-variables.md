# EXTERNAL Variables

Variables defined in extensions can be accessed by prefacing their data type declaration with the `EXTERNAL` keyword. This must occur in the [DATA section](../structure-of-ldpl-source-code/data-section/) of an LDPL program. Once an external variable is declared, it can be used just like any other LDPL variable. 

#### Syntax:

```text
<variable> IS EXTERNAL <data type>
```

**Example:**

```text
DATA:
RL-PROMPT IS EXTERNAL TEXT
WINDOW.SIZE IS EXTERNAL NUMBER
```



