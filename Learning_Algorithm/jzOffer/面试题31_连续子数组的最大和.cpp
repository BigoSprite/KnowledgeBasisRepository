/*
	������31������һ���������飬������������Ҳ�и�����������һ���������Ķ���������һ�������顣
			   ������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(N).
			  
	���磺{1,-2,3,10,-4,7,2,-5}
	
	����  	����	curSum	 greastSum	
	  1      ��1       1         1     ���curSum > 0����ô������
	  2      ��-2      -1        1
	  3      ��ֵ3     3         3     ���curSum < 0����ô��ֵ
	  4      ��10      13        13    ���curSum > greastSum����ô����greastSum
	  5      ��-4      9         13
	  6      ��7       16        16
	  7      ��2       18        18
	  8      ��-5      13        18			
*/

bool g_InvalidInput = false;// ��־λ

int getGreastSumOfSubArray(int A[], int N)
{
	if(A == NULL || N < 1)
		g_InvalidInput = true;
		return -1;
	
	int curSum = 0;
	int greastSum = 0x80000000;// ��С�ĸ���
	// �������飬�����ĺ�
	for(int i = 0; i < N; ++i){
		if(curSum <= 0)
			curSum = A[i];
		else
			curSum += A[i];
		
		if(curSum > greastSum)
			greastSum = curSum;		
	}
	
	return greastSum;
}