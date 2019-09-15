
#include "../common.h"

// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// AC

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution 
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		// AC
		ListNode* p = head, *pre = NULL;
		int i = 0, j = 0;

		if (head == NULL) return head;

		i = 0;
		while (p)
		{
			i += 1;
			p = p->next;
		}
		
		j = i - n;
		p = head;
		pre = NULL;
		for (i = 0; i < j; i++)
		{
			pre = p;
			p = p->next;
		}

		if (pre)
		{
			// Normal cases
			pre->next = p->next;
		}
		else
		{
			// Delete the first one
			head = p->next;
		}

		return head;
	}

};

ListNode* AddNode(ListNode* head, int x)
{
	ListNode* p = head;

	if (head == NULL)
	{
		p = new ListNode(x);
		return p;
	}

	while (p->next)
	{
		p = p->next;
	}

	p->next = new ListNode(x);

	return head;
}

int main()
{
	Solution sln;
	int n = 2;
	ListNode* ret = NULL;
	ListNode* head = NULL;
	int i = 0;


	for (i = 1; i < 6; i++)
	{
		head = AddNode(head, i);
	}

	ret = sln.removeNthFromEnd(head, n);
	
	while (ret)
	{
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << "NULL" << endl;


	return 0;
}





