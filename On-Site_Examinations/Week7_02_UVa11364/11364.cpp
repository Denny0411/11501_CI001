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
		sort(inputValue.begin(), inputValue.end());
		cout << (inputValue.at(inputValue.size() - 1) - inputValue.at(0)) * 2 << endl;
	}
}