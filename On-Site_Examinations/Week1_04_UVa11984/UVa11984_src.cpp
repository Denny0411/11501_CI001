#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int T;
	double C, d, result;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> C >> d;
		result = C + d * 5.0 / 9.0;
		cout << "Case " << i << ": " << fixed << setprecision(2) << result;
		// if (i != T)
			cout << endl;
	}

	return 0;
}