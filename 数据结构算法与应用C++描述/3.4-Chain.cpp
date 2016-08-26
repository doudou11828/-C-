#include "3.4-Chain.h"

using std::cout;
using std::endl;

template<class T>
Chain<T>::~Chain()
{ //������������ɾ�����������нڵ㣬����Ϊ���ó�Ա����Erase()
	Erase();
}

template<class T>
void Chain<T>::Erase()
{ //ɾ�������е����нڵ�
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
{ //����������Ԫ������
	ChainNode<T>* current = first;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}
	cout << "������Ϊ��" << len << endl;
	return len;
}

template<class T>
bool Chain<T>::Find(int k, T& x) const
{ //Ѱ�������е�k��Ԫ�أ������䴫����x���������ڵ�k��Ԫ�أ�����false�����򷵻�true
	if (k < 1)
	{
		return false;
	}
	ChainNode<T>* current = first;
	int index = 1; //current������
	while (index < k && current)
	{
		current = current->link;
		index++;
	}
	if (current) //current��Ϊ�գ�˵�����ڵ�k��Ԫ��
	{
		x = current->data;
		return true;
	}
	return false;
}

template<class T>
int Chain<T>::Search(const T& x) const
{ //Ѱ��x�����ҵ�������x�ĵ�ַ������������x���������У�����0
	ChainNode<T>* current = first;
	int index = 1; //current������
	while (current && current->data != x) //��ҪT���Ͷ���!=����
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
{ //�ѵ�k��Ԫ��ȡ��x��Ȼ���������ɾ����k��Ԫ��
  //�������Σ�1)kС��1������Ϊ�գ�2)����Ϊ����ɾ����Ԫ�أ�3)����Ϊ����ɾ����Ԫ��֮���Ԫ��
	if (k < 1 || !first)
	{
		cout << "����k<1��������Ϊ�գ������ڵ�k��Ԫ��" << endl;
		return -1;
	}
	ChainNode<T>* p = first; //p���ս�ָ���k���ڵ�
	if (1 == k) //p�Ѿ�ָ����Ҫɾ������Ԫ�أ�ɾ��֮
	{
		first = first->link;
	}
	else //��qָ���k-1��Ԫ��
	{
		ChainNode<T>* q = first;
		for (int index = 1; index < k - 1 && q; index++)
		{
			q = q->link;
		}
		if (!q || !q->link)
		{
			cout << "����Ϊ�գ�������Ԫ������С��k���ʲ����ڵ�k��Ԫ��" << endl;
			return -1;
		}
		p = q->link; //��pָ���k��Ԫ��
		if (p == last) //�������һ��Ԫ��
		{
			last = q;
		}
		q->link = p->link; //ɾ����k��Ԫ��
	}
	x = p->data;
	delete p;
	p = NULL;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{ //�ڵ�k��Ԫ��֮�����x
	if (k < 0)
	{
		cout << "����k<0�������ڵ�k��Ԫ��" << endl;
		return *this;
	}
	ChainNode<T>* p = first; //p���ս�ָ���k���ڵ�
	for (int index = 1; index < k && p; index++)
	{
		p = p->link;
	}
	if (k > 0 && !p)
	{
		cout << "�����ڵ�k��Ԫ��" << endl;
		return *this;
	}
	ChainNode<T>* y = new ChainNode<T>; //ʵ�ֲ���
	y->data = x;
	if (0 == k) //��Ϊ��һ��Ԫ�ز���
	{
		y->link = first;
		first = y;
	}
	else
	{
		y->link = p->link;
		p->link = y;
	}
	if (!y->link) //�������һ��Ԫ��
	{
		last = y;
	}
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Append(const T& x)
{ //������β�����x
	ChainNode<T>* y = new ChainNode<T>;
	y->data = x;
	y->link = 0;
	if (first) //����ǿ�
	{
		last->link = y;
		last = y;
	}
	else //����Ϊ��
	{
		first = last = y;
	}
	return *this;
}

template<class T>
void Chain<T>::Output(std::ostream& out) const
{ //������Ԫ�����������
	ChainNode<T>* current;
	for (current = first; current; current = current->link)
	{
		out << current->data << ' '; //��ҪT���Ͷ���<<����
	}
	std::cout << std::endl;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x)
{ //����<<
	x.Output(out);
	return out;
}

template<class T>
T* ChainIterator<T>::Initialize(const Chain<T>& c)
{
	location = c.first;
	if (location)
	{
		cout << "�����������ʼ��Initialize�ɹ���" << endl;
		return &location->data;
	}
	else
	{
		cout << "����Ϊ�գ��޷���ʼ�������������" << endl;
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
			cout << "�����в�������һ�ڵ�" << endl;
			return 0;
		}
	}
	else
	{
		cout << "�����������ʼ��ʱ����Ϊ�գ����޷�����Next()������" << endl;
		return 0;
	}
}

//int main()
//{
//	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8;
//	Chain<int> Chain;
//	if (Chain.IsEmpty())
//	{
//		cout << "��������Ϊ�ա�" << endl;
//	}
//	else
//	{
//		cout << "��������Ϊ��" << endl;
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