
#include "../common.h"

// https://leetcode-cn.com/problems/merge-k-sorted-lists/
// AC

// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * genList(vector<int> arrs)
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
ListNode * appendList(ListNode *a, ListNode *b)
{
	ListNode * p = NULL;
	ListNode * q = NULL;

	if (a == NULL) return b;
	if (b == NULL) return a;

	p = a;
	while (p->next)p = p->next;

	while (b)
	{
		p->next = new ListNode(b->val);
		p = p->next;
		b = b->next;
	}

	return a;
}


class Solution 
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode* ret = NULL;
		int i = 0, j = 0;
		ListNode* head = NULL;
		ListNode* p = NULL;
		ListNode* q = NULL;

		i = 0;
		while(i < lists.size())
		{
			if (lists[i] == NULL)
			{
				lists.erase(lists.begin() + i, lists.begin() + i + 1);
			}
			else
			{
				i += 1;
			}
		}
		if (lists.size() == 0) return NULL;
		if (lists.size() == 1) return lists[0];


		while (lists.size() > 1)
		{
			q = lists[0];
			j = 0;
			for (i = 1; i < lists.size(); i++)
			{
				if (q->val > lists[i]->val)
				{
					q = lists[i];
					j = i;
				}
			}

			lists[j] = q->next;
			q->next = NULL;

			if (head == NULL) 
			{
				head = q; 
				p = head;
			}
			else
			{
				p->next = q;
				p = p->next;
			}

			if (lists[j] == NULL)
			{
				lists.erase(lists.begin() + j, lists.begin() + j + 1);
			}
		}

		//ret = appendList(head, lists[0]);
		p->next = lists[0];
		ret = head;

		return ret;
	}

};


int main()
{
	Solution sln;
	ListNode* ret = NULL;
	ListNode* head = NULL;
	vector<ListNode*> lists;
	vector<int> nums1 = { 1,4,5 };
	vector<int> nums2 = { 1,3,4 };
	vector<int> nums3 = { 2,6 };

	head = genList(nums1);
	lists.push_back(head);

	head = genList(nums2);
	lists.push_back(head);

	head = genList(nums3);
	lists.push_back(head);

	ret = sln.mergeKLists(lists);
	while (ret)
	{
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << "NULL" << endl;


	return 0;
}





