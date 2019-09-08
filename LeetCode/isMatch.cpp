
#include"common.h"



// https://leetcode-cn.com/problems/regular-expression-matching/
//

class Solution
{
public:

	bool isMatch(string s, string p)
	{
		bool ret = true;
		bool bt = false;
		string str = "";
		int i = 0, j = 0, k = 0;
		int curIdx = 0;

		if (s.length() == 0 && p.length() == 0) return true;
		else if (s.length() == 0)
		{
			for (i = 0; i < p.length(); i++)
			{
				if (p[i] != '*')
				{
					if (i + 1 == p.length()) return false;
					else if (p[i] != '*') return false;
				}
			}
		}
		else if (p.length() == 0) return false;
		
		// s.length() > 0 && p.length() > 0

		if (p[0] == '.')
		{
			if (p.length() == 1)
			{
				if (s.length() == 1) return true;
				else return false;
			}
			else
			{
				if (p[1] == '*')
				{
					bt = isMatch(s, p.substr(2));
					if (bt == true) return true;

					bt = isMatch(s.substr(1), p.substr(2));
					if (bt == true) return true;

					for (i = 1; i < s.length(); i++)
					{
						if (s[i] != s[i - 1]) return false;
						
						bt = isMatch(s.substr(i+1), p.substr(2));
						if (bt == true) return true;
					}
				}
				else
				{
					return isMatch(s.substr(1), p.substr(1));
				}
			}
		}
		else if (p[0] == '*')
		{

		}
		else // p[0]: a~z
		{

		}

		return ret;
	}

};



// 
int main()
{
	string s = "aa";
	string p = ".*";
	bool ret = false;
	Solution sln;

	ret = sln.isMatch(s, p);
	if (ret == true) cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}


