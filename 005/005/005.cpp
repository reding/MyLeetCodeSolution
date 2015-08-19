// 005.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() <= 0)
			return NULL;
		char *ss = (char*)malloc((s.length() * 2 + 3)*sizeof(char));
		for (int i = 0;i < s.length();i++)
		{
			if (i == 0)
				ss[i] = '@';
			ss[2 * i + 1] = '#';
			ss[2 * i + 2] = s[i];
		}
		ss[s.length() * 2 + 1] = '#';
		ss[s.length() * 2 + 2] = '\0';

		int maxlen = 0;
		int maxindex = 0;
		for (int j = 0;j < s.length() * 2 + 2;j++)
		{
			int len = 0;

			while (ss[j + 1 + len] == ss[j - 1 - len])
			{
				len++;
				if (j + 1 + len>s.length() * 2 + 1)
					break;
				if (j - 1 - len <= 0)
					break;
			}
			if (len > maxlen)
			{
				maxlen = len;
				maxindex = j;
			}
		}
		string restring;
		for (int i = maxindex - maxlen;i <maxindex + maxlen;i++)
		{
			if (ss[i] != '#')
				restring.push_back(ss[i]);
		}
		return restring;
	}
};

int main()
{
	Solution s;
	if (!s.longestPalindrome("abab").compare("aba"))
		cout << "test 1 passed!" << endl;
	if (!s.longestPalindrome("abcd").compare("a"))
		cout << "test 2 passed!" << endl;
	if (!s.longestPalindrome("abccba").compare("abccba"))
		cout << "test 3 passed!" << endl;
	if (!s.longestPalindrome("abcba").compare("abcba"))
		cout << "test 4 passed!" << endl;
	string dd = s.longestPalindrome("zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez");
	cout << dd.c_str() << endl;
	system("pause");
	return 0;
}

