#include <iostream>
#include <list>
/*
	面试题58：二叉树的下一个节点
	
	题目：给定一棵二叉树和其中一个节点，如何找出中序遍历顺序的下一个节点？
		 树中的节点（根节点除外）除了有两个分别指向左右子节点的指针以外，还有一个指向父节点的指针。

	思路：画一个二叉树，写出中序遍历序列，观察发现：
		 1.如果该节点有右子树，那么该节点中序遍历的下一个节点是右子树中最左子节点；
		 2.如果该节点没有右子树
			2-1.若该节点是其父节点的左子节点，则该节点的父节点即为所求；
			2-2.若该节点是其父节点的右子节点，则该节点的下一个节点为
				一直向上遍历其父节点，直到父节点是某节点A的左子结点；则A即为所求。
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
	TreeNode* m_pParent;
};
/*
 * @功能 二叉树的下一个节点
 * @param pNode 指向二叉树中某节点的指针
 */
TreeNode* getNextNode(TreeNode* pNode)
{
	// 边界条件检查
	if (pNode == NULL)
		return NULL;

	TreeNode* pResult = NULL;

	// 1. 节点右子树不为空===>找右子树的最左子节点
	if (pNode->m_pRight != NULL) {		
		TreeNode* pTmp = pNode->m_pRight;
		while (pTmp->m_pLeft != NULL)
			pTmp = pTmp->m_pLeft;

		pResult = pTmp;
	}
	// 2.节点的右子树为空
	else if (pNode->m_pParent != NULL) {
		// 2-1.节点为左子节点===>父节点即为所求
	    if (pNode == pNode->m_pParent->m_pLeft)
	    	pResult = pNode->m_pParent;
		// 2-2.节点为右子节点===>TODO
	    else if (pNode == pNode->m_pParent->m_pRight) {
	    
	    	TreeNode* pTmp = pNode->m_pParent;
	    	while (pTmp != NULL && pTmp->m_pParent != NULL)
	    	{
				if (pTmp == pTmp->m_pParent->m_pLeft) {
					pResult = pTmp->m_pParent;
				}
				pTmp = pTmp->m_pParent;
	    	}
	    }
	}
	
	return pResult;
}