// 003.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int charhash[256];
		int fast = 0;
		int slow = 0;
		int maxlength =0;

		if (s.length() == 0)
			return 0;
		if (s.length() == 1)
			return 1;

		while (1)
		{
			if (slow >= s.length() - 1)
				return maxlength;
			memset(charhash, 0, 256*sizeof(int));
			int length = 0;
			fast = slow;
			while (charhash[s[fast]] == 0)
			{
				length++;
				if (fast >= s.length() - 1)
					break;
				charhash[s[fast]] = 1;
				fast++;
			}
			if (length > maxlength)
				maxlength = length;
			slow++;
		}
		return maxlength;
	}
};

int main()
{
	Solution s;
	if(3 != s.lengthOfLongestSubstring("abcabcbb"))
	{
		cout << "test 1 failed!"<<endl;
	}
	if (1 != s.lengthOfLongestSubstring("bbbbb"))
	{
		cout << "test 2 failed!"<<endl;
	}
	if (0 != s.lengthOfLongestSubstring(""))
	{
		cout << "test 3 failed!"<<endl;
	}
	if (4 != s.lengthOfLongestSubstring("bcd cd"))
	{
		cout << "test 3 failed!" << endl;
	}
	if (2 != s.lengthOfLongestSubstring("au"))
	{
		cout << "test 4 failed!" << endl;
	}
	if (1 != s.lengthOfLongestSubstring("a"))
	{
		cout << "test 5 failed!" << endl;
	}
	if (3 != s.lengthOfLongestSubstring("vdvf"))
	{
		cout << "test 6 failed!" << endl;
	}
	cout << "all test over!" << endl;
	system("pause");
	return 0;
}

