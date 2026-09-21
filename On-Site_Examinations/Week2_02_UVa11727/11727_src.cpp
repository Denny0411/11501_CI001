#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		vector<int> sal(3, 0);
		cin >> sal.at(0) >> sal.at(1) >> sal.at(2);
		sort(sal.begin(), sal.end());
		cout << "Case " << i << ": " << sal.at(1) << endl;
	}
	return 0;
}