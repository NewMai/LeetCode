
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
	vector<TreeNode*> solve(vector<int>& nums, int low, int high)
	{
		vector<TreeNode*> ret;
		vector<TreeNode*> left;
		vector<TreeNode*> right;
		TreeNode* p = NULL;
		int i = 0, j = 0, k = 0;

		if (low > high) return ret;
		if (low == high)
		{
			p = new TreeNode(nums[low]);
			ret.push_back(p);
			return ret;
		}

		for (i = low; i <= high; i++)
		{
			left = solve(nums, low, i - 1);
			right = solve(nums, i+1, high);

			if (left.size() == 0)
			{
				if (right.size() == 0)
				{
					p = new TreeNode(nums[i]);
					ret.push_back(p);
					p == NULL;
				}
				else
				{
					for (j = 0; j < right.size(); j++)
					{
						p = new TreeNode(nums[i]);
						ret.push_back(p);
						p->right = right[j];
						p == NULL;
					}
				}
			}
			else // left.size() > 0
			{
				if (right.size() == 0)
				{
					for (j = 0; j < left.size(); j++)
					{
						p = new TreeNode(nums[i]);
						ret.push_back(p);
						p->left = left[j];
						p == NULL;
					}
				}
				else
				{
					for (j = 0; j < left.size(); j++)
					{
						for (k = 0; k < right.size(); k++)
						{
							p = new TreeNode(nums[i]);
							ret.push_back(p);
							p->left = left[j];
							p->right = right[k];
							p == NULL;
						}
					}
				}
				
			}
		}

		return ret;
	}
public:
	int numTrees(int n)
	{
		vector<TreeNode*> ret;
		vector<TreeNode*> left;
		vector<TreeNode*> right;
		int i = 0, j = 0;
		vector<int> nums;

		if (n <= 0)
		{
			return 0;
		}

		for (i = 1; i <= n; i++)
		{
			nums.push_back(i);
		}

		ret = solve(nums, 0, n - 1);
		
		return ret.size();
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





