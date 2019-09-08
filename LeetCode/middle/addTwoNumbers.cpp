
#include"common.h"



// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// https://leetcode-cn.com/problems/add-two-numbers/
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *ret = NULL, *p, *cur;
		int carry = 0, t;
		int i = 0, j = 0, k = 0;

		if (l1->next == NULL && l1->val == 0)
		{
			return l2;
		}
		if (l2->next == NULL && l2->val == 0)
		{
			return l1;
		}
		
		while (l1 != NULL && l2 != NULL)
		{
			p = new ListNode(0);
			t = l1->val + l2->val + carry;
			p->val = t % 10;
			carry = t / 10;

			if (ret == NULL)
			{
				ret = p;
				cur = p;
			}
			else
			{
				cur->next = p;
				cur = p;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL)
		{
			p = new ListNode(0);
			t = l1->val + carry;
			p->val = t % 10;
			carry = t / 10;

			if (ret == NULL)
			{
				ret = p;
				cur = p;
			}
			else
			{
				cur->next = p;
				cur = p;
			}
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			p = new ListNode(0);
			t = l2->val + carry;
			p->val = t % 10;
			carry = t / 10;

			if (ret == NULL)
			{
				ret = p;
				cur = p;
			}
			else
			{
				cur->next = p;
				cur = p;
			}
			l2 = l2->next;
		}
		while (carry > 0)
		{
			p = new ListNode(0);
			p->val = carry % 10;
			carry = carry / 10;
			cur->next = p;
			cur = p;
		}

		return ret;
	}

	void addNodeToEnd(ListNode** head, int x)
	{
		ListNode* p = *head;
		if (*head == NULL)
		{
			*head = new ListNode(x);
		}
		else
		{
			while (p->next) p = p->next;
			p->next = new ListNode(x);
		}
	}
};



// AC
int main7()
{
	ListNode* a = NULL, *b = NULL;
	ListNode* ret = 0, *p;
	Solution s;

	s.addNodeToEnd(&a, 2);
	s.addNodeToEnd(&a, 4);
	s.addNodeToEnd(&a, 3);

	s.addNodeToEnd(&b, 5);
	s.addNodeToEnd(&b, 6);
	s.addNodeToEnd(&b, 4);

	ret = s.addTwoNumbers(a, b);

	p = ret;
	while (p)
	{
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << endl;

	// Delete

	return 0;
}


