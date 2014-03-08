#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<string>sBack;stack<string>sForward;

int main()
{
	string cur="http://www.acm.org/";
	string input;
	while(cin>>input&&input!="QUIT")
	{
		if(input=="VISIT")
		{
			sBack.push(cur);
			cin>>cur;
			cout<<cur<<endl;
			while(!sForward.empty())
				sForward.pop();
		}
		else if(input=="BACK")
		{
			if(sBack.size()==0)
				cout<<"Ignored\n";
			else
			{
				sForward.push(cur);
				cur=sBack.top();
				cout<<cur<<endl;sBack.pop();
			}
		}
		else if(input=="FORWARD")
		{
			if(sForward.size()==0)
				cout<<"Ignored\n";
			else
			{
				sBack.push(cur);
				cur=sForward.top();
				sForward.pop();
				cout<<cur<<endl;
			}
		}
	}

	return 0;
}