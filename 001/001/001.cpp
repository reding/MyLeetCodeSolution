// 001.cpp : 定义控制台应用程序的入口点。
//
/****
Given an array of integers, 
find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers 
such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers
(both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target) {

}
};

***/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> twoSum(vector<int> &numbers, int target);
int main()
{
	vector<int> number;
	int target;
	vector<int> index;
	
	number.push_back(3);
	number.push_back(2);
	number.push_back(4);

	target = 6;
	index = twoSum(number, target);
	for (int i = 0; i < index.size(); i++)
	{
		cout << index[i] << endl;
	}
	system("pause");
	return 0;
}

vector<int> twoSum(vector<int> &numbers, int target) //O(n^2)超时!
{
	vector<int> index;
	vector<int> copy = numbers;

	std::sort(numbers.begin(), numbers.end());
	int begin = 0;
	int end = numbers.size()-1;
	while (begin < end)
	{
		long sum = numbers[begin] + numbers[end];

		if (sum == target)
		{
			for (int i = 0; i < numbers.size(); i++)
			{
				if (numbers[begin] == copy[i])
				{
					index.push_back(i + 1);
					continue;
				}
				if (numbers[end] == copy[i])
				{
					index.push_back(i + 1);
					continue;
				}
			}
			break;
		}
		else
		{
			if (sum < target)
				begin++;
			else
				end--;
		}
	}
	return index;
}
/*
解法总结

不论原序列是有序还是无序，解决这类题有以下三种办法：

1、二分（若无序，先排序后二分），时间复杂度总为O(N log N)，空间复杂度为O（1）；
2、扫描一遍X - S[i] 映射到一个数组或构造hash表，时间复杂度为O(N)，空间复杂度为O(N)；
3、两个指针两端扫描（若无序，先排序后扫描），时间复杂度最后为：
											有序O(N)，无序O(N log N + N) = O(N log N)，
											空间复杂度都为O(1)。
所以，要想达到时间O(N)，空间O(1)的目标，除非原数组是有序的（指针扫描法），
不然，当数组无序的话，就只能先排序，后指针扫描法或二分（时间 O(Nlog N)，空间O(1)），
或映射或hash（时间O(N)，空间O(N)）。时间或空间，必须牺牲一个，达到平衡。

综上，若是数组有序的情况下，优先考虑两个指针两端扫描法，以达到最佳的时O(N)，空O(1)效应。
否则，如果要排序的话，时间复杂度最快当然是只能达到O(N log N)，空间O(1)则不在话下。
*/