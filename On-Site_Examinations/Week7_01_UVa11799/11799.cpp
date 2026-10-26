#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	// 如何讀到換行 '\n'？
	int testCases;
	cin >> testCases;
	for (int i = 1; i <= testCases; i++)
	{
		vector<int> inputValue;
		int temp;
		while (cin >> temp && cin.get() != '\n')
		{
			inputValue.push_back(temp);
		}
		inputValue.push_back(temp);
		sort(inputValue.begin(), inputValue.end());
		int output = inputValue.at(inputValue.size() - 1);
		cout << "Case " << i << ": " << output << "\n";
	}
}