# 使用 `stringstream` 處理輸入

input
```
2 // case num
5 9 3 5 2 6 // case 1
1 2 // case 2
```
Q: 假設我不知道每個 case 要讀多少個 input value，我該怎麼處理？
A: 使用 `stringstream`。

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    // 忽略第一行 T 殘留的換行符
    cin.ignore(); // 只會跳過一個字元
    
    string line;
    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        getline(cin, line); // 一次讀取整行輸入
        stringstream ss(line); // 將輸入轉換成 stringstream

        int temp;
        vector<int> inputValue;
        while (ss >> temp) // 從 stringstream 讀取，一次讀取一個數字
            inputValue.push_back(temp); // 將讀取到的數字儲存到 vector

        /* 後續處理 */
    }

    return 0;
}
```

## Problem

UVa 11799