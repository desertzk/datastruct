

void heap_insert()
{

}






//总的来说就是和自己的两个儿子中较大的交换
void siftdown(int a[], int curi, int n)
{
	int j=0;
	int curnode=0;
	curnode = a[curi];
	while ((j = 2 * curi + 1) < n)
	{
		if (j < n - 1 && a[j] < a[j + 1])
			j++;        //比较左右子节点中的较大值
		if (curnode < a[j])//如果当前节点小于子节点  则交换(其实这里就是把子节点上移)
		{
			a[(j - 1) / 2] = a[j];
			curi = j;
		}
		else
			break;
	}
	a[(j - 1) / 2] = curnode;     //放在他该在的位置
}


void heap_sort(int a[], int n) 
{
	int curi = 0;
	int curnode = 0;
	for (curi = (n - 2) / 2; curi >= 0; curi--)
		siftdown(a, curi, n);
	//到此建立堆完毕
	for (curi = n-1; curi >0; curi--)
	{
		//以下类似于删除堆的操作了，把最大值放到最后然后调整堆
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