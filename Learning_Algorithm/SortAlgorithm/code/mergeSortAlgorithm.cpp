#include <iostream>

/*
* 功能：合并两个有序数列A[left...center]和A[center + 1...right]到Tmp数组中
* 思想：归并中的“并”操作。
*      只要从比较这两个数列的第一个数，谁小就先取谁，取了后就在对应数列中删除即可。
*	   然后再进行比较，如果到达某个数列的末端，则直接将另一个数列了的数据依次取出即可。
*
* @param A[]：待排序数组
* @param left：数组A的第一个索引
* @param right：数组A的最后一个索引
* @param center：数组A中间位置对应的索引
* @param Tmp：接收已排列数据的数组
*
* 时间复杂度：O(N)
*/
void MergeArray(int A[], int left, int right, int center, int Tmp[])
{
	int i = left, j = center + 1, k = 0;	// Tmp数组的索引

	// ！！！都没有到达各自的数组尾端
	while (i <= center && j <= right)
	{
		if (A[i] <= A[j])
			Tmp[k++] = A[i++];
		else
			Tmp[k++] = A[j++];
	}

	// ！！！有一个到达了尾端
	while (i <= center)// 第二个子数组到达了尾端
		Tmp[k++] = A[i++];
	while (j <= right)// 第一个子数组到达了尾端
		Tmp[k++] = A[j++];

	// ！！！更新原数组A为有序
	for (int i = 0; i < k; ++i){
		A[left + i] = Tmp[i];// A[left + i] Yes, A[i] no
	}


}


/*
* 功能：递归地把数组A分解成有序数列（O(logN)），然后再合并（O(N)）
* 思想：归并中的“归”操作——递归的分解成有序数列。
*		如何让数组内数据有序了？
*		递归地分解数组为两数组，以此类推；当分出来的小组只有一个数据时，可以认为这个小组组内已经达到了有序，然后再合并相邻的二个小组就可以了。
* 这样通过先递“归”的分解数列，再合“并”数列就完成了归并排序。
*
* @param A[]：待排序数组
* @param left：数组A的第一个索引
* @param right：数组A的最后一个索引
* @param Tmp：接收已排列数据的数组
*
* 时间复杂度：O(N·logN)
*/
void MSort(int A[], int left, int right, int Tmp[])
{
	int center;
	if (left < right){
		center = (left + right) / 2;
		// ！！！左边有序
		MSort(A, left, center, Tmp);
		// ！！！右边有序
		MSort(A, center + 1, right, Tmp);

		// ！！！合并操作——O(N)
		MergeArray(A, left, right, center, Tmp);
	}
}


/*
* 功能：递归排序算法主程
* @param A[]：待排序数组
* @param N：A元素的个数
*/
void mergeSort(int A[], int N)
{
	// 临时数组
	int* tmp = (int*)malloc(N*sizeof(int));

	if (tmp){
	
		MSort(A, 0, N - 1, tmp);

		// 释放资源
		free(tmp);
	}
}