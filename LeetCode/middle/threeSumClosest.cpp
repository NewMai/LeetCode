
#include "../common.h"

// https://leetcode-cn.com/problems/3sum-closest/
// AC after reference the other answer

class Solution 
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int ret = 0;
		int i = 0, j = 0;
		int start = 0, end = 0;
		int minDist = 999999999;
		int sum = 0;
		int dist = 0;

		if (nums.size() < 3) return 0;
		if (nums.size() == 3) return nums[0] + nums[1] + nums[2];


		sort(nums.begin(), nums.end());

		for (i = 0; i < nums.size(); i++)
		{
			start = i + 1; 
			end = nums.size() - 1;
			while (start < end)
			{
				sum = nums[i] + nums[start] + nums[end];
				dist = abs(sum - target);
				
				if (sum < target) start++;
				else if (sum > target) end--;
				else return sum;

				if (dist < minDist)
				{
					minDist = dist;
					ret = sum;
				}
			}
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	int target = -1;
	vector<int> nums = { -1, 2, 1, - 4 };


	ret = sln.threeSumClosest(nums, target);
	cout << ret << endl;


	return 0;
}





