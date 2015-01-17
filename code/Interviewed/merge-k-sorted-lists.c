/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /**Can have better solution**/
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode*head=new ListNode(0);
        ListNode*prev=head;
        vector<int>rs(lists.size(),0);
        vector<ListNode*>cur(lists.size(),NULL);
        for(int i=0;i<lists.size();i++)
        	cur[i]=lists[i];
        ListNode*cur2=NULL;
        while(1)
        {
        	int i=0;cur2=NULL;int j=0;
        	for(i=0;i<lists.size();i++)
        	{
        		if(cur2==NULL)
        		{
        			if(cur[i])
        			{
        				j=i;cur2=cur[i];
        			}
        		}
        		else
        		{
        			if(cur[i]&&cur[i]->val<cur2->val)
        			{
        				cur2=cur[i];j=i;
        			}
        		}
        	}
        	if(!cur2)
        		return head->next;
        	else
        	{
        		prev->next=cur2;
                prev=cur2;
        		cur[j]=cur[j]->next;
        	}
        }
        return head->next=NULL;
    }
};