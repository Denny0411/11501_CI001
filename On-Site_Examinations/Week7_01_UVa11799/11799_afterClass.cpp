#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // 忽略第一行 T 殘留的換行符
    
    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        string inputValue;
        getline(cin, inputValue); // 一次讀取整行輸入
        stringstream ss(inputValue); // 將輸入轉換成 stringstream

        int N;
        ss >> N; // the number of students acting as scary creatures

        int maxSpeed = 0;
        int speed;
        while (ss >> speed)
            maxSpeed = max(speed, maxSpeed);

        cout << "Case " << caseNum << ": " << maxSpeed << "\n";
    }

    return 0;
}