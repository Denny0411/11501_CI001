#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	string a, b;
	while (getline(cin, a) && getline(cin, b))
	{
		vector<int> aCount(26, 0);
		vector<int> bCount(26, 0);
		for (int i = 0; i < a.size(); i++)
		{
			aCount.at(a.at(i) - 'a')++;
		}
		for (int i = 0; i < b.size(); i++)
		{
			bCount.at(b.at(i) - 'a')++;
		}

		for (int i = 0; i < 26; i++)
		{
			if (aCount.at(i) > 0 && bCount.at(i) > 0)
			{
				int time = min(aCount.at(i), bCount.at(i));
				while (time--)
				{
					cout << static_cast<char>(i + 'a');
				}
			}
		}
		cout << endl;
	}
}