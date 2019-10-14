
#include "../common.h"

// https://leetcode-cn.com/problems/validate-binary-search-tree/
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
public:
	bool solve(TreeNode* root, int64_t minValue, int64_t maxValue)
	{
		bool ret = 0;

		if (!root) return true;
		if (root->val <= minValue) return false;
		if (root->val >= maxValue) return false;


		ret = solve(root->left, minValue, root->val);
		if (ret == false) return false;

		ret = solve(root->right, root->val, maxValue);
	
		return ret;
	}
	bool isValidBST(TreeNode* root)
	{
		int64_t minValue, maxValue;
		bool ret = 0;

		minValue = LLONG_MIN;
		maxValue = LLONG_MAX;
		ret = solve(root, minValue, maxValue);

		return ret;
	}

};


int main()
{
	Solution sln;
	bool ret;
	vector<int> nums = { 2, 1, 3, };  // True
	//vector<int> nums = { 5,1,4,NULL_NODE,NULL_NODE,3,6, };  // False
	//vector<int> nums = { 5,3,10,1,4,6,12, };  // True
	//vector<int> nums = { 5,3,10,1,4,4,12, };  // True
	TreeNode* root;

	root = createTree(nums);
	ret = sln.isValidBST(root);
	//inorderPrintTree(root);
	printf("%d\n", ret);

	return 0;
}





