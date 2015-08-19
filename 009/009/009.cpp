// 009.cpp : 定义控制台应用程序的入口点。
//
//Determine whether an integer is a palindrome.Do this without extra space.

#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		long long xx = x;
		long long new_xx = 0;

		while (xx > 0) {
			new_xx = new_xx * 10 + xx % 10;
			xx /= 10;
		}

		return new_xx == (long long)x;
	}
};

int main()
{
    return 0;
}

