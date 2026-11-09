#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b) // constant reference
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    map<char, int> count;
    while (n--)
    {
        string input;
        getline(cin, input);
        for (int i = 0; i < input.size(); i++)
        {
            if (isalpha(input.at(i)))
            {
                count[toupper( input.at(i) )]++;
            }
        }
    }

    // 將 map 的元素 (pair) 轉移到 vector
    vector< pair<char, int> > v(count.begin(), count.end());
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i).first << " " << v.at(i).second << "\n";
}