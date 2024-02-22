# GOTO & LABEL

> "If you want to go somewhere, goto is the best way to get there."  
> -- Ken Thompson

The `GOTO` statement performs a **one-way transfer** of control to a line of code marked by a `LABEL` statement. In lame man terms, the execution jumps to the line where the wanted `LABEL` is found and continues from there.

While maligned by [Edsger W. Dijkstra](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra) and his cohorts, `GOTO` is very useful in many situations. Its reputation is undeserved and mostly perpetuated by people that don't understand the origins of the criticism or how the statement can be used.

You also can't make a COBOL_esque_ language without `GOTO`, so \(due to popular request\) here we've added it to the language.

#### Syntax:

```text
LABEL <labelName>
```

```text
GOTO <labelName>
```

{% hint style="info" %}
Label names follow the naming rules stated [here](../naming-rules.md#label-naming-conventions).
{% endhint %}

#### Example:

```text
PROCEDURE:
GOTO start

LABEL start
display "> starting..." crlf

GOTO ending

LABEL middle
display "> entering the middle section..." crlf

sub-procedure cool-code
    GOTO cool
    display "hmm... is this cool?" crlf
    LABEL cool
    display "wow, yeah! cool code!" crlf
end sub-procedure

LABEL ending
CALL cool-code
display "> that's the end" crlf
```

In the output of this program you can see the `middle` LABEL and the start of the `cool-code` SUB-PROCEDURE are skipped:

```text
> starting...
wow, yeah! cool code!
> that's the end
```

In order to keep `GOTO` from turning your source into "_unmaintainable spaghetti code_", both your `GOTO` statement and the `LABEL` it jumps to have to be used together in the same sub-procedure or in the main code body of an LDPL program. So you can't `goto` across sub-procedures or into them, or anything like that.

