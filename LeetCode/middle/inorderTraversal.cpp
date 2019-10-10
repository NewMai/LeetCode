
#include "../common.h"

// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// AC



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution 
{
public:
	vector<int> inorderTraversal(TreeNode* root)
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

};


int main()
{
	Solution sln;
	vector<int> ret;
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };
	TreeNode* root;

	ret = sln.inorderTraversal(root);
	printV(ret);


	return 0;
}





