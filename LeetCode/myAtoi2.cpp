
#include "common.h"

// https://leetcode-cn.com/problems/string-to-integer-atoi/
// AC

class Solution 
{
public:

	string removePrefixAndPostfix(string str)
	{
		int i = 0;

		i = str.find_first_not_of(' ');
		if (i != string::npos)
		{
			str = str.substr(i);
		}

		i = str.find_last_not_of(' ');
		if (i != string::npos)
		{
			str = str.substr(0, i+1);
		}

		return str;
	}
	string removePrefixZero(string str)
	{
		int i = 0;

		i = str.find_first_not_of('0');

		if (i == string::npos)
		{
			return "";
		}
		else
		{
			str = str.substr(i);
		}

		return str;
	}
	int getValidLength(string str)
	{
		int i = 0;
		int ret = 0;
		
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] < '0' || str[i] > '9') break;
		}

		ret = i;
		return ret;
	}
	int myAtoi(string str) 
	{
		int ret = 0;
		int i = 0, j = 0;
		int sym = 1;
		int len = 0;
		long long value = 0;

		str = removePrefixAndPostfix(str);
		if (str.length() == 0)
		{
			return 0;
		}

		if (str[0] == '+')
		{
			str = str.substr(1);
			sym = 1;
		}
		else if (str[0] == '-')
		{
			str = str.substr(1);
			sym = -1;
		}

		//str = removePrefixAndPostfix(str);
		//if (str.length() == 0)
		//{
		//	return 0;
		//}

		str = removePrefixZero(str);
		len = getValidLength(str);
		if (len < str.length())
		{
			str = str.substr(0, len);
		}
		if (str.length() == 0)
		{
			return 0;
		}

		if (str.length() > 10)
		{
			if (sym == 1) return INT_MAX;
			else return INT_MIN;
		}

		value = atoll(str.c_str());
		value *= sym;

		if (value > INT_MAX)
		{
			ret = INT_MAX;
		}
		else if (value < INT_MIN)
		{
			ret = INT_MIN;
		}
		else
		{
			ret = value;
		}

		return ret;
	}
};


int main1()
{
	Solution sln;
	int ret = 0;
	string str = "     -42";
	str = "-91283472332";
	str = "    0000000000000   ";
	str = "-   234";
	ret = sln.myAtoi(str);
	cout << ret << endl;

	return 0;
}



