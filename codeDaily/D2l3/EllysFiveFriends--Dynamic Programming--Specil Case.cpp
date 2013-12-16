#include <vector>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define FF(i,n) for(i=0;i<n;i++)

int dp[5][30];int n;int len[5];
typedef long long int64;
int64 res[30][30][30][30][30];
//vector<vector<vector<vector<vector<int64 > > > > > dp;

int64 get(int*arr,int round)
{
	int i,j,k;
	int64&tmp=res[arr[0]][arr[1]][arr[2]][arr[3]][arr[4]];
	if(tmp!=-1) return tmp;
	FF(i,5) if(len[i]!=arr[i]) break;
	if(i==5) tmp=1;else
	{
		tmp=0;FF(i,5)
		{
			j=(i+1)%5;if(arr[i]==len[i]||arr[j]==len[j]) continue;
			int a=dp[i][arr[i]],b=dp[j][arr[j]];int arr2[5];
			FF(k,5) arr2[k]=arr[k];if(a%2==1&&b%2==1)
			{	
				arr2[i]++;arr2[j]++;tmp=(tmp+get(arr2,round+1))%MOD;
				if(a==1&&b==1) {}
				else if(a==1) arr2[j]++;
				else if(b==1) arr2[i]++;
				else { arr2[i]++;arr2[j]++; }
				tmp=(tmp+get(arr2,round+1))%MOD;
			}
			else
			{
				if(a==1||b==1){ arr2[i]+=1;arr2[j]+=1; }
				else
				{
					if(a%2==1) { arr2[i]+=2;arr2[j]+=1; }
					else if(b%2==1) { arr2[i]+=1;arr2[j]+=2; }
					else { arr2[i]+=1;arr2[j]+=1; }
				}
				tmp=(tmp+get(arr2,round+1))%MOD;
			} 
		}
	}
	return tmp;
}

int getZero(vector<int> const &numbers) 
{
	int i;FF(i,5)
	{
		len[i]=0;int num=numbers.at(i);
		dp[i][len[i]++]=num;
		while(num!=0)
		{
			if(num%2==0)
			{
				dp[i][len[i]++]=num/2;num/=2;
			}
			else
			{
				dp[i][len[i]++]=num-1;num-=1;
			}
		}
	}
	FF(i,5) len[i]=len[i]-1;
	int arr[5];memset(arr,0,sizeof(arr));
    memset(res,-1,sizeof(res));
    return get(arr,0);
}

/*int main()
{
	int num2[]={5,1,1,2,3};
	cout<<getZero(vector<int>(num2,num2+sizeof(num2)/sizeof(int)))<<endl;
	return 0;
}
*/