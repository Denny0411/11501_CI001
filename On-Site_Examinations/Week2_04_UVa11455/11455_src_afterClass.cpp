#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);

        // 正方形：最大邊等於最小邊，則四邊相等
        if (a[0] == a[3])
            cout << "square\n";
        // 長方形：對邊等長共兩組
        else if (a[0] == a[1] && a[2] == a[3])
            cout << "rectangle\n";
        // 四邊形：最長邊需小於其他邊之和
        else if (a[0] + a[1] + a[2] > a[3])
            cout << "quadrangle\n";
        else
            cout << "banana\n";
    }
    return 0;
}