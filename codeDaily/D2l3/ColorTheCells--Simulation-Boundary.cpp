#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

int mV=0x3fffff;int n;
vector<int> paintedTime;
vector<int> dryingTime;

void dfs(int curT,int curP,int m)
{
	if(m==n)
	{ 
		/*cout<<"(";
		for(int i=0;i<3;i++)
				cout<<paintedTime[i]<<" ";
		cout<<")\n";*/
		mV=min(mV,curT);return;
	}
	int i,j,k,l;int tt;
	FF(l,n)
	{
		if(paintedTime.at(l)!=-1) continue;
		FF(k,2)
		{
			if(k==0&&l==0) continue;if(k==1&&l==n-1) continue;
			if(k==0) i=l-1; if(k==1) i=l+1;tt=curT;j=curP;
			int flag=1;
			if(i<curP) flag=-1;
			else flag=1;
			while(j!=i)
			{
				j+=flag; if(paintedTime.at(j)==-1) tt++;
				else tt=max(tt,paintedTime[j]+dryingTime[j])+1; 
			}
			//cout<<"curT:"<<curT<<" curP:"<<curP<<" i:"<<i<<" l:"<<l<<" tt:"<<tt<<endl;
			paintedTime[l]=tt+1;dfs(tt+1,i,m+1);paintedTime[l]=-1;
		}
	}
}

int minimalTime(vector<int> const &drying) 
{
	dryingTime=vector<int>(drying.begin(),drying.end());
	n=dryingTime.size();paintedTime=vector<int>(n,-1);
	mV=0x3fffff;dfs(0,0,0);
    return mV;
}

/*int main()
{
	vector<int> drying;drying.push_back(2);
	drying.push_back(2);drying.push_back(3);
	cout<<minimalTime(drying)<<endl;
	return 0;
}*/