#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define SR(c) {sort(c.begin(),c.end());reverse(c.begin(),c.end());}
#define INF 0x3fffff
#define  FF(l,s) for(l=0;l<s;l++)

int solve(vector<int> mid,vector<int> a)
{
	SR(a);int i;int midS=0;int aS=0;int num=0;
	FF(i,mid.size()) midS+=mid.at(i);
	FF(i,a.size()) aS+=a.at(i);
	if(midS<aS) return INF;
	FF(i,min(mid.size(),a.size())) num+=min(mid.at(i),a.at(i));
	return aS-num;
}

int minRepaintings(vector<int> const &balloonCount,
                   string const &balloonSize,
                   vector<int> const &maxAccepted) 
{
    int n=maxAccepted.size();
    int i; int ans=INF;
    vector<int> mid;vector<int> large;
    FF(i,balloonSize.size())
    {
    	if(balloonSize.at(i)=='M') mid.push_back(balloonCount.at(i));
    	else large.push_back(balloonCount.at(i));
    }
    SR(mid);SR(large);
    FF(i,1<<n)
    {
    	vector<int> a;vector<int> b;
    	int j;
    	FF(j,n)
    	{
           
    		if((i&(1<<j))!=0) a.push_back(maxAccepted.at(j));
    		else b.push_back(maxAccepted.at(j));
    	}
        //1100
       /* if(i==12)
        {
            cout<<"begin"<<endl;
            for(int k=0;k<a.size();k++)
            {
                cout<<a.at(k)<<endl;
            }
        }*/
            
       /* if(solve(mid,a)!=INF&&solve(large,b)!=INF) cout<<"test"<<endl;
        else if(solve(mid,a)!=INF)
        {
          //  cout<<"i:"<<i<<" "<<solve(mid,a)<<endl;
        }*/
    	ans=min(ans,solve(mid,a)+solve(large,b));
    }
    if(ans==INF) return -1;
    return ans;
}

/*int main()
{
    int dd[]={5,6,1,5,6,1,5,6,1};int dd1[]={7,7,4,4,7,7};
    vector<int> balloonCount(dd,dd+sizeof(dd)/sizeof(int));
    string balloonSize="MLMMLMMLM";
    vector<int> maxAccepted(dd1,dd1+sizeof(dd1)/sizeof(int));
    cout<<minRepaintings(balloonCount,balloonSize,maxAccepted)<<endl;
    return 0;
}*/
