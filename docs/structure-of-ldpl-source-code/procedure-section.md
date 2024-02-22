# PROCEDURE Section

As stated in [Structure of LDPL Source Code](./), LDPL programs are divided in two sections, one of them being the [DATA](data-section/) section, the other being the **PROCEDURE** section. The PROCEDURE section is where all the code of a LDPL program that is not a variable declaration is written. A LDPL program **must** contain a PROCEDURE section, even if it's empty. Compilation will fail otherwise.

Within the PROCEDURE section, every line can contain either a comment, a statement, a statement and a comment or be empty. No two statements can be written on the same line.

```coffeescript
PROCEDURE: 
  #A comment 
  STORE 5 IN myVariable 
  STORE 6 IN myOtherVariable #A statement and a comment
```

Available statements will be explained further in the following sections of this document.

Code within the PROCEDURE section is executed from top to bottom, skipping [SUB-PROCEDURE](sub-procedures.md) sections, unless explicitly called.

