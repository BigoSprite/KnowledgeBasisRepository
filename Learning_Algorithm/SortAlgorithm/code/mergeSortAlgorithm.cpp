#include <iostream>

/*
* ���ܣ��ϲ�������������A[left...center]��A[center + 1...right]��Tmp������
* ˼�룺�鲢�еġ�����������
*      ֻҪ�ӱȽ����������еĵ�һ������˭С����ȡ˭��ȡ�˺���ڶ�Ӧ������ɾ�����ɡ�
*	   Ȼ���ٽ��бȽϣ��������ĳ�����е�ĩ�ˣ���ֱ�ӽ���һ�������˵���������ȡ�����ɡ�
*
* @param A[]������������
* @param left������A�ĵ�һ������
* @param right������A�����һ������
* @param center������A�м�λ�ö�Ӧ������
* @param Tmp���������������ݵ�����
*
* ʱ�临�Ӷȣ�O(N)
*/
void MergeArray(int A[], int left, int right, int center, int Tmp[])
{
	int i = left, j = center + 1, k = 0;	// Tmp���������

	// ��������û�е�����Ե�����β��
	while (i <= center && j <= right)
	{
		if (A[i] <= A[j])
			Tmp[k++] = A[i++];
		else
			Tmp[k++] = A[j++];
	}

	// ��������һ��������β��
	while (i <= center)// �ڶ��������鵽����β��
		Tmp[k++] = A[i++];
	while (j <= right)// ��һ�������鵽����β��
		Tmp[k++] = A[j++];

	// ����������ԭ����AΪ����
	for (int i = 0; i < k; ++i){
		A[left + i] = Tmp[i];// A[left + i] Yes, A[i] no
	}


}


/*
* ���ܣ��ݹ�ذ�����A�ֽ���������У�O(logN)����Ȼ���ٺϲ���O(N)��
* ˼�룺�鲢�еġ��顱���������ݹ�ķֽ���������С�
*		��������������������ˣ�
*		�ݹ�طֽ�����Ϊ�����飬�Դ����ƣ����ֳ�����С��ֻ��һ������ʱ��������Ϊ���С�������Ѿ��ﵽ������Ȼ���ٺϲ����ڵĶ���С��Ϳ����ˡ�
* ����ͨ���ȵݡ��顱�ķֽ����У��ٺϡ��������о�����˹鲢����
*
* @param A[]������������
* @param left������A�ĵ�һ������
* @param right������A�����һ������
* @param Tmp���������������ݵ�����
*
* ʱ�临�Ӷȣ�O(N��logN)
*/
void MSort(int A[], int left, int right, int Tmp[])
{
	int center;
	if (left < right){
		center = (left + right) / 2;
		// �������������
		MSort(A, left, center, Tmp);
		// �������ұ�����
		MSort(A, center + 1, right, Tmp);

		// �������ϲ���������O(N)
		MergeArray(A, left, right, center, Tmp);
	}
}


/*
* ���ܣ��ݹ������㷨����
* @param A[]������������
* @param N��AԪ�صĸ���
*/
void mergeSort(int A[], int N)
{
	// ��ʱ����
	int* tmp = (int*)malloc(N*sizeof(int));

	if (tmp){
	
		MSort(A, 0, N - 1, tmp);

		// �ͷ���Դ
		free(tmp);
	}
}