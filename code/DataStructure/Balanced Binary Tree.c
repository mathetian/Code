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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     	flag=true;
     	if(!root) return flag;
     	int height=0;
     	isF(root,height);
     	return flag;  	
    }
private:
	bool flag;
	void isF(TreeNode *node,int&height)
	{
		if(flag==false)
			return;
		if(!node->left&&!node->right)
		{
			height=1;
		}
		else if(node->left&&node->right)
		{
			int l=0,r=0;
			isF(node->left,l);isF(node->right,r);
			if(abs(l-r)>1)
				flag=false;
			else
				height=max(l,r)+1;
		}
		else if(node->left)
		{
			if(node->left->left||node->left->right)
				flag=false;
			height=2;
		}
		else if(node->right)
		{
			if(node->right->left||node->right->right)
				flag=false;
			height=2;
		}
	}
};