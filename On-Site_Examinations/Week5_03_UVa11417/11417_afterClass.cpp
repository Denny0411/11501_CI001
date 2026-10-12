#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);

    return gcd(a, b - a);
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
				G += gcd(i, j);
			}
		}
		cout << G << "\n";
	}
	return 0;
}