/*
	������40��������ֻ����һ�ε�����

	��Ŀ��һ�����������������������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ
		  ����һ�ε����֡�Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1).
		
	���磺{1,1,5,2,3,3,2,6}
	
	
		  
	����������ֻ��һ������ֻ����һ�Σ��������־��������Σ���ô��������֣�
		{5, 2, 3, 3, 2}
		
	��һ������ν���������㣺���յĽ��Ϊ�Ǹ�ֻ����һ�ε����֣��ظ������ֱ�������
						  ��Ϊ�κ��������������0��
		0101  5
	  ^	0010  2
	   ------
		0111
	  ^ 0011  3
	  -------
	    0100
	  ^ 0011  3
	  -------
	    0111
	  ^ 0010  2
	  -------
	    0101  ���ս��Ϊ5
		
		
	��ˣ����԰�һ������ֳ��������飬ÿ�����鶼ֻ��һ�����ֳ���һ�Σ��������ֳ������Ρ�
	
	�ڶ��������Ը�����������A{1,1,5,2,3,3,2,6}�������õ����3��0011�����һλ�Ƿ�Ϊ1��
			��������A�ֳ�����{1,1,5,3,3}��{2,2,6}
					
	���������ֱ��������������򣬼����ҳ�5��6.
*/


void findNumsAppearOnce(int A[], int N, int* num1, int* num2)
{
	if(A == NULL || N < 2)
		return;
	
	// ��һ��
	int resultAfterOR = 0;
	for(int i = 0; i < N; ++i){
		resultAfterOR^=A[i];		
	}
	
	// �ڶ������ҵ�resultAfterOR�����������ұ�1�����������㿪ʼ��
	unsigned int indexOf1 = getIndexof1FromRightHand(resultAfterOR);
	
	// ���������������鲢�������������������
	*num1 = *num2 = 0;
	for(int j < 0; j < N; ++j){
		if(isBit1(A[j], indexOf1))
			*num1 ^= A[j];
		else
			*num2 ^= A[j];
	}
}

unsigned int getIndexof1FromRightHand(int num)
{
	int resultIndex = 0;
	
	// 0001010100  resultIndex==2
	while(((num&1)==0)&&(resultIndex < 8 * sizeof(int))){
		num = num >> 1;
		++resultIndex;
	}
	
	return resultIndex;
}

bool isBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;// 0010--->0001  indexBit==1��ע����ұ�������0��ʼ����
	return num&1;	
}









