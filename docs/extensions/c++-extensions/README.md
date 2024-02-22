# C++ Extensions

Extensions contain [SUBPROCEDUREs](../../structure-of-ldpl-source-code/sub-procedures.md) and [VARIABLEs](../../variables-in-ldpl/) that are written in another language and usable in LDPL through the [CALL EXTERNAL](../call-external.md) statement and [EXTERNAL](../external-variables.md) data type keyword. This allows programmers to extend LDPL with new features or to wrap 3rd party libraries and re-use their functionality. 

Starting with release **3.0.0**, LDPL supports extensions written in C++. Because LDPL programs compile down to C++, there is no need for a translation layer or bridge: extensions can be included directly into LDPL programs and manipulate, share, and access subprocedures and variables natively. All that's needed is a few naming conventions on the C++ side and the use of the `EXTERNAL` syntax for variables and subprocedures on the LDPL side.

{% hint style="info" %}
Check out the ["Hello World"](hello-world-c++-example.md) for a quick example.
{% endhint %}



