
#include "../common.h"
#include<numeric>

// https://leetcode-cn.com/problems/3sum/
// AC after reference the other answer

class Solution 
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ret;
		set<vector<int>> myset;
		int i = 0, j = 0;
		int start = 0, end = 0;
		int sum = 0;
		int pre = -1, cur = 0;

		if (nums.size() < 3) return ret;
		
		//sum = accumulate(nums.begin(), nums.end(), 0);
		//if (sum == 0) return 0;

		//for (i = 0; i < nums.size(); i++)
		//{
		//	if (nums[i] != 0) break;
		//}
		//if (i == nums.size())
		//{
		//	vector<int> v = { 0, 0, 0 };
		//	ret.push_back(v);
		//	return ret;
		//}

		sort(nums.begin(), nums.end());
		//nums.erase(unique(nums.begin(), nums.end()), nums.end());

		for (i = 0; i < nums.size(); i++)
		{
			start = i + 1; 
			end = nums.size() - 1;
			while (start < end)
			{
				if (start > i + 1 && nums[start] == nums[start - 1])
				{
					start++;
					continue;
				}
				if (end < nums.size() - 1 && nums[end] == nums[end + 1])
				{
					end--;
					continue;
				}

				sum = nums[i] + nums[start] + nums[end];
		
				if (sum < 0) start++;
				else if (sum > 0) end--;
				else
				{
					vector<int> v = { nums[i], nums[start], nums[end] };
					pre = myset.size();
					myset.insert(v);
					cur = myset.size();
					if(cur > pre) ret.push_back(v);
					start++;
					end--;
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
	int i = 0, j = 0;
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };


	ret = sln.threeSum(nums);

	cout << "[" << endl;
	for (i = 0; i < ret.size(); i++)
	{
		cout << "\t[";
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





