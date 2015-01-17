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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flag=true;
        mlr(p,q);
        return flag;
    }
private:
	bool flag;
	void mlr(TreeNode*p,TreeNode*q)
	{
		if(flag==false)
			return;
		if(p&&q&&p->val==q->val)
		{
			mlr(p->left,q->left);
			mlr(p->right,q->right);
		}
		else
		{
			if(!p&&!q)
				return;
			else
				flag=false;
		}
	}
};