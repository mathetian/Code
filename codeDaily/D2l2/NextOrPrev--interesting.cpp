#include <vector>
#include <string>
using namespace std;

int getMinimum(int nextCost,
               int prevCost,
               string const &start,
               string const &goal) {
    int a=0;int flag=0;
    for(int i=0;i<start.size();i++)
    {
    	for(int j=0;j<goal.size();j++)
    	{
    		if(start.at(i)>start.at(j)&&goal.at(i)<goal.at(j)) return -1;
    		if(start.at(i)<start.at(j)&&goal.at(i)>goal.at(j)) return -1;
    	}
    }
    for(int i=0;i<start.size();i++)
    {
    	if(start.at(i)<goal.at(i)) a+=(goal.at(i)-start.at(i))*nextCost;
    	else if(start.at(i)==goal.at(i)){}
    	else a+=(start.at(i)-goal.at(i))*prevCost;
    }
    return a;
}
