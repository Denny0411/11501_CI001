#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//string input;
	char c;
	int doubleQuoteCount = 0;

	while (cin.get(c))
	{
		if (c == '"')
			doubleQuoteCount++;

		if (c == '"' && doubleQuoteCount % 2 == 1)
			cout << "``";
		else if (c == '"' && doubleQuoteCount % 2 == 0)
			cout << "''";
		else
			cout << c;
	}
}