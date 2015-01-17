/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 #include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return;
        vector<TreeLinkNode*> tQ1;
        vector<TreeLinkNode*> tQ2;
        tQ1.push_back(root);int flag=0;
        while(1)
        {
        	if(tQ1.size()==0)
        		break;
        	clearVector(tQ2);
            for(int i=0;i<tQ1.size()-1;i++)
                tQ1[i]->next=tQ1[i+1];
            if(tQ1.size()>=1)
            {
                 tQ1[tQ1.size()-1]->next=NULL;
            }
        	for(int i=0;i<tQ1.size();i++)
        	{
        		TreeLinkNode*tmp=tQ1[i];

        		if(tmp->left)
                {
                   tQ2.push_back(tmp->left);
                }
        		if(tmp->right)
                {
                    tQ2.push_back(tmp->right);
                }
        			
        	}
            tQ1=tQ2;
        }
    }
private:
    void clearVector(vector<TreeLinkNode*> &iVec)
    {
        int s=iVec.size();
        while(s-->0) iVec.pop_back();
    }
};

/*int print(TreeLinkNode *root)
{
   vector<TreeLinkNode*> tQ1;
   vector<TreeLinkNode*> tQ2;
   tQ1.push_back(root);
    while(1)
    {

    }
}
*/
int main()
{
    TreeLinkNode*node1=new TreeLinkNode(1);
    TreeLinkNode*node2=new TreeLinkNode(2);
    node1->right=node2;
    Solution solution;
    solution.connect(node1);
    return 0;
}