
#include"common.h"




// https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution
{
public:
	int reverse(int x)
	{
		int ret = 0;
		int i = 0, j = 0, k = 0;
		bool isMinus = false;
		long long r1 = 0, r2 = x;  // 64 bit integer

		if (r2 < 0)
		{
			isMinus = true;
			r2 = abs(r2);
		}
		
		while (r2 != 0)
		{
			k = r2 % 10;
			r2 = r2 / 10;

			r1 = r1 * 10 + k;
		}

		if (isMinus)
		{
			r1 = 0 - r1;
		}

		if (r1 > INT_MAX) ret = 0;
		else if (r1 < INT_MIN) ret = 0;
		else ret = r1;

		return ret;
	}
};

// AC
int main6()
{
	int x = -123;
	x = 123;
	x = 1534236469;
	int ret = 0;
	Solution s;

	ret = s.reverse(x);
	cout << ret << endl;
	//printf("%s\n", ret.c_str());

	return 0;
}


