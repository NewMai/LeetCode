
#include "../common.h"

// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
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

class Solution 
{
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode* ret = NULL;
		ListNode* retEnd = NULL;
		ListNode* tmpHead = NULL;
		ListNode* tmpEnd = NULL;

		ListNode* p = NULL;
		ListNode* q = NULL;
		ListNode* preq = NULL;
		ListNode* cur = NULL;
		int i = 0, j = 0;
		bool isEnd = false;

		if (head == NULL) return head;
		if (k < 2) return head;
		tmpHead = new ListNode(0);
		
		while (true)
		{
			p = head;
			if (p == NULL) break;
			isEnd = false;
			q = p;
			preq = NULL;
			i = 0;

			// Get k nodes
			while (q && i < k)
			{
				i++;
				preq = q;
				q = q->next;
			}
			if (i < k)
			{
				// There is no enough node
				if (ret == NULL) ret = p;
				else retEnd->next = p;

				break;
			}

			if (q)
			{
				head = q;
				preq->next = NULL;
			}
			else
			{
				// There is no additional node at the end
				isEnd = true;
			}
			
			// Reverse a tmep list with k elements
			tmpHead->next = NULL;
			tmpEnd = p;
			while (p)
			{
				q = p;
				p = p->next;

				// Isolate this node
				q->next = NULL;

				// Reverse insert method
				q->next = tmpHead->next;
				tmpHead->next = q;
			}

			// Concatenate two lists
			if (ret == NULL)
			{
				ret = tmpHead->next;
				tmpHead->next = NULL;
				retEnd = tmpEnd;
			}
			else
			{
				retEnd->next = tmpHead->next;
				tmpHead->next = NULL;
				retEnd = tmpEnd;
			}

			if (isEnd) break;
		}

		return ret;
	}

};


int main()
{
	Solution sln;
	ListNode* ret = NULL;
	ListNode* head = NULL;
	int k = 2;
	vector<int> nums = { 1,2,3,4,5 };

	head = genList(nums);
	ret = sln.reverseKGroup(head, k);
	
	while (ret)
	{
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << "NULL" << endl;



	return 0;
}





