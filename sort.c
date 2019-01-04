

#define COUNT(arr) \
(sizeof(arr)/sizeof(arr[0]))


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

//插入排序每次都能保证前面的i个序列有序
//每次拿出一张牌，插到该插的位置，比这张牌大的后移
void insertion_sort(int arr[])
{
	int num = COUNT(arr);
	for (int i = 1; i < num; i++)//取出的牌从第二张牌（因为下标是0）开始往后取
	{
		int target = arr[i];//取出的牌
		for (int j = i-1; j > 0; j--)
		{
			if (target < arr[j])
			{
				arr[j + 1] = arr[j];//后移
			}
		}
		arr[i] = target;
	}

}


void bubble_sort(int arr[])
{
	int num = COUNT(arr);
	for (int i = num; i >0; i--)
	{
		int flag = 0;
		for (int j = 0; j < num; j++)//一趟排序最大的沉底
		{
			if (arr[j] < arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;//标记发生了交换
			}
		}
		if (flag == 0) break;//全程无交换
	}
}


//void selection_sort()