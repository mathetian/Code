/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
	There is a perfect solution for this problem
**/
#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MIN 0x3fffffff

typedef struct _T1 {
   	struct _T1 *left;struct _T1 *right; 
    int v1,v2; int val;
    _T1(int x) : val(x), left(NULL), right(NULL), v1(0), v2(0) {};
}T1;

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        rT1=copyTree(root);
        mx=-MIN;
        rlm(rT1);
        return mx;
    }
private:
	T1*rT1;
	T1* copyTree(TreeNode*node)
	{
		if(!node)
			return NULL;
		else
		{
			T1*t1=new T1(node->val);
			t1->left=copyTree(node->left);
			t1->right=copyTree(node->right);
			return t1;
		}
	}
	int mx;
	void rlm(T1*node)
	{
		if(!node)
			return;
		if(!node->right&&!node->left)
		{
			node->v1=node->v2=node->val;
			mx=max(node->v1,mx);
			return;
		}
		rlm(node->right);rlm(node->left);
		if(node->left&&node->right)
		{
			int r1=node->left->v2;int r2=node->right->v2;
			if(r1>0&&r2>0)
			{
				//v1 cross
				node->v1=r1+r2+node->val;
				//v2 max
				node->v2=max(r1,r2)+node->val;
			} 
			else if(r1>0)
			{
				node->v1=r1+node->val;
				node->v2=node->v1;
			}
			else if(r2>0)
			{
				node->v1=r2+node->val;
				node->v2=node->v1;
			}
			else
			{
				node->v1=node->val;
				node->v2=node->v1;
			}	
		}
		else if(node->left)
		{
			int r1=node->left->v2;
			if(r1>0)
				node->v1=r1+node->val;
			else
				node->v1=node->val;
			node->v2=node->v1;
		}
		else
		{
			int r2=node->right->v2;
			if(r2>0)
				node->v1=r2+node->val;
			else
				node->v1=node->val;
			node->v2=node->v1;
		}
		mx=max(max(node->v1,node->v2),mx);
	}
};

int main()
{
	TreeNode*node1=new TreeNode(-2);
	TreeNode*node2=new TreeNode(-3);
	//TreeNode*node3=new TreeNode(3);
	//node1->left=node2;node1->right=node3;
	node1->right=node2;
	Solution solution;
	std::cout<<solution.maxPathSum(node1)<<endl;
	return 0;
}