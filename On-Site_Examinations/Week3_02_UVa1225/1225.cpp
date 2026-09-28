#include <iostream>
#include <vector>

using namespace std;

//void f(int i, &vector<int> cnt)
//{
//
//}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		
		// counting from 1 to n
		vector<int> cnt(10, 0);
		for (int i = 1; i <= n; i++)
		{
			int current = i;
			while (current > 0)
			{
				int digit = current % 10;
				current /= 10;
				cnt[digit]++;
			}
		}

		// output
		for (int i = 0; i < 9; i++)
		{
			cout << cnt.at(i) << " ";
		}
		cout << cnt.at(9) << "\n";
	}
}