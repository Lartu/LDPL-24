# EXTERNAL SUB-PROCEDUREs

Sometimes when writting C++ Extensions you'll find yourself in the need of declaring a function in C++ but coding it in LDPL. This is the opposite of writing C++ functions and calling them from LDPL, it's writing LDPL SUB-PROCEDUREs and calling them from C++.

These C++ calleable SUB-PROCEDUREs are called EXTERNAL SUB-PROCEDUREs, as they can be called from an EXTERNAL medium.

In order to declare an EXTERNAL SUB-PROCEDURE you must first declare it in your C++ source code. Say, for example, that you want to declare a SUB-PROCEDURE called `helloWorld`. In your C++ you should write the following line:

```text
void HELLOWORLD();
```

Note that EXTERNAL SUB-PROCEDUREs cannot receive any kind of parameters and must be declared as `void`. You may then call the EXTERNAL SUB-PROCEDURE from C++ code like:

```text
int myCPPFunction(){
  HELLOWORLD();
  return 1;
}
```

Once that's taken care of, you can declare your EXTERNAL SUB-PROCEDURE as any other SUB-PROCEDURE in LDPL by preppending the identifier EXTERNAL to the SUB-PROCEDURE declaration:

```text
EXTERNAL SUB-PROCEDURE helloWorld
  #Code here...
END SUB-PROCEDURE
```

These SUB-PROCEDUREs can be called from LDPL as any other SUB-PROCEDURE, but their names must follow the [External Identifier Naming Scheme](c++-extensions/external-identifier-naming-scheme.md) as any other C++ interfacing component.

