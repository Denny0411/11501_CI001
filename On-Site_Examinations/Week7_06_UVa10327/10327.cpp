#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		vector<int> inputValue(N);
		for (int i = 0; i < N; i++)
		{
			cin >> inputValue.at(i);
		}
		// bubble sort
		int swapCount = 0;
		for (int i = N - 2; i >= 0; i--) // 2 -> 0
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
		cout << "Minimum exchange operations : " << swapCount << "\n";
	}
}