#include "3.4-Chain.h"

//int main()
//{
//	Chain<int> Chain;
//	if (Chain.IsEmpty())
//	{
//		std::cout << "现在链表为空。" << std::endl;
//	}
//	else
//	{
//		std::cout << "现在链表不为空" << std::endl;
//	}
//
//	system("pause");
//	return 0;
//}

/*值得注意，快速排序不是一种稳定的排序算法，
  也就是说，多个相同的值的相对位置也许会在算法结束时产生变动*/
void quickSort(int a[], int len, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int baseIndex = partition(a, len, left, right); //一次划分后，得到基准数据的位置
	quickSort(a, len, left, baseIndex - 1); //快排左边部分
	quickSort(a, len, baseIndex + 1, right); //快排右边部分
}

int partition(int a[], int len, int left, int right)
{
	int base = a[left]; //每一次的划分，都让第一个元素作为基准
	int baseIndex = left; //记下刚开始的位置，便于最后相遇时交换
	while (left < right)
	{
		while (left < right && a[right] >= base) //查找右部分比base还小的元素的下标
		{
			right--;
		}
		while (left < right && a[left] <= base) //查找左部分比base还大的元素的下标
		{
			left++;
		}
		swap(a, left, right); //将这一趟比基准大和比基准小的所找到的第一个值，互相交换
	}
	/*在left与right相遇时，将基准数与相遇点交换，
	  这样这一次划分，就可以保证左边的比基准数小，右边的比基准数大*/
	swap(a, baseIndex, left);
	return left; //划分完成后，以left位置的元素作为新的基准，分成左右序列，分别递归排序
}

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}