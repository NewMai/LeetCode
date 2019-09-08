
#include"common.h"


// https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution
{
public:
	string longestPalindrome(string s)
	{
		string ret = "";
		int i = 0, j = 0, k = 0;

		if (s.length() <= 1)
		{
			return s;
		}
		if (s.length() == 2)
		{
			if (s[0] == s[1]) return s;
			else return s.substr(0, 1);
		}
		ret = s.substr(0, 1);

		// s.length() >= 3
		for (i = 1; i < s.length(); i++)
		{
			if (s[i] == s[i - 1])   // First cases: "...bb..."
			{
				j = i - 2;
				k = i + 1;
				while (j >= 0 && k < s.length() && s[j] == s[k])
				{
					j--;
					k++;
				}
				if (ret.length() < (k - j - 1)) ret = s.substr(j + 1, k - j - 1);
			}
		
			if (s[i - 1] == s[i + 1])  // Second cases: "...aba..."
			{
				j = i - 2;
				k = i + 2;
				while (j >= 0 && k < s.length() && s[j] == s[k])
				{
					j--;
					k++;
				}
				if (ret.length() < (k - j - 1)) ret = s.substr(j + 1, k - j - 1);
			}
		}

		return ret;
	}
};

// AC
int main5()
{
	string str = "babad";
	string ret = "";
	Solution s;

	ret = s.longestPalindrome(str);
	//cout << ret << endl;
	printf("%s\n", ret.c_str());

	return 0;
}


