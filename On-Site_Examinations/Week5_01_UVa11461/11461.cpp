#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b && !(a == 0 && b == 0))
	{
		// a 到 b 之間有多少平方數
		int squareNumCount = 0;
		for (int i = static_cast<int>(sqrt(a)); i <= static_cast<int>(sqrt(b)); i++)
		{
			if (a <= i * i && i * i <= b)
				squareNumCount++;
		}
		cout << squareNumCount << "\n";
	}
}