
#include "../common.h"

// https://leetcode-cn.com/problems/longest-common-prefix/
// AC

class Solution 
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string ret = "";
		string match = "";
		int i = 0, j = 0;

		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];

		match = strs[0];
		for (i = 1; i < strs.size(); i++)
		{
			if (match.size() == 0) break;

			for (j = 0; j < match.size() && j < strs[i].size(); j++)
			{
				if (match[j] != strs[i][j]) break;
			}
			if (j < match.size())
			{
				match = match.substr(0, j);
			}
		}

		ret = match;
		return ret;
	}

};


int main()
{
	Solution sln;
	string ret = "";
	vector<string> strs; // ("flower", "flow", "flight");
	
	strs.push_back("");
	//strs.push_back("flower");
	//strs.push_back("flow");
	//strs.push_back("flight");

	ret = sln.longestCommonPrefix(strs);
	cout << ret.c_str() << endl;


	return 0;
}





