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

	//two pointers
	vector<vector<int>> threeSum2(vector<int>& nums)
	{
		vector<vector<int>> results;
		sort(nums.begin(), nums.end());
		for (int i = 0;i < nums.size();i++)
		{
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			int left = i+1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum > 0)
				{
					right--;		
				}
				else if (sum < 0)
				{
					left++;
				}
				else
				{
					vector<int> r;
					r.push_back(nums[i]);
					r.push_back(nums[left]);
					r.push_back(nums[right]);
					results.push_back(r);
					left++;
					while (nums[left - 1] == nums[left]&&left<right)
						left++;
					while ((right + 1)<nums.size()&&nums[right + 1] == nums[right] && left<right)
						right--;
				}
			}

		}
		return results;
	}

};

void test1(Solution s)
{
	vector<int> test;
	test.push_back(1);
	test.push_back(-1);
	test.push_back(0);
	vector<vector<int>> result = s.threeSum2(test);
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

void test2(Solution s)
{
	vector<int> test;
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	vector<vector<int>> result = s.threeSum2(test);
	int resultnum = 1;
	if (result.size() != resultnum)
	{
		cout << "test 2 failed!" << endl;
		return;
	}

	for (int i = 0;i < resultnum;i++)
	{
		if (result[i].size() != 3)
		{
			cout << "test 2 failed!" << endl;
		}
		for (int j = 0;j < 3;j++)
		{
			if ((result[i][0] + result[i][1] + result[i][2]) == 0)
				continue;
			else
			{
				cout << "test 2 failed!" << endl;
				return;
			}
		}
	}
	cout << "test2 passed!" << endl;
}

int main()
{
	Solution s;
	test1(s);
	test2(s);
	system("pause");
    return 0;
}

