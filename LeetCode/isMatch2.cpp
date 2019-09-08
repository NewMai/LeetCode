
#include "common.h"

// https://leetcode-cn.com/problems/regular-expression-matching/
// AC

class Solution 
{
public:
	bool isMatch(string s, string p)
	{
		int i = 0;
		bool ret = false;
		bool bt = false;
		int len1 = s.length();
		int len2 = p.length();

		if (len1 == 0 && len2 == 0) return true;
		else if (len1 == 0)
		{
			if (len2 % 2 == 1)return false;
			else
			{
				for (i = 1; i < len2; i+= 2)
				{
					if (p[i] != '*') return false;
				}
				return true;
			}
		}
		else if (len2 == 0) return false;

		if (p[0] == '.')
		{
			if (len2 > 1)
			{
				if (p[1] == '*')
				{
					for (i = 0 ; i <= len1; i++)
					{
						bt = isMatch(s.substr(i), p.substr(2));
						if (bt == true) return true;
					}
					return false;
				}
				else
				{
					bt = isMatch(s.substr(1), p.substr(1));
					return bt;
				}
			}
			else // len2 == 1
			{
				bt = isMatch(s.substr(1), "");
				return bt;
			}
		}
		else if (p[0] == '*')
		{
			// This case is processed by "p[1] == '*'"
			return false;
		}
		else // p[0] != '.' || p[0] != '*'
		{
			if (len2 == 1)
			{
				if (len1 != 1) return false;
				else return s[0] == p[0];
			}
			else
			{
				if (p[1] == '*')
				{
					bt = isMatch(s, p.substr(2));
					if (bt == true) return true;

					if (s[0] == p[0])
					{
						for (i = 1; i < len1; i++)
						{
							if (s[0] == s[i])
							{
								bt = isMatch(s.substr(i), p.substr(2));
								if (bt == true) return true;
							}
							else
							{
								break;
							}
						}
						bt = isMatch(s.substr(i), p.substr(2));
						return bt;
					}
					else
					{
						bt = isMatch(s, p.substr(2));
						return bt;
					}
					
				}
				else
				{
					if (s[0] != p[0]) return false;
					else return isMatch(s.substr(1), p.substr(1));
				}
			}
			
		}

		return ret;
	}
};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "aab";
	string ptn = "c*a*b";

	str = "mississippi";
	ptn = "mis*is*p*.";

	str = "ab";
	ptn = ".*";

	str = "a";
	ptn = "ab*";

	str = "bbbba";
	ptn = ".*a*a";

	ret = sln.isMatch(str, ptn);
	if(ret == true) cout << "true" << endl;
	else  cout << "false" << endl;

	return 0;
}



