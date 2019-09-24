
#include "../common.h"

// https://leetcode-cn.com/problems/maximum-subarray/
// AC

class Solution 
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int ret = 0;
		int i = 0, j = 0;
		int max = 0;
		int cur = 0;

		max = nums[0];
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] + cur >= 0)
			{
				cur += nums[i];
				if (cur > max) max = cur;
			}
			else
			{
				cur = 0;
				if (nums[i] > max) max = nums[i];
			}
		}

		ret = max;
		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "test";
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };


	ret = sln.maxSubArray(nums);
	cout << ret << endl;


	return 0;
}





