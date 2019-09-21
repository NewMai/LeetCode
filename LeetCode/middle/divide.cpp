
#include "../common.h"

// https://leetcode-cn.com/problems/divide-two-integers/
// 

class Solution 
{
	
public:


	uint32_t myPow(uint32_t a, uint32_t p)
	{
		// Example: 
		//		Input: a = 123, p = 2 
		//		Output: 12300
		uint32_t m_bases[15] = {
			1, 10, 100, 1000, 10000, 100000, 1000000,
			10000000, 100000000, 1000000000, UINT_MAX, };
		char buf[15] = "";
		uint32_t len = 0;
		uint32_t i = 0;
		uint32_t t = 0;
		uint32_t ret = 0;
		int s = 0;

		if (p == 0) return a;

		sprintf(buf, "%d", a);
		len = strlen(buf);
		if (len == 10) return UINT_MAX;

		for (i = 0; i < len; i++)
		{
			s = buf[i] - '0';
			while (s > 0)
			{
				t = ret;
				ret += m_bases[len - i + p - 1];
				s -= 1;
				if (t < ret)
				{
					return UINT_MAX;
				}
			}
		}

		return ret;
	}

	int divide(int dividend, int divisor)
	{
		int ret = 0;
		int f = 1;
		uint32_t a = 0;
		uint32_t b = 0;
		uint32_t c = 0;
	

		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		if (divisor == 1) return dividend;

		if (dividend < 0)
		{
			f = -1;
			if (dividend == INT_MIN)
			{
				a = INT_MAX + 1;
			}
			else
			{
				a = 0 - dividend;
			}
		}
		else a = dividend;
		if (divisor < 0)
		{
			if (divisor == INT_MIN)
			{
				b = INT_MAX + 1;
			}
			else
			{
				b = 0 - divisor;
			}
			if (f == -1) f = 1;
			else f = -1;
		}
		else b = divisor;

		ret = myDiv(a, b);  // ret = a / b;
	
		if (f != 1)
		{
			ret = 0 - ret;
		}

		return ret;
	}

	int myDiv(uint32_t dividend, uint32_t divisor)
	{
		uint32_t ret = 0;
		uint32_t i = 0, j = 0;
		uint32_t base = 0;
		uint32_t t = 0;
		uint32_t q = 0;
		uint32_t oflag = 0;
		uint32_t remainder = 0;

		if (dividend < divisor) return 0;
		if (dividend == divisor) return 1;
		
		base = 1;
		t = divisor;
		i = 1;
		while (t < dividend )
		{
			if (i >= 10) break;      // Overflow
			t = myPow(divisor, i++); // t = t * (10^i);
		}

		j = i - 2;
		if (i >= 10 && t < dividend) j = i - 1;
		
		t = myPow(divisor, j);
		q = t;
		i = 0;
		oflag = 0;
		while (q < dividend)
		{
			if (UINT_MAX - t < q)
			{
				oflag = 1;
				break;
			}
			i++;
			q = q + t;
		}
		
		if (oflag == 0) q = q - t;
		if (i == 0) i = 1;

		remainder = dividend - q;
		q = myPow(i, j);
		ret = q + myDiv(remainder, divisor);

		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	int dividend = 7;
	int divisor = -3;
	dividend = -2147483648;
	divisor = -1;

	//dividend = 2147483647;
	//divisor = 1;
	//divisor = 2;
	//divisor = 3;

	//dividend = 2147483647;
	//divisor = 1004914333;

	//dividend = -2147483648;
	//divisor = -445115814;

	ret = sln.divide(dividend, divisor);
	//ret = sln.myPow(123, 1);
	cout << ret << endl;


	return 0;
}





