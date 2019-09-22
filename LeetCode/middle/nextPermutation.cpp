
#include "../common.h"

// https://leetcode-cn.com/problems/next-permutation/
// AC after reference

class Solution 
{
public:

	int solve(vector<int>& nums, int step)
	{
		int ret = 0;
		int i = 0, j = 0;
		bool flag = false;
		int size = nums.size();
		int t = 0;

		if (size < 2) return 1;
		if (step == size) return 0;

		for (i = size - 1; i > 0; i -= step)
		{
			j = i - step;
			if (j < 0) break;
			if (nums[j] < nums[i])
			{
				t = nums[i];
				nums[i] = nums[j];
				nums[j] = t;

				sort(nums.begin() + j + 1, nums.end());

				return 1;
			}
		}

		ret = solve(nums, step+1);
		
		return ret;
	}

	void nextPermutation(vector<int>& nums)
	{
		int ret = 0;
		int i = 0, j = 0;
		bool flag = false;
		int size = nums.size();
		int min = 0, elem;
		int min_j = 0;

		if (size < 2) return;

		//ret = solve(nums, 1);
		//if(ret == 0) sort(nums.begin(), nums.end());

		for (i = size - 2; i >= 0; i--)
		{
			elem = nums[i];
			min = INT_MAX;
			min_j = -1;
			for (j = i + 1; j < size; j++)
			{
				if (nums[j] > elem && nums[j] < min)
				{
					min = nums[j];
					min_j = j;
				}
			}
			if (min_j >= 0)
			{
				nums[i] = nums[min_j];
				nums[min_j] = elem;
				sort(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		sort(nums.begin(), nums.end());

	}

};


int main()
{
	Solution sln;
	int i = 0;
	string str = "test";
	//vector<int> nums = { 1,8,6,2,5,4,8,3,7 };
	//vector<int> nums = { 2,3,1 };
	//vector<int> nums = { 4,2,0,2,3,2,0 };
	//vector<int> nums = { 1,2};
	vector<int> nums = { 1,3,2 };

	sln.nextPermutation(nums);
	
	for (i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;


	return 0;
}





