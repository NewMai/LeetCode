
#include "../common.h"

// https://leetcode-cn.com/problems/interleaving-string/
// AC

class Solution 
{
public:
	bool isInterleaveInternal(string& s1, int i, string& s2, int j, string& s3, int k)
	{
		bool ret = 0;
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();

		while (k < len3)
		{
			if (s1[i] == s2[j])
			{
				if (s1[i] == s3[k])
				{
					ret = isInterleaveInternal(s1, i + 1, s2, j, s3, k + 1);
					if (ret) return true;
					ret = isInterleaveInternal(s1, i, s2, j + 1, s3, k + 1);
					return ret;
				}
				else return false;
			}
			else if (s3[k] == s1[i])
			{
				k++;
				i++;
			}
			else if (s3[k] == s2[j])
			{
				k++;
				j++;
			}
			else return false;
		}

		return true;
	}
	bool isInterleave(string s1, string s2, string s3)
	{
		int i = 0, j = 0, k = 0;
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();

		if ((len1 + len2) != len3) return false;
		return isInterleaveInternal(s1, i, s2, j, s3, k);
	}
};


int main()
{
	Solution sln;
	int ret = 0;
	string str1 = "aabcc";
	string str2 = "dbbca";
	string str3 = "aadbbcbcac";

	str1 = "aacaac";
	str2 = "aacaaeaac";
	str3 = "aacaaeaaeaacaac";


	ret = sln.isInterleave(str1, str2, str3);
	cout << ret << endl;


	return 0;
}





