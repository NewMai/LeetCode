
#include "../common.h"

// https://leetcode-cn.com/problems/trapping-rain-water/
// AC

class Solution 
{
public:

	int getCapacity(vector<int>& height, int low, int high)
	{
		int ret = 0;
		int i = 0;

		for (i = low; i < high; i++)
		{
			ret += height[low] - height[i];
		}

		return ret;
	}

	int solve(vector<int>& height)
	{
		int ret = 0;
		int i = 0, j = 0, k = 0;
		int elem = 0;
		int min = 0;
		int cap = 0;
		int max = 0;
		int max_i = 0;
		int size = height.size();


		if (size < 2) return 0;

		for (i = 0; i < size; )
		{
			elem = height[i];
			if (elem == 0)
			{
				i += 1;
				continue;
			}

			// Find next maximum element
			min = elem;
			max = 0;
			max_i = i;
			for (j = i + 1; j < size; j++)
			{
				if (height[j] >= elem) break;

				if (min != elem)
				{
					if (height[j] > max)
					{
						max = height[j];
						max_i = j;
					}
				}

				if (min > height[j]) min = height[j];
			}
			if (j == (i + 1))
			{
				i += 1;
				continue;
			}

			if (j == size )
			{
				if (max_i == i)
				{
					i += 1;
					continue;
				}
				else
				{
					j = max_i;

					// Get capacity
					for (k = i + 1; k < j; k++)
					{
						if(height[j] > height[k])
							cap += height[j] - height[k];
					}
					i = j;
					continue;
				}
			}

			// Get capacity
			for (k = i+1; k < j; k++)
			{
				cap += height[i] - height[k];
			}
			i = j;
		}

		ret = cap;
		return ret;
	}

	int trap(vector<int>& height)
	{
		int ret = 0;
		int i = 0, j = 0;

		ret = solve(height);

		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "test";
	//vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	//vector<int> height = { 4,2,3 };
	vector<int> height = { 5,4,1,2 };

	ret = sln.trap(height);
	cout << ret << endl;


	return 0;
}





