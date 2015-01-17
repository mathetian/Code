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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode*nHead=new ListNode(0);
        nHead->next=head;
        int n=0;ListNode*cur=head;
        while(cur)
        {
        	n++;cur=cur->next;
        }
        if(n==0)
        	return head;
        k=k%n;
        if(k==0)
        	return head;
       k=n-k;//k: 1 to n-1
       int m=1;
       cur=nHead;
       while(m<=k)
       {
       		cur=cur->next;
       		m++;
       }
       ListNode*cur2=cur->next;
       cur->next=NULL;
       ListNode*cur3=head;
       nHead->next=cur2;
       while(cur2->next)
			cur2=cur2->next;
		cur2->next=cur3;
		return nHead->next;
    }
};