
#include "../common.h"

// https://leetcode-cn.com/problems/
// 

class Solution 
{
public:
	int test(vector<int>& nums)
	{
		int ret = 0;
		int i = 0, j = 0;

		for (i = 0; i < nums.size(); i++)
		{
			ret += nums[i];
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "test";
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };


	ret = sln.test(nums);
	cout << ret << endl;


	return 0;
}





