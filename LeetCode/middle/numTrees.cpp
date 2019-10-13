
#include "../common.h"

// https://leetcode-cn.com/problems/unique-binary-search-trees/
// AC

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
	int* m_ans;
	int solve(int low, int high)
	{
		int ret = 0;
		int left = 0;
		int right = 0;
		int i = 0, j = 0, k = 0;

		if (low >= high) return 1;
		if (m_ans[high - low + 1] > 0) return m_ans[high - low + 1];

		for (i = low; i <= high; i++)
		{
			left = solve(low, i - 1);
			right = solve(i+1, high);

			ret += left * right;
		}

		m_ans[high - low + 1] = ret;
		return ret;
	}
public:
	int numTrees(int n)
	{
		int i = 0, j = 0;
		vector<int> nums;
		m_ans = new int[n + 3];
		memset(m_ans, 0, n + 3);
		m_ans[1] = 1;
		m_ans[2] = 2;
		int ret = 0;

		if (n <= 0)
		{
			return 0;
		}

		ret = solve(1, n);
		
		delete[] m_ans;
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





