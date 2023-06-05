#include <iostream>
using namespace std;
#include <cmath>; // for squaring, rounding and logs etc
#include <string>
#include <vector>

class Solution {
public:
	//exercise 1
	vector<int> twoSum(vector<int>& nums, int target) {

		int size = nums.size(), answer1 = 0, answer2 = 0, i, j;

		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if ((nums[i] + nums[j]) == target) {
					if (i != j)
					{
						answer1 = i;
						answer2 = j;
					}
				}
			}
		}
		cout << answer1 << endl;
		cout << answer2 << endl;
		return { answer1,answer2 };
	}
	//exercise 9
	bool isPalindrome(int x) {
		bool test = false;

		string sInteger = to_string(x);
		int size = sInteger.length();
		if (sInteger[0] == '-')//if negative it cant be a palindrome
		{
			test = false;
			cout << test << endl;
			return test;
		}
		for (int i = 0; i < size; i++)
		{
			if (sInteger[i] == sInteger[size - i - 1])
			{
				test = true;
			}
			else
			{
				test = false;
				return test;
			}
		}
		cout << test << endl;
		return test;
	}

	//exercise 13
	int romanToInt(string s) {
		int answer = 0;
		int size = s.length();

		for (int i = 0; i < size; i++)
		{
			switch (s[size - i - 1])
			{
			case 'I':
				answer < 5 ? answer += 1 : answer -= 1;
				break;
			case 'V':
				answer < 10 ? answer += 5 : answer -= 5;
				break;
			case 'X':
				answer < 50 ? answer += 10 : answer -= 10;
				break;
			case 'L':
				answer < 100 ? answer += 50 : answer -= 50;
				break;
			case 'C':
				answer < 500 ? answer += 100 : answer -= 100;
				break;
			case 'D':
				answer < 1000 ? answer += 500 : answer -= 500;
				break;
			case 'M':
				answer += 1000;
				break;
			default:
				break;
			}
			cout << i << "  " << answer << endl;
		}
		cout << "answer:" << answer;
		return answer;
	}
	//exercise 14
	string longestCommonPrefix(vector<string>& strs) {
		string output = "";
		int size = strs.size();
		int wordSize = strs[0].length();
		vector <char> charTest;
		int i = 0;
		int j = 0;
		int count;
		bool done = false;

		//error handling (inputs)
		if (size == 1)//if there is only one string
		{
			done = true;
			output = strs[0];
		}
		for (i = 0; i < size; i++) {//if any are empty
			if (strs[i][0] == *"")
			{
				done = true;
			}
		}
		while (done == false)//continues until prefix's no longer match
		{
			count = 0;

			for (i = 0; i < size; i++)
			{
				charTest.push_back(strs[i][j]);//get first char of each string to compare
				if (charTest[0] == charTest[i])//compare chars 
				{
					count++;
				}
			}
			if (size == (count) && j < wordSize)
			{
				output += charTest[0];//if same, record the char in OUTPUT, and check the next char
				j++;
				charTest.clear();
			}
			else
			{
				done = true;
			}
		}
		cout << output;
		return output;
	}

	bool isValid(string s) {
		int i = 0;
		int parenthesesBrackets = 0, curlyBrackets = 0, squareBrackets = 0;
		int pCount = 1, cCount = 1, sCount = 1;
		int length = s.length();

		for (i = 0; i < length; i++)
		{
			if (parenthesesBrackets < 0 || curlyBrackets < 0 || squareBrackets < 0) { return false; }//closed before an open
			if (s[i] == *"(") { parenthesesBrackets += 1; pCount = i; }
			else {
				if (s[i] == *"{") { curlyBrackets += 1; cCount = i; }
				else {
					if (s[i] == *"[") { squareBrackets += 1; sCount = i; }
					else {
						if (s[i] == *")") { parenthesesBrackets -= 1; pCount -= i; }
						else {
							if (s[i] == *"}") { curlyBrackets -= 1; cCount -= i; }
							else { if (s[i] == *"]") { squareBrackets -= 1; sCount -= i; } }
						}
					}
				}
			}
		}
		if (pCount % 2 == 0 || cCount % 2 == 0 || sCount % 2 == 0) { return false; }//checks for odd spacing as should always be even for pairs
		if (parenthesesBrackets == 0 && curlyBrackets == 0 && squareBrackets == 0)
		{
			return true;
		}
		else { return false; }
	}
};

int  main()
{
	Solution Test;/*
	vector<int> nums = {3, 3};
	twosumTest.twoSum(nums, 6);*/
	/*	Solution palindromeTest;
		palindromeTest.isPalindrome(121);*/
		/*	Solution romanNumeralsTest;
			romanNumeralsTest.romanToInt("MCMXCIV");*/
			/*vector <string>  strs{ "flower","flower","flower","flower" };
			Test.longestCommonPrefix(strs);*/

			//cout <<"Output: "<< Test.isValid("[({])}") << endl;

	return 0;
}

