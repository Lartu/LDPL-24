# About LDPL

## What is LDPL?

**LDPL** _\(Lartu's Definitive Programming Language\)_ is a programming language designed from the ground up to be excessively expressive, fast, readable and easy to learn. It mimics English in the likeness of \[the good parts of\] older languages like COBOL, with the desire that it can be understood by anybody. It's highly portable and runs on a plethora of different architectures and operating systems including AMD-64, ARMv8 and PowerPC Linux and Mac OS X. It also supports UTF-8 out of the box.

```coffeescript
data: 
  name is text     # Your name goes here! 

procedure: 
  display "Hello World" crlf "What's your name? " 
  accept name 
  display "你好, " name "! Welcome to LDPL!" crlf
```

LDPL also aims to suppress unreadable code and redundancy by only having one way of doing everything. What a command does should never overlap with the purpose of another and, as such, every LDPL command does one and only one thing. Every line is a step further towards the completion of an algorithm, no more, no less.

