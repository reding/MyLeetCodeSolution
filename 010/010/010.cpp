// 010.cpp : 定义控制台应用程序的入口点。
//
/**
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
**/


#include <iostream>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) 
			return s.empty();
		if (p[1] != '*') 
		{
			if (s[0] == p[0] || (p[0] == '.' && s[0] != '\0')) 
				return isMatch(s.substr(1), p.substr(1));
			else 
				return false;
		}
		else 
		{
			if (isMatch(s, p.substr(2))) 
				return true;
			int index = 0;
			while (index < s.size() && (s[index] == p[0] || p[0] == '.')) 
			{
				if (isMatch(s.substr(++index), p.substr(2))) 
					return true;
			}
			return false;
		}
	}
};

int main()
{
	Solution s;
	if (s.isMatch("aa", "a")==false)
		cout << "test 1 passed!" << endl;
	if (s.isMatch("aa", "aa")==true)
		cout << "test 2 passed!" << endl;
	if (s.isMatch("aa", "a*") == true)
		cout << "test 3 passed!" << endl;
	if (s.isMatch("aa", ".*") == true)
		cout << "test 4 passed!" << endl;
	if (s.isMatch("aab", "c*a*b") == true)
		cout << "test 5 passed!" << endl;
	system("pause");
    return 0;
}

