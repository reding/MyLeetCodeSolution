// 015.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		sort(nums.begin(), nums.end());

		for (int i = 0; i<nums.size(); i++)
		{
			twoSum(i, nums, results, 0 - nums[i]);

			while (i<nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
		return results;
	}
	void twoSum(int index, vector<int>&nums, vector<vector<int>>& results, int sum)
	{
		unordered_map<int, int> record;

		for (int i = index + 1; i<nums.size(); i++)
		{
			if (record.find(nums[i]) == record.end())
				record[sum - nums[i]] = nums[i];
			else
			{
				vector<int> vec;
				vec.push_back(nums[index]);
				vec.push_back(record[nums[i]]);
				vec.push_back(nums[i]);
				results.push_back(vec);

				while (i<nums.size() - 1 && nums[i] == nums[i + 1])
					i++;
			}
		}
	}
};

void test1(Solution s)
{
	vector<int> test;
	test.push_back(1);
	test.push_back(-1);
	test.push_back(0);
	vector<vector<int>> result = s.threeSum(test);
	int resultnum = 1;
	if (result.size() != resultnum) 
	{
		cout << "test 1 failed!" << endl;
		return;
	}
		
	for (int i = 0;i < resultnum;i++)
	{
		if (result[i].size() != 3)
		{
			cout << "test 1 failed!" << endl;
		}
		for (int j = 0;j < 3;j++)
		{
			if ((result[i][0] + result[i][1] + result[i][2]) == 0)
				continue;
			else
			{
				cout << "test 1 failed!" << endl;
				return;
			}
		}
	}
	cout << "test1 passed!" << endl;
}

int main()
{
	Solution s;
	test1(s);
	system("pause");
    return 0;
}

