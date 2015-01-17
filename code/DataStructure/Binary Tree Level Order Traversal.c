class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
       	vector<vector<int> >rs;
       	if(!root)
       		return rs;
       	v1.push_back(root);
       	while(v1.size()!=0)
       	{
       		clearVector(v2);
       		vector<int>tmp;
       		for(size_t i=0;i<v1.size();i++)
       		{	
       			TreeNode*n1=v1[i];
       			if(n1->left) v2.push_back(n1->left);
       			if(n1->right) v2.push_back(n1->right);
       		}
       		for(size_t i=0;i<v1.size();i++)
       			tmp.push_back(v1.at(i)->val);
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