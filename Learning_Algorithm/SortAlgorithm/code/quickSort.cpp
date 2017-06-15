/*
 * ���ܣ�����������������
 *
 * ˼�룺�ڿ�������
 * ά�������������ѵ�һ��Ԫ����Ϊ��׼���ɿӣ�<�ѵ�һ��Ԫ����Ϊ��׼��ʵ���ã������������㷨����>��
 * 1. Ȼ���ȴӺ���ǰ�ҵ��Ȼ�׼��С�������¿ӣ�����������ɿ��У�
 * 2. Ȼ���ٴ�ǰ�����ұȻ�׼����ķ����¿ӣ��γ��µ��¿ӡ��ظ�1��
 *
 * @param A������������
 * @param left����ߵ�����
 * @param right���ұߵ�����
 */
int QSort(int A[], int left, int right)
{
	int i = left;
	int j = right;
	int tmp = A[left];// ������A[left]Ϊ��һ����

	while (i < j)
	{
		// �������Ӻ���ǰ��
		while (i < j && A[j] >= tmp)
			--j;
		if (i < j){// �ҵ������
			A[i] = A[j];// �γ��¿�A[j]
			++i;
		}

		// ��������ǰ������
		while (i < j && A[i] < tmp)
			++i;
		if (i < j){// �ҵ������
			A[j] = A[i];
			--j;
		}
	}

	// �������˳�ʱ��i = j����tmp�������� 
	A[i] = tmp;

	return i;
}


/*
 * ���ܣ���������
 *
 * �÷����Ļ���˼���ǣ�
 * 1���ȴ�������ȡ��һ������Ϊ��׼��(����ŦԪ)��
 * 2���������̣���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
 * 3���ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
 *
 * @param A������������
 * @param left����ߵ�����
 * @param right���ұߵ�����

 * ʱ�临�Ӷȣ�O(N��logN)
 */
void quickSort(int A[], int left, int right)
{
	if (left < right){
		int i = QSort(A, left, right);
		// ����������Ϊi��Ԫ��Ϊ�м�ֵ���´εݹ�ʱ�����ٿ���
		quickSort(A, left, i - 1);
		quickSort(A, i + 1, right);	
	}
}