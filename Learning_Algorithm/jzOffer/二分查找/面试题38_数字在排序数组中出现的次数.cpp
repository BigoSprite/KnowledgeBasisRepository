/*
	面试题38：数字在排序数组中出现的次数
	题目：统计一个数字在排序数组中出现的次数。
	      例如输入排序数组{1, 2, 3, 3, 3, 3, 4, 5}和数字3，由于3出现了4次，那么输出4。

	思路：1、暴力搜索：从头到尾遍历数组，并记录数字k的次数；时间复杂度为O(n)。
	      2、由于数组已排序，那么可使用二分查找；找到中间的k，然后前后遍历逐次查找k，并记录出现的次数；
			 因为要查找的数字k在长度为n的数组中可能出现O(n)次，所以和思路1方法的一样。
		  
		  3、时间复杂度更低的算法O(logn)

*/
int getCountOfK(int* data, int length, int k)//O(logn)
{
	int count = 0;
	if (data != NULL && length > 0) {
		int first = getFirstK_Iteratively(data, length, k);// O(logn)
		int last = getLastK_Recursively(data, length,k, 0, length - 1);// O(logn)

		if (first > -1 && last > -1)
			return last - first + 1;
	}
}

/*
 * 使用二分查找找到排序数组中的第一个k
 * @param data 排序数组
 * @param lenght 数组长度
 * @param k 要查找的目标值
 *
 * 时间复杂度：O(logN)
 */
int getFirstK_Iteratively(int* data, int length, int k)
{
	// 边界条件检查 
	if (data == NULL || length <= 0)
		return -1;

	// 起始索引和结束索引
	int startIndex = 0;
	int endIndex = length - 1;

	while (startIndex <= endIndex)
	{
		// 中间索引
		int middleIndex = (endIndex - startIndex) / 2 + startIndex;// 直接使用(high + low) / 2 可能导致溢出
		// 根据是否找到，做出索引的更新或返回
		if (data[middleIndex] == k) {
			// 中间索引为0或中间索不为0且前一个数字不为k，那么这个k就是第一个
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
				return middleIndex;
			else
				endIndex = middleIndex - 1;
		}
		else if(data[middleIndex] > k)// k在左边=>调整结束索引的位置为中间索引的前一个位置
			endIndex = middleIndex - 1;
		else
			startIndex = middleIndex + 1;
	}

	return -1;
}


/*
 * 使用二分查找找到排序数组中的最后一个k
 * @param data 排序数组
 * @param length 数组长度
 * @param k 要查找的目标值
 *
 * 时间复杂度：O(logN)
 */
int getLastK_Recursively(int* data, int length, int k, int start, int end)
{
	if (data == NULL || length <= 0)
		return -1;

	int middle = (end - start) / 2 + start;
															   
	if (data[middle] == k) {

		if ((middle < length - 1 && data[middle + 1] != k) || middle == length - 1)
			return middle;
		else
			end = middle - 1;
	}
	else if (data[middle] > k)
		end = middle - 1;
	else
		end = middle + 1;

	return getLastK_Recursively(data, length, k, start, end);
}