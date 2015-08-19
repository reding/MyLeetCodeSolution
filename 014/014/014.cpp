// 014.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string result = "";
		int strindex = 0;
		while (1)
		{
			if (strindex >= strs[0].length())
				return strs[0].substr(0, strindex);
			char temp = strs[0][strindex];
			for (int i = 1;i < strs.size();i++)
			{
				
				if (strindex < strs[i].length())
				{
					if (temp == strs[i][strindex])
						continue;
					else
						return strs[0].substr(0, strindex);
				}
				else
					return strs[0].substr(0, strindex);
			}
			strindex++;
		}
	}
};

void test1(Solution s)
{
	vector<string> testr1;
	testr1.push_back("aaasss");
	testr1.push_back("aas");
	cout << s.longestCommonPrefix(testr1).c_str() << endl;
	if (!s.longestCommonPrefix(testr1).compare("aa"))
		cout << "test 1 passed!" << endl;
	else
		cout << "test 1 failed!" << endl;
}

void test2(Solution s)
{
	vector<string> testr2;
	testr2.push_back("aaasss");
	testr2.push_back("bbb");
	cout << s.longestCommonPrefix(testr2).c_str() << endl;
	if (!s.longestCommonPrefix(testr2).compare(""))
		cout << "test 2 passed!" << endl;
	else
		cout << "test 2 failed!" << endl;
}

void test3(Solution s)
{
	vector<string> testr2;
	testr2.push_back("a");
	testr2.push_back("b");
	cout << s.longestCommonPrefix(testr2).c_str() << endl;
	if (!s.longestCommonPrefix(testr2).compare(""))
		cout << "test 3 passed!" << endl;
	else
		cout << "test 3 failed!" << endl;
}

void test4(Solution s)
{
	vector<string> testr2;
	testr2.push_back("aa");
	testr2.push_back("a");
	cout << s.longestCommonPrefix(testr2).c_str() << endl;
	if (!s.longestCommonPrefix(testr2).compare("a"))
		cout << "test 4 passed!" << endl;
	else
		cout << "test 4 failed!" << endl;
}

int main()
{
	Solution s;
	test1(s);
	test2(s);
	test3(s);
	test4(s);
	system("pause");
    return 0;
}

