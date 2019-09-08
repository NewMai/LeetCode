
#include "common.h"

// https://leetcode-cn.com/problems/3sum/
class Solution 
{
public:

	vector<vector<int>> threeSum(vector<int>& nums)
	{
		char buf[100] = {0};
		set<string> st;
		
		vector<vector<int>> ret;
		int size = 0;
		int i = 0, j = 0, k = 0;
		int a, b, c, t;
		int oldsize = 0;
		int low, high, mid;

		size = nums.size();
		sort(nums.begin(), nums.end(), less<int>());

		for(i = 0; i < size; i++)
		{
			a = nums[i];
			if (a > 0) break;
			
			low = i + 1;
			high = size - 1;
			while (low < high)
			{
				b = nums[low];
				c = nums[high];
				t = a + b + c;
				if (t < 0) low += 1;
				else if (t > 0) high -= 1;
				else 
				{
					vector<int> tv;
					tv.push_back(a);
					tv.push_back(nums[low]);
					tv.push_back(nums[high]);
					ret.push_back(tv);
					low += 1;
					high -= 1;
				}
			}
		}
		set<vector<int>> ts(ret.begin(), ret.end());
		vector<vector<int>> ret2(ts.begin(), ts.end());
		return ret2;

	}

};


int main2()
{
	//int src[10] = {-1, 0, 1, 2, -1, -4};
	int src[10] = { 0,0,0,0,0,0, };
	//int src[10] = { 0,0 };
	int i = 0, j = 0;
	Solution s;
	vector<int> data(src, src+6);
	vector<vector<int>> ret;
	vector<int> v;

	ret = s.threeSum(data);

	for (i = 0; i < ret.size(); i++)
	{
		for (j = 0; j < ret[i].size(); j++)
		{
			printf("%d,", ret[i][j]);
		}
		puts("");
		//printf("[%d,%d,%d]\n", ret[i][0], ret[i][1], ret[i][2]);
	}
	
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



