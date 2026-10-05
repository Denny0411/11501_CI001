#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b && !(a == -1 && b == -1))
	{
		int up = b - a;
		int down = a + 100 - b;
		cout << min(up, down) << "\n";
	}

	return 0;
}