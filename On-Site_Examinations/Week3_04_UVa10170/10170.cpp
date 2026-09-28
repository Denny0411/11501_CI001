#include <iostream>

using namespace std;

int main()
{
	int s; // the initial size of the group
	long long d; // you will have to find the group size staying in the hotel on D - th day(starting from 1)

	while (cin >> s >> d)
	{
		long long day = 0;
		while (d > day)
		{
			day += s;
			s += 1;
		}
		cout << s - 1 << "\n";
	}
}