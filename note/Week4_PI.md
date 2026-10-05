# 在 C++ 建立 $\pi$ 常數的方法

1. **C++20 `<numbers>` 標頭檔**

自 C++20 起，標準庫提供了精確且為編譯期常數的數學常數：
```cpp
#include <numbers>

constexpr double pi = std::numbers::pi;
```


2. **POSIX 巨集 `M_PI`（`<cmath>`）**

多數編譯器支援 POSIX 標準定義的 `M_PI`。在 MSVC 環境下使用時，需在引入 `<cmath>` 前定義 `_USE_MATH_DEFINES`：
```cpp
#define _USE_MATH_DEFINES
#include <cmath>

const double pi = M_PI;
```


3. **使用反餘弦函式計算**

```cpp
const double pi = acos(-1);
```