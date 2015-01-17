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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low=0,high=num.size()-1;
        if(high<low)
            return NULL;
        if(low==high)
        {
        	TreeNode*node=new TreeNode(num[0]);
        	return node;
        }
        int mid=(low+high)/2+(low+high)%2;
        TreeNode*node=new TreeNode(num[mid]);
        node->right=dfs(num,mid+1,high);
        node->left=dfs(num,low,mid-1);
    	return node;
    }
private:
	TreeNode*dfs(vector<int>&num,int low,int high)
	{
		if(high<low)
			return NULL;
		if(high==low)
		{
			TreeNode*node=new TreeNode(num[low]);
			return node;
		}
		int mid=(low+high)/2+(low+high)%2;
        TreeNode*node=new TreeNode(num[mid]);
        node->right=dfs(num,mid+1,high);
        node->left=dfs(num,low,mid-1);
        return node;
	}
};