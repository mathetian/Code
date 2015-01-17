#include <iostream>
#include <stack>
using namespace std;

stack<int> sort(stack<int>&input)
{
	stack<int> rs;
	while(!input.empty())
	{
		int t=input.top();input.pop();
		while(!rs.empty()&&rs.top()<t)
		{ input.push(rs.top());rs.pop(); }
		rs.push(t);
	}
	return rs;
}