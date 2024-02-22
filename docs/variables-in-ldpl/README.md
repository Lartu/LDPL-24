# Variables in LDPL

LDPL is not a case sensitive language. Variables called `myVar` and `MYVAR` are considered to be the same variable, the same with sub-procedure names and statements of any kind. Variable names must follow the rules stated [here](../naming-rules.md).

### Usage of Variables

In the following sections you will see excerpts of code like this one:

```coffeescript
STORE <NUMBER-VAR or NUMBER> IN <NUMBER-VAR>
```

Notice the parts in between less-than and greater-than symbols \(`<like this>`\). Parts of procedures stylized like that mean that they should be replaced by whatever they say inside. In the example above, the first replaceable part can be substituted with the name of a variable of NUMBER type or by a NUMBER constant.

 Available replacement values are:

* `NUMBER`: A constant of type NUMBER.
* `TEXT`: A constant of type TEXT.
* `NUMBER-VAR`: A variable of type NUMBER.
* `TEXT-VAR`: A variable of type TEXT.
* `SUB-NAME`: A name of a sub-procedure.

