
#include "../common.h"

// https://leetcode-cn.com/problems/valid-parentheses/
// AC

class Solution 
{
public:
	bool isValid(string s)
	{
		int ret = 0;
		int i = 0, j = 0;
		stack<char> S;
		char c;

		if (s.size() == 0) return true;

		for (i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
				case '(':
				case '[':
				case '{':
				{
					S.push(s[i]);
					break;
				}
				case ')':
				{
					if(S.size() == 0) return false;
					c = S.top();
					S.pop();
					if (c != '(') return false;
					break;
				}
				case ']':
				{
					if (S.size() == 0) return false;
					c = S.top();
					S.pop();
					if (c != '[') return false;
					break;
				}
				case '}':
				{
					if (S.size() == 0) return false;
					c = S.top();
					S.pop();
					if (c != '{') return false;
					break;
				}
			}
		}
		if (S.size() != 0) return false;

		return true;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "()";


	ret = sln.isValid(str);
	cout << ret << endl;


	return 0;
}





