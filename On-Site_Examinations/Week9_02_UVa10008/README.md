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