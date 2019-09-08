
#include "common.h"

// https://leetcode-cn.com/problems/two-sum/submissions/
class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		map<int, int> m;
		vector<int> ret;
		int key = 0, value = 0;
		int i = 1;

		for(i = 0; i < nums.size(); i++)
		{
			value = nums[i];
			if (m.find(value) != m.end())
			{
				// Find it
				ret.insert(ret.begin(), m[value]);
				ret.insert(ret.begin() + 1, i);
				break;
			}
			key = target - value;
			m[key] = i;
			
		}
		return ret;
	}

};

// AC
int main1()
{
	//int src[10] = { 2, 7, 11, 15 };
	//int target = 9;

	int src[10] = { -3,4,3,90 };
	int target = 0;

	Solution s;
	vector<int> data(src, src+4);
	vector<int> ret;

	ret = s.twoSum(data, target);
	printf("[%d,%d]\n", ret[0], ret[1]);

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



