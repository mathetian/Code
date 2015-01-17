#include <iostream>
#include <vector>
using namespace std;

class Lock{
public:
	void Acquire() { }
	void Release() { }
};

template<class T>
class Singleton{
	Singleton() {}
	static T *t;
	static Lock lock;
public:
	T*GetSingleton()
	{
		if(t==NULL)
		{
			lock.Acquire();
			if(t==NULL) t=new T();
			lock.Release();
		}
		return t;
	}
};