# Data Types

LDPL natively supports the **NUMBER** and **TEXT** data types. It also supports **VECTORS** of values of such types.

The **NUMBER** data type, as its name suggests, depicts numeric values. It's recommended that it be represented internally as a **binary64** double-precision floating-point format number as defined by the **IEEE 754**.

Both variables and numeric constants can be members of the NUMBER type.

Valid number literals must begin with a decimal value \(for example `5` or `0.12`, `.12` wouldn't be a valid NUMBER\) and may be preceded by a minus sign for negative numbers \(`-5`, `-567.912`\). Numbers may not be preceded by a plus sign \(`+5` is not a valid number literal\). The literal `-0` is implicitly transformed into `0`.

The **TEXT** data type, as its name suggests, represents alphanumeric strings. In the interest of supporting as many locales as possible, LDPL should be **utf-8** encoded to be compatible with Unicode. A TEXT maximum length is explicitly not defined and it should be limited only by the amount of available memory on the system. Strings in LDPL are enclosed between two `"`quotes`"` and can contain [multiple escape sequences](https://ldpl.lartu.net/reference/#esc).

Both variables and string constants can be members of the TEXT type.

The **VECTOR** data type is not a type itself but a collection of NUMBER or TEXT variables. This implies that only variables can be members of the VECTOR type, as collections of constants \(and thus, constant VECTORs\) are not present in the language.

VECTORs superficially resemble arrays in other programming languages but with fundamental differences. In LDPL, there's no need to specify the size of a VECTOR before you start to use it. Additionally, any number or string in LDPL may be used as an array index, not just consecutive integers.

VECTORs, as collections of NUMBER or TEXT variables, can only have one defined type at any given time: TEXT or NUMBER. A single VECTOR is not capable of storing both numeric and alphanumeric values.

