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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      	return build(inorder,postorder,0,0,inorder.size());
    }
private:
	TreeNode *build(vector<int>&inorder,vector<int>&postorder,int l1,int l2,int num)
	{
		if(num==0)
			return NULL;
		if(num==1)
		{
			TreeNode*node=new TreeNode(inorder[l1]);
			return node;
		}
		int end=postorder[l2+num-1];
		int i;
		for(i=l1;i<l1+num;i++)
			if(inorder[i]==end)
				break;
		TreeNode *node=new TreeNode(end);
		
		int nl1;int nl2;int nnum;
		nnum=i-l1;
		if(nnum>=1)
			node->left=build(inorder,postorder,l1,l2,nnum);
		nl1=i+1;nl2=l2+nnum;nnum=num-nnum-1;
		if(nnum>=1)
			node->right=build(inorder,postorder,nl1,nl2,nnum);
		return node;
	}
};