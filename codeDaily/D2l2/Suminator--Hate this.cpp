#include <vector>
#include <string>
#include <stack>
using namespace std;

#define FF(i,n) for(i=0;i<n;i++)

typedef long long _int64;
typedef pair<_int64,int> iiP;

/*int findMissing(vector<int> const &program,int wantedResult) {
    int n=program.size();int m=0;int i;
    FF(i,n) 
    {
    	if(program.at(i)==-1)
    	{
    		m=i;break;
    	}
    }

    stack<iiP> is; i = 0;
    while(i<m)
    {
        if(program.at(i)==0)
        {
            if(is.size()<2){i++; continue;}
            _int64 a=is.top().first;is.pop();
            _int64 b=is.top().first;is.pop();
            is.push(make_pair(a+b,0));
        }
        else is.push(make_pair(program.at(i),0));
        i++;
    }

    stack<iiP> is1=is;int j=i;i=i+1;
    if(is1.size()>=2)
    {
        _int64 a=is1.top().first;is1.pop();
        _int64 b=is1.top().first;is1.pop();
        is1.push(make_pair(a+b,0));
        while(i<n)
        {
            if(program.at(i)==0)
            {
                if(is1.size()<2){i++;continue;}
                _int64 a=is1.top().first;is1.pop();
                _int64 b=is1.top().first;is1.pop();
                is1.push(make_pair(a+b,0));
            }
            else is1.push(make_pair(program.at(i),0));
            i++;
        }
        if(is1.top().first==wantedResult) return 0;
    }
    else
    {
        while(i<n)
        {
            if(program.at(i)==0)
            {
                if(is1.size()<2){i++;continue;}
                _int64 a=is1.top().first;is1.pop();
                _int64 b=is1.top().first;is1.pop();
                is1.push(make_pair(a+b,0));
            }
            else is1.push(make_pair(program.at(i),0));
            i++;
        }
        if(is1.top().first==wantedResult) return 0;
    }

    is.push(make_pair(0,1));i=j+1;
    while(i<n)
    {
        if(program.at(i)==0)
        {
            if(is.size()<2){i++;continue;}
            iiP a1=is.top();is.pop();
            iiP a2=is.top();is.pop();
            int dd=a1.second | a2.second;
            if(dd!=0) is.push(make_pair(a1.first+a2.first,1));
            else is.push(make_pair(a1.first+a2.first,0));
        }
        else is.push(make_pair(program.at(i),0));
        i++;
    }
    if(is.top().second==0)
    {
        if(is.top().first==wantedResult) return 0;
        return -1;
    }
    else
    {
        _int64 a = is.top().first;_int64 remain = wantedResult-a;
        if(a>=wantedResult) return -1;
        return remain;
    }
    return 0;
}*/

int findMissing(vector<int> const &program,int wantedResult) 
{
    int m=0;int i,j;int n=program.size();
    for(i=0;i<program.size();i++) if(program.at(i)==-1) {m=i;break;}
    stack<iiP> is;
    for(i=0;i<m;i++)
    {
        if(program.at(i)!=0) is.push(make_pair(program.at(i),0));
        else
        {
            if(is.size()>=2)
            {
                iiP a1=is.top();is.pop();
                iiP a2=is.top();is.pop();
                is.push(make_pair(a1.first+a2.first,0));
            }
        }
    }
    //zero
    stack<iiP> is2=is;
    for(i=m;i<n;i++)
    {
        if(i==m)
        {
            if(is2.size()>=2)
            {
                iiP a1=is2.top();is2.pop();
                iiP a2=is2.top();is2.pop();
                is2.push(make_pair(a1.first+a2.first,0));
            }
        }
        else if(program.at(i)!=0) is2.push(make_pair(program.at(i),0));
        else
        {
            if(is2.size()>=2)
            {
                iiP a1=is2.top();is2.pop();
                iiP a2=is2.top();is2.pop();
                is2.push(make_pair(a1.first+a2.first,0));
            }
        }
    }
    if(is2.size()>=1&&is2.top().first==wantedResult) return 0;
    //with positive value
    is.push(make_pair(0,1));
    for(i=m+1;i<n;i++)
    {
        if(program.at(i)!=0) is.push(make_pair(program.at(i),0));
        else
        {
            if(is.size()>=2)
            {
                iiP a1=is.top();is.pop();
                iiP a2=is.top();is.pop();
                if(a1.second|a2.second==1) is.push(make_pair(a1.first+a2.first,1));
                else is.push(make_pair(a1.first+a2.first,0));
            }
        }
    }
    if(is.size()>=1)
    {
        iiP a1=is.top();
        if(a1.second==0)
        {
            if(wantedResult==a1.first) return 1;
            else return -1;
        }
        else
        {
            if(wantedResult==a1.first) return -1;
            else if(wantedResult<a1.first) return -1;
            else return wantedResult-a1.first;
        }
    }
    return -1;
}