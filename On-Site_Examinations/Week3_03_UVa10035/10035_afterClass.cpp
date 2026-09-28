#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    while (cin >> a >> b && !(a == 0 && b == 0))
    {
        int carry = 0; // 記錄進位值（來自前一位的進位，只會是 0 或 1）
        int carryCount = 0; // 累計進位次數

        while (a > 0 || b > 0)
        {
            int sum = (a % 10) + (b % 10) + carry; // 當前數位與進位的和
            carry = sum / 10; // 計算要進到下一位的進位
            if (carry > 0)
                carryCount++;

            a /= 10;
            b /= 10;
        }

        if (carryCount == 0)
			cout << "No carry operation.\n";
		else if (carryCount == 1)
			cout << "1 carry operation.\n";
		else
			cout << carryCount << " carry operations.\n";
    }

    return 0;
}