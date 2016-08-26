#include "3.4-Chain.h"

//int main()
//{
//	Chain<int> Chain;
//	if (Chain.IsEmpty())
//	{
//		std::cout << "��������Ϊ�ա�" << std::endl;
//	}
//	else
//	{
//		std::cout << "��������Ϊ��" << std::endl;
//	}
//
//	system("pause");
//	return 0;
//}

/*ֵ��ע�⣬����������һ���ȶ��������㷨��
  Ҳ����˵�������ͬ��ֵ�����λ��Ҳ������㷨����ʱ�����䶯*/
void quickSort(int a[], int len, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int baseIndex = partition(a, len, left, right); //һ�λ��ֺ󣬵õ���׼���ݵ�λ��
	quickSort(a, len, left, baseIndex - 1); //������߲���
	quickSort(a, len, baseIndex + 1, right); //�����ұ߲���
}

int partition(int a[], int len, int left, int right)
{
	int base = a[left]; //ÿһ�εĻ��֣����õ�һ��Ԫ����Ϊ��׼
	int baseIndex = left; //���¸տ�ʼ��λ�ã������������ʱ����
	while (left < right)
	{
		while (left < right && a[right] >= base) //�����Ҳ��ֱ�base��С��Ԫ�ص��±�
		{
			right--;
		}
		while (left < right && a[left] <= base) //�����󲿷ֱ�base�����Ԫ�ص��±�
		{
			left++;
		}
		swap(a, left, right); //����һ�˱Ȼ�׼��ͱȻ�׼С�����ҵ��ĵ�һ��ֵ�����ཻ��
	}
	/*��left��right����ʱ������׼���������㽻����
	  ������һ�λ��֣��Ϳ��Ա�֤��ߵıȻ�׼��С���ұߵıȻ�׼����*/
	swap(a, baseIndex, left);
	return left; //������ɺ���leftλ�õ�Ԫ����Ϊ�µĻ�׼���ֳ��������У��ֱ�ݹ�����
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}