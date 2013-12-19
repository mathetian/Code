#include <vector>
#include <string>
#include <map>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)
#define MX 1000000009

/*int countGenerators(vector<string> const &fragment, int W, int i0, int j0) 
{
	string str(W,'?');int sp=(i0*W+j0)%W;int i,j;
	int n=fragment.size(),m=fragment[0].size();
	FF(i,n)
	{
		FF(j,m) str[sp+j]=fragment[i][j];
		sp+=W;
	}
	int num=0;
	for(int i=0;i<str.size();i++)
		if(str.at(i)=='?') num++;

    return 0;
}
*/
/*int countGenerators(vector<string> const &fragment, int W, int i0, int j0) 
{
	vector<int> bP;int i,j,k;int s=0;int n=fragment.size(),m=fragment[0].size();
	vector
	for(i=1;i<=W;i++)
	{
		s=0;
		int a=(W-s)/i;a=s+a*i;
		s=W-a;bP.push_back(s);
	}
	int num=0;
	for(i=1;i<=W;i++)
	{
		string str(i,'?');int flag=0;
		FF(j,n)
		{
			int sp=bP.at(i0+j);
			FF(k,m)
			{
				s=(sp+j0+k)%i;
				if(str.at(s)=='?') str[s]=fragment[j+i0][k+j0];
				else
				{
					if(str.at(s)==fragment[j+i0][k+j0]) continue;
					flag=1;break;
				}
			}
			if(flag==1) break;
		}
		num=(num+1)%MX;
	}
	return num;
}*/

int modPow(int x, int y)
{
    long long res = 1, a = x;
    while (y > 0) {
        if (y & 1) {
            res = (res * a) % MX;
        }
        a = (a * a) % MX;
        y >>= 1;
    }
    return (int)res;
}

int countGenerators(vector<string> const &fragment, int W, int i0, int j0) 
{
	int n=fragment.size(),m=fragment.at(0).size(),tim=0,r=0;
	int64 rs=0;
	for(int w=1;w<=W;w++)
	{
		int a=W/w;a=W-a*w;int i,j;
		string str(w,'?');
		for(i=i0;i<n+i0;i++)
		{
			int sp=(i*a)%w;
			for(j=j0;j<m+j0;j++)
			{
				//int ep=(sp+j)%w;
				//int ep = ((i0 + i)*W + (j0 + j)) % w;
				int ep=(i*W+j)%w;
				if(str.at(ep)=='?') str[ep]=fragment[i-i0][j-j0];
				else if(str.at(ep)!=fragment[i-i0][j-j0]) break;
			}
			if(j<m+j0) break;
		}
		if(i<n+i0) continue;
		int tim1=0;
		for(i=0;i<w;i++) if(str.at(i)=='?') tim1++;
		rs=(rs+modPow(26,tim1))%MX;
		/*if(tim1==0) r++; else tim+=tim1;*/
	}
	/*cout<<tim<<endl;
	int64 r1=1;int tim1=tim;
	if(tim1==0) return r; else return (r1+r)%MX;*/
	return rs;
}

/*const int MOD = 1000000009;
int modPow(int x, int y)
{
    long long res = 1, a = x;
    while (y > 0) {
        if (y & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        y >>= 1;
    }
    return (int)res;
}

int countGenerators(vector <string> const&fragment, int W, int i0, int j0)
{
    int r = fragment.size(), c = fragment[0].size();
    int res = 0;int num=0;
    for (int w = 1; w <= W; w++) {
        map<int, char > val;
        bool good = true;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                int p = ((i0 + i)*W + (j0 + j)) % w;
                if (val.count(p)) {
                    good = good && (val[p] == fragment[i][j]);
                } else {
                    val[p] = fragment[i][j];
                }
            }
        }
        if (good) {
            // Partial result is equal to 26 raised to the x-th power:
            int x = w - val.size();num+=x;
            res = ( res + modPow(26, x)) % MOD;
        }
    }
    cout<<"num:"<<num<<endl;
    return res;
}*/