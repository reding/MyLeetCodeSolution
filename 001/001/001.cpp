// 001.cpp : �������̨Ӧ�ó������ڵ㡣
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

vector<int> twoSum(vector<int> &numbers, int target) //O(n^2)��ʱ!
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
�ⷨ�ܽ�

����ԭ���������������򣬽�����������������ְ취��

1�����֣����������������֣���ʱ�临�Ӷ���ΪO(N log N)���ռ临�Ӷ�ΪO��1����
2��ɨ��һ��X - S[i] ӳ�䵽һ���������hash��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(N)��
3������ָ������ɨ�裨�������������ɨ�裩��ʱ�临�Ӷ����Ϊ��
											����O(N)������O(N log N + N) = O(N log N)��
											�ռ临�Ӷȶ�ΪO(1)��
���ԣ�Ҫ��ﵽʱ��O(N)���ռ�O(1)��Ŀ�꣬����ԭ����������ģ�ָ��ɨ�跨����
��Ȼ������������Ļ�����ֻ�������򣬺�ָ��ɨ�跨����֣�ʱ�� O(Nlog N)���ռ�O(1)����
��ӳ���hash��ʱ��O(N)���ռ�O(N)����ʱ���ռ䣬��������һ�����ﵽƽ�⡣

���ϣ������������������£����ȿ�������ָ������ɨ�跨���Դﵽ��ѵ�ʱO(N)����O(1)ЧӦ��
�������Ҫ����Ļ���ʱ�临�Ӷ���쵱Ȼ��ֻ�ܴﵽO(N log N)���ռ�O(1)���ڻ��¡�
*/