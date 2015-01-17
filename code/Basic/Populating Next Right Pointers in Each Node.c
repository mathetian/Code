class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return;
        vector<TreeLinkNode*> tQ1;
        vector<TreeLinkNode*> tQ2;
        tQ1.push_back(root);int flag=0;
        while(1)
        {
        	if(tQ1.size()==0)
        		break;
        	clearVector(tQ2);
            for(int i=0;i<tQ1.size()-1;i++)
                tQ1[i]->next=tQ1[i+1];
            if(tQ1.size()>=1)
            {
                 tQ1[tQ1.size()-1]->next=NULL;
            }
        	for(int i=0;i<tQ1.size();i++)
        	{
        		TreeLinkNode*tmp=tQ1[i];

        		if(tmp->left)
                {
                   tQ2.push_back(tmp->left);
                }
        		if(tmp->right)
                {
                    tQ2.push_back(tmp->right);
                }
        			
        	}
            tQ1=tQ2;
        }
    }
private:
    void clearVector(vector<TreeLinkNode*> &iVec)
    {
        int s=iVec.size();
        while(s-->0) iVec.pop_back();
    }
};