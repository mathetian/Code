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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(m==n)
            return head;
        ListNode*nHead=new ListNode(-1);
        nHead->next=head;
        ListNode*prev=nHead;ListNode*cur=nHead->next;
        for(int i=1;i<m;i++)
            prev=prev->next;
        cur=prev->next;
        ListNode*end=cur;
        for(int i=m;i<n;i++)
            end=end->next;
        end=end->next;
        prev->next=end;
        while(cur->next!=end)
        {
            ListNode*cur2=cur->next;
            cur->next=prev->next;
            prev->next=cur;
            cur=cur2;
        }
        ListNode*cur2=cur->next;
        cur->next=prev->next;
        prev->next=cur;
        cur=cur2;
        return nHead->next;
    }
};