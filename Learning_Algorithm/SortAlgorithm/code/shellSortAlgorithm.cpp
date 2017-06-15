

/*
 * 功能：希尔排序
 * 
 * 思想：分组插入排序。
 * 先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，
 * 然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小，通常为1）时，
 * 再对全体元素进行一次直接插入排序。
 *
 * 时间复杂度：最坏情况O(N^2)；使用Hibbard增量的希尔排序的最坏情况运行时间为O(N^(3/2))
 * 《大话数据结构》：不管怎么说，希尔排序是我们终于突破了慢速时代（超越了时间复杂度O(N^2)），之后更高效的排序算法出现了
 */
void shellSort(int A[], int N)
{
	int j, tmp;

	for (int increment = N / 2; increment > 0; increment /= 2){

		// increment==1时以下为插入排序
		for (int i = increment; i < N; ++i){

			tmp = A[i];

			for (j = i; j >= increment; j -= increment)
			{
				if (A[j - increment] > tmp)
					A[j] = A[j - increment];
				else
					break;
			}

			A[j] = tmp;
		}
	}
}