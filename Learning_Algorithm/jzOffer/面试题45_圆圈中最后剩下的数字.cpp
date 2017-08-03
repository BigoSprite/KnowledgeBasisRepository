#include <iostream>
#include <list>
/*
	面试题43：圆圈中最后剩下的数字
			0~n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
			删除第m个数字。求最后剩下的数字。

	思路：1.使用STL中的list来模拟循环链表
*/

/*
 * @功能 圆圈中最后剩下的数字
 * @param n 数字的个数
 * @param m 要删除第m个数字
 *
 * @复杂度 #1时间复杂度O(m·n);#2空间复杂度O(n)
 */
int getLastNumber(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;

	// #2 把0...n-1这些数字存入list
	std::list<int> numbersList;
	for (int i = 0; i < n; ++i)
		numbersList.push_back(i);
	
	std::list<int>::iterator current = numbersList.begin();
	// #1
	while (numbersList.size() > 1) {
		for (int i = 1; i < m; ++i) {// 走m-1步找到要删除节点的位置（迭代器）
			++current;
			if (current == numbersList.end())// 当前迭代器current每向前走一步，就需要判断是否到达end()
				current = numbersList.begin();
		}

		// 删除（注意erase会使得迭代器失效）
		// 方法1
		//auto next = ++current;// 先把指向下一个元素的迭代器保存下来，因为erase迭代器会使得迭代器失效
		//if (next == numbersList.end())
		//	next = numbersList.begin();		
		//--current;// 上行代码不能使用current + 1，它是错误的，因为list不支持随机访问！
		//numbersList.erase(current);
		//current = next;
		// 或者 方法2
		current = numbersList.erase(current);// OR numbersList.erase(current++);其中，pos = current++;
		if (current == numbersList.end())
			current = numbersList.begin();
	}

	return *current;
}