
#include "../common.h"

// https://leetcode-cn.com/problems/generate-parentheses/
// 

class Solution 
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> ret;
		vector<string> tmp;
		int i = 0, j = 0;
		int preSize = 0;
		string str;
		set<string> s;

		if (n == 0) return ret;
		if (n == 1)
		{
			ret.push_back("()");
			return ret;
		}

		tmp = generateParenthesis(n - 1);
		for (i = 0; i < tmp.size(); i++)
		{
			str = "()" + tmp[i];
			//ret.push_back(str);

			preSize = s.size();
			s.insert(str);
			if(s.size() > preSize) ret.push_back(str);

			str = tmp[i] + "()";
			//ret.push_back(str);
			preSize = s.size();
			s.insert(str);
			if (s.size() > preSize) ret.push_back(str);

			str = "(" + tmp[i] + ")";
			//ret.push_back(str);
			preSize = s.size();
			s.insert(str);
			if (s.size() > preSize) ret.push_back(str);
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	vector<string>  ret;
	int n = 3;
	int i = 0;

	ret = sln.generateParenthesis(n);
	
	for (i = 0; i < ret.size(); i++)
	{
		cout << ret[i].c_str() << endl;
	}
	


	return 0;
}





