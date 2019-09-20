
#include "../common.h"

// https://leetcode-cn.com/problems/generate-parentheses/
// AC after reference

class Solution 
{
public:
	vector<string> generateParenthesis1(int n)
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
	vector<string> generateParenthesis(int n)
	{
		vector<string> ret;
		//vector<vector<string>> total(n+1, vector<string>());
		vector<vector<string>> total;
		vector<string> tmp;
		int i = 0, j = 0, k = 0;
		int a = 0, b = 0;
		string str;
		set<string> s;

		if (n == 0) return ret;
		if (n == 1)
		{
			ret.push_back("()");
			return ret;
		}

		tmp.push_back("");
		total.push_back(tmp);
		tmp.clear();
		tmp.push_back("()");
		total.push_back(tmp);
		for (i = 2; i <= n; i++)
		{
			tmp.clear();
			for (j = 0; j < i; j++)
			{
				k = i - j - 1;
				for (a = 0; a < total[j].size(); a++)
				{
					for (b = 0; b < total[k].size(); b++)
					{
						str = "(" + total[j][a] + ")" + total[k][b];
						tmp.push_back(str);
						//str = total[j][a] + "(" + total[k][b] + ")" ;
						//tmp.push_back(str);
					}
				}
			}
			total.push_back(tmp);
		}

		ret = total[n];
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





