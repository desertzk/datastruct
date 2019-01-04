

#define COUNT(arr) \
(sizeof(arr)/sizeof(arr[0]))


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

//��������ÿ�ζ��ܱ�֤ǰ���i����������
//ÿ���ó�һ���ƣ��嵽�ò��λ�ã��������ƴ�ĺ���
void insertion_sort(int arr[])
{
	int num = COUNT(arr);
	for (int i = 1; i < num; i++)//ȡ�����ƴӵڶ����ƣ���Ϊ�±���0����ʼ����ȡ
	{
		int target = arr[i];//ȡ������
		for (int j = i-1; j > 0; j--)
		{
			if (target < arr[j])
			{
				arr[j + 1] = arr[j];//����
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
		for (int j = 0; j < num; j++)//һ���������ĳ���
		{
			if (arr[j] < arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag = 1;//��Ƿ����˽���
			}
		}
		if (flag == 0) break;//ȫ���޽���
	}
}


//void selection_sort()