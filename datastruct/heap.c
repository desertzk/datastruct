

void heap_insert()
{

}






//�ܵ���˵���Ǻ��Լ������������нϴ�Ľ���
void siftdown(int a[], int curi, int n)
{
	int j=0;
	int curnode=0;
	curnode = a[curi];
	while ((j = 2 * curi + 1) < n)
	{
		if (j < n - 1 && a[j] < a[j + 1])
			j++;        //�Ƚ������ӽڵ��еĽϴ�ֵ
		if (curnode < a[j])//�����ǰ�ڵ�С���ӽڵ�  �򽻻�(��ʵ������ǰ��ӽڵ�����)
		{
			a[(j - 1) / 2] = a[j];
			curi = j;
		}
		else
			break;
	}
	a[(j - 1) / 2] = curnode;     //���������ڵ�λ��
}


void heap_sort(int a[], int n) 
{
	int curi = 0;
	int curnode = 0;
	for (curi = (n - 2) / 2; curi >= 0; curi--)
		siftdown(a, curi, n);
	//���˽��������
	for (curi = n-1; curi >0; curi--)
	{
		//����������ɾ���ѵĲ����ˣ������ֵ�ŵ����Ȼ�������
		curnode = a[0];
		a[0] = a[curi];
		a[curi] = curnode;
		
		siftdown(a, 0, curi);
	}
}
int arrheap[] = { 46,26,22,68,48,42,36,84,66 };


void main1231642()
{
	
	heap_sort(arrheap,9);

	system("pause");
}