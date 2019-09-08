
#include "common.h"

// https://leetcode-cn.com/problems/container-with-most-water/
//

class Solution 
{
public:
	int maxArea(vector<int>& height)
	{
		int ret = 0;
		//vector<int> v(height.size(), 0);
		int i = 0, j = 0;
		int maxl = 0;
		int maxg = 0;
		int low = 0;
		int tmp = 0;

		for (i = 0; i < height.size(); i++)
		{
			maxl = 0;
			for (j = i + 1; j < height.size(); j++)
			{
				low = height[j] < height[i] ? height[j] : height[i];
				tmp = low * (j - i);
				maxl = maxl > tmp ? maxl : tmp;
			}
			if (maxl > maxg) maxg = maxl;
		}

		ret = maxg;
		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	vector<int> height = { 1,8,6,2,5,4,8,3,7 };


	ret = sln.maxArea(height);
	cout << ret << endl;


	return 0;
}


//
//int main()
//{
//	map<int, int> m;
//	static char src[0x10000];
//
//	int len = 0, tlen;
//	int sum = 0;
//	int key = 0, value = 0;
//	int i = 1, j = 0;
//
//	len = scanf("%s", src);
//	//gets(src, sizeof(src));
//	len = strlen(src);
//	scanf("%d", &sum);
//	src[len - 1] = 0;  // Remove "]"
//	len -= 1;
//
//	j = 0;
//	while (1)
//	{
//		sscanf(src + i, "%d", &value);
//		if (value <= sum)
//		{
//			if (m.find(value) != m.end())
//			{
//				// Find it
//				printf("[%d,%d]\n", m[value], j);
//				break;
//			}
//			key = sum - value;
//			m[key] = j++;
//		}
//		while (i < len && src[i] != ',') i++;
//		i += 1;
//		if (i >= len)
//		{
//			// End
//			break;
//		}
//	}
//
//	return 0;
//}



