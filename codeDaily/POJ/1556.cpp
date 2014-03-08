#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include <math.h>

#define FF(i,n) for(i=0;i<n;i++)
#define FR(i,j,n) for(i=j+1;i<n;i++)

bool intersect(double xa1, double ya1, double xa2, double ya2, double xb1, double yb1, double xb2, double yb2)
{
    if(xa1 == xb1 && ya1 == yb1) return false;
    if(xa1 == xb2 && ya1 == yb2) return false;
    if(xa2 == xb1 && ya2 == yb1) return false;
    if(xa2 == xb2 && ya2 == yb2) return false;

    if (((xa2 - xa1) * (yb1 - ya1) - (xb1 - xa1) * (ya2 - ya1)) *
        ((xa2 - xa1) * (yb2 - ya1) - (xb2 - xa1) * (ya2 - ya1)) > 0)
        return false;
    if (((xb2 - xb1) * (ya1 - yb1) - (xa1 - xb1) * (yb2 - yb1)) *
        ((xb2 - xb1) * (ya2 - yb1) - (xa2 - xb1) * (yb2 - yb1)) > 0)
        return false;
    return true;
}

typedef pair<double,double> PP;

bool intersect(PP aa1, PP aa2, PP aa3, PP aa4)
{
    return intersect(aa1.first,aa1.second, aa2.first, \
            aa2.second, aa3.first, aa3.second, aa4.first, aa4.second);
}

double dis(PP aa1, PP aa2)
{
    double ax1=aa1.first  - aa2.first;
    double ax2=aa1.second - aa2.second;
    return sqrt(ax1*ax1+ax2*ax2);
}

struct _tSeg
{
    double x;
    double y[4];
    _tSeg(double * a)
    {
        x=a[0]; int i;
        FF(i,4) y[i]=a[i+1];

        sort(y,y+4);
    }
};

typedef struct _tSeg Seg;

struct cmp
{
    bool operator()(const Seg &a1,const Seg &a2){
        if(a1.x < a2.x) return true;
        return false;
    }
};

double arr[100][100];int n,m;

double Bellman()
{
    double rss[500];
    int i, j, k;FF(i,m) rss[i]=0x3ffffff;
    rss[0]=0;
    FF(k,m) FF(i,m) FR(j,i,m)
    {
         rss[j] = min(rss[j], rss[i] + arr[i][j]);
    }
   

    return rss[m-1];
}

int main()
{
    while(cin>>n && n != -1)
    {
        vector<Seg>segs;int i,j,k;
        m = n;
        while(m--)
        {
            double a[5];
            FF(i,5) cin>>a[i];
            Seg seg(a);
            segs.push_back(seg);
        }
        sort(segs.begin(),segs.end(),cmp());
        m=4*n+2;
        vector<PP>points;
        vector<pair<double, PP> >segments;

        FF(i,m)
        {
            if(i==0) points.push_back(make_pair(0,5));
            else if(i==m-1) points.push_back(make_pair(10,5));
            else
            {
                int k=i/4; if(i%4==0) k--;
                Seg seg=segs.at(k);
                j=(i-1)%4;
                points.push_back(make_pair(seg.x,seg.y[j]));
            }
        }

        FF(i,n)
        {
            Seg seg = segs.at(i);
            segments.push_back(make_pair(seg.x,make_pair(0,seg.y[0])));
            segments.push_back(make_pair(seg.x,make_pair(seg.y[1],seg.y[2])));
            segments.push_back(make_pair(seg.x,make_pair(seg.y[3],10)));
        }

        FF(i,m) FF(j,m)
        {
            if(i==j) arr[i][i]=0;
            else arr[i][j]=0x3ffffff;
        }

        PP p1, p2, p3, p4;

        FF(i,m)
        {
            FR(j,i,m)
            {
                p1 = points.at(i);
                p2 = points.at(j);
                FF(k, segments.size())
                {
                    p3.first  = segments[k].first;
                    p3.second = segments[k].second.first;

                    p4.first  = segments[k].first;
                    p4.second = segments[k].second.second;
                    
                    if(intersect(p1,p2,p3,p4) == 1) break;
                }

                if(k==segments.size())  arr[i][j]=dis(p1,p2); 
            }
        }
        double rs = Bellman();
        printf("%0.2f\n",rs);
    }
    return 0;
}