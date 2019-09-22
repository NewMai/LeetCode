
#include "../common.h"

// https://leetcode-cn.com/problems/first-missing-positive/
// AC after reference

class Solution 
{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int ret = 0;
		int i = 0, j = 0;
		int t = 0;
		int max = 0;
		int min = INT_MAX;
		int n = nums.size();

		for (i = 0; i < n; i++)
		{
			if (nums[i] < min && nums[i] > 0) min = nums[i];
			if (nums[i] > max) max = nums[i];
		}

		if (max == 0) return 1;
		if (min > 1) return 1;

		// Add a element for convenient
		nums.push_back(1);

		// Prepare: set all elements into range 1 to n-1
		for (i = 0; i < n; i++)
		{
			if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
		}

		for (i = 0; i < n; i++)
		{
			t = abs(nums[i]);
			// Set nums[i] to a nagtive number
			nums[t] = -abs(nums[t]);
		}

		for (i = 2; i <= n; i++)
		{
			if (nums[i] > 0 ) return i;
		}

		return n + 1;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "test";
	//vector<int> nums = { 0,1,2 };
	//vector<int> nums = { 3,4,-1,1 };
	//vector<int> nums = { 1, 4, 2, 0, 3, 4, 2, 4, 2 };
	vector<int> nums = { 3,4,-1,1 };

	ret = sln.firstMissingPositive(nums);
	cout << ret << endl;


	return 0;
}





