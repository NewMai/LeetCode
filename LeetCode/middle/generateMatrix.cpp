
#include "../common.h"

// https://leetcode-cn.com/problems/spiral-matrix-ii/submissions/
// AC

class Solution 
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> ret(n, vector<int>(n, 0));
		int i = 0, j = 0;
		int off = 0;
		int loc = 1;
		int off2 = 0;
		int n2 = n * n;

		while (loc <= n2)
		{
			// Top
			for (i = off; i < n - off; i++)
			{
				ret[off][i] = loc++;
				//printVV2(ret);
			}
			//if (loc > n2) break;

			off2 = i - 1;

			// Right
			for (i = off + 1; i < n - off; i++)
			{				
				ret[i][off2] = loc++;
				//printVV2(ret);
			}

			off2 = i - 1;

			// Button
			for (i = off2 - 1; i >= off; i--)
			{
				ret[off2][i] = loc++;
				//printVV2(ret);
			}

			// Left
			for (i = off2 - 1; i > off; i--)
			{
				ret[i][off] = loc++;
				//printVV2(ret);
			}

			off += 1;
		}
			
		return ret;
	}

};


int main()
{
	Solution sln;
	int i = 0, j = 0;
	vector<vector<int>> ret ;
	string str = "test";
	int nums = 9;


	ret = sln.generateMatrix(nums);
	
	printVV1(ret);


	return 0;
}





