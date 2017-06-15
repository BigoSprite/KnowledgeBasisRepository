/*
 * 功能：快速排序驱动程序
 *
 * 思想：挖坑填数。
 * 维护两个索引，把第一个元素作为基准（旧坑）<把第一个元素作为基准其实不好，这里着重于算法本身>。
 * 1. 然后先从后往前找到比基准数小的数（新坑），把数填入旧坑中；
 * 2. 然后再从前往后找比基准数大的放入新坑，形成新的新坑。重复1。
 *
 * @param A：待排序数组
 * @param left：左边的索引
 * @param right：右边的索引
 */
int QSort(int A[], int left, int right)
{
	int i = left;
	int j = right;
	int tmp = A[left];// ！！！A[left]为第一个坑

	while (i < j)
	{
		// ！！！从后往前找
		while (i < j && A[j] >= tmp)
			--j;
		if (i < j){// 找到后，填坑
			A[i] = A[j];// 形成新坑A[j]
			++i;
		}

		// ！！！从前往后找
		while (i < j && A[i] < tmp)
			++i;
		if (i < j){// 找到后，填坑
			A[j] = A[i];
			--j;
		}
	}

	// ！！！退出时，i = j；将tmp填到这个坑中 
	A[i] = tmp;

	return i;
}


/*
 * 功能：快速排序
 *
 * 该方法的基本思想是：
 * 1．先从数列中取出一个数作为基准数(或枢纽元)。
 * 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
 * 3．再对左右区间重复第二步，直到各区间只有一个数。
 *
 * @param A：待排序数组
 * @param left：左边的索引
 * @param right：右边的索引

 * 时间复杂度：O(N·logN)
 */
void quickSort(int A[], int left, int right)
{
	if (left < right){
		int i = QSort(A, left, right);
		// ！！！索引为i的元素为中间值，下次递归时，不再考虑
		quickSort(A, left, i - 1);
		quickSort(A, i + 1, right);	
	}
}