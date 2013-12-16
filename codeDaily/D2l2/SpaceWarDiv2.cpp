#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	int strength;
	int count;
}ELEM;

struct less_than_key{
    bool operator() (const ELEM& e1, const ELEM& e2){return (e1.strength < e2.strength);}
};


int minimalFatigue(vector<int> const &magicalGirlStrength,
                   vector<int> const &enemyStrength,
                   vector<int> const &enemyCount) {
    int all=0;for(int i=0;i<enemyCount.size();i++) all+=enemyCount.at(i);
    int low=all/magicalGirlStrength.size();
    if(all%magicalGirlStrength.size()!=0) low+=1;
	vector<int> magical=magicalGirlStrength;
	sort(magical.begin(),magical.end());
	vector<ELEM> eVec;
	for(int i=0;i<enemyStrength.size();i++)
	{
		ELEM elem;elem.count=enemyCount.at(i);
		elem.strength=enemyStrength.at(i);
		eVec.push_back(elem);
	}
	sort(eVec.begin(),eVec.end(),less_than_key());

	for(int i=low;i<=all;i++)
	{
		int j=magical.size()-1;
		vector<ELEM>cur=eVec;int l=cur.size()-1;
		while(l>=0&&j>=0)
		{
			//for people j, delete the maxinum possible value
			int mx=i;
			if(cur.at(l).strength>magical.at(j)) break;

			int m=l;
			while(l>=0&&mx>0&&cur.at(l).count<=mx)
			{
				mx-=cur.at(l).count;
				cur[l].count=0;
				l--;
			}
			if(l>=0) cur[l].count-=mx;
			j--;
		}
		if(l==-1) return i;
	}
	return -1;
}

/*int main()
{
	int a[]={5, 3, 1, 8, 8, 2, 6, 1, 2, 6, 4, 9, 3, 1, 4};
	int b[]={1};int c[]={20};
	vector<int> magicalGirlStrength(a,a+sizeof(a)/sizeof(int));
	vector<int> enemyStrength(b,b+1);vector<int> enemyCount(c,c+1);
	cout<<minimalFatigue(magicalGirlStrength,enemyStrength,enemyCount)<<endl;
	return 0;
}*/