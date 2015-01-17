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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*>v1;vector<TreeNode*>v2;
       	vector<vector<int> >rs;
       	if(!root) return 1;
       	v1.push_back(root);
       	while(v1.size()!=0)
       	{
       		clearVector(v2);
       		vector<int>tmp;size_t i;
          int nflag=0;
       		for(i=0;i<v1.size()/2;i++)
       		{
       			TreeNode*n1=v1.at(i);
       			TreeNode*n2=v1.at(v1.size()-i-1);
       			if(n1==NULL)
       			{
       				if(n2!=NULL)
       					return 0;
       			}
       			else
       			{
       				if(n2==NULL||n2->val!=n1->val)
       					return 0;
              nflag=1;
       			}
       		}
          if(v1.size()!=1&&nflag==0)
            break;
       		for(i=0;i<v1.size();i++)
       		{	
       			TreeNode*n1=v1[i];
            if(n1)
            {
              v2.push_back(n1->left);
              v2.push_back(n1->right);
            }
       		}
       		
       		v1=v2;
       	}
       	return 1;
    }
private:
	void clearVector(vector<TreeNode*> &v2)
	{
		int len=v2.size();
		while(len!=0)
		{
			v2.pop_back();len--;
		}
	}
};

int main()
{
  TreeNode*n1=new TreeNode(1);
  TreeNode*n2=new TreeNode(2);
  n1->left=n2;
  Solution solution;
  std::cout<<solution.isSymmetric(n1)<<endl;
  return 0;
}