
#include "../common.h"

// https://leetcode-cn.com/problems/permutation-sequence/
// AC

class Solution 
{
	uint64_t m_nums[12];   // n <= 9
public:

	void getNums(int n)
	{
		int i = 0;

		m_nums[0] = 0;
		m_nums[1] = 1;
		for (i = 2; i <= n; i++)
		{
			m_nums[i] = m_nums[i - 1] * i;
		}
	}

	string solve(int k, vector<int> rem)
	{
		string ret ;
		int i = 0, j = 0;
		int num = 0;
		int e = 0;
		vector<int> r;
		string tmp ;
		char buf[10];

		if (rem.size() == 1)
		{
			sprintf(buf, "%d", rem[0]);
			ret = string(buf);
			return ret;
		}

		num = m_nums[rem.size() - 1];
		for (i = 0; i < rem.size(); i++)
		{
			r.assign(rem.begin(), rem.end());
			e = r[i];
			r.erase(r.begin() + i, r.begin() + i + 1);

			if (k > num)
			{
				k -= num;
			}
			else
			{
				tmp = solve(k, r);
				sprintf(buf, "%d", e);
				ret = string(buf) + tmp;
				break;
			}
		}

		return ret;
	}

	string getPermutation(int n, int k)
	{
		string ret;
		int i = 0, j = 0;
		int tmp = 0;
		vector<int> rem(n);

		getNums(n + 1);

		for (i = 0; i < n; i++)
		{
			rem[i] = i + 1;
		}
		ret = solve(k, rem);

		return ret;
	}

};


int main()
{
	Solution sln;
	string ret;
	int n = 3, k = 3;


	ret = sln.getPermutation(n, k);
	cout << ret.c_str() << endl;


	return 0;
}





