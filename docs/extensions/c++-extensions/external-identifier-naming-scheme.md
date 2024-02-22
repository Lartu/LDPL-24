# External Identifier Naming Scheme

All C++ variable and functions accessible to LDPL programs must contain only `A-Z`, `0-9`,  and the `_` character in their names. All other characters used on the LDPL side to reference the variable or function will get converted to an underscore \(`_`\) or, if it's a letter, capitalized.

**LDPL =&gt; C++ Conversion Examples**

| LDPL Identifier | C++ Identifier |
| :--- | :--- |
| window.rows | WINDOW\_ROWS |
| HTTP/get | HTTP\_GET |
| SDL/Font.new | SDL\_FONT\_NEW |
| sdl.font-new | SDL\_FONT\_NEW |
| NAME | NAME |
| version\_number | VERSION\_NUMBER |

{% hint style="warning" %}
Note that this conversion scheme can cause collisions: all of these LDPL variables will convert to `ONE_TWO:` 

* `One-Two` 
* `one.two` 
* `one/two` 
* `OnE-TWO`
{% endhint %}

