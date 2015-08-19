// 007.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool belowzero = false;
		if (x < 0) {
			belowzero = true;
			if (x == INT_MIN)
				return 0;
			x = -x;
		}
		queue<int> numbers;
		int tmp = x;
		while (1)
		{
			int modx = tmp % 10;
			numbers.push(modx);
			tmp = tmp / 10;
			if (tmp < 10)
			{
				if(tmp>0)
					numbers.push(tmp);
				break;
			}
		}
		long result = 0;
		while (!numbers.empty())
		{
			result = result * 10 + numbers.front();
			numbers.pop();
		}
		if (result >= INT_MAX)
			return 0;
		return belowzero ? result*(-1) : result;
	}
};

int main()
{
	Solution s;
	if (321 != s.reverse(123))
		cout << "test 1 failed!" << endl;
	if (-321 != s.reverse(-123))
		cout << "test 2 failed!" << endl;
	if (11 != s.reverse(110))
		cout << "test 3 failed!" << endl;
	if (1 != s.reverse(100))
		cout << "test 4 failed!" << endl;
	if (1 != s.reverse(1))
		cout << "test 5 failed!" << endl;
	if (0 != s.reverse(-2147483648))
		cout << "test 6 failed!" << endl;
	cout << "all test passed!" << endl;
	system("pause");
    return 0;
}

