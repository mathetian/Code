class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int v[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<int>val(v,v+13);
       	vector<int>rs;
       	string flag[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
       	int i=val.size()-1;
       	while(i>=0)
       	{
       		int j=0;
       		while(num>=val[i])
       		{
       			j++;
       			num-=val[i];
       		}
       		rs.push_back(j);
       		i--;
       	}
       	string rs2;
       	for(i=0;i<rs.size();i++)
       	{
			for(int j=0;j<rs[i];j++)
				rs2.append(flag[i]);
       	}
       	return rs2;
    }
};