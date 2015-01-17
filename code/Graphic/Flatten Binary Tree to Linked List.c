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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*> rs;
        mlr(root,rs);
        for(int i=0;i<rs.size();i++)
        {
        	rs[i]->left=NULL;
        	if(i==rs.size()-1)
        		rs[i]->right=NULL;
        	else
        		rs[i]->right=rs[i+1];
        }
    }
private:
	void mlr(TreeNode*node,vector<TreeNode*>&rs)
	{
		if(!node)
			return;
		rs.push_back(node);
		mlr(node->left,rs);mlr(node->right,rs);
	}
};