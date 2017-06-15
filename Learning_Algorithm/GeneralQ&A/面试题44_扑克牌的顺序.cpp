#include <iostream>
/*
	面试题44：扑克牌的顺序

	思路：把大小王当作0；A当作1；2~10为数字本身；JQK分别为11、12、13

	算法： 1.排序数组；
	       2.统计数组中0的个数m；
		   3.统计数字间的间隔总数n
				若n>m，则0不够填，那么这个数组不是连续的；否则连续。
		   注意：若数组中数字重复（即出现了对子），那么不连续。
*/

int Compare(const void* arg1, const void* arg2);

/** 
 * @功能 判断数组A是否是连续的
 * @param A 待判断的数组
 * @param N 数组的大小
 */
bool isContinuous(int A[], int N)
{
	if (A == NULL || N < 1)
		return false;

	// 使用C库函数中的快速排序来排序数组
	qsort(A, N, sizeof(int), Compare);
	
	// 统计0的个数
	int numberOfZeros = 0;
	for (int i = 0; i < N && A[i] == 0; ++i) {
		++numberOfZeros;
	}

	// 遍历数组统计间隔总数
	int numberOfGap = 0;
	int small = numberOfZeros, big = small + 1;
	while (big < N) {

		// 对子
		if (A[small] == A[big])
			return false;

		if (A[big] - A[small] != 1) {// 有空格
			numberOfGap += A[big] - A[small] - 1;
		}

		small = big;
		++big;
	}


	// 空格的总数 > 0的总数
	if (numberOfGap > numberOfZeros)
		return false;
	return true;
}

int Compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}


void main()
{
	int A[] = { 0, 1, 3, 2, 5, 6, 0 };

	std::cout << std::boolalpha <<isContinuous(A, 7) << std::endl;

	std::cin.get();
}