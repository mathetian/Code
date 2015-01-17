class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	    vector<string>rs;char*rs1=new char[digits.size()+1];
	    memset(rs1,'\0',digits.size()+1);
	    dfs(rs,digits,digits.size(),0,rs1);
	    return rs;
    }
private:
	void dfs(vector<string>&rs,string digits,int n,int m,char*rs1)
	{
		if(m==n)
			rs.push_back(rs1);
		else
		{
			if(digits[m]=='0')
			{
				rs1[m]=' ';
				dfs(rs,digits,n,m+1,rs1);
			}
			else if(digits[m]=='1')
			{

			}
			else
			{	
				if(digits[m]<='6')
				{
					char st=(digits[m]-'2')*3+'a';
					for(int i=0;i<3;i++)
					{
						rs1[m]=st+i;
						dfs(rs,digits,n,m+1,rs1);
					}
				}
				else
				{
					if(digits[m]=='7')
					{
						string s1="pqrs";
						for(int i=0;i<4;i++)
						{
							rs1[m]=s1[i];
							dfs(rs,digits,n,m+1,rs1);
						}
					}
					else if(digits[m]=='8')
					{
						string s1="tuv";
						for(int i=0;i<3;i++)
						{
							rs1[m]=s1[i];
							dfs(rs,digits,n,m+1,rs1);
						}
					}
					else
					{
						string s1="wxyz";
						for(int i=0;i<4;i++)
						{
							rs1[m]=s1[i];
							dfs(rs,digits,n,m+1,rs1);
						}
					}
				}
				
			}
		}
	}
};