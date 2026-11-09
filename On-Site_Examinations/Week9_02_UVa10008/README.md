# Code Review Report: UVa 10008 - What’s Cryptanalysis?

## Fail Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct Count
{
	char alpha;
	int num = 0;
};

bool compare(Count a, Count b)
{
	return a.num > b.num;
}

int main()
{
	int n;
	string input;
	vector<Count> count(26);
	for (int i = 0; i < 26; i++)
		count.at(i).alpha = 'A' + i;

	cin >> n;
	n++;
	while (n--)
	{
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
		{
			if (isalpha(input.at(i)) != 0)
			{
				count.at(toupper(input.at(i)) - 'A').num++;
			}
		}
	}
	sort(count.begin(), count.end() ,compare);
	int maxendl = 0;
	for (int i = 0; i < 26; i++)
	{
		if (count.at(i).num > 0 && i > maxendl)
			maxendl = i;
	}
	for (int i = 0; i < 26; i++)
	{
		if (count.at(i).num > 0)
		{
			cout << count.at(i).alpha << " " << count.at(i).num;
			if (i < maxendl)
				cout << "\n";
		}
	}
}
```

範例測資正確，結果 WA。

### Why it failed

> 1. **排序沒有處理「出現次數相同時」的字母順序要求**
> * **問題所在**：題目在 Output 區塊有規定：「If two letters have the same frequency, then the letter which comes first in the alphabet must appear first in the output.」（如果兩個字母出現次數相同，字母表順序較前面的必須先輸出）。
> 
> * **原因分析**：你的 `compare` 函式只寫了 `return a.num > b.num;`，完全沒有定義當 `a.num == b.num` 時該如何比較 `alpha`。雖然你在初始化 `vector` 時已經按照 `A` 到 `Z` 排好，但 C++ 的 `std::sort` 是**不穩定排序（Unstable Sort）**。在範例測資中，次數相同的字母剛好沒有被 `sort` 打亂順序，但在正式測資較複雜的情況下，相同次數的字母順序就會亂掉（例如次數相同時 `H` 排在 `A` 前面）。
> 
> * **修改方向**：在 `compare` 函式中加入判斷，當兩者 `num` 相等時，比較兩者的 `alpha` 大小（較小的排前面）；或者改用能夠保留原本相對順序的穩定排序函式。
> 
> 2. **最後一行缺少換行符號**
> * **問題所在**：你特意用了 `maxendl` 變數來控制最後一筆輸出不要印出 `\n`。
> 
> * **原因分析**：在 UVa Online Judge 等競賽系統中，題目要求「Each line of output...」時，代表每一行輸出（包含最後一行）的結尾都必須有換行符號 `\n`。在某些嚴格比對的裁判系統上，最後一行沒換行會直接被判定為 Wrong Answer。
> 
> * **修改方向**：把計算與判斷 `maxendl` 的邏輯移除，每次輸出字母與次數時直接加上換行符號即可。
>
> written by gemini 4 argon

## Correct Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct Count
{
	char alpha;
	int num = 0;
};

bool compare(Count a, Count b)
{
	if (a.num != b.num)
		return a.num > b.num;
	else // a.num == b.num
		return a.alpha < b.alpha;
}

int main()
{
	int n;
	string input;
	vector<Count> count(26);
	for (int i = 0; i < 26; i++)
		count.at(i).alpha = 'A' + i;

	cin >> n;
	n++;
	while (n--)
	{
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
		{
			if (isalpha(input.at(i)) != 0)
			{
				count.at(toupper(input.at(i)) - 'A').num++;
			}
		}
	}
	sort(count.begin(), count.end() ,compare);
	for (int i = 0; i < 26; i++)
	{
		if (count.at(i).num > 0)
		{
			cout << count.at(i).alpha << " " << count.at(i).num << "\n";
		}
	}
}
```

### Why it works

* 新增 `a.num == b.num` 時的比較。

```cpp
// before
bool compare(Count a, Count b)
{
	return a.num > b.num;
}

// after
bool compare(Count a, Count b)
{
	if (a.num != b.num)
		return a.num > b.num;
	else // a.num == b.num
		return a.alpha < b.alpha;
}
```
* 移除換行相關的冗餘程式碼。

## `map` version

### Fail Code

```cpp
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    map<char, int> count;
    while (n--)
    {
        string input;
        getline(cin, input);
        for (int i = 0; i < input.size(); i++)
        {
            if (isalpha(input.at(i)))
            {
                count[toupper( input.at(i) )]++;
            }
        }
    }

    for (auto i : count)
        cout << i.first << " " << i.second << "\n";
}
```

1. 為什麼 `n` 明明輸入 3，while 迴圈卻只有跑 2 次？

> 其實 `while (n--)` 確實有執行 3 次，只是**第一次讀到的是空字串**。
> 
> * **原因**：當你使用 `cin >> n;` 讀取數字 `3` 時，`cin` 只讀走了數字本身，你按下 Enter 所產生的**換行符號（`\n`）還留在輸入緩衝區（Input Buffer）裡**。接著進入 `while` 迴圈第一次執行 `getline(cin, input);` 時，`getline` 一看到緩衝區裡殘留的 `\n` 就認為第一行結束了，導致第一次讀進來的 `input` 是空的（`""`），後面兩次才真正讀到第一行與第二行的文字，而第三行文字根本沒被讀到。
> 
> * **為什麼第一版程式沒這個問題？**：回顧你上一版的 `2_10008.cpp`，你在 `cin >> n;` 後面多寫了一行 `n++;`，用多跑一次迴圈的方式把那個殘留的換行符號「吃掉」了。
> 
> * **標準解法**：不需要改動 `n` 的值，只要在 `cin >> n;` 之後、`while` 迴圈之前，加上 `cin.ignore();`（或是 `getline(cin, input);` 先空讀一次），把緩衝區裡的換行符號清除即可。
> 
> written by gemini

2. 該怎麼讓 `count` 按照 value 的大小排列，並且 value 一樣時按照 key 的字典序排列？

C++ 的 `std::map` 底層是紅黑樹，它的特性是永遠只會根據 Key 來自動排序（預設由小到大），無法直接對 `map` 本身呼叫 `std::sort` 來改用 Value 排序。

若要對 map 的統計結果進行自訂排序，標準做法是將資料轉移到 `std::vector` 中再進行排序。