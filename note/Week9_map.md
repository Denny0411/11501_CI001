# STL - `<map>`

`map` 以「鍵值對」（key-value pair）的形式存儲元素。

`map` 中的元素具備以下特點：
* 透過鍵（Key）存取，而非索引，且每個鍵都是唯一的。
* 預設會依鍵的值自動進行升冪排序（Ascending order）。

若要使用 `map`，必須包含 `<map>` 標頭檔：

```cpp
// 引入 map 程式庫
#include <map>
```

## 建立 `map` (Create a `map`)

建立 `map` 時，使用 `map` 關鍵字，並在角括號 `<>` 內指定鍵 key 與值 value 的資料型態。最後指定該 `map` 的名稱，語法如下：

`map<keytype, valuetype> mapName;`

```cpp
// 建立名為 people 的 map，鍵為 string，值為 int
map<string, int> people;
```

若要在宣告時同時初始化元素，可以使用大括號 `{}` 包裹以逗號分隔的鍵值對列表：

```cpp
// 建立一個儲存不同人名與年齡的 map
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};
```

## 存取 `map` (Access a `map`)

`map` 不能像陣列（Array）或向量（Vector）那樣透過數字索引存取元素。

作為替代，可以在中括號 `[]` 內指定鍵 key 來存取對應的值 value：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 取得與鍵 "John" 相關聯的值
cout << "John is: " << people["John"] << "\n";
// John is: 32

// 取得與鍵 "Adele" 相關聯的值
cout << "Adele is: " << people["Adele"] << "\n";
// Adele is: 45
```

也可以使用 `.at()` 成員函式進行存取：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 取得與鍵 "Adele" 相關聯的值
cout << "Adele is: " << people.at("Adele") << "\n";
// Adele is: 45

// 取得與鍵 "Bo" 相關聯的值
cout << "Bo is: " << people.at("Bo") << "\n";
// Bo is: 29
```

> **注意：** 通常更推薦使用 `.at()` 函式而非中括號 `[]`，因為當指定的鍵不存在時，`.at()` 會拋出異常（Exception）報錯，而不會無意間插入預設值。

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29}
};

// 嘗試存取不存在的元素（將拋出異常）
cout << people.at("Jenny");
// Exit Code 1
```

## 修改值（Change Values）

可以透過鍵來修改其對應的值：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

cout << "Before changing, John is: " << people["John"] << "\n";
// Before changing, John is: 32

// 將 John 的值改為 50（原為 32）
people["John"] = 50;

cout << "After changing, John is: " << people["John"];
// After changing, John is: 50
```

使用 `.at()` 函式修改更加安全：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

cout << "Before changing, John is: " << people.at("John") << "\n";
// Before changing, John is: 32

// 將 John 的值改為 50（原為 32）
people["John"] = 50;

cout << "After changing, John is: " << people.at("John");
// After changing, John is: 50
```

## 新增元素（Add Elements）

新增元素至 `map` 可以直接使用中括號 `[]`：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 新增元素
people["Jenny"] = 22;
people["Liam"] = 24;
people["Kasper"] = 20;
people["Anja"] = 30;

cout << "Anja is: " << people.at("Anja");
// Anja is: 30
```

* key 存在時，容器會找到對應的節點，並回傳該節點中 value 的**參考**，覆寫（Overwrite）原本的值。
* key 不存在時，容器會立刻以該 key 為鍵，並呼叫 value 型別的預設建構子（Default Constructor）建立預設值（例如 `int` 會值初始化為 0，`std::string` 為空字串 ""），將這個新的 key-value pair 插入 map 中。插入後，同樣回傳這個新值的**參考**並覆寫。

也可以使用 `.insert()` 成員函式：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 新增元素
people.insert({"Jenny", 22});
people.insert({"Liam", 24});
people.insert({"Kasper", 20});
people.insert({"Anja", 30});

cout << "Anja is: " << people.at("Anja");
// Anja is: 30
```

## 重複鍵的處理（Elements with Equal Keys）

`map` 容器內不能存在重複的鍵（Keys）。

如果嘗試向 `map` 中插入兩次相同的鍵（例如 "Jenny"），它只會保留第一次插入的結果：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 嘗試新增兩個鍵相同的元素
people.insert({"Jenny", 22});
people.insert({"Jenny", 30}); // 此行將被忽略，Jenny 的值仍為 22
// 特別注意：是忽略，不是取代！

cout << "Jenny is: " << people.at("Jenny");
// Jenny is: 22
```

**結論：** 值（Values）可以重複，但鍵（Keys）必須唯一。

## 刪除元素（Remove Elements）

要從 `map` 中刪除特定元素，可以使用 `.erase()` 函式：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 依據鍵刪除元素
people.erase("John");

cout << "John is: " << people.at("John");
// John is: 
// Exit Code 1
```

若要清除 `map` 中的所有元素，可以使用 `.clear()` 函式：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

// 清空所有元素
people.clear();

cout << "John is: " << people.at("John");
// John is: 
// Exit Code 1
```

## 取得 Map 的大小（Find the Size of a Map）

使用 `.size()` 函式取得 `map` 目前含有的元素數量：

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

cout << people.size(); // 3
// people 有 3 個 key-value pair
```

## 檢查 Map 是否為空（Check if a Map is Empty）

使用 `.empty()` 函式檢查 `map` 是否為空容器。

若容器為空則回傳 `1`（`true`），否則回傳 `0`（`false`）：

```cpp
map<string, int> people;
cout << people.empty(); // 1
```

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};
cout << people.empty(); // 0
```

> **注意：** 若要檢查某個特定的鍵是否存在，可以使用 `.count(key)` 函式。若存在回傳 `1`，不存在則回傳 `0`：
```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};
cout << people.count("John"); // 1
// key 為 "John" 的 key-value pair 存在
```

## 走訪 Map（Loop Through a Map）

可以使用範圍 `for` 迴圈（for-each loop）走訪 `map`。走訪時需注意以下幾點：

1. 建議在 `for` 迴圈內使用 `auto` 關鍵字（C++11 引進），讓編譯器自動推導每個鍵值對的型態。
2. 因為 `map` 元素是由鍵與值組合而成的對（pair），在迴圈中需使用 `.first` 存取鍵，使用 `.second` 存取值。
3. 元素預設會依照鍵的字典序／大小以升冪自動排序。

```cpp
map<string, int> people = { 
    {"John", 32}, 
    {"Adele", 45}, 
    {"Bo", 29} 
};

for (auto person : people)
    cout << person.first << " is: " << person.second << "\n";
```

輸出結果：
```text
Adele is: 45
Bo is: 29
John is: 32
```

若希望改變排序方式為降冪排序（由大到小），可以在宣告時於角括號中加入 `greater<type>` 仿函式（Functor）：

```cpp
map<string, int, greater<string>> people = {
    {"John", 32},
    {"Adele", 45},
    {"Bo", 29}
};

for (auto person : people)
    cout << person.first << " is: " << person.second << "\n";
```

**輸出結果：**

```text
John is: 32
Bo is: 29
Adele is: 45
```

> **提示：** 也可以使用迭代器（Iterator）來走訪 `map`。