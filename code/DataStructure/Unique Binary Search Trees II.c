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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       	return dfs(1,n);
    }
private:
	vector<TreeNode*> dfs(int low,int high)
	{
		vector<TreeNode*>trees;
		if(low>high)
		{
			trees.push_back(NULL);
			return trees;
		}

		for(int i=low;i<=high;i++)
		{
	   		vector<TreeNode*>lT=dfs(low,i-1);
	   		vector<TreeNode*>rT=dfs(i+1,high);
	   		for(int j=0;j<lT.size();j++)
	   		{
	   			for(int k=0;k<rT.size();k++)
	   			{
	   				TreeNode*node=new TreeNode(i);
	   				node->left=lT[j];
	   				node->right=rT[k];
	   				trees.push_back(node);
	   			}
	   		}
		}
		return trees;
	}
};