/*
	������41��
	
	��Ŀһ������һ��������������ĺ�Ϊһ������s���������в����������֣�
			ʹ�����ǵĺ�������s������ж�����ֵĺ�Ϊs����ô�������һ�Լ��ɡ�
			
	���ӣ�����{1,2,4,7,11,15}������15
	
	
	1�����������������飬ÿ�ι̶�һ�����֣�Ȼ���������ģ��жϺ��Ƿ�Ϊ15.
		�ʱ�临�Ӷ�Ϊ��O(N^2)
	2�������������飬��Ϊ15
		ά����������left��right���ֱ�ָ������ĵ�һ�������һ��Ԫ�أ��������ǵĺ�s��
		��1�����s > 15����ô��right�����ƶ�һ��λ�ã�
		��2�����s < 15����ô��left�����ƶ�һ��λ�ã�
		��3�����s == 15��������ɣ�over��
		�ʱ�临�Ӷ�ΪO(N)
*/

void findNumsWithSum(int A[], int N, int sum, int* num1, int* num2)
{
	if(A == NULL || N < 2 || num1 == NULL || num2 == NULL)
		return false;
	
	int left = 0;
	int right = N - 1;
	
	while(left < right){
		int curSum = A[left] + A[right];
		
		if(curSum > sum)
			--right;
		else if(curSum < sum)
			++left;
		else{
			*num1 = A[left];
			*num2 = A[right];
			return true;
		}
	}
	
	return false;
}

/*
	��Ŀ��������һ������s����ӡ�����к�Ϊs���������������У����ٰ����������֣���
		���磺����15������1+2+3+4+5=4+5+6+7=7+8=15�����Դ�ӡ��3����������1~5,4~6��7~8.
		
		
		˼·��ά����������small��big�����ֱ��ʼ��Ϊ0��1����sum=small+big����sum
			��1�����sum < s������big��
			��2�����sum > s������small��
			��3�����sum==s����ӡ�����������big������һ�֡�
		��Ϊ������Ҫ�����������֣���ôsmallһֱ���ӵ���1+s��/2Ϊֹ��
--------------------------------------------------------------------------------		
		���磺s=9			��s+1��/ 2== 5
		
		����		small		big 		����		�� 		��s��Ƚ�  		��һ������
		  1 		   1		 2           1,2	     3			<				����big
		  2 		   1 		 3		     1,2,3       6          <               ����big
		  3            1         4           1,2,3,4     10         >               ����small
		  4            2         4           2,3,4       9          ==              ��ӡ���У�����big
		  5            2         5           2,3,4,5     14         >               ����small
		  6            3         5           3,4,5       12         >               ����small
		  7            4         5           4,5         9          ==              ��ӡ���У�����big
		  8            4         6           4,5,6       15         >               ����small�������������ˣ���Ϊsmall< 5             
*/

void findNumsWithContinuousSequence(int sum)
{
	if(sum < 3)
		return;
	
	int small = 1;
	int big = 2;
	int middle = (1+sum)/2;
	
	int curSum =  samll + big;
	
	while(small < middle){
		if(curSum == sum)
			printSequence(small, big);
		else if(curSum < sum)
			++big;
			curSum += big;
		else{
			curSum -= small;
			++small;
		}
	}
}