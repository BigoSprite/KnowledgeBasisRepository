/*
	������38�����������������г��ֵĴ���
	��Ŀ��ͳ��һ�����������������г��ֵĴ�����
	      ����������������{1, 2, 3, 3, 3, 3, 4, 5}������3������3������4�Σ���ô���4��

	˼·��1��������������ͷ��β�������飬����¼����k�Ĵ�����ʱ�临�Ӷ�ΪO(n)��
	      2������������������ô��ʹ�ö��ֲ��ң��ҵ��м��k��Ȼ��ǰ�������β���k������¼���ֵĴ�����
			 ��ΪҪ���ҵ�����k�ڳ���Ϊn�������п��ܳ���O(n)�Σ����Ժ�˼·1������һ����
		  
		  3��ʱ�临�Ӷȸ��͵��㷨O(logn)

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
 * ʹ�ö��ֲ����ҵ����������еĵ�һ��k
 * @param data ��������
 * @param lenght ���鳤��
 * @param k Ҫ���ҵ�Ŀ��ֵ
 *
 * ʱ�临�Ӷȣ�O(logN)
 */
int getFirstK_Iteratively(int* data, int length, int k)
{
	// �߽�������� 
	if (data == NULL || length <= 0)
		return -1;

	// ��ʼ�����ͽ�������
	int startIndex = 0;
	int endIndex = length - 1;

	while (startIndex <= endIndex)
	{
		// �м�����
		int middleIndex = (endIndex - startIndex) / 2 + startIndex;// ֱ��ʹ��(high + low) / 2 ���ܵ������
		// �����Ƿ��ҵ������������ĸ��»򷵻�
		if (data[middleIndex] == k) {
			// �м�����Ϊ0���м�����Ϊ0��ǰһ�����ֲ�Ϊk����ô���k���ǵ�һ��
			if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
				return middleIndex;
			else
				endIndex = middleIndex - 1;
		}
		else if(data[middleIndex] > k)// k�����=>��������������λ��Ϊ�м�������ǰһ��λ��
			endIndex = middleIndex - 1;
		else
			startIndex = middleIndex + 1;
	}

	return -1;
}


/*
 * ʹ�ö��ֲ����ҵ����������е����һ��k
 * @param data ��������
 * @param length ���鳤��
 * @param k Ҫ���ҵ�Ŀ��ֵ
 *
 * ʱ�临�Ӷȣ�O(logN)
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