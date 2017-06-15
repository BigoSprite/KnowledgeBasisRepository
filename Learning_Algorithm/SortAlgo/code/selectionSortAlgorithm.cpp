/*
* 功能：简单选择排序
*
* @param A[]：待排序数组
* @param N：数组A元素的个数
*
* 时间复杂度：O(N^2)
*/
void selectionSort(int A[], int N)
{
	// 1. 外层循环从数组第一个元素遍历到倒数第二个元素
	for (int i = 0; i < N - 1; ++i)
	{
		int min = i;// min记录元素值较小的索引

		// 2.内层循环遍历当前i索引之后的所有元素
		for (int j = i + 1; j < N; ++j)
		{// 从内层循环中找到最小元素的索引
			if (A[min] > A[j])
			{// 更新min对应索引的位置
				min = j;
 			}		
		}

		// 此时min索引对应最小的元素，与当前i索引对应的元素交换即可
		int tmp = A[min];
		A[min] = A[i];
		A[i] = tmp;
	}
}

