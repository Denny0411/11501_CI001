/*
* regular palindrome
	* mirrored palindrome
* mirrored string

isPalindrome
isMirrored
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	string mirrored = "AEHIJLMOSTUVWXYZ12358";
	while (getline(cin, input))
	{
		// judge palindrome
		bool isPalindrome = true;
		for (int i = 0; i < input.size() / 2; i++)
		{
			if (input.at(i) != input.at(input.size() - 1 - i))
			{
				isPalindrome = false;
				//break;
			}
		}

		// judge mirrored
		bool isMirrored = false;
		vector<int> judgeMirrored(input.size(), 0);
		// 0: false
		// 1: true
		for (int i = 0; i < input.size(); i++)
		{
			for (int j = 0; j < mirrored.size(); j++)
			{
				if (input.at(i) == mirrored.at(j))
				{
					judgeMirrored.at(i) = 1;
					//continue;
				}
			}
		}
		int countMirrored = 0;
		for (int i : judgeMirrored)
			countMirrored += i;
		if (countMirrored == input.size())
			isMirrored = true;

		if (isPalindrome == true && isMirrored == true)
			cout << input << " -- is a mirrored palindrome.\n\n";
		else if (isPalindrome == true)
			cout << input << " -- is a regular palindrome.\n\n";
		else if (isMirrored == true)
			cout << input << " -- is a mirrored string.\n\n";
		else
			cout << input << " -- is not a palindrome.\n\n";
	}
}