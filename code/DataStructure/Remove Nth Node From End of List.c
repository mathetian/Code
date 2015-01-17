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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode*nHead=new ListNode(0);
        nHead->next=head;
        ListNode*cur=nHead;
        int i=1;
        while(i<=n)
        {
        	cur=cur->next;i++;
        }
        ListNode*cur2=nHead;
        while(cur&&cur->next)
        {
        	cur2=cur2->next;
        	cur=cur->next;
        }
        cur2->next=cur2->next->next;
        return nHead->next;
    }
};