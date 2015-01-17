/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(preorder,inorder,0,0,inorder.size());
    }
private:
	TreeNode *build(vector<int> &preorder, vector<int> &inorder,int l1,int l2,int num)
	{
		if(num==0)
			return NULL;
		if(num==1)
		{
			TreeNode*node=new TreeNode(preorder[l1]);
			return node;
		}
		int end=preorder[l1];
		int i;
		for(i=l2;i<l2+num;i++)
			if(inorder[i]==end)
				break;
		TreeNode *node=new TreeNode(end);
		int nl1;int nl2;int nnum;
		nnum=i-l2;
		//std::cout<<l1+1<<" "<<l2<<endl;
		if(nnum>=1)
			node->left=build(preorder,inorder,l1+1,l2,nnum);
		nl1=l1+1+nnum;nl2=i+1;nnum=num-nnum-1;
		if(nnum>=1)
			node->right=build(preorder,inorder,nl1,nl2,nnum);
		return node;
	}
};

int main()
{
	vector<int>preorder({1,2});
	vector<int>inorder({2,1});
	Solution solution;
	TreeNode*bt=solution.buildTree(preorder,inorder);
	std::cout<<bt->val<<endl;
	std::cout<<bt->left->val<<endl;
	return 0;
}