
#include"common.h"


// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		double ret = 0;
		int i = 0, j = 0;
		bool isOdd = false;
		int total = nums1.size() + nums2.size();
		int midIdx = total / 2;
		int needToDel = 0;

		if (total & 1 == 1)
		{
			isOdd = true;
			midIdx += 1;
			needToDel = total - 1;
		}
		else
		{
			needToDel = total - 2;
		}

		if (total == 0)
		{
			return 0;  // Impossible
		}
		else if (nums1.size() == 0)
		{
			if (isOdd)
			{
				return 0.0 + nums2[total / 2];
			}
			else
			{
				return (0.0 + nums2[total / 2 - 1] + nums2[total / 2]) / 2;
			}
		}
		else if (nums2.size() == 0)
		{
			if (isOdd)
			{
				return 0.0 + nums1[total / 2];
			}
			else
			{
				return (0.0 + nums1[total / 2 - 1] + nums1[total / 2]) / 2;
			}
		}
		// else

		while (needToDel > 0)
		{
			// Delete the lowest one
			if (nums1.size() > 0 && nums2.size() > 0)
			{
				if (nums1[0] < nums2[0]) 
				{
					nums1.erase(nums1.begin());  
				}
				else
				{
					nums2.erase(nums2.begin());
				}
			}
			else if(nums1.size() > 0)
			{
				nums1.erase(nums1.begin());
			}
			else
			{
				nums2.erase(nums2.begin());
			}

			// Delete the largest one
			if (nums1.size() > 0 && nums2.size() > 0)
			{
				if (nums1[nums1.size() - 1] > nums2[nums2.size() - 1])
				{
					nums1.erase(nums1.end() - 1);
				}
				else
				{
					nums2.erase(nums2.end() - 1);
				}
			}
			else if (nums1.size() > 0)
			{
				nums1.erase(nums1.end() - 1);
			}
			else
			{
				nums2.erase(nums2.end() - 1);
			}

			needToDel -= 2;
		}

		if (isOdd)
		{
			if(nums1.size() > 0) ret = nums1[0];
			else ret = nums2[0];
		}
		else
		{
			if (nums1.size() > 0 && nums2.size() > 0) ret = (0.0 + nums1[0] + nums2[0]) / 2;
			else if (nums1.size() > 0) ret = (0.0 + nums1[0] + nums1[1]) / 2;
			else ret = (0.0 + nums2[0] + nums2[1]) / 2;
		}

		return ret;
	}
};

// AC
int main4()
{
	//vector<int> nums1 = { 1, 3 };
	//vector<int> nums2 = { 2, };
	//vector<int> nums1 = { 1, 2 };
	//vector<int> nums2 = { 3, 4 };
	vector<int> nums1 = {  };
	vector<int> nums2 = { 2, 3 };

	double ret;
	Solution s;

	ret = s.findMedianSortedArrays(nums1, nums2);
	cout << ret << endl;
	//printf("%f\n", ret);

	return 0;
}


