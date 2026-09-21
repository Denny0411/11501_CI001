#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		/*unsigned long long int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == b && b == c && c == d)
			cout << "square" << endl;
		else if ()*/
		vector<unsigned long long int> length(4, 0);
		for (int i = 0; i < 4; i++)
			cin >> length.at(i);
		sort(length.begin(), length.end());
		if (
			length.at(0) == length.at(1) &&
			length.at(1) == length.at(2) &&
			length.at(2) == length.at(3)
			)
			cout << "square" << endl;
		else if (
			length.at(0) == length.at(1) &&
			length.at(2) == length.at(3)
			)
			cout << "rectangle" << endl;
		else if ((length.at(0) + length.at(1) + length.at(2)) >= length.at(3))
			cout << "quadrangle" << endl;
		else
			cout << "banana" << endl;
	}
	return 0;
}