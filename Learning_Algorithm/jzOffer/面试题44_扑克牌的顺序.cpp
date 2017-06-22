#include <iostream>
/*
	������44���˿��Ƶ�˳��

	˼·���Ѵ�С������0��A����1��2~10Ϊ���ֱ���JQK�ֱ�Ϊ11��12��13

	�㷨�� 1.�������飻
	       2.ͳ��������0�ĸ���m��
		   3.ͳ�����ּ�ļ������n
				��n>m����0�������ô������鲻�������ģ�����������
		   ע�⣺�������������ظ����������˶��ӣ�����ô��������
*/

int Compare(const void* arg1, const void* arg2);

/** 
 * @���� �ж�����A�Ƿ���������
 * @param A ���жϵ�����
 * @param N ����Ĵ�С
 */
bool isContinuous(int A[], int N)
{
	if (A == NULL || N < 1)
		return false;

	// ʹ��C�⺯���еĿ�����������������
	qsort(A, N, sizeof(int), Compare);
	
	// ͳ��0�ĸ���
	int numberOfZeros = 0;
	for (int i = 0; i < N && A[i] == 0; ++i) {
		++numberOfZeros;
	}

	// ��������ͳ�Ƽ������
	int numberOfGap = 0;
	int small = numberOfZeros, big = small + 1;
	while (big < N) {

		// ����
		if (A[small] == A[big])
			return false;

		if (A[big] - A[small] != 1) {// �пո�
			numberOfGap += A[big] - A[small] - 1;
		}

		small = big;
		++big;
	}


	// �ո������ > 0������
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