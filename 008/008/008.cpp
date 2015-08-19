// 008.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		bool belowzero = false;
		bool abovezero = false;
		while (str[0] == '-' || str[0] == '+'|| str[0] == ' ')
		{
			if (str[0] == ' ')
			{
				if (belowzero || abovezero)
					return 0;
				str = str.substr(1, str.length() - 1);
			}
			if (str[0] == '-')
			{
				if (abovezero)
					return 0;
				if (belowzero)
					return 0;
				belowzero = belowzero ? 0 : 1;
				str = str.substr(1, str.length() - 1);
			}
			if (str[0] == '+')
			{
				if (abovezero)
					return 0;
				if (belowzero)
					return 0;
				abovezero = true;
				str = str.substr(1, str.length() - 1);
			}
		}

		long long result = 0;
		for (int i = 0;i < str.length();i++)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				break;
			}
			result = result * 10 + str[i] - '0';
			if (result > INT_MAX)
				break;
		}

		if (belowzero)
		{
			if (result > INT_MAX)
			{
				return INT_MIN;
			}
		}
		else 
		{
			if (result > INT_MAX)
			{
				return INT_MAX;
			}
		}
		return belowzero?-(int)result: (int)result;
	}
};

int main()
{
	Solution s;
	if (s.myAtoi("123") == 123)
		cout << "test 1 passed!" << endl;
	if (s.myAtoi("0") == 0)
		cout << "test 2 passed!" << endl;
	if (s.myAtoi("-123") == -123)
		cout << "test 3 passed!" << endl;
	if (s.myAtoi("-+123") == -123)
		cout << "test 4 passed!" << endl;
	if (s.myAtoi("--123") == 123)
		cout << "test 5 passed!" << endl;
	if (s.myAtoi("+1") == 1)
		cout << "test 6 passed!" << endl;
	if (s.myAtoi("-+1") == 0)
		cout << "test 7 passed!" << endl;
	if (s.myAtoi("+-1") == 0)
		cout << "test 8 passed!" << endl;
	if (s.myAtoi("    010") == 10)
		cout << "test 9 passed!" << endl;
	if (s.myAtoi("    -0010a12") == -10)
		cout << "test 10 passed!" << endl;
	if (s.myAtoi("-2147483648") == -2147483648)
		cout << "test 11 passed!" << endl;
	if (s.myAtoi("++1") == 0)
		cout << "test 12 passed!" << endl;
	if (s.myAtoi("--1") == 0)
		cout << "test 13 passed!" << endl;
	if (s.myAtoi("9223372036854775809") == 2147483647)
		cout << "test 14 passed!" << endl;
	system("pause");
    return 0;
}

