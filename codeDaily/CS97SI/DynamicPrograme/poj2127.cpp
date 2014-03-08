#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define SZ 505

#define FF(i,n)   for(i = 0;i < n;i++)
#define FS(i,a,b) for(i = a;i < b;i++)
#define FR(i,a,b) for(i = a;i >= b;i--)

int arr1[SZ], arr2[SZ], dp[SZ][SZ];

void trav(int a,int b)
{
    if(dp[a][b] == 1) cout<<arr1[a];
    else
    {
        int i, j;
        FR(i,a,0) FR(j,b,0)
        {
            if(i == a && j == b) continue;
            if(dp[i][j] == dp[a][b] - 1)
                goto lable;
        }
lable:
        trav(i,1);
        cout<<" "<<arr1[a];
    }
}

int main()
{
	int n, m, i, j, k, l;
    
    memset(dp,0,sizeof(dp));

    cin >> n;
	FF(i,n) cin>>arr1[i];
    cin >> m;
    FF(i,m) cin>>arr2[i];
    
    int rrrsss = 0;int a,b;

    FF(i,n) FF(j,m) 
    {
        if(arr1[i] == arr2[j])
        {
            int & rs = dp[i][j]; rs = 1;
            FR(k,i-1,0) FR(l,j-1,0)
            rs = max(rs,dp[k][l] + 1);
            if(rrrsss < rs) {a = i;b = j;}
            rrrsss = max(rrrsss, rs);
        }
    }
    cout<<rrrsss<<endl;
    trav(a,b);cout<<endl;
    return 0;
}

/*int LIS(int n, elem_t *a, int m, elem_t *b, elem_t *ans){
    int i, j, l, r, k;
    DP[0][0] = 0;
    num[0] = (b[0] == a[0]);
    for(i = 1; i < m; i++) {
        num[i] = (b[i] == a[0]) || num[i-1];
        DP[i][0] = 0;
    }
    for(i = 1; i < n; i++){
        if(b[0] == a[i] && !num[0]) {
            num[0] = 1;
            DP[0][0] = i<<10;
        }
        for(j = 1; j < m; j++){
            for(k=((l=0)+(r=num[j-1]-1))>>1; l<=r; k=(l+r)>>1)
                if(_cp(a[DP[j-1][k]>>10], a[i]))
                    l=k+1;
                else
                    r=k-1;
            if(l < num[j-1] && i == (DP[j-1][l]>>10) ){
                if(l >= num[j]) DP[j][num[j]++] = DP[j-1][l];
                else DP[j][l] = _cp(a[DP[j][l]>>10],a[i]) ? DP[j][l] : DP[j-1][l];
            }
            if(b[j] == a[i]){
                for(k=((l=0)+(r=num[j]-1))>>1; l<=r; k=(l+r)>>1)
                    if(_cp(a[DP[j][k]>>10], a[i]))
                        l=k+1;
                    else
                        r=k-1;
                DP[j][l] = (i<<10) + j;
                num[j] += (l>=num[j]);
                p[DP[j][l]] = l ? DP[j][l-1] : -1;
            }
        }
    }
    for (k=DP[m-1][i=num[m-1]-1];i>=0;ans[i--]=a[k>>10],k=p[k]);
    return num[m-1];
}*/