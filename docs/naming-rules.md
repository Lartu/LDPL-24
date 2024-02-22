# Identifier Naming Schemes

## Variable and SUB-PROCEDURE naming scheme

Variables and SUB-PROCEDURE names follow the same naming rules. These names can't be empty and may consist of any character with few exceptions \(listed below\). Like statements, variable and SUB-PROCEDURE names in LDPL are not case sensitive.

* Variable and SUB-PROCEDURE names cannot contain the character `:`, it is used for vector accesses.
* Variable and SUB-PROCEDURE names cannot contain the character `"`, it is used to delimit strings.
* Variable and SUB-PROCEDURE names cannot contain spaces.
* Variable and SUB-PROCEDURE names cannot be valid numbers.
* Variable and SUB-PROCEDURE names cannot contain the character `(` nor the character `)` as these characters are used in mathematical expressions.
* Variables and SUB-PROCEDUREs cannot be called `CRLF`, as it is internally turned into `"\r\n"`.
* Variables and SUB-PROCEDUREs cannot be called `+` nor `-` nor `*` nor `/` as these characters are used in mathematical expressions.

## LABEL naming scheme

Labels in LDPL can't be empty and may contain any character except spaces and `"`. LABELs can't be named `CRLF` for the same reasons explained in the section above.

## External Identifier Naming Scheme

Please refer to [this page](extensions/c++-extensions/external-identifier-naming-scheme.md).

