# Usage of VECTORs

Vectors in LDPL aren't more than a collection of variables. When you declare a vector, you declare a structure that lets you store something of its type on any sub-index of the variable. For example, say you declare the vector `myVector`:

```coffeescript
DATA:
  myVector IS NUMBER VECTOR 
```

Then you can use `myVector` as a multivariable with various indexes where you can store NUMBERs.

```coffeescript
DATA:
  myVector IS NUMBER VECTOR
PROCEDURE:
  STORE 5 IN myVector:1 #Stores 5 in the subindex 1 of myVector
  STORE -10.2 IN myVector:5 #Stores -10.2 in the subindex 5 of myVector
```

Vector sub-indexes can't just be constant NUMBERs, though. They can also be NUMBER variables, TEXT and TEXT variables, or even sub-indexes of other arrays. For example:

```coffeescript
DATA:
  myVector IS NUMBER VECTOR
  myOtherVector IS NUMBER VECTOR
  myVar IS NUMBER

PROCEDURE:
  STORE 17 IN myVar
  STORE 1 IN myVector:"hello" #Stores 1 in the subindex "hello" of myVector
  STORE 7 IN myVector:myVar #Stores 7 in the position of index value of myVar
  STORE 3 IN myVector:myOtherVector:4
  #Stores 3 in the position of index value of myVar of myOtherVector
```

Please note that as a VECTOR is a collection of variables, a single index of a VECTOR is a variable in itself. This means that a VECTOR with a sub-index can be used in any position where you could use a variable of the same type of the vector. So, if you have something like this:

```coffeescript
STORE <NUMBER-VAR or NUMBER> IN <NUMBER-VAR>
```

You could use a NUMBER VECTOR with a defined sub-index where it says NUMBER-VAR.

