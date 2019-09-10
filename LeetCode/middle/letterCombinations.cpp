
#include "../common.h"

// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// AC

class Solution 
{
	map<string, vector<string>> m_map;
public:
	Solution()
	{
		m_map = getMap();
	}
	vector<vector<string>> getDict()
	{
		vector<vector<string>> ret(10, vector<string>());
		int i = 0, j = 0;

		vector<string> v2 = {"a", "b", "c"};
		//ret.push_back(v2);
		ret[2] = v2;

		vector<string> v3 = { "d", "e", "f" };
		//ret.push_back(v3);
		ret[3] = v3;

		vector<string> v4 = { "g", "h", "i" };
		//ret.push_back(v4);
		ret[4] = v4;

		vector<string> v5 = { "j", "k", "l" };
		//ret.push_back(v5);
		ret[5] = v5;

		vector<string> v6 = { "m", "n", "o" };
		//ret.push_back(v6);
		ret[6] = v6;

		vector<string> v7 = { "p", "q", "r", "s" };
		//ret.push_back(v7);
		ret[7] = v7;

		vector<string> v8 = { "t", "u", "v" };
		//ret.push_back(v8);
		ret[8] = v8;

		vector<string> v9 = { "w", "x", "y", "z" };
		//ret.push_back(v9);
		ret[9] = v9;

		return ret;
	}
	map<string, vector<string>> getMap()
	{
		map<string, vector<string>> ret;
		int i = 0, j = 0;

		vector<string> v2 = { "a", "b", "c" };
		ret["2"] = v2;

		vector<string> v3 = { "d", "e", "f" };
		ret["3"] = v3;

		vector<string> v4 = { "g", "h", "i" };
		ret["4"] = v4;

		vector<string> v5 = { "j", "k", "l" };
		ret["5"] = v5;

		vector<string> v6 = { "m", "n", "o" };
		ret["6"] = v6;

		vector<string> v7 = { "p", "q", "r", "s" };
		ret["7"] = v7;

		vector<string> v8 = { "t", "u", "v" };
		ret["8"] = v8;

		vector<string> v9 = { "w", "x", "y", "z" };
		ret["9"] = v9;

		return ret;
	}
	
	vector<string> letterCombinations(string digits)
	{
		vector<string> ret;
		vector<string> tv;
		vector<string> tv_ret;
		string str = "";
		//vector<vector<string>> dict = getDict();
		int i = 0, j = 0;

		if (digits.length() == 0) return ret;
		if (digits.length() == 1) return m_map[digits];

		tv = m_map[digits.substr(0,1)];
		tv_ret = letterCombinations(digits.substr(1));
		for (i = 0; i < tv.size(); i++)
		{
			for (j = 0; j < tv_ret.size(); j++)
			{
				str = tv[i] + tv_ret[j];
				ret.push_back(str);
			}
		}

		return ret;
	}
};


int main()
{
	Solution sln;
	vector<string> ret = {};
	string str = "23";
	int i = 0;

	ret = sln.letterCombinations(str);
	
	cout << "[";
	for (i = 0; i < ret.size(); i++)
	{
		if (i > 0) cout << ",";
		cout << "\"" << ret[i].c_str() << "\"";
	}
	cout << "]" << endl;


	return 0;
}





