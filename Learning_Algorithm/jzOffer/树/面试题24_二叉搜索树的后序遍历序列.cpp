/*
	面试题24：二叉搜索树的后序遍历序列
	题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
		  如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

		  左           右            根
	思路：{5, 7, 6,    9, 11, 10,     8}
	     后序遍历：左右根===>数组的最后一个元素是根节点存储的值。
		 二叉搜索树：任意左子树节点的值 < 根节点的值 < 任意右子树节点的值

		 ！！！记录一个索引i，指向数组中右子树的第一个元素。根据索引i进行递归即可。
*/
bool verifySquenceOfBST_Recursively(int data[], int length)
{
	if (data == NULL || length <= 0)
		return false;
	
	int rootValue = data[length - 1];
	
	// 记录一个索引i，指向数组中右子树的第一个元素；找到它
	int i = 0;
	for (; i < length - 1; ++i) {
		if (data[i] > rootValue)
			break;
	}
	// 判断右子树是否符合二叉搜索树的条件
	int j = i;
	for (; j < length - 1; ++j) {
		if (data[j] < rootValue)
			return false;
	}

	// 判断左子树是不是二叉搜索树
	bool isLeft = true;
	if (i > 0) 
		isLeft = verifySquenceOfBST_Recursively(data, i);

	// 判断右子树是不是二叉搜索树
	bool isRight = true;
	if (i < length - 1)
		isRight = verifySquenceOfBST_Recursively(data + i, length - i - 1);

	return isLeft&&isRight;
}