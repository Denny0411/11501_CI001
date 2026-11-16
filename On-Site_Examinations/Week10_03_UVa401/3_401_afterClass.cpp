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
	string character = "AEHIJLMOSTUVWXYZ12358";
	string reverse   = "A3HILJMO2TUVWXY51SEZ8";
	string characterReverseTheSame = "AHIMOTUVWXY18";

	while (getline(cin, input))
	{
		bool isPalindrome = true;
		bool isMirrored = true;
		bool isCenterMirrored = false;

		// judge palindrome
		for (int i = 0; i < input.size() / 2; i++)
		{	
			if (input.at(i) != input.at(input.size() - 1 - i))
			{
				isPalindrome = false;
			}
		}

		// do reverse
		string reverseInput = input;
		bool isMirrorExist = false;
		for (int i = 0; i < input.size(); i++)
		{	
			for (int j = 0; j < character.size(); j++)
			{
				if (input.at(i) == character.at(j))
					{
						isMirrorExist = true;
						break;
					}
			}
			if (isMirrorExist == true)
				break;
		}
		if (isMirrorExist == false)
			isMirrored = false;
		

			for (int i = 0; i < input.size() / 2; i++)
			{	
				for (int j = 0; j < character.size(); j++)
				{
					if (input.at(i) == character.at(j))
						{
							reverseInput.at(i) = reverse.at(j);
						}
				}
			}

		// judge mirrored
		if (reverseInput.size() % 2 == 0)
		{
			for (int i = 0; i < reverseInput.size() / 2; i++)
			{	
				if (reverseInput.at(i) != reverseInput.at(reverseInput.size() - 1 - i))
				{
					isMirrored = false;
				}
			}
		}
		else
		{
			for (int i = 0; i < reverseInput.size() / 2; i++)
			{	
				if (reverseInput.at(i) != reverseInput.at(reverseInput.size() - 1 - i))
				{
					isMirrored = false;
				}
			}
			for (int i = 0; i < characterReverseTheSame.size(); i++)
			{
				if (reverseInput.at(reverseInput.size() / 2) == characterReverseTheSame.at(i))
					isCenterMirrored = true;
			}
			if (isCenterMirrored == false)
				isMirrored = false;
		}

		//cout << reverseInput << "\n";
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