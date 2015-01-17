/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag=true;int s,b;
        mlr(root,s,b);
        return flag;
    }
private:
	bool flag;
	void mlr(TreeNode*node,int&s,int&b)
	{
		if(!node||flag==false)
			return;
		if(!node->left&&!node->right)
		{
			s=b=node->val;
			return;
		}
		else
		{
			int ls,lb;int rs,rb;
			mlr(node->left,ls,lb);mlr(node->right,rs,rb);
			if(flag==false)
				return;
			if(node->left&&node->right)
			{
				if(node->val<=lb||node->val>=rs)
				{
					flag=false;
					return;
				}
				s=ls;b=rb;
			}
			else if(node->left)
			{
				if(node->val<=lb)
				{
					flag=false;
					return;
				}
				s=ls;b=node->val;
			}
			else
			{	
				if(node->val>=rs)
				{
					flag=false;
					return;
				}
				s=node->val;b=rb;
			}
		}
	}
};