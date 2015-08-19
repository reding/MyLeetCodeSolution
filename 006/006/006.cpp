// 006.cpp : 定义控制台应用程序的入口点。
//
/*
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 0)return NULL;
		if (numRows == 1)return s;
		char* res = (char*)malloc(s.length()*sizeof(char));
		int x = (numRows - 1) * 2;
		int reindex = 0;
		for (int i = 0;i <= x/2;i++)
		{
			int index = i;
			if (index == x / 2)
			{
				while (index < s.length())
				{
					res[reindex] = s[index];
					reindex++;
					index = index + x;
				}
				break;
			}
			if (index == 0)
			{
				while (index < s.length())
				{
					res[reindex] = s[index];
					reindex++;
					index = index + x;
				}
				continue;
			}
			int n = 1;
			while (index < s.length())
			{
				res[reindex] = s[index];
				reindex++;
				if ((n*x - index)>s.length())
					goto l1;
				else {
					res[reindex] = s[n*x - index];
					reindex++;
					n++;
				}
				l1:
				index = index + x;
			}
			
		}
		return res;
	}
};

int main()
{
	Solution s;
	string tmp1 = s.convert("PAYPALISHIRING", 3);
	cout << tmp1.c_str() << endl;
	if (!tmp1.compare("PAHNAPLSIIGYIR"))
		cout << "test 1 failed!" << endl;
	string tmp2 = s.convert("abcdefghijklmnopqrstuvwxyz", 4);
	cout << tmp2.c_str() << endl;
	if(!tmp2.compare("agmsybfhlnrtxzceikoquwdjpv"))
		cout << "test 2 failed!" << endl;
	string tmp3 = s.convert("whsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqca", 61);
	cout << tmp3.c_str() << endl;
	string tmp4 = s.convert("xtigsieehkchzdflilrjq", 12);
	cout << tmp4.c_str() << endl;
	system("pause");
	return 0;
}

*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		vector<vector<char>> res(numRows);
		int resindex = 0;
		bool forward = true;
		for (int i = 0;i < s.length();i++)
		{
				res[resindex].push_back(s.at(i));
				if (forward)
					resindex++;
				else
					resindex--;
				if (resindex == numRows - 1)
					forward = false;
				if (resindex == 0)
					forward = true;
		}
		string result;
		for (int k = 0;k < res.size();k++)
		{
			for (int t = 0;t < res[k].size();t++)
			{
				result.push_back(res[k][t]);
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	string tmp1 = s.convert("PAYPALISHIRING", 3);
	cout << tmp1.c_str() << endl;
	if (!tmp1.compare("PAHNAPLSIIGYIR"))
		cout << "test 1 failed!" << endl;

	string tmp2 = s.convert("abcdefghijklmnopqrstuvwxyz", 4);
	cout << tmp2.c_str() << endl;
	if (!tmp2.compare("agmsybfhlnrtxzceikoquwdjpv"))
		cout << "test 2 failed!" << endl;

	string tmp3 = s.convert("whsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqca", 61);
	cout << tmp3.c_str() << endl;


	string tmp4 = s.convert("xtigsieehkchzdflilrjq", 12);
	cout << tmp4.c_str() << endl;
	system("pause");
	return 0;
}