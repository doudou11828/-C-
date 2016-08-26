#pragma once
#include <iostream>

/*3.4������������һ�����Ա��ʾ��һ����*/
template<class T> //ǰ�������Ա�������Ԫ��
class Chain;
template<class T> //ǰ�������Ա�������Ԫ��
class ChainIterator;

template<class T>
class ChainNode //�ڵ���
{
	friend class Chain<T>; //Chain<T>�г�Ա������ΪChainNode<T>����Ԫ�������ɷ���ChainNode<T>˽�г�Ա
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class Chain //������
{
	friend class ChainIterator<T>;
public:
	Chain() { first = 0; }
	~Chain();
	void Erase(); //�����亯����ɾ�����������нڵ㣬�ȼ�����������
	void Zero() { first = 0; } //�����亯������firstָ����Ϊ0������ɾ���κνڵ�
	bool IsEmpty() const { return 0 == first; }
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	Chain<T>& Append(const T& x); //�����亯�����������Ҷ����һ��Ԫ��
	void Output(std::ostream& out) const;
private:
	ChainNode<T>* first; //ָ���һ���ڵ��ָ��
	ChainNode<T>* last; //������������һ��Ԫ�أ�Ϊ���亯��Append()����
};

template<class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x);

template<class T>
class ChainIterator
{
public:
	T* Initialize(const Chain<T>& c); //��locationָ�������е�һ���ڵ㣬������ָ��ýڵ��������ָ��
	T* Next(); //��locationָ����������һ���ڵ㣬������ָ��ýڵ��������ָ��
private:
	ChainNode<T>* location; //���ڸ��ٵ�ǰ��������������λ��
};
