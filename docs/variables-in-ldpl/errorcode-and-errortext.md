# ERRORCODE and ERRORTEXT

Some LDPL operations may fail when executed. Maybe you tried LOADing a file that wasn't there or getting the ASCII value of a multi-byte emoji. These operations make use of the `ERRORCODE` and `ERRORTEXT` variables to tell you if they ran successfully or not.

The `ERRORCODE` and `ERRORTEXT` variables come declared by default. Some statements may modify their values to express their results.

The `ERRORCODE` variable is a NUMBER variable. It will hold the value 0 if the statement ran successfully and any other number if it did not.

The `ERRORTEXT` variable is a TEXT variable that will be empty if the statement ran successfully. If it did not, it will store a human readable description of what went wrong.

`ERRORCODE` and `ERRORTEXT` can be read and written like any other LDPL variable.

{% hint style="warning" %}
When handling ERROR checks, please bear in mind that the content of the `ERRORTEXT` variable may change in future releases of LDPL. The value stored in `ERRORCODE`, however, will not change and so that's the value that should be used to check whether an operation ran successfully or not.
{% endhint %}

