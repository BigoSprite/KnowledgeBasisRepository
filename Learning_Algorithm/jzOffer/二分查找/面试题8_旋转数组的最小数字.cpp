/*
	面试题8：旋转数组的最小数字
	题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
		  输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
		  例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

	思路：1.暴力法：顺序遍历数组，找到最小元素；时间复杂度O(N)；没用到旋转数组的特性，面试官不会满意。
	      2.使用二分查找，时间复杂度O(logN)。
		    维护两个索引start和end，求中间索引middle。判断该索引对应值位于哪个递增的子数组中:
				2-1.若data[middle] >= data[start]，则它位于前面的递增子数组，令start=middle以缩小范围；
				2-2.若data[middle] <= data[end]，则它位于后面的递增子数组，令end=middle以缩小范围；
				2-3.若start和end相邻，即相差1，那么停止循环；end所指元素即为最小元素。
*/
int getMinNumber(int data[], int length)
{
	if (data == NULL || length <= 0)
		throw new std::exception("Invalid parameters.");// 不可用

	int start = 0;
	int end = length - 1;
	// middle保存最小值的索引
	int middle = start;// ！！！如果把数组前面的第0个元素搬到数组末尾；下面循环不执行，直接返回数组的第一个元素
	while (data[start] >= data[end]) {// 前面索引对应的值始终大于后面的才循环

		if (end - start == 1) {// ！！！ 循环的终止条件
			middle = start;// middle保存最小值的索引
			break;
		}

		middle = (end - start) / 2 + start;

		// ！！！如果start、end及middle三个索引对应的值相等，那么只能使用顺序查找最小值
		if (data[start] == data[middle] && data[end] == data[middle])
			return getMinInOrder(data, start, end);

		if (data[middle] >= data[start]) {
			start = middle;
		}
		else if (data[middle] <= data[end]) {
			end = middle;
		}
	}

	return data[middle];// middle
}

/*
	顺序查找data数组中的最小值
	传入start和end索引是因为，查找的区间可能是data的子区间
*/
int getMinInOrder(int data[], int start, int end)
{
	int min = data[start];
	for (int i = start + 1; i <= end; ++i) {
		if (data[i] < min) {
			min = data[i];
		}
	}
	return min;
}

