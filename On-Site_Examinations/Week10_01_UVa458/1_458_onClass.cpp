#include <iostream>

using namespace std;

int main()
{
	char c;
	int ascii;

	while (cin.get(c))
	{
		if (c == '\n')
			cout << c;
		else if (c < 7)
		{
			ascii = static_cast<int>(c) + 128 - 7;
			cout << static_cast<char>(ascii);
		}
		else
		{
			ascii = static_cast<int>(c) - 7;
			cout << static_cast<char>(ascii);
		}
	}
}