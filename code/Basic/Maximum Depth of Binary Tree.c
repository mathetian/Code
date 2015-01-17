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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return mx(root);
    }
private:
	int mx(TreeNode*node)
	{
		if(!node)
			return 0;
		return 1+max(mx(node->left),mx(node->right));
	}
};