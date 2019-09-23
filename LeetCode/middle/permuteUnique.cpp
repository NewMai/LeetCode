
#include "../common.h"

// https://leetcode-cn.com/problems/permutations-ii/
// AC

class Solution 
{
	vector<vector<int>> m_ans;
public:


	int solve(vector<int> cur_ans, vector<int> nums)
	{
		int i = 0, j = 0;
		int ret = 0;
		vector<int> ta;
		vector<int> tn;


		if (0 == nums.size())
		{
			m_ans.push_back(cur_ans);
		}

		for (i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			ta.assign(cur_ans.begin(), cur_ans.end());
			ta.push_back(nums[i]);

			tn.assign(nums.begin(), nums.end());
			tn.erase(tn.begin() + i, tn.begin() + i + 1);

			solve(ta, tn);
		}

		return ret;
	}


	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> ret;
		int i = 0, j = 0;
		vector<int> ta;
		vector<int> tn(nums);

		sort(tn.begin(), tn.end());

		solve(ta, tn);

		ret.assign(m_ans.begin(), m_ans.end());

		return ret;
	}

};


int main()
{
	Solution sln;
	vector<vector<int>> ret;
	string str = "test";
	vector<int> nums = { 1,1,2};
	int i = 0, j = 0;

	ret = sln.permuteUnique(nums);
	
	
	cout << "[" << endl;
	for (i = 0; i < ret.size(); i++)
	{
		cout << "    [";
		for (j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << ",";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;


	return 0;
}





