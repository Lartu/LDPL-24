# Structure of LDPL Source Code

LDPL was designed to be a rigidly structured programming language and, as such, variable declarations and the rest of the code procedure are separated in two different, mutually exclusive **sections** within a source file. Variable declarations should be placed within the [DATA ](data-section/)section, while the rest of the code should be placed inside the [PROCEDURE ](procedure-section.md)section. Further subprocedures should be placed also within the PROCEDURE section, inside their own [SUB-PROCEDURE](sub-procedures.md) subsection.

Bearing this in mind, the basic skeleton of a LDPL source code will look like this:

```coffeescript
DATA: 

PROCEDURE: 

```

Every statement in LDPL has to be on its own line. Thus, statements are separated by line breaks and it's not possible to have two statements on the same line.

{% hint style="info" %}
The DATA section can be obviated if no variables are declared.
{% endhint %}

