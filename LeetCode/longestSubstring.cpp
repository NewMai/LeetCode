
#include"common.h"


// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int ret = 0;
		int i = 0, j = 0;
		int prei = 0;
		int len = 0;
		int tlen = 0;

		if (s.length() <= 1)
		{
			return s.length();
		}

		for (i = 1; i < s.length(); i++)
		{
			for (j = prei; j < i; j++)
			{
				if (s[i] == s[j])
				{
					if (len < (i - prei))
					{
						len = i - prei;
					}
					prei = j + 1;
					break;
				}
			}
		}
		if (len < (i - prei))
		{
			len = i - prei;
		}

		if (prei == 0)
		{
			ret = s.length();
		}
		else
		{
			ret = len;
		}

		return ret;
	}
};

// AC
int main3()
{
	//string src = "abcabcbb";
	//string src = "bbbbbb";
	string src = "pwwkew";
	int ret;
	Solution s;

	ret = s.lengthOfLongestSubstring(src);
	printf("%d\n", ret);

	return 0;
}


