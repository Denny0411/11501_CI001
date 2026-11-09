#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct Count
{
	char alpha;
	int num = 0;
};

bool compare(Count a, Count b)
{
	return a.num > b.num;
}

int main()
{
	int n;
	string input;
	vector<Count> count(26);
	for (int i = 0; i < 26; i++)
		count.at(i).alpha = 'A' + i;

	cin >> n;
	n++;
	while (n--)
	{
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
		{
			if (isalpha(input.at(i)) != 0)
			{
				count.at(toupper(input.at(i)) - 'A').num++;
			}
		}
	}
	sort(count.begin(), count.end() ,compare);
	int maxendl = 0;
	for (int i = 0; i < 26; i++)
	{
		if (count.at(i).num > 0 && i > maxendl)
			maxendl = i;
	}
	for (int i = 0; i < 26; i++)
	{
		if (count.at(i).num > 0)
		{
			cout << count.at(i).alpha << " " << count.at(i).num;
			if (i < maxendl)
				cout << "\n";
		}
	}
}