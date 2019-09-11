
#include "../common.h"

// https://leetcode-cn.com/problems/4sum/
// AC

class Solution 
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> ret = {};
		int i = 0, j = 0, k = 0;
		int start = 0, end = 0;
		int sum = 0;
		int tmp_target = 0;

		if (nums.size() < 4) return ret;
		if (nums.size() == 4)
		{
			for (sum = 0, i = 0; i < 4; i++)
			{
				sum += nums[i];
			}
			if (sum == target)
			{
				vector<int> tv = { nums[0], nums[1], nums[2], nums[3] };
				ret.push_back(tv);
			}
			return ret;
		}

		sort(nums.begin(), nums.end());
		for (i = 0; i < nums.size() - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
			{
				i++;
				while (i < nums.size() - 3 && nums[i] == nums[i - 1]) i++;
			}
			if (nums[i] > target && nums[i] > 0) break;
			tmp_target = target - nums[i];
			for (j = i + 1; j < nums.size() - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
				{
					j++;
					while (j < nums.size() - 2 && nums[j] == nums[j - 1]) j++;
				}
				if (nums[j] > tmp_target && nums[j] > 0) break;
				start = j + 1;
				end = nums.size() - 1;
				while (start < end)
				{
					sum = nums[j] + nums[start] + nums[end];
					if (sum  < tmp_target)
					{
						start++;
						while (start < end && nums[start-1] == nums[start])start++;
					}
					else if (sum > tmp_target)
					{
						end--;
						while (start < end && nums[end+1] == nums[end])end--;
					}
					else
					{
						vector<int> tv = {nums[i], nums[j], nums[start], nums[end]};
						ret.push_back(tv);
						start++;
						while (start < end && nums[start - 1] == nums[start])start++;
						end--;
						while (start < end && nums[end + 1] == nums[end])end--;
					}
				}
			}
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	vector<vector<int>> ret;
	//int target = 0;
	int i = 0, j = 0;
	//vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	//vector<int> nums = { -3,-2,-1,0,0,1,2,3 };
	//vector<int> nums = { 1,-2,-5,-4,-3,3,3,5 };
	//int target = -11;

	//vector<int> nums = { -1,-5,-5,-3,2,5,0,4 };
	//int target = -7;

	vector<int> nums = { -1,0,-5,-2,-2,-4,0,1,-2 };
	int target = -9;

	ret = sln.fourSum(nums, target);

	cout << "[" << endl;
	for (i = 0; i < ret.size(); i++)
	{
		cout << "    [";
		for (j = 0; j < ret[i].size(); j++)
		{
			if (j > 0) cout << ",";
			cout << ret[i][j];
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;


	return 0;
}





