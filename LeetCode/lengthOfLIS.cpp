
#include "common.h"


// https://leetcode-cn.com/problems/longest-increasing-subsequence/
// AC
class Solution 
{
public:
	int lengthOfLIS(vector<int>& nums) 
	{
		int ret = 0;
		vector<int> C(nums.size(), 1);
		int i = 0, j = 0, k = 0;
		int max = 0;
		
		if (nums.size() == 0)
		{
			return 0;
		}
		if (nums.size() == 1)
		{
			return 1;
		}

		for (i = 1; i < nums.size(); i++)
		{
			max = C[i];
			k = i;
			for (j = i-1; j >= 0; j--)
			{
				if (nums[j] < nums[i])
				{
					if (C[j] >= max)
					{
						max = C[j];
						k = j;
					}
				}
			}
			if (k != i)
			{
				C[i] = max + 1;
			}
		}

		max = C[0];
		for (i = 1; i < nums.size(); i++)
		{
			if (C[i] > max)
			{
				max = C[i];
			}
		}

		ret = max;
		return ret;
	}
};

int main10()
{
	vector<int> nums = { 10,9,2,5,3,7,101,18 };
	Solution solution;
	int ret = 0;

	ret = solution.lengthOfLIS(nums);
	cout << ret << endl;

	return 0;
}