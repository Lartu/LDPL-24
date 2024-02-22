# Writing C++ Extensions

Extensions can create variables and functions that are accessible from LDPL through the [CALL EXTERNAL](../call-external.md) statement and [EXTERNAL](../external-variables.md) data type keyword. Typically all you need is a single `.cpp` file that you give the `ldpl` compiler when building your program, but you can also use `.o` files, `.a` files, or any combination of them all.

Extensions interact with LDPL in two main way: defining functions and declaring variables.

## Functions

To create a function in C++ that can be called from an LDPL program, you must follow two rules:

1. The function's type must be `void(void)`, ex: `void MY_FUNC();`
2. The function's name must conform to LDPL's [Extension Naming Convention](external-identifier-naming-scheme.md).

Because LDPL functions don't accept arguments or return values, to be callable from LDPL your C++ functions musn't either.

And because LDPL doesn't "know" the names of your functions and instead allows the programmer to call them using the `EXTERNAL` syntax, all C++ variable and subprocedure names must contain only `A-Z`, `0-9`, and the `_` character. Everything else on the LDPL side will get converted to an underscore \(`_`\) when referencing the C++ side.

### Example

For example, this function:

```cpp
void PROMPT_ADD() 
{
  int a, b, sum;
  cout << "1st number: ";
  cin >> a;
  cout << "2nd number: ";
  cin >> b;
  cout << "sum: " << sum << end; 
}
```

Once defined and built into LDPL, can be called using:

```text
CALL EXTERNAL prompt-add
```

## Variables

To create or reference a variable in a C++ extension that is shared with an LDPL program, you must follow two rules:

1. The variable's name must conform to LDPL's [Extension Naming Convention](external-identifier-naming-scheme.md).
2. The C++ type of the variable must match LDPL's internal type usage.

The first rule should be familiar from the functions section: all C++ variable and subprocedure names must contain only `A-Z`, `0-9`, and the `_` character. Everything else on the LDPL side will get converted to an underscore \(`_`\).

For the second, here's the mapping between types:

| LDPL Data Type | C++ Type |
| :--- | :--- |
| `TEXT` | `std::string` |
| `NUMBER` | `double` |
| `TEXT VECTOR` | `ldpl_vector<std::string>` |
| `NUMBER VECTOR` | `ldpl_vector<double>` |

### Example

Declaring `TEXT`and `NUMBER` variables is easy on the C++ side:

```cpp
std::string NAME;
double AGE;
std::string STREET_ADDRESS;
```

These will be available to an LDPL program to declare in its `DATA:` section:

```text
DATA:
name IS EXTERNAL TEXT
age IS EXTERNAL NUMBER
street-address IS EXTERNAL TEXT
```

## Accessing Variables in Functions

Since LDPL and C++ are using the same variable when you use the `EXTERNAL` keyword, any changes you make to the variable's content are shared. Just use them like you would use regular C++ variables.

```cpp
double A, B, SUM;
void ADD() 
{
    SUM = A + B;
}
```

```text
DATA:
A IS EXTERNAL NUMBER
B IS EXTERNAL NUMBER
SUM IS EXTERNAL NUMBER

PROCEDURE:
STORE 100 IN A
STORE 250 IN B
CALL EXTERNAL add
DISPLAY SUM CRLF
```

Building and running this program will print `350`.

## LDPL Vectors

The `VECTOR` types are a bit trickier - they are defined as `ldpl_vector<T>`, so you'll want to declare this prototype in your `.cpp` or `.h` file to use it in your extension:

```cpp
#ifndef ldpl_vector
template<typename T>
struct ldpl_vector {
    T& operator [] (const std::string& i);
    T& operator [] (double i);
};
#endif
```

Now you can use vectors in LDPL:

```text
DATA:
Names IS EXTERNAL TEXT VECTOR
```

And in C++:

```cpp
ldpl_vector<std::string> NAMES;

// later...
NAMES[0] = "Pauline"
NAMES[1] = "just Paul"
```

