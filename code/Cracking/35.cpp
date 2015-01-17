#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Stack
{
stack<int> stk1;
stack<int> stk2;
public:
	void push(int val)
	{
		stk1.push(val);
	}

	int top()
	{
		if(!stk2.empty()) stk2.top();
		while(!stk.empty())
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
		if(stk2.empty()) return -1;
		return stk2.top();
	}

	void pop()
	{
		if(!stk2.empty()) stk2.pop();
		while(!stk.empty())
		{
			stk2.push(stk1.top());
			stk1.pop();
		}
		if(!stk2.empty()) stk2.pop();
	}

	void empty()
	{
		if(stk1.empty() && stk2.empty()) return true;
		return false;
	}
};

int main()
{
	return 0;
}