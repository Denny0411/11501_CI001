# Code Review Report: UVa 458

## Fail Code

```cpp
#include <iostream>

using namespace std;

int main()
{
	char c;
	int ascii;

	while (cin.get(c))
	{
		if (c == '\n')
			cout << c;
		else if (c < 7)
		{
			ascii = static_cast<int>(c) + 128 - 7;
			cout << static_cast<char>(ascii);
		}
		else
		{
			ascii = static_cast<int>(c) - 7;
			cout << static_cast<char>(ascii);
		}
	}
}
```

範例測資正確，結果 WA。

### Why it failed

> 你的程式在範例測資通過但正式評測拿到 Wrong Answer，主要有以下兩個原因：
> 
> **1. 未處理 Windows 格式的換行字元（`\r`）**
> 
> * 你的程式使用逐字元讀取（`cin.get`），並且只針對 `\n`（ASCII 10）做原樣輸出，其餘字元一律減 7。
> * 許多線上評測系統（如 UVa）的隱藏測資檔案是在 Windows 環境下建立的，換行是由 `\r\n`（ASCII 13 與 ASCII 10）兩個字元組成。
> * 當程式讀到 `\r`（ASCII 13）時，因為不符合 `\n` 的條件，會進入最後的分支被減去 7，變成 ASCII 6 的控制字元並輸出到結果中，導致格式錯誤而判定為 Wrong Answer。你自己手動貼上範例測資測試時，環境通常只會產生單純的 `\n`，因此測不出來。
> 
> **2. 多餘的 `< 7` 判斷與有號字元（signed char）溢位風險**
> 
> * 題目說明編碼是針對 ASCII 的「可見字元部分（printable portion）」進行單一算術運算，可見字元的 ASCII 範圍為 32（空白）到 126（`~`），因此原本的設計並不需要處理小於 7 的循環回繞。
> * 在多數 C++ 編譯環境中，預設的 `char` 是有號整數（範圍為 -128 到 127）。如果隱藏測資中包含需要解碼為 `y`（121）或 `z`（122）的字元，它們編碼後的數值會是 128 或 129。這類數值存進 `char` 時會溢位變成負數，進而誤觸你寫的「小於 7」條件，加上 128 再減 7 後會得到完全錯誤的負數結果。
> 
> **修正方向**
> 
> * 在處理換行時，除了保留 `\n` 之外，也必須將 `\r` 原樣輸出（或直接忽略不輸出）。
> * 移除小於 7 的分支判斷，讓所有非換行的字元直接減去 7 即可（若要防範超過 127 的字元溢位，可先將讀入的字元轉型為無號字元再進行減法運算）。
>
> written by gemini

## Correct Code

```cpp
#include <iostream>

using namespace std;

int main()
{
	char c;
	unsigned char uc;
	int ascii;

	while (cin.get(c))
	{
		if (c == '\n' || c == '\r')
			cout << c;
		else
		{
			// printable portion: 32 ~ 126
			uc = static_cast<unsigned char>(c);
			ascii = static_cast<int>(uc) - 7;
			cout << static_cast<char>(ascii);
		}
	}
}
```

z: 122
Before decoding, z is 122 + 7 = 129.
A char can only store -128 to 127.
This will cause an overflow when storing 129 into a char.
For this problem, we need to use unsigned char: 0 to 255.

為什麼 `while (cin.get(c))` 的時候不會 overflow？

> `cin.get(c)` 在讀取 `129` 時，數值上其實已經發生環繞（`c` 裡存的確實是溢位後的 `-127`），但這不會造成資料遺失或程式錯誤，因為這整個過程只是單純的 **8-bit 位元複製**，而非會觸發未定義行為（Undefined Behavior）的算術溢位。
> 
> 具體的底層運作分為三個階段：
> 
> * **`cin.get(c)` 執行的是無損的位元搬移**
> `cin.get(c)` 從輸入串流讀取一個位元組時，底層（`rdbuf()->sbumpc()`）會先將該位元組當作 `unsigned char`（範圍 `0` 到 `255`）讀出，再透過 `static_cast<char>` 寫入變數 `c`。當輸入為 `129`（二進位 `10000001`）時，這 8 個位元會原封不動被複製進 `c` 的 1 byte 記憶體中，沒有任何位元被截斷。
> 
> * **數值變成 `-127` 是因為「解讀方式」改變，而非資料損壞**
> 在 C++ 中，將超出範圍的整數轉型給有號整數（例如把 `129` 塞進 `-128` 到 `127` 的 `char`），並不像「有號整數加減乘除溢位」那樣屬於未定義行為，而是合法的型別轉換（自 C++20 起標準已明確規範採二補數模運算）。由於 `c` 是有號型別，程式在讀取 `10000001` 時，會依照二補數規則將它解讀為 `-127`。
> 
> * **`static_cast<unsigned char>(c)` 只是切換回無號解讀**
> 因為記憶體裡的 8 個位元始終維持 `10000001`，當程式執行 `uc = static_cast<unsigned char>(c)` 時，CPU 並不會更動這些位元，只是把解讀規則從「有號二補數（`-127`）」切回「無號二進位（`129`）」。因此原本的 `129` 得以完整還原，後續減 `7` 就能正確算出 `122`（`'z'`）。
> 
> 如果想讓語意從頭到尾都保持一致、連中間變成 `-127` 的過程都省去，實務上也可以直接宣告 `char` 陣列或改用 `cin.get()` 的無參數版本（回傳型別為 `int`，直接回傳 `0` 到 `255` 或 `EOF`），就完全不需要在有號與無號 `char` 之間來回轉型。
>
> written by gemini