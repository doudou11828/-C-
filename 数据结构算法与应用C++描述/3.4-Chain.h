#pragma once
#include <iostream>

/*3.4链表描述：把一个线性表表示成一个链*/
template<class T> //前导声明以便设置友元类
class Chain;
template<class T> //前导声明以便设置友元类
class ChainIterator;

template<class T>
class ChainNode //节点类
{
	friend class Chain<T>; //Chain<T>中成员函数均为ChainNode<T>的友元函数，可访问ChainNode<T>私有成员
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class Chain //链表类
{
	friend class ChainIterator<T>;
public:
	Chain() { first = 0; }
	~Chain();
	void Erase(); //（扩充函数）删除链表中所有节点，等价于析构函数
	void Zero() { first = 0; } //（扩充函数）将first指针置为0，但不删除任何节点
	bool IsEmpty() const { return 0 == first; }
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	Chain<T>& Append(const T& x); //（扩充函数）在链表右端添加一个元素
	void Output(std::ostream& out) const;
private:
	ChainNode<T>* first; //指向第一个节点的指针
	ChainNode<T>* last; //跟踪链表的最后一个元素，为扩充函数Append()服务
};

template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x);

template<class T>
class ChainIterator
{
public:
	T* Initialize(const Chain<T>& c); //将location指向链表中第一个节点，并返回指向该节点数据域的指针
	T* Next(); //将location指向链表中下一个节点，并返回指向该节点数据域的指针
private:
	ChainNode<T>* location; //用于跟踪当前在链表中所处的位置
};
