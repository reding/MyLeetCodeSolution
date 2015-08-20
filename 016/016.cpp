// 016.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int differ = INT_MAX;
		int result = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0;i < nums.size();i++)
		{
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (differ >= abs(sum - target))
				{
					differ = abs(sum - target);
					result = sum;
					left++;
					while (nums[left - 1] == nums[left] && left<right)
						left++;
					while ((right + 1)<nums.size() && nums[right + 1] == nums[right] && left<right)
						right--;
				}
				if (differ < abs(sum - target))
				{
					if (sum - target>0)
					{
						right--;
					}
					else
					{
						left++;
					}
				}
			}
		}
		return result;
	}
};

void test1(Solution s)
{
	vector<int> nums;
	nums.push_back(-1), nums.push_back(2), nums.push_back(1), nums.push_back(4);
	int target = 1;
	int result = 2;
	if (result == s.threeSumClosest(nums, target))
	{
		cout << "test 1 passed!" << endl;
	}
	else
	{
		cout << "test 1 failed!" << endl;
	}
}

int main()
{
	Solution s;
	test1(s);
	system("pause");
    return 0;
}

