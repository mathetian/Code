/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //exist head
      if(!head||!head->next)
        	return head;
   		ListNode*head2=new ListNode(0);//less
      ListNode*head3=new ListNode(0);//big
      ListNode*prev2=head2;
      ListNode*prev3=head3;

      ListNode*cur=head;
      
      while(cur)
      {
        ListNode*cur2=cur->next;
        if(cur->val>=x)
        {
          prev3->next=cur;
          prev3=cur;
        }
        else
        {
          prev2->next=cur;
          prev2=cur;
        }
        cur->next=NULL;
        cur=cur2;
      }
      ListNode*end=prev2;
      prev2->next=head3->next;
      return head2->next;
    }
};

int main()
{
  ListNode*n1=new ListNode(1);
  ListNode*n2=new ListNode(2);
  n1->next=n2;
  Solution solution;
  solution.partition(n1,0);
  return 0;
}