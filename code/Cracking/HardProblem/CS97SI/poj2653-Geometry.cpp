#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

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

class Stick
{	
public:
	double ax, ay;
	double bx, by;
	int id;
	
};

bool operator<(const Stick &s1,const Stick &s2)
{
	return s1.id < s2.id ? true : false;
}
struct cmp
{
	bool operator()(const Stick &s1, const Stick &s2)
	{
		return s1.id < s2.id ? true : false;
	}
};
vector<Stick> sticks;

bool intersect(Stick s1, Stick s2)
{
	return intersect(s1.ax,s1.ay,s1.bx,s1.by,s2.ax,s2.ay,s2.bx,s2.by);
}

int main()
{
	int n;
	while(cin>>n && n != 0)
	{
		set<Stick> tSticks;
		Stick stick;
		int i; FF(i, n)
		{
			cin>>stick.ax;
			cin>>stick.ay;
			cin>>stick.bx;
			cin>>stick.by;
			stick.id = i;
			LA:
			set<Stick>::iterator iter = tSticks.begin();
			for(;iter != tSticks.end();iter++)
			{
				if(intersect(stick, *iter))
				{
					tSticks.erase(iter);			
					goto LA;
				}
			}

			tSticks.insert(stick);
		}

		vector<Stick> output(tSticks.size());
		copy(tSticks.begin(), tSticks.end(), output.begin());
		sort(output.begin(),output.end());

		cout<<"Top sticks: ";
		for(int i=0;i<output.size();i++)
		{
			cout<<output[i].id+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}