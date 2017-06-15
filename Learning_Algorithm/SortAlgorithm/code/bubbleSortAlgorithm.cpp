/*
 * 功能：冒泡排序
 * 思想：两两比较相邻的关键字值的大小，如果前面（小索引）的数据大于后面的数据，则交换；重复即可。
 *
 * 标准的冒泡排序代码
 * @param A[]：待排序数组
 * @param N：数组A元素的个数
 */
void bubbleSort(int A[], int N)
{
	// 外层循环	从第一个元素对应的索引到倒数第二个元素对应的索引
	for (int i = 0; i <= N - 2; ++i){
		// 内层循环的索引从倒数第二个元素对应索引到i
		for (int j = N - 2; j >= i; --j){
			// 如果前面的值＞后面的值，则交换
			if (A[j] > A[j + 1]){
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}	
	}
}


/*
 * 功能：改进的冒泡排序
 *
 * @param A[]：待排序数组
 * @param N：数组A元素的个数
 */
void bubbleSort_Ex(int A[], int N)
{
	bool flag = true;// 增加一个标志位

	for (int i = 0; i <= N - 2 && flag; ++i){

		flag = false;// 初始化为false

		// 内层for循环执行一圈后，如果flag=false，表明没有交换，即有序；整个排序算法时间复杂度最好O（N）；
		// 逆序为最坏情况:O(N^2)，即两层for循环都走一圈
		for (int j = N - 2; j >= i; --j){
			if (A[j] > A[j + 1]){
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				// 如果有交换，flag置为true
				flag = true;
			}
		}
	}
}