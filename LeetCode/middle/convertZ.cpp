
#include"common.h"



// https://leetcode-cn.com/problems/zigzag-conversion/
class Solution
{
public:
	string convert(string s, int numRows)
	{
		string ret;
		int i = 0, j = 0, k = 0;
		int maxCol = s.length() / numRows;
		char* buf = NULL;
		int colOffset = 0;    // Control column offset
		bool isFinished = false;

		if (numRows <= 1) return s;

		maxCol = maxCol * (numRows - 1) + 2;
		buf = new char[maxCol * numRows];
		memset(buf, 0, maxCol * numRows);

		// Fill
		while(1)
		{
			// Fill a column form top to down
			for (j = 0; j < numRows; j++)
			{
				buf[colOffset + maxCol * j] = s[i++];
				if (i >= s.length())
				{
					isFinished = true;
					break;
				}
			}

			if (isFinished) break;

			colOffset += 1;

			// Fill Z form dowm to top
			for (j = numRows - 2; j > 0; j--)
			{
				buf[colOffset + maxCol * j] = s[i++];
				colOffset += 1;
				if (i >= s.length())
				{
					isFinished = true;
					break;
				}
			}

			if (isFinished) break;
		}

		// Collect
		for (i = 0; i < numRows; i++)
		{
			for (j = 0; j < maxCol; j++)
			{
				if (buf[i * maxCol + j] != 0)
				{
					ret.append(1, buf[i * maxCol + j]);
				}
			}
		}

		delete[] buf;
		return ret;
	}

};



// AC
int main8()
{
	string str = "LEETCODEISHIRING";
	int numRows = 3;

	str = "LEETCODEISHIRING";
	numRows = 4;

	string ret = "";
	Solution s;

	ret = s.convert(str, numRows);
	printf("%s\n", ret.c_str());

	return 0;
}


