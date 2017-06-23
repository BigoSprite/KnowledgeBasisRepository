/*
	面试题18：树的子结构
	题目：输入两棵二叉树A和B，判断B是否是A的子结构。

	思路：第一步：使用前序遍历在树A中找到和B的根节点的值一样的节点R；
	      第二步：使用前序遍历判断A中以R为根节点的子树是不是包含和树B一样的结构。
*/
struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

// 第二步
bool doesTreeAHasTreeB(TreeNode* pRootA, TreeNode* pRootB);

// 第一步
bool hasSubtree(TreeNode* pRootA, TreeNode* pRootB)
{
	bool result = false;

	if (pRootA && pRootB) {// 非空
		if (pRootA->m_nValue == pRootB->m_nValue)
			result = doesTreeAHasTreeB(pRootA, pRootB);	// 找到A树中与B树中根节点值相同的节点node后
														// 判断以node为根节点的树是否包含B树子结构
		// 左
		if (!result)
			result = hasSubtree(pRootA->m_pLeft, pRootB);
		// 右
		if (!result)
			result = hasSubtree(pRootA->m_pRight, pRootB);
	}

	return result;
}


bool doesTreeAHasTreeB(TreeNode* pRootA, TreeNode* pRootB)
{
	if (pRootB == NULL)
		return true;
	if (pRootA == NULL)
		return false;

	if (pRootA->m_nValue != pRootB->m_nValue)
		return false;

	bool isLeft = doesTreeAHasTreeB(pRootA->m_pLeft, pRootB->m_pLeft);
	bool isRight = doesTreeAHasTreeB(pRootA->m_pRight, pRootB->m_pRight);

	return isLeft && isRight;
}