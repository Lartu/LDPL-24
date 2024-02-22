# DATA Section

As stated in [Structure of LDPL Source Code](../), LDPL programs are divided in two sections, one of them being the **DATA** section. The DATA section is where variables are declared. In no other part of a LDPL source can variables be declared. If no variables are declared, the DATA section can be skipped altogether.

All variables in LDPL are global \(LDPL has no concept of scope\) and have a defined [data type](data-types.md).

{% hint style="info" %}
 Available data types are NUMBER, TEXT, NUMBER VECTOR and TEXT VECTOR.
{% endhint %}

The DATA section is defined and preceded by the `DATA:` keyword. An empty data section looks like this:

```coffeescript
DATA:

```

On every line within the DATA section \(that is, on every line after the `DATA:` keyword and before the [`PROCEDURE:`](../procedure-section.md) keyword\) one and only one variable can be declared.

The syntax for declaring a variable in LDPL is:

```coffeescript
variable name IS data type
```

{% hint style="info" %}
**Variable names** should follow the rules stated [here](../../naming-rules.md).
{% endhint %}

A DATA section cannot contain anything but variable declarations, comments and empty lines. En example DATA section may end up looking like this:

```coffeescript
DATA: #This is the DATA section 
  myNumber IS NUMBER 
  #Next I'm going to declare a text vector 
  niceTextVector IS TEXT VECTOR 

PROCEDURE: 
  #This is a comment within the PROCEDURE section! 
```

