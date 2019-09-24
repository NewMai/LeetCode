
#include "../common.h"

// https://leetcode-cn.com/problems/powx-n/
// AC

class Solution 
{
public:
	double myPow(double x, int n)
	{
		double ret = 0;
		int i = 0, j = 0;
		long long m = n;
		int n1, n2;

		if (m < 0)
		{
			x = 1 / x;
			m = -m;
		}

		if (m == 0) return 1;
		if (m == 1) return x;
		
		n1 = m / 2;
		ret = myPow(x, n1);
		ret *= ret;
		if (m % 2 > 0)
		{
			ret *= x;
		}
		return ret;
	}

};


int main()
{
	Solution sln;
	double ret = 0;
	double x = 12.45;
	int n = 3;

	ret = sln.myPow(x, n);
	cout << ret << endl;


	return 0;
}





