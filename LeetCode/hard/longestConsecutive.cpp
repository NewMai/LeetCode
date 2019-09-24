
#include "../common.h"

// https://leetcode-cn.com/problems/longest-consecutive-sequence/
// AC after reference

class Solution 
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int ret = 0;
		int i = 0, j = 0;
		int size = nums.size();
		int t = 0;
		int curN = 0;
		int curL = 0;
		int max = 0;
		unordered_map<int, int> mp;
		unordered_map<int, int>::iterator itmp;
	

		for (i = 0; i < size; i++)
		{
			mp[nums[i]] = 1;
		}

		for (i = 0; i < size; i++)
		{
			curN = nums[i];
			curL = 0;
			
			do
			{
				itmp = mp.end();
				curN++;
				curL++;
				//t = mp[curN];
				itmp = mp.find(curN);

			} while (itmp != mp.end());

			if (curL > max) max = curL;
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
	//vector<int> nums = { 1,4,8,3,7 };
	vector<int> nums = { 100,4,200,1,3,2 };

	ret = sln.longestConsecutive(nums);
	cout << ret << endl;


	return 0;
}





