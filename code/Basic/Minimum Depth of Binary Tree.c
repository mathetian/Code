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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        a=0x3fffffff;
        if(!root)
        	return 0;
        mlr(root,0);
        return a;
    }
private:
	int a;
	void mlr(TreeNode*node,int b)
	{
		b=b+1;
		if(b>=a)
			return;
		if(!node->left&&!node->right)
			a=min(a,b);
		else
		{
			if(node->left)
				mlr(node->left,b);
			if(node->right)
				mlr(node->right,b);
		}
	}
};