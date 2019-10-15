
#include "../common.h"

// https://leetcode-cn.com/problems/recover-binary-search-tree/
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
	vector<TreeNode*> m_nodes;
	vector<TreeNode*> m_pNodes;  // Parent node
	int m_firstInvalidNode;
	int m_secondInvalidNode;
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

		if (!root) return ;
		
		m_firstInvalidNode = -1;
		m_secondInvalidNode = -1;

		// Root node default as a right child of psudo super node
		solve(root, NULL);
		for (i = 0; i < m_nodes.size(); i++)
		{
			if ((i + 1 < m_nodes.size()) && m_nodes[i]->val >= m_nodes[i + 1]->val)
			{
				if (m_firstInvalidNode < 0) m_firstInvalidNode = i;
				else m_secondInvalidNode = i;
			}
		}

		if (m_firstInvalidNode < 0 && m_secondInvalidNode < 0) return;
		if (m_firstInvalidNode > 0 && m_secondInvalidNode > 0)
		{
			// Exchange value
			value = m_nodes[m_secondInvalidNode]->val;
			m_nodes[m_secondInvalidNode]->val = m_nodes[m_firstInvalidNode]->val;
			m_nodes[m_firstInvalidNode]->val = value;
		}

		// Impossible execute to here
	}

};


int main()
{
	Solution sln;
	vector<int> ret;
	vector<int> nums = { 1, 3,NULL_NODE,NULL_NODE,2, };
	//vector<int> nums = { 3, 1, 4, NULL_NODE,NULL_NODE,2, };
	TreeNode* root;

	root = createTree(nums);
	puts("Before recover [In-order treval]:");
	inorderPrintTree(root);
	sln.recoverTree(root);
	puts("After recover [In-order treval]:");
	inorderPrintTree(root);
	

	return 0;
}





