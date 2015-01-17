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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return reverseKGroup(head,2);
    }

private:
	 ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       ListNode*nHead=new ListNode(0);
       nHead->next=head;
       ListNode*prev=nHead;
       ListNode*cur=head;
       int num=0;
       while(cur)
       {
	      num=0;
	      prev->next=NULL;ListNode*cur3=cur;
	      while(num<k&&cur)
	      {
	      	ListNode*cur2=cur->next;
	      	cur->next=prev->next;
	      	prev->next=cur;
	      	cur=cur2;
	      	num++;
	      }
	      if(num<k)
	      {
	      	cur=prev->next;prev->next=NULL;
	      	while(cur)
	      	{
	      		ListNode*cur2=cur->next;
	      		cur->next=prev->next;
	      		prev->next=cur;
	      		cur=cur2;
	      	}
	      	break;
	      }
	      else
	      {
	      	prev=cur3;
	      	cur3->next=cur;
	      }
       }
       return nHead->next;
    }
};