#include <iostream>

using namespace std;

int main()
{
	char c;
	unsigned char uc;
	int ascii;

	while (cin.get(c))
	{
		if (c == '\n' || c == '\r')
			cout << c;
		else
		{
			// printable portion: 32 to 126
			uc = static_cast<unsigned char>(c);
			ascii = static_cast<int>(uc) - 7;
			cout << static_cast<char>(ascii);
		}
	}
}

/*
z: 122
before decoding, z is 122 + 7 = 129
char only store -128 ~ 127
this will cause overflow when let 129 storing into char
for this problem, we need to use ussigned char: 0 ~ 255
*/