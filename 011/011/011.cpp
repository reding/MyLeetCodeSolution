// 011.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
using namespace std;

#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a

class Solution {
public:
	int maxArea(vector<int>& height) {
		int area = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			int h = Min(height[left],height[right]);
			area = Max(area, h*(right - left));
			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return area;
	}
};

int main()
{
    return 0;
}

