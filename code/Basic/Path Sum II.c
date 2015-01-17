class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>vT;
        clearVector(rs);
        if(!root)
        	return rs;
        mlr(root,vT,0,sum);
        return move(rs);
    }
private:
	vector<vector<int> >rs;
	void mlr(TreeNode *node,vector<int>&vT,int t,int sum)
	{
		vT.push_back(node->val);
		if(!node->left&&!node->right)
		{
			if(t+node->val==sum)
				rs.push_back(vT);
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