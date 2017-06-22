/*
	面试题6：重建二叉树
	题目：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
		  假设输入的前序遍历和中序遍历的结果中不包含重复的数字。例如：
		  前序遍历：{1, 2, 4, 7, 3, 5, 6, 8}；中序遍历：{4, 7, 2, 1, 5, 3, 8, 6},
		  请重建出图2.6所示的二叉树并输出它的头节点。

	思路：前序遍历：根左右；中序遍历：左根右
	      --->1为根；然后遍历中序遍历的结果，找到指向根节点的指针；并计算出左子树的长度，
		  这里如果知道左子树的长度，那么前就知道了序遍历中的左子树序列及中序遍历中的左子树序列；右子树亦如此。
		  然后，递归地构造二叉树即可。
	
*/
#include <exception>
struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

TreeNode* construct(int* preOrder, int* inOrder, int length)
{
	if (preOrder == NULL || inOrder == NULL || length <= 0)
		return NULL;
	return constructCore(preOrder, preOrder + length - 1,
		inOrder, inOrder + length - 1);
}

/*
	@param startPreOrder 前序遍历结果序列起始元素的位置（指针）
	@param endPreOrder 前序遍历结果序列结束元素的位置（指针）
	@param startInOrder 中序遍历结果序列起始元素的位置（指针）
	@param endInOrder 中序遍历结果序列尾元素的位置（指针）
*/
TreeNode* constructCore(
	int* startPreOrder, int* endPreOrder,
	int* startInOrder, int* endInOrder)
{
	// 根节点存储的值
	int rootValue = *startPreOrder;

	//！！！根节点
	TreeNode* pRoot = new TreeNode();
	pRoot->m_nValue = rootValue;
	pRoot->m_pLeft = NULL;
	pRoot->m_pRight = NULL;

	// 合法性
	if (startPreOrder == endPreOrder) {
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return pRoot;
		else
			throw std::exception("Invalid input.");
	}

	// ！！！找到中序序列中“指向根节点的指针”：rootInOrder
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;

	// 合法性
	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
		throw std::exception("Invalid input.");

	// 计算左子树节点序列的长度：leftLength
	int leftLength = rootInOrder - startInOrder;

	int* leftPreOrderEnd = startPreOrder + leftLength;// 前序遍历中左子树序列结束的指针
	if (leftLength > 0) 
		pRoot->m_pLeft = constructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	if (leftLength < endPreOrder - startPreOrder)
		pRoot->m_pRight = constructCore(leftPreOrderEnd + 1, endPreOrder,
			rootInOrder + 1, endInOrder);

	return pRoot;
}