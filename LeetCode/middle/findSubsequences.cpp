
#include "../common.h"

// https://leetcode-cn.com/problems/increasing-subsequences/
// 

class Solution 
{
	vector<vector<int>> m_ans;
	vector<int> m_nums;
	set<int> m_nums_set;

public:

	vector<vector<int>> solveDFS(int cur)
	{
		vector<vector<int>> ret;
		vector<vector<int>> tmp;
		vector<int> t;
		int i = 0, j = 0, k  = 0;
		int size = m_nums.size();
		int step = 2;

		
		return ret;
	}

	vector<vector<int>> findSubsequences(vector<int>& nums)
	{
		vector<vector<int>> ret;
		int i = 0, j = 0;

		if (nums.size() < 2)
		{
			return ret;
		}

		m_nums.assign(nums.begin(), nums.end());
		sort(m_nums.begin(), m_nums.end());

		ret = solve(0);

		//ret.assign(m_ans.begin(), m_ans.end());

		return ret;
	}

};


int main()
{
	Solution sln;
	vector<vector<int>> ret;
	string str = "test";
	//vector<int> nums = { 4,6,7,7 };
	vector<int> nums = { 1,3,5,7 };

	ret = sln.findSubsequences(nums);
	printVV1(ret);


	return 0;
}





