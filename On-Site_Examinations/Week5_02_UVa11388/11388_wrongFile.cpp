#include <iostream>
#include <algorithm>

using namespace std;
using ULL = unsigned long long;

ULL gcd(ULL a, ULL b)
{
	// a >= b
	if (a < b)
		swap(a, b);

	ULL remainder = a % b;
	ULL quotient = a / b;
	a = remainder;
	while (remainder != 0 && b != 1)
	{
		swap(a, b);
		remainder = a % b;
		quotient = a / b;
		a = remainder;
	}
	if (b == 1)
		return 1;
	return quotient;
}

ULL lcm(ULL a, ULL b)
{
	ULL g = gcd(a, b);
	a /= g;
	b /= g;
	return a * b;
}

int main()
{
	
	return 0;
}

/*
一個正整數可以是很多數的 GCD，
也可以是很多數的 LCM
1 2
GCD(1, 2) == 1
LCM(1, 2) == 2
3 4
GCD(3, 4) == 1
LCM(3, 4) == 12
*/