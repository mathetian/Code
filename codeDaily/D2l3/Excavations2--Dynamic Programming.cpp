#include <vector>
#include <string>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

/*int64 mm=0;vector<int> found;
vector<pair<int,int> > iiV;*/

/*int64 get1(int m,int n)
{
	
	//select n numbers from m numbers
	int64 r=1;int e=m-n+1;
//	cout<<"m:"<<m<<" n:"<<n<<" r:"<<r<<endl;
	vector<int> flags(n+1,0);
	while(m>=e)
	{
		r*=m;m--;
		for(int i=2;i<=n;i++)
		{
			if(flags[i]==0&&r%i==0)
			{
				r/=i;flags[i]=1;
			}
		}
	}
	
	//cout<<"m:"<<m<<" n:"<<n<<" r:"<<r<<endl;
	return r;
}

//m index, n index at most, K remain
void dfs(int m,int n,int K,vector<int> sel)
{
	int i;
	if(K==0)
	{
		if(m==n)
		{
		//	cout<<"wat?"<<endl;
			int64 r=1;
			FF(i,n) r*=get1(iiV.at(i).second,sel.at(i));
		//	cout<<r<<"rr"<<endl;
			mm+=r;
		}
		return;
	}
	else if(m==n) return;
	else
	{
		FF(i,iiV.at(m).second+1)
		{
			if(i+1>K) break;
		//	cout<<"("<<m<<" "<<n<<" "<<K-i-1<<")"<<endl;
			sel[m]=i+1;dfs(m+1,n,K-i-1,sel);
		}
	}
}

int64 count(vector<int> const &kk, vector<int> const &ff, int K) 
{
	mm=0;vector<int>kind=vector<int>(kk.begin(),kk.end());
	sort(kind.begin(),kind.end());int i=0,j;int n=kind.size();
	while(i<n)
	{
		int old=i;while(i<n&&kind.at(old)==kind.at(i)) i++;
		iiV.push_back(make_pair(kind.at(old),i-old));
	}
	vector<pair<int,int> >iiV2;i=0;
	FF(i,ff.size())
	{
		FF(j,iiV.size())
		{
			if(iiV.at(j).first==ff.at(i)) iiV2.push_back(iiV.at(j));
		}
	}
	swap(iiV,iiV2);vector<int> sel(ff.size(),0);
	dfs(0,ff.size(),K,sel);
	return mm;
}*/

int64 ncr[52][52];

void genncr()
{
    int i, j;
    ncr[0][0]=1;
    int limncr = 50;
    for(i = 1; i <= 51; i++)
        for(j = 0; j <= 51; j++)
        {
            if(j > i) ncr[i][j] = 0;
            else if(j == i || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
}

vector<vector<int64> >dp;

int64 get(int index,vector<int> &iV,int remain)
{
	int64&mm=dp[index][remain];
	if(mm!=-1) return dp.at(index).at(remain);
	int n=iV.size(), remain2=n-(index+1);mm=0;
	if(index==0) mm=ncr[iV.at(0)+1][remain+1];
	else
	{
		int r1=0;int i;for(i=0;i<index;i++) r1+=iV.at(i);
		for(i=remain;i>=0;i--)
		{
			if(i>iV.at(index)) continue;if(remain-i>r1) break;
			mm+=ncr[iV.at(index)+1][i+1]*get(index-1,iV,remain-i);
		} 
	}
	return mm;
}

int64 count(vector<int> const &kk, vector<int> const &found, int K) 
{
	int64 mm=0;vector<int>kind(kk.begin(),kk.end());
	sort(kind.begin(),kind.end());int i=0;int n=kind.size();
	vector<pair<int,int> > iiV;vector<int>iV;int j;
	while(i<n)
	{
		int old=i;while(i<n&&kind.at(old)==kind.at(i)) i++;
		iiV.push_back(make_pair(kind.at(old),i-old));
	}
	FF(i,found.size())
	{
		FF(j,iiV.size())
		{
			if(iiV.at(j).first==found.at(i))
			{
				iV.push_back(iiV.at(j).second-1);
			}
		}
	}
	dp=vector<vector<int64> >(51,vector<int64>(3000,-1));
	genncr();return get(iV.size()-1,iV,K-iV.size());
}
