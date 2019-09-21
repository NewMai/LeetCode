
#include "../common.h"

// https://leetcode-cn.com/problems/
// 

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* genList(vector<int> arrs)
{
	ListNode * head = NULL;
	ListNode *p = NULL;
	int i = 0;

	if (arrs.size() == 0) return head;

	p = new ListNode(arrs[0]);
	head = p;

	for (i = 1; i < arrs.size(); i++)
	{
		p->next = new ListNode(arrs[i]);
		p = p->next;
	}

	return head;
}

void printList(ListNode* head)
{
	cout << "Values of the list:" << endl;
	while (head)
	{
		if (head->next)
		{
			cout << head->val << "->";
		}
		else 
		{
			cout << head->val;
		}

		head = head->next;
	}
	//cout << "NULL" << endl;
	cout << endl;
}


class Solution 
{
public:
	ListNode* ReverseList(ListNode* head)
	{
		int i = 0, j = 0;
		ListNode* ret = NULL;
		ListNode* p = NULL;
		ListNode* q = NULL;
		
		ret = new ListNode(0);

		// Reverse a node by heading-insert method
		p = head;
		while (p)
		{
			q = p;
			p = p->next;

			// Isolate this node
			q->next = NULL;

			q->next = ret->next;
			ret->next = q;
		}
		
		// Delete a head node
		p = ret->next;
		delete ret;
		ret = p;

		return ret;
	}

};


int main()
{
	Solution sln;
	ListNode* ret = NULL;
	ListNode* head = NULL;
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };


	head = genList(nums);
	ret = sln.ReverseList(head);
	printList(ret);


	return 0;
}





