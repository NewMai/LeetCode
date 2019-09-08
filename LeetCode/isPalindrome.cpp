
#include "common.h"

// https://leetcode-cn.com/problems/palindrome-number/
// 

class Solution 
{
public:
	bool isPalindrome(int x) 
	{
		bool ret = false;
		long long y = 0, w = x;
		char buf[100] = "";
		string s1, s2;

		if (x < 0) return false;
		if (x == 0) return true;

		sprintf(buf, "%d", x);
		s1 = buf;
		s2 = s1;
		reverse(s2.begin(), s2.end());
		return s1 == s2;

		//while (w != 0)
		//{
		//	y *= 10;
		//	y += w % 10;
		//	w /= 10;
		//}

		//if (y == x) return true;

		//return false;
	}

};


int main3()
{
	Solution sln;
	int ret = 0;
	int x = 121;



	ret = sln.isPalindrome(x);
	if(ret == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}



