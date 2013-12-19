#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

double get(double r1,double r2)
{
	return 2*sqrt(r1*r2);
}

void print(vector<double> rs)
{
	for(int i=0;i<rs.size();i++)
		cout<<rs.at(i)<<" ";
	cout<<endl;
}

double totalWidth(vector<int> const &radius) 
{
	vector<int> pr;int i,j;int n=radius.size();
	double rs2=1e100;
	for(i=0;i<n;i++) pr.push_back(i);
	do{
		double v=0;vector<double> pos;
		double rs;pos.push_back(0);
		for(i=1;i<n;i++)
		{
			rs=pos.at(i-1);
			for(j=i-1;j>=0;j--)
			{
				double r3=get(radius.at(pr.at(j)),radius.at(pr.at(i)));
				rs=max(rs,r3+pos.at(j));
			}
			pos.push_back(rs);
		}
		rs2=min(rs,rs2);
	}while(next_permutation(pr.begin(),pr.end()));
    return (double)rs2;
}

/*int main()
{
	//int rr[]={1000000000, 200000000, 300000000, 400000000, 500000000, 600000000, 700000000, 800000000};
	int rr[]={1,2,3,4,5,6,7,8};
	vector<int> radius(rr,rr+sizeof(rr)/sizeof(int));
	cout<<totalWidth(radius)<<endl;
	return 0;
}
*/
/*
 double cal_center(double c1, double r1, double r2) { 
        return c1 + 2 * sqrt(r1 * r2); 
    } 


    double totalWidth(vector <int> r) { 
        vector<int> p; 
        int times = 1; 
        for (int i = 0; i < r.size(); ++i) { 
            p.push_back(i); 
            times *= (i + 1); 
        } 
         
        double ans = 1e100; 
        double c[10]; 
        for (int i = 0; i < times; ++i) { 
            c[p[0]] = 0; 
            for (int j = 1; j < r.size(); ++j) { 
                double tmp = 0, tmp2; 
                for (int k = 0; k < j; ++k) { 
                    tmp2 = cal_center(c[p[k]], r[p[k]], r[p[j]]); 
                    if (tmp2 > tmp) tmp = tmp2; 
                } 
                c[p[j]] = tmp; 
            } 
            if (c[p[r.size() - 1]] < ans) ans = c[p[r.size() - 1]]; 
         
            next_permutation(p.begin(), p.end()); 
        } 
         
        return ans; 
    } 
*/