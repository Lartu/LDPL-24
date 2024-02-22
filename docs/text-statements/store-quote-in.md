# STORE QUOTE - IN

The `STORE QUOTE IN` statement allows you to store multiple lines in a single TEXT variable. Between the `STORE QUOTE IN` and `END QUOTE` statements whitespace is preserved literally, escape codes like `\t` and `\e` work the same as they do in regular text variables \(and can themselves be escaped using `\\`\), and double quotes \(`"`\) don't need to be escaped. 

**Syntax:**

```python
STORE QUOTE IN <TEXT-VAR>
  #Text goes here
END QUOTE
```

**Example:**

```coffeescript
DATA:
template IS TEXT

PROCEDURE:
STORE QUOTE IN template
<html>
    <head><title>{{title}}</title></head>
    <body>{{body}}</body>
</html>
END QUOTE

# ...code to use the template...
```

