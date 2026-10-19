#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

int main()
{
	LL N;
	while (cin >> N && N >= 0)	
	{
		if (N == 0)
		{
			cout << 0 << endl;
			continue;
		}
		int bit;
		vector<int> output;
		while (N > 0)
		{
			bit = N % 3;
			output.push_back(bit);
			N /= 3;
		}
		for (int i = output.size() - 1; i >= 0; i--)
			cout << output.at(i);
		cout << endl;
	}
}