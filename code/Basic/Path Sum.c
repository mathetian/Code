class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>vT;
        clearVector(rs);flag=0;
        if(!root)
        	return flag;
        mlr(root,vT,0,sum);
        return flag;
    }
private:
	vector<vector<int> >rs;
	int flag;
	void mlr(TreeNode *node,vector<int>&vT,int t,int sum)
	{
		if(flag==1)
			return;
		vT.push_back(node->val);
		if(!node->left&&!node->right)
		{
			if(t+node->val==sum)
				flag=1;
		}
		if(node->left)
			mlr(node->left,vT,t+node->val,sum);
		if(node->right)
			mlr(node->right,vT,t+node->val,sum);
		vT.pop_back();
	}
	void clearVector(vector<vector<int> > &iVec)
    {
        int s=iVec.size();
        while(s-->0) iVec.pop_back();
    }
};