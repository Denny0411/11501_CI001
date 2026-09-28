#include <iostream>

using namespace std;

int f(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	long long n;
	while (cin >> n && n != 0)
	{
		while (n >= 10)
		{
			n = f(n);
		}
		cout << n << "\n";
	}
}