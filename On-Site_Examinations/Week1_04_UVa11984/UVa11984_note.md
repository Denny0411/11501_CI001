# UVa 11984

## 如何控制 cout double 的精度？

* `#include <iomanip>`
* `cout << fixed << setprecision(n)`，n: 要使用的精度
* `setprecision()` 前面要有 `fixed`！