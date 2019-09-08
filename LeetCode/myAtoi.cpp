
#include"common.h"



// https://leetcode-cn.com/problems/string-to-integer-atoi/
class Solution
{
public:
	int myAtoi(string str)
	{
		int ret = 0;
		string tstr = "";
		long long x = 0;
		int i = 0;
		bool isMinus = false;

		tstr = purify(str);
		if (tstr.length() == 0) return ret;
		if (tstr[0] == '-')
		{
			//if (tstr.length() > 10) return INT_MIN;
			isMinus = true;
			i = 1;
		}
		else
		{
			//if (tstr.length() > 10) return INT_MAX;
			if(tstr[0] == '+') i = 1;
			else i = 0;
		}

		for (; i < tstr.length(); i++)
		{
			if (tstr[i] == ' ') continue; // Ignore white space
			x = x * 10;
			x = x + (tstr[i] - '0');

			if (x > INT_MAX || (-x) < INT_MIN) break;
		}

		if (isMinus)
		{
			x = 0 - x;
			if (x < INT_MIN) ret = INT_MIN;
			else ret = x;
		}
		else
		{
			if (x > INT_MAX) ret = INT_MAX;
			else ret = x;
		}

		return ret;
	}

	bool isDigit(char c)
	{
		if (c < '0' || c > '9') return false;
		return true;
	}

	string purify(string str)
	{
		string ret = "";
		int i = 0, j = 0;

		// Remove prefix white space
		while (i < str.length() && str[i] == ' ') i++;

		// Remove prefix zero
		while (i < str.length() && str[i] == '0') i++;

		if (i == str.length()) return ret;

		if (str[i] != '-' && str[i] != '+' && !isDigit(str[i])) return ret;

		j = i + 1;
		while (j < str.length() && (isDigit(str[j]) || str[j] == ' ') ) j++;

		ret = str.substr(i, j - i);

		return ret;
	}

};



// 
int main9()
{
	string str = "   -42";
	str = "242";
	str = "-91283472332";
	str = "+1";
	str = "  0000000000012345678";
	str = " - 000000000000001";
	int ret = 0;
	Solution s;

	ret = s.myAtoi(str);
	printf("%d\n", ret);

	return 0;
}


