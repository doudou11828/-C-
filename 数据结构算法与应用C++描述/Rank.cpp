#include <iostream>

using namespace std;

template <typename T>
void Rank(T a[], int n, int r[]) //��������
{
	for (int i = 0; i < n; i++)
	{
		r[i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] <= a[i])
			{
				r[i]++;
			}
			else
			{
				r[j]++;
			}
		}
	}
	for (int i = 0; i < 5; i++) //��ӡ����
	{
	cout << r[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void Rearrange(T a[], int n, int r[]) //����������
{
	T *tempArr = new T[n];
	for (int i = 0; i < n; i++)
	{
		tempArr[r[i]] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = tempArr[i];
	}
	delete[]tempArr;
	tempArr = NULL;
	for (int i = 0; i < n; i++) //��ӡ��������������a
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void main(void)
{
	int *a = new int[5];
	a[0] = 4;
	a[1] = 3;
	a[2] = 9;
	a[3] = 3;
	a[4] = 7;
	int n = 5;
	int *r = new int[5];
	for (int i = 0; i < n; i++) //��ӡ����ǰ������a
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	Rank(a, n, r); //Rank�������ӡ����r
	Rearrange(a, n, r); //Rearrange�����ڻ��ӡ��������������a
	
	delete[]a;
	a = NULL;
	delete[]r;
	r = NULL;

	system("pause");
}