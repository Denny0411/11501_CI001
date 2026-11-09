#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		int wordCount = 0;
		bool isInsideWord = false;
		for (int i = 0; i < input.size(); i++)
		{
			//cout << isalpha(input.at(i)) << "\n";
			if (isInsideWord == false && isalpha(input.at(i)) != 0)
			{
				isInsideWord = true;
				wordCount++;
			}
			else if (isalpha(input.at(i)) == false)
			{
				isInsideWord = false;
			}
		}
		cout << wordCount << "\n";
	}
}