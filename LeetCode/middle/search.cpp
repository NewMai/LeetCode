
#include "../common.h"

// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// AC

class Solution 
{
public:
	int search(vector<int>& nums, int target)
	{
		int ret = 0;
		int i = 0, j = 0;
		int left, right, mid;
		int size = nums.size();
		int e = 0;

		if (size == 0) return -1;


		left = 0;
		right = size - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			e = nums[mid];
			if (e == target)  return mid;
			if (nums[left] == target)  return left;
			if (nums[right] == target)  return right;

			if (e > nums[left] && (nums[left] > target || target > e))
			{
				left = mid + 1;  // Target in right part
				continue;
			}
			if (e < nums[right] && nums[right] > target && e < target)
			{
				left = mid + 1;  // Target in right part
				continue;
			}
			right = mid - 1;  // Target in left part
			
		}

		ret = -1;
		return ret;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	int target = 0;
	//vector<int> nums = { 4,5,6,7,0,1,2 };
	vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
	target = 8;

	ret = sln.search(nums, target);
	cout << ret << endl;


	return 0;
}





