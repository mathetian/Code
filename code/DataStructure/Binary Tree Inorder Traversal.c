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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>rs;
        lmr(root,rs)
        return rs;
    }
private:
	void lmr(TreeNode*node,vector<int>&rs)
	{
		if(!node)
			return;
		if(node->left)
			lmr(node->left,rs);
		rs.push_back(node->val);
		if(node->right)
			lmr(node->right,rs);

	}
};