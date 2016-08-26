#include "3.4-Chain.h"

using std::cout;
using std::endl;

template<class T>
Chain<T>::~Chain()
{ //析构函数用于删除链表中所有节点，定义为调用成员函数Erase()
	Erase();
}

template<class T>
void Chain<T>::Erase()
{ //删除链表中的所有节点
	ChainNode<T>* next;
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const
{ //返回链表中元素总数
	ChainNode<T>* current = first;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}
	cout << "链表长度为：" << len << endl;
	return len;
}

template<class T>
bool Chain<T>::Find(int k, T& x) const
{ //寻找链表中第k个元素，并将其传送至x，若不存在第k个元素，返回false，否则返回true
	if (k < 1)
	{
		return false;
	}
	ChainNode<T>* current = first;
	int index = 1; //current的索引
	while (index < k && current)
	{
		current = current->link;
		index++;
	}
	if (current) //current不为空，说明存在第k个元素
	{
		x = current->data;
		return true;
	}
	return false;
}

template<class T>
int Chain<T>::Search(const T& x) const
{ //寻找x，若找到，返回x的地址（索引），若x不在链表中，返回0
	ChainNode<T>* current = first;
	int index = 1; //current的索引
	while (current && current->data != x) //需要T类型定义!=操作
	{
		current = current->link;
		index++;
	}
	if (current)
	{
		return index;
	}
	return 0;
}

template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{ //把第k个元素取至x，然后从链表中删除第k个元素
  //三种情形：1)k小于1或链表为空；2)链表不为空且删除首元素；3)链表不为空且删除首元素之外的元素
	if (k < 1 || !first)
	{
		cout << "由于k<1或者链表为空，不存在第k个元素" << endl;
		return -1;
	}
	ChainNode<T>* p = first; //p最终将指向第k个节点
	if (1 == k) //p已经指向需要删除的首元素，删除之
	{
		first = first->link;
	}
	else //将q指向第k-1个元素
	{
		ChainNode<T>* q = first;
		for (int index = 1; index < k - 1 && q; index++)
		{
			q = q->link;
		}
		if (!q || !q->link)
		{
			cout << "链表不为空，但由于元素总数小于k，故不存在第k个元素" << endl;
			return -1;
		}
		p = q->link; //将p指向第k个元素
		if (p == last) //跟踪最后一个元素
		{
			last = q;
		}
		q->link = p->link; //删除第k个元素
	}
	x = p->data;
	delete p;
	p = NULL;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{ //在第k个元素之后插入x
	if (k < 0)
	{
		cout << "由于k<0，不存在第k个元素" << endl;
		return *this;
	}
	ChainNode<T>* p = first; //p最终将指向第k个节点
	for (int index = 1; index < k && p; index++)
	{
		p = p->link;
	}
	if (k > 0 && !p)
	{
		cout << "不存在第k个元素" << endl;
		return *this;
	}
	ChainNode<T>* y = new ChainNode<T>; //实现插入
	y->data = x;
	if (0 == k) //作为第一个元素插入
	{
		y->link = first;
		first = y;
	}
	else
	{
		y->link = p->link;
		p->link = y;
	}
	if (!y->link) //跟踪最后一个元素
	{
		last = y;
	}
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Append(const T& x)
{ //在链表尾部添加x
	ChainNode<T>* y = new ChainNode<T>;
	y->data = x;
	y->link = 0;
	if (first) //链表非空
	{
		last->link = y;
		last = y;
	}
	else //链表为空
	{
		first = last = y;
	}
	return *this;
}

template<class T>
void Chain<T>::Output(std::ostream& out) const
{ //将链表元素送至输出流
	ChainNode<T>* current;
	for (current = first; current; current = current->link)
	{
		out << current->data << ' '; //需要T类型定义<<操作
	}
	std::cout << std::endl;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x)
{ //重载<<
	x.Output(out);
	return out;
}

template<class T>
T* ChainIterator<T>::Initialize(const Chain<T>& c)
{
	location = c.first;
	if (location)
	{
		cout << "链表遍历器初始化Initialize成功。" << endl;
		return &location->data;
	}
	else
	{
		cout << "链表为空，无法初始化链表遍历器。" << endl;
		return 0;
	}
}

template<class T>
T* ChainIterator<T>::Next()
{
	if (location)
	{
		location = location->link;
		if (location)
		{
			return &location->data;
		}
		else
		{
			cout << "链表中不存在下一节点" << endl;
			return 0;
		}
	}
	else
	{
		cout << "链表遍历器初始化时链表为空，故无法进行Next()操作。" << endl;
		return 0;
	}
}

//int main()
//{
//	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8;
//	Chain<int> Chain;
//	if (Chain.IsEmpty())
//	{
//		cout << "现在链表为空。" << endl;
//	}
//	else
//	{
//		cout << "现在链表不为空" << endl;
//	}
//	Chain.Append(a);
//	Chain.Output(cout);
//	Chain.Append(b);
//	Chain.Insert(1, c);
//	cout << Chain << endl;
//	Chain.Insert(0, d);
//	Chain.Insert(4, e);
//	Chain.Length();
//	Chain.Insert(-1, f);
//	Chain.Insert(6, f);
//	Chain.Length();
//	Chain.Output(cout);
//
//	system("pause");
//	return 0;
//}