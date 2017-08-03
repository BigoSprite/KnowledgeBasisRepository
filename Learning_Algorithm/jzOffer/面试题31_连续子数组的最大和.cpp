/*
	面试题31：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。
			   求所有子数组的和的最大值。要求时间复杂度为O(N).
			  
	例如：{1,-2,3,10,-4,7,2,-5}
	
	步骤  	操作	curSum	 greastSum	
	  1      加1       1         1     如果curSum > 0，那么就增加
	  2      加-2      -1        1
	  3      赋值3     3         3     如果curSum < 0，那么赋值
	  4      加10      13        13    如果curSum > greastSum，那么更新greastSum
	  5      加-4      9         13
	  6      加7       16        16
	  7      加2       18        18
	  8      加-5      13        18			
*/

bool g_InvalidInput = false;// 标志位

int getGreastSumOfSubArray(int A[], int N)
{
	if(A == NULL || N < 1)
		g_InvalidInput = true;
		return -1;
	
	int curSum = 0;
	int greastSum = 0x80000000;// 最小的负数
	// 遍历数组，找最大的和
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