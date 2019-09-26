
#include "../common.h"

// https://leetcode-cn.com/problems/multiply-strings/
// AC

class Solution 
{
public:
	string multiply(string num1, string num2)
	{
		string ret ;
		int i = 0, j = 0, k = 0;
		int s1 = num1.size();
		int s2 = num2.size();
		int s3 = s1 + s2 + 1;
		int carry = 0, r = 0;

		vector<int> n1(s1, 0);
		vector<int> n2(s2, 0);
		vector<int> n3(s3, 0);

		if (s1 == 1 && num1[0] == '0') return "0";
		if (s2 == 1 && num2[0] == '0') return "0";
		if (s1 < 1 || s2 < 1) return "0";

		for (i = 0; i < s1; i++)
		{
			n1[i] = num1[s1 - i - 1] - '0';
		}
		for (i = 0; i < s2; i++)
		{
			n2[i] = num2[s2 - i - 1] - '0';
		}

		for (i = 0; i < s1; i++)
		{
			carry = 0;
			for (j = 0; j < s2; j++)
			{
				carry = n2[j] * n1[i];
				k = i + j;
				while (carry > 0)
				{
					carry += n3[k];
					n3[k++] = carry % 10;
					carry /= 10;
				}
			}
		}

		for (i = 0; i < s3; i++)
		{
			ret += n3[s3 - i - 1] + '0';
		}

		for (i = 0; i < s3; i++)
		{
			if (ret[i] != '0') break;
		}
		if (i > 0 && i < s3)
		{
			ret = ret.substr(i);
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	string ret ;
	string num1 = "123";
	string num2 = "456";
	


	ret = sln.multiply(num1, num2);
	cout << ret.c_str() << endl;


	return 0;
}





