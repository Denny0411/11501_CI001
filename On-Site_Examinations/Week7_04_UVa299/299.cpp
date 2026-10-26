#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int testCases;
	cin >> testCases;
	while (testCases--)
	{
		int inputSize;
		cin >> inputSize;
		vector<int> inputValue(inputSize);
		for (int i = 0; i < inputSize; i++)
		{
			cin >> inputValue.at(i);
		}
		// bubble sort
		int swapCount = 0;
		for (int i = inputSize - 2; i >= 0; i--) // 2 -> 0
		{
			for (int j = 0; j <= i; j++)
			{
				if (inputValue.at(j) > inputValue.at(j + 1))
				{
					swap(inputValue.at(j), inputValue.at(j + 1));
					swapCount++;
				}
			}
		}
		cout << "Optimal train swapping takes " << swapCount << " swaps.\n";
	}
}