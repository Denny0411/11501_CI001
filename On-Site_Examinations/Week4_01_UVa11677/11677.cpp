#include <iostream>

using namespace std;

int main()
{
	int h1, m1, h2, m2;
	while (cin >> h1 >> m1 >> h2 >> m2 && !(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0))
	{
		int num1 = h1 * 60 + m1;
		int num2 = h2 * 60 + m2;

		if (num2 >= num1)
		{
			cout << num2 - num1 << "\n";
		}
		else
		{
			num2 += 24 * 60;
			cout << num2 - num1 << "\n";
		}
	}

	return 0;
}