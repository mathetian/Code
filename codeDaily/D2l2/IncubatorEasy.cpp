#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int maxMagicalGirls(vector<string> const &love) {
    int i,j,k;int n=love.size();int mx=0;
    FF(i,1<<n)
    {
    	int pp=0;
    	FF(j,n)
    	{
    		if((i&(1<<j))!=0)
    		{
    			FF(k,n)
    			{
    				if(love[j][k]=='Y') pp|=(1<<k);
    			}
    		}
    	}
    	int num=0;
    	FF(j,n)
    	{
    		FF(k,n)
    		{
    			if((pp&(1<<k))!=0)
    			{
    				int l;
    				FF(l,n)
    				{
    					if(love[k][l]=='Y') pp|=(1<<l);
    				}
    			}
    		}
    	}

    	FF(j,n)
    	{
    		if((i&(1<<j))!=0) if((pp&(1<<j))==0) num++;
    	}
    	//if(num==2) cout<<"i:"<<i<<endl;
    	mx=max(num,mx);
    }
    return mx;
}
