
#include "../common.h"

// https://leetcode-cn.com/problems/unique-binary-search-trees/
// 

#define NULL_NODE (INT_MIN)

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& nums)
{
	TreeNode* root = NULL;
	queue<TreeNode*> nq;
	TreeNode* p = NULL, *q = NULL;
	int i = 0;

	if (nums.size() == 0) return root;

	i = 0;
	p = new TreeNode(nums[i]);
	root = p;
	nq.push(p);
	i++;

	while (nq.empty() == false)
	{
		p = nq.front();
		nq.pop();

		if (i < nums.size() && nums[i] != NULL_NODE)
		{
			q = new TreeNode(nums[i]);
			p->left = q;
			nq.push(q);
		}
		i++;

		if (i < nums.size() && nums[i] != NULL_NODE)
		{
			q = new TreeNode(nums[i]);
			p->right = q;
			nq.push(q);
		}
		i++;
	}

	return root;
}

void inorderPrintTree(TreeNode* root)
{
	if (!root) return;

	if (root->left)
	{
		inorderPrintTree(root->left);
	}

	printf("%-3d,", root->val);

	if (root->right)
	{
		inorderPrintTree(root->right);
	}

}

class Solution 
{
	int solve(vector<int>& nums, int low, int high)
	{
		int ret = 0;
		int left = 0;
		int right = 0;
		int i = 0, j = 0, k = 0;

		if (low > high) return 0;
		if (low == high)
		{
			return 1;
		}

		for (i = low; i <= high; i++)
		{
			left = solve(nums, low, i - 1);
			right = solve(nums, i+1, high);

			if (left == 0)
			{
				if (right == 0)
				{
					ret += 1;
				}
				else
				{
					ret += right;
				}
			}
			else // left.size() > 0
			{
				if (right == 0)
				{
					ret += left;
				}
				else
				{
					ret += left * right;
				}
				
			}
		}

		return ret;
	}
public:
	int numTrees(int n)
	{
		int i = 0, j = 0;
		vector<int> nums;
		int ret = 0;

		if (n <= 0)
		{
			return 0;
		}

		for (i = 1; i <= n; i++)
		{
			nums.push_back(i);
		}

		ret = solve(nums, 0, n - 1);
		
		return ret;
	}

};


int main()
{
	Solution sln;
	int ret;
	int nums = 3;
	int i = 0;

	ret = sln.numTrees(nums);
	printf("ret = %d\n", ret);

	return 0;
}





