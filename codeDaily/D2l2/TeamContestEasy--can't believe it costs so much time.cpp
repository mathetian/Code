#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int worstRank(vector<int> const &strength) {
    int m=strength.at(0);
    int fVal=strength.at(0);int num=0;
    for(int i=1;i<3;i++)
    {
    	fVal+=strength.at(i);
    	m=min(m,strength.at(i));
    }
    fVal-=m;
    vector<int> ns(strength.begin()+3,strength.end());
    sort(ns.begin(),ns.end());
    int low=0,high=ns.size()-1;int mid=1;
    vector<char>used(strength.size()-3,0);
    while(mid<high)
    {
    	int a=ns.at(high);
    	if(a>=fVal)
        {
            while(used[low]==1) low++;
            if(low==mid) mid++;
            if(mid==high) break;
            num++;low++;used[mid]=1;mid++;high--;
            continue;
        }
        a=fVal-a;
    	while(used[low]==1) low++;
        if(low==mid) mid++;
        if(mid==high) break;
        while(mid<high&&ns.at(mid)<=a){ mid++;}
        used[mid]=1;
        if(mid<high){ num++;}
        mid++;high--;low++;

    }
    return num+1;
}

/*int main()
{
    int bb[]={210909, 411218, 560249, 766374, 500298, 205709, 509865, 528239, 81348, 880837, 913652, 829129, 244826, 186819, 98635, 449502, 141183, 824882, 327969, 148250, 836690, 712525, 374966, 450472};
    vector<int>strength(bb,bb+sizeof(bb)/sizeof(int));
    cout<<worstRank(strength)<<endl;
}*/