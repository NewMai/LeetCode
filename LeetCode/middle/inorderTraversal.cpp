
#include "../common.h"

// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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

TreeNode* CreateTree(vector<int>& nums)
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

class Solution 
{
public:
	vector<int> inorderTraversal_rec(TreeNode* root)
	{
		vector<int> ret;
		vector<int> left;
		vector<int> right;
		int i = 0, j = 0;

		if (!root)
		{
			return ret;
		}

		if (root->left)
		{
			left = inorderTraversal(root->left);
		}
		if (root->right)
		{
			right = inorderTraversal(root->right);
		}

		ret.assign(left.begin(), left.end());
		ret.push_back(root->val);
		for (i = 0; i < right.size(); i++)
		{
			ret.push_back(right[i]);
		}

		return ret;
	}
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ret;
		vector<TreeNode*> nStack;
		TreeNode* p = root;
		int i = 0, j = 0;


		if (!p)
		{
			return ret;
		}

		do
		{
			while (p)
			{
				nStack.push_back(p);
				p = p->left;
			}

			p = nStack.back();
			nStack.pop_back();

			ret.push_back(p->val);
			p = p->right;

		}while (nStack.empty() == false || p);

		return ret;
	}

};


int main()
{
	Solution sln;
	vector<int> ret;
	//vector<int> nums = { 1,NULL_NODE,2,3 };
	vector<int> nums = { 1, 5, 6, 7,2,NULL_NODE,NULL_NODE,3,9,};
	TreeNode* root;

	root = CreateTree(nums);
	ret = sln.inorderTraversal(root);
	printV(ret);


	return 0;
}





