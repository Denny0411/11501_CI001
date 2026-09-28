#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long a, b;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;

		vector<int> carry(11, 0);
		//vector<int> digitA(10, 0);
		//vector<int> digitB(10, 0);

		//while (a > 0)
		//{
		//	
		//}


		for (int i = 0; i < 11 && (a > 0 || b > 0); i++)
		{
			int carryDigit = 0;
			if ((a % 10 + b % 10 + carry.at(i)) >= 10)
				carryDigit = 1;
			a /= 10;
			b /= 10;
			carry.at(i + 1) += carryDigit;
		}

		int carrySum = 0;
		for (int i = 0; i < 11; i++)
			carrySum += carry.at(i);

		// cout << carrySum << "\n";
		if (carrySum == 0)
			cout << "No carry operation.\n";
		else if (carrySum == 1)
			cout << "1 carry operation.\n";
		else
			cout << carrySum << " carry operations.\n";
	}

	return 0;
}