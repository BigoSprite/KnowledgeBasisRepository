/*
	面试题40：数组中只出现一次的数字

	题目：一个整型数组里除了两个数字之外，其他数字都出现了两次。请写程序找出这两个只
		  出现一次的数字。要求时间复杂度为O(n)，空间复杂度为O(1).
		
	例如：{1,1,5,2,3,3,2,6}
	
	
		  
	考虑数组中只有一个数字只出现一次，其他数字均出现两次，怎么找这个数字？
		{5, 2, 3, 3, 2}
		
	第一步：逐次进行异或运算：最终的结果为那个只出现一次的数字，重复的数字被抵消；
						  因为任何数字异或本身都等于0。
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
	    0101  最终结果为5
		
		
	因此，可以把一个数组分成两个数组，每个数组都只有一个数字出现一次，其他数字出现两次。
	
	第二步：可以根据整个数组A{1,1,5,2,3,3,2,6}异或运算得到结果3（0011）最后一位是否为1，
			来把数组A分成两组{1,1,5,3,3}和{2,2,6}
					
	第三步：分别对两个数组求异或，即可找出5和6.
*/


void findNumsAppearOnce(int A[], int N, int* num1, int* num2)
{
	if(A == NULL || N < 2)
		return;
	
	// 第一步
	int resultAfterOR = 0;
	for(int i = 0; i < N; ++i){
		resultAfterOR^=A[i];		
	}
	
	// 第二步：找到resultAfterOR二进制中最右边1的索引（从零开始）
	unsigned int indexOf1 = getIndexof1FromRightHand(resultAfterOR);
	
	// 第三步：遍历数组并根据条件进行异或运算
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
	num = num >> indexBit;// 0010--->0001  indexBit==1（注意从右边数，从0开始数）
	return num&1;	
}









