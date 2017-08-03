/*
	面试题41：
	
	题目一：输入一个递增排序数组的和为一个数字s，在数组中查找两个数字，
			使得它们的和正好是s。如果有多对数字的和为s，那么输出任意一对即可。
			
	例子：数组{1,2,4,7,11,15}和数字15
	
	
	1、暴力法：遍历数组，每次固定一个数字，然后遍历后面的，判断和是否为15.
		最坏时间复杂度为：O(N^2)
	2、递增排序数组，和为15
		维护两个索引left和right，分别指向数组的第一个和最后一个元素，计算它们的和s；
		（1）如果s > 15，那么把right向左移动一个位置；
		（2）如果s < 15，那么把left向右移动一个位置；
		（3）如果s == 15，输出即可，over。
		最坏时间复杂度为O(N)
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
	题目二：输入一个数字s，打印出所有和为s的连续正整数数列（至少包含两个数字）。
		例如：输入15，由于1+2+3+4+5=4+5+6+7=7+8=15，所以打印出3个连续序列1~5,4~6和7~8.
		
		
		思路：维护两个数字small和big，并分别初始化为0和1，求sum=small+big，求sum
			（1）如果sum < s，增加big；
			（2）如果sum > s，增加small；
			（3）如果sum==s，打印输出，并增加big进行下一轮。
		因为至少需要两个连续数字，那么small一直增加到（1+s）/2为止。
--------------------------------------------------------------------------------		
		例如：s=9			（s+1）/ 2== 5
		
		步骤		small		big 		序列		和 		和s相比较  		下一步操作
		  1 		   1		 2           1,2	     3			<				增加big
		  2 		   1 		 3		     1,2,3       6          <               增加big
		  3            1         4           1,2,3,4     10         >               增加small
		  4            2         4           2,3,4       9          ==              打印序列，增加big
		  5            2         5           2,3,4,5     14         >               增加small
		  6            3         5           3,4,5       12         >               增加small
		  7            4         5           4,5         9          ==              打印序列，增加big
		  8            4         6           4,5,6       15         >               增加small，不能再增加了，因为small< 5             
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