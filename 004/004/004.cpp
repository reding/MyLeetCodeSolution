// 004.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> v3;
		while (nums1.size() >= 0 && nums2.size() >= 0)
		{
			if (nums1.size() == 0)
			{
				while (nums2.size() != 0)
				{
					v3.push_back(nums2[nums2.size() - 1]);
					nums2.pop_back();
				}
				break;
			}
			if (nums2.size() == 0)
			{
				while (nums1.size() != 0)
				{
					v3.push_back(nums1[nums1.size() - 1]);
					nums1.pop_back();
				}
				break;
			}
			if (nums1[nums1.size() - 1] <= nums2[nums2.size() - 1])
			{
				v3.push_back(nums2[nums2.size()-1]);
				nums2.pop_back();
			}
			else
			{
				v3.push_back(nums1[nums1.size() - 1]);
				nums1.pop_back();
			}
		}
		if (v3.size() % 2 == 1)
		{
			return v3[(v3.size() - 1) / 2];
		}
		if (v3.size() % 2 == 0)
		{
			return 0.5*(v3[v3.size() / 2-1]+ v3[v3.size() / 2]);
		}
	}
};

int main()
{
	vector<int> v1 ;
	vector<int> v2 ;
	Solution s;
	for (int i = 0;i <= 100000;i++)
		v1.push_back(i);
	for (int j = 11;j < 200000;j++)
		v2.push_back(j);
	cout << s.findMedianSortedArrays(v1, v2) << endl;
	system("pause");
	return 0;
}


