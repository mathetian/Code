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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() functions
        return subSum(root,0);
    }
private:
	int subSum(TreeNode*root,int value)
	{
		if(root==NULL)
			return value;
		else if(root->right&&root->left)
			return subSum(root->left,10*value+root->val)+subSum(root->right,10*value+root->val);
		else if(root->right)
			return subSum(root->right,10*value+root->val);
		else if(root->left)
			return subSum(root->left,10*value+root->val);
		else
			return value*10+root->val;
	}
};