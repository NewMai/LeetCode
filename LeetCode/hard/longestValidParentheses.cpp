
#include "../common.h"

// https://leetcode-cn.com/problems/longest-valid-parentheses/
// AC

class Solution 
{
public:
	int longestValidParentheses(string s)
	{
		int ret = 0;
		int i = 0, j = 0, k = 0;
		int size = s.size();
		char c = 0;
		struct D
		{
			int len;
			int end;
			D() : len(0), end(0) {}
		};
		vector<D> dp(size + 2);

		if (size < 2) return 0;

		for (i = size - 2; i >= 0; i--)
		{
			c = s[i];
			if (c == '(')
			{
				j = dp[i + 1].end + 1;
				if (s[i + 1] == ')')
				{
					k = i + 2;
					if (k < size && dp[k].len > 0)
					{
						dp[i].len = dp[k].len + 2;
						dp[i].end = dp[k].end;
						//if ((k + 1) < size && dp[k + 1].len > 0)
						//{
						//	dp[i].len += dp[k + 1].len;
						//	dp[i].end = dp[k + 1].end;
						//}
					}
					else
					{
						dp[i].len = 2;
						dp[i].end = i + 1;
					}
				}
				else if (dp[i + 1].len > 0 && j < size && s[j] == ')')
				{
					dp[i].len = dp[i + 1].len + 2;
					dp[i].end = j;
					if ((j + 1) < size && dp[j + 1].len > 0)
					{
						dp[i].len += dp[j + 1].len;
						dp[i].end = dp[j + 1].end;
					}
				}
			}
		}

		for (i = 0; i < size; i++)
		{
			if (ret < dp[i].len) ret = dp[i].len;
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = ")()())";
	//str = "(()())";
	str = "((()))())";
	str = "()(())";

	ret = sln.longestValidParentheses(str);
	cout << ret << endl;


	return 0;
}





