
#include "../common.h"

// https://leetcode-cn.com/problems/increasing-subsequences/
// 

class Solution 
{
	vector<vector<int>> m_ans;
	vector<int> m_nums;

public:

	vector<vector<int>> solve(int cur)
	{
		vector<vector<int>> ret;
		vector<vector<int>> tmp;
		vector<int> t;
		int i = 0, j = 0, k  = 0;
		int size = m_nums.size();
		int step = 2;

		if (cur == size - 2)
		{
			t.push_back(m_nums[cur]);
			t.push_back(m_nums[cur+1]);
			ret.push_back(t);
			return ret;
		}

		tmp = solve(cur + 1);

		// Copy from previous result
		for (i = 0; i < tmp.size(); i++)
		{
			ret.push_back(tmp[i]);
		}

		// New form of two numbers
		if (m_nums[cur] != m_nums[cur + 1])
		{
			for (i = cur + 1; i < size; i++)
			{
				if (m_nums[i] == m_nums[i - 1]) continue;

				t.push_back(m_nums[cur]);
				t.push_back(m_nums[i]);
				ret.push_back(t);
				t.clear();
			}
		}

		// Add current number and with previous result
		for (i = 0; i < tmp.size(); i++)
		{
			if (tmp[i].size() <= 2) continue; 

			// Delete one number from the return set
			for (j = 1; j < tmp[i].size(); j++)  
			{
				//if (tmp[i][j] == m_nums[cur]) continue;
				if (j > 0 && tmp[i][j] == tmp[i][j - 1]) continue;
				t.clear();
				t.push_back(m_nums[cur]);

				for (k = 0; k < tmp[i].size(); k++)
				{
					if (k == j) continue; // Delete tmp[i][j] element
					if (k > 0 && tmp[i][k] == tmp[i][k - 1])
					{
						t.clear();
						break;
					}
					t.push_back(tmp[i][k]);
				}
				ret.push_back(t);
				t.clear();
			}
		}

		// Add current element to the previous result
		for (i = 0; i < tmp.size(); i++)
		{
			t.clear();
			t.push_back(m_nums[cur]);
			for (j = 0; j < tmp[i].size(); j++)
			{
				t.push_back(tmp[i][j]);
			}
			ret.push_back(t);
			t.clear();
		}


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





