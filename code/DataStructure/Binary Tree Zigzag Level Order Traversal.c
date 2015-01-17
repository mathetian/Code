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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
       	vector<vector<int> >rs;
       	if(!root)
       		return rs;
       	v1.push_back(root);bool flag=false;
       	while(v1.size()!=0)
       	{
       		clearVector(v2);
       		vector<int>tmp;
       		for(int i=0;i<v1.size();i++)
       		{	
       			TreeNode*n1=v1[i];
       			if(n1->left) v2.push_back(n1->left);
       			if(n1->right) v2.push_back(n1->right);
       		}
       		if(flag==false)
          {
            for(int i=0;i<v1.size();i++)
            {
              tmp.push_back(v1[i]->val);
            }
          }		
       		else
          {
            for(int i=v1.size()-1;i>=0;i--)
            {
              tmp.push_back(v1[i]->val);
            }
          }
       			
          flag=!flag;
       		rs.push_back(tmp);
       		v1=v2;
       	}
       	return rs;
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
  vector<vector<int> > rs=solution.zigzagLevelOrder(n1);

  return 0;
}