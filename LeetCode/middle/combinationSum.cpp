
#include "../common.h"

// https://leetcode-cn.com/problems/combination-sum/
// AC after reference

class Solution 
{
	vector<vector<int>> m_ans;
	vector<int> m_cand;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>>  ret;
		int i = 0, j = 0;
		vector<int> elems;

		m_cand.assign(candidates.begin(), candidates.end());
		sort(m_cand.begin(), m_cand.end());
		
		divide_conquer(elems, target, 0);

		ret.assign(m_ans.begin(), m_ans.end());
			
		return ret;
	}

	void divide_conquer(vector<int> elems, int target, int cur)
	{
		int i = 0;
		int e = 0;
		int ntarget = 0;

		if (target < 0) return;
		if (target == 0)
		{
			m_ans.push_back(elems);
			return;
		}

		for (i = cur; i < m_cand.size(); i++)
		{
			e = m_cand[i];
			ntarget = target - e;
			if (ntarget < 0) return;

			elems.push_back(e);
			if (ntarget == 0) m_ans.push_back(elems);
			else divide_conquer(elems, ntarget, i);
			elems.pop_back();
		}
	}

};


int main()
{
	Solution sln;
	vector<vector<int>> ret;
	int target = 7;
	vector<int> nums = { 2,3,6,7 };
	int i = 0, j = 0;

	ret = sln.combinationSum(nums, target);
	
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





