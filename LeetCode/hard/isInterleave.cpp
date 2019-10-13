
#include "../common.h"

// https://leetcode-cn.com/problems/interleaving-string/
// 

class Solution 
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		bool ret = 0;
		int i = 0, j = 0, k = 0;

		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();

		if ((len1 + len2) != len3) return false;

		while (k < len3)
		{
			if (s1[i] == s2[j])
			{
				if (s1[i] == s3[k])
				{
					ret = isInterleave(s1.substr(i + 1), s2.substr(j), s3.substr(k + 1));
					if (ret) return true;
					ret = isInterleave(s1.substr(i), s2.substr(j + 1), s3.substr(k + 1));
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

};


int main()
{
	Solution sln;
	int ret = 0;
	string str1 = "aabcc";
	string str2 = "dbbca";
	string str3 = "aadbbcbcac";


	ret = sln.isInterleave(str1, str2, str3);
	cout << ret << endl;


	return 0;
}





