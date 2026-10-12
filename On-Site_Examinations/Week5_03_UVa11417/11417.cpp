#include <iostream>
#include <algorithm>

using namespace std;
// using ULL = unsigned long long;

int gcd(int a, int b)
{
	// a >= b
	if (a == 1 || b == 1)
		return 1;
	if (a < b)
		swap(a, b);
	if (a % b == 0)
		return b;

	int remainder = a % b;
	int quotient = a / b;
	a = remainder;
	while (remainder != 0 && b != 1)
	{
		swap(a, b);
		remainder = a % b;
		quotient = a / b;
		a = remainder;
	}
	//if (b == 1)
	//	return 1;
	return  b;
}

int main()
{
	int N;
	while (cin >> N && N != 0)
	{
		int G = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				/*cout << "i: " << i << "\n";
				cout << "j: " << j << "\n";
				int returnValue = gcd(i, j);
				cout << "returnValue:" << returnValue << "\n";*/
				G += gcd(i, j);
				//G += returnValue;
			}
		}
		cout << G << "\n";
	}
	return 0;
}