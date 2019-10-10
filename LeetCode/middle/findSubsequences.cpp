
#include "../common.h"

// https://leetcode-cn.com/problems/increasing-subsequences/
// Can't AC

class Solution 
{
	vector<vector<int>> m_ans;
	vector<int> m_nums;
	vector<int> m_path;
	set<int> m_nums_set;

public:

	void solveDFS(int cur)
	{
		int i = 0, j = 0, k  = 0;
		int size = m_nums.size();
		int step = 2;
		int num = 0;
		int pre_num = INT_MIN;

		if (m_path.size() > 1)
		{
			m_ans.push_back(m_path);
		}
		if (m_path.size() > 0)
		{
			pre_num = m_path.back();
		}

		for (i = cur; i < size; i++)
		{
			//if (m_nums[i] < pre_num) continue;
			if (i > cur && m_nums[i] == m_nums[i - 1]) continue;
			m_path.push_back(m_nums[i]);
			solveDFS(i + 1);
			m_path.pop_back();
		}
		
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

		solveDFS(0);

		ret.assign(m_ans.begin(), m_ans.end());

		return ret;
	}

};


int main()
{
	Solution sln;
	vector<vector<int>> ret;
	string str = "test";
	//vector<int> nums = { 4,6,7,7 };
	//vector<int> nums = { 1,3,5,7 };
	vector<int> nums = { -8,28,68,-54,96,97,84,-32,8,-87,1,-7,-20,12,22 };

	ret = sln.findSubsequences(nums);
	printVV1(ret);
	printf("Total list length: %d\n", ret.size());

	return 0;
}





