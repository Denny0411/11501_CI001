#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;

long long myPow(long long base, int x)
{
	if (x == 0)
		return 1;
	else if (x == 1)
		return base;
	for (int i = 1; i < x; i++)
		base *= base;
	return base;
}

int main()
{
	// 1. is input hex?
	// yes, do hex to dec
	// no, convert to dec
	// 
	// 2. is input negative?
	// yes, terminate
	// no, do dec to hex

	string input;
	bool isHex = false;
	bool isTerminate = false;

	while (isTerminate == false && cin >> input)
	{
		// 1. is input hex?
		if (input.substr(0, 2) == "0x")
		{
			isHex = true;

			// hex to dec
			input.erase(0, 2);
			reverse(input.begin(), input.end());
			LL hexToDec = 0;
			for (int i = 0; i < input.size(); i++)
			{
				if ('0' <= input.at(i) && input.at(i) < 'A') // 0 ~ 9
				{
					hexToDec += (input.at(i) - '0') * pow(16, i);
				}
				else // A ~ F
				{
					hexToDec += (input.at(i) - 'A' + 10) * pow(16, i);
				}
			}
			cout << hexToDec << "\n";
		}
		else // input is dec
		{
			// 2. is input negative ?
			LL inputInt = stoi(input);
			if (inputInt < 0)
			{
				isTerminate = true;
				continue;
			}
			else if (inputInt == 0)
				cout << "0x" << 0 << "\n";
			else // dec to hex
			{
				string decToHex;
				int bit;
				while (inputInt > 0)
				{
					bit = inputInt % 16;
					if (bit >= 10)
					{
						decToHex.push_back(bit - 10 + 'A');
					}
					else // bit < 10
					{
						decToHex.push_back(bit + '0');
					}
					inputInt /= 16;
				}
				reverse(decToHex.begin(), decToHex.end());
				cout << "0x" << decToHex << "\n";
			}
		}
	}
}