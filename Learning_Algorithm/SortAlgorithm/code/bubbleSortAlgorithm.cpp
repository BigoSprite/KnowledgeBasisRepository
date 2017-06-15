/*
 * ���ܣ�ð������
 * ˼�룺�����Ƚ����ڵĹؼ���ֵ�Ĵ�С�����ǰ�棨С�����������ݴ��ں�������ݣ��򽻻����ظ����ɡ�
 *
 * ��׼��ð���������
 * @param A[]������������
 * @param N������AԪ�صĸ���
 */
void bubbleSort(int A[], int N)
{
	// ���ѭ��	�ӵ�һ��Ԫ�ض�Ӧ�������������ڶ���Ԫ�ض�Ӧ������
	for (int i = 0; i <= N - 2; ++i){
		// �ڲ�ѭ���������ӵ����ڶ���Ԫ�ض�Ӧ������i
		for (int j = N - 2; j >= i; --j){
			// ���ǰ���ֵ�������ֵ���򽻻�
			if (A[j] > A[j + 1]){
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}	
	}
}


/*
 * ���ܣ��Ľ���ð������
 *
 * @param A[]������������
 * @param N������AԪ�صĸ���
 */
void bubbleSort_Ex(int A[], int N)
{
	bool flag = true;// ����һ����־λ

	for (int i = 0; i <= N - 2 && flag; ++i){

		flag = false;// ��ʼ��Ϊfalse

		// �ڲ�forѭ��ִ��һȦ�����flag=false������û�н��������������������㷨ʱ�临�Ӷ����O��N����
		// ����Ϊ����:O(N^2)��������forѭ������һȦ
		for (int j = N - 2; j >= i; --j){
			if (A[j] > A[j + 1]){
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				// ����н�����flag��Ϊtrue
				flag = true;
			}
		}
	}
}