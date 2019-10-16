
#include "../common.h"

// https://leetcode-cn.com/problems/recover-binary-search-tree/
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
	vector<TreeNode*> m_nodes;
	vector<TreeNode*> m_pNodes;  // Parent node
public:
	void solve(TreeNode* root, TreeNode* pRoot)
	{

		if (!root) return;

		// Visit left child
		solve(root->left, root);

		// Visit itself
		m_nodes.push_back(root);
		m_pNodes.push_back(pRoot);
	
		// Visit right child
		solve(root->right, root);
	}

	void recoverTree(TreeNode* root)
	{
		int i = 0, j = 0;
		TreeNode *left, *right;
		int value = 0;
		int minV = 0;
		int minI = 0;

		if (!root) return ;
		
		minI = -1;

		// Root node default as a right child of psudo super node
		solve(root, NULL);
		for (i = 0; i < m_nodes.size(); i++)
		{
			if ((i + 1 < m_nodes.size()) && m_nodes[i]->val >= m_nodes[i + 1]->val)
			{
				minI = i;
				break;
			}
		}

		if (minI < 0) return;
	
		// Exchange value
		value = m_nodes[minI]->val;
		minV = value;
		j = -1;
		for (i = minI + 1; i < m_nodes.size(); i++)
		{
			if (minV > m_nodes[i]->val)
			{
				j = i;
				minV = m_nodes[i]->val;
			}
		}
		if (j >= 0)
		{
			m_nodes[j]->val = value;
			m_nodes[minI]->val = minV;
		}
		
	}

};


int main()
{
	Solution sln;
	vector<int> ret;
	//vector<int> nums = { 1, 3,NULL_NODE,NULL_NODE,2, };
	vector<int> nums = { 3, 1, 4, NULL_NODE,NULL_NODE,2, };
	TreeNode* root;

	root = createTree(nums);
	puts("Before recover [In-order treval]:");
	inorderPrintTree(root);
	puts("");

	sln.recoverTree(root);

	puts("After recover [In-order treval]:");
	inorderPrintTree(root);
	puts("");

	return 0;
}





