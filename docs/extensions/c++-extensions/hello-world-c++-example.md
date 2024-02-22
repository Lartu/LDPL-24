# "Hello World" C++ Example

{% code-tabs %}
{% code-tabs-item title="simple.cpp" %}
```cpp
#include <iostream>
void SIMPLE(){
        std::cout << "Very simple!" << std::endl;
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

{% code-tabs %}
{% code-tabs-item title="simple.ldpl" %}
```text
PROCEDURE:
CALL EXTERNAL simple

```
{% endcode-tabs-item %}
{% endcode-tabs %}

```bash
$ ldpl -i=simple.cpp simple.ldpl
LDPL: Compiling...
* File(s) compiled successfully.
* Saved as simple-bin
$ ./simple-bin
Very simple!
```



