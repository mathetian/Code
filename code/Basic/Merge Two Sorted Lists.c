/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode*head=new ListNode(0);
        ListNode*cur=head;cur->next=NULL;
        while(l1&&l2)
        {
        	if(l1->val>l2->val)
        	{
        		cur->next=l2;
                cur=l2;
        		l2=l2->next;
                cur->next=NULL;
        	}
        	else
        	{
        		cur->next=l1;
                cur=l1;
        		l1=l1->next;
                cur->next=NULL;
        	}
        }
        while(l1)
        {
        	cur->next=l1;
            cur=l1;
        	l1=l1->next;
            cur->next=NULL;
        }
        while(l2)
        {
        	cur->next=l2;
             cur=l2;
        	l2=l2->next;
              cur->next=NULL;
        }
        return head->next;
    }
};