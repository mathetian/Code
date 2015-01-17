#include <iostream>
using namespace std;

template<class T>
class SNode
{
	T t; SNode*next;
public: 
	SNode() { next = NULL; }
};

template<class T>
class SList
{
	SNode<T> *head;
public:
	void Init() { head = new SNode<T>(); }
	void Add(const T&t);
	void Add();
	bool Remove(const T&t);
	SNode<T>* Get(const T&t);
	SNode<T>* First();
	SNode<T>* End();
	bool      Empty();
};

template<class T>
class DList
{

};

template<class T>
class SQueue
{

};

template<class T>
class TailQueue
{

};

template<class T>
class CircleQueue
{
};

int main()
{
	return 0;
}