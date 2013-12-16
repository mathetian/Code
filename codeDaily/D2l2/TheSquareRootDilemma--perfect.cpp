#include <vector>
#include <string>
#include <string.h>
using namespace std;

/*int countPairs(int N,int M) {
    int a=0;
    for(int i=1;i<=77777;i++)
    {
    	if(i*i>N*M) break;
    	for(int j=1;j<i&&j<=N;j++)
    	{
    		if((i*i)%j==0)
    		{
    		//	int k=i/j;k*=i;
    		    int k=(i*i)/j;
            	if(k<=M) a++;
    		} 
    	}
        for(int j=1;j<i&&j<=M;j++)
        {
            if((i*i)%j==0)
            {
                int k=(i*i)/j;
                if(k<=N) a++;
            } 
        }
        if(i<=M&&i<=N) a++;
    }
    return a;
}*/

#define LEN 77778
#define FF(i,n) for(i=0;i<n;i++)

int countPairs(int N,int M) 
{
    int arr1[LEN],arr2[LEN];int i,j;
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    
    for(i=1;i<=N;i++)
    {
        int tmp=i;
        for(j=2;(j*j)<=i;j++)
        {
            int r=j*j;
            while((tmp%r)==0) tmp/=r;
        }
         arr1[tmp]++;
    }
    for(i=1;i<=M;i++)
    {
        int tmp=i;
        for(j=2;(j*j)<=i;j++)
        {
            int r=j*j;
            while((tmp%r)==0) tmp/=r;
        }
         arr2[tmp]++;
    }
    int cnt=0;
    for(i=0;i<LEN;i++) cnt=cnt+arr1[i]*arr2[i];
    return cnt;
}