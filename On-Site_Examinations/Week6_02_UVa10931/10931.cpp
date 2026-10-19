#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned long long I;
	while (cin >> I && I != 0)
	{
		int bit;
		vector<int> binary;
		while (I > 0)
		{
			bit = I % 2;
			binary.push_back(bit);
			I /= 2;
		}
		int digit1 = 0;
		cout << "The parity of ";
		for (int i = binary.size() - 1; i >= 0; i--)
		{
			cout << binary.at(i);
			if (binary.at(i) == 1)
				digit1++;
		}
		cout << " is " << digit1 << " (mod 2).\n";
	}
}