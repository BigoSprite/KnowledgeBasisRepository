/*
	面试题19：二叉树的镜像
	题目：请完成一个函数，输入一棵二叉树，该函数输出它的镜像。

	思路：前序遍历。画图
					8                       　　　8
                 6     10    ----　镜像树     10     6
               5   7  9   11                11   9  7   5
*/

struct TreeNode
{
	int m_nValue;
	TreeNode m_pLeft;
	TreeNode m_pRight;
};

void mirrorTree_Recursively(TreeNode* pRoot)
{
	// 边界条件
	if(pRoot == NULL)
		return;
	if(!pRoot->m_pLeft && !pRoot->m_pRight)
		return;
	
	// 先序遍历，根有子节点--->交换它们
	TreeNode* right = pRoot->m_pRight;
	pRoot->m_pRight = pRoot->m_pLeft;
	pRoot->m_pLeft = right;
	
	// 左
	if(pRoot->m_pLeft)
		mirrorTree_Recursively(pRoot->m_pLeft);
		
	// 右
	if(pRoot->m_pRight)
		mirrorTree_Recursively(pRoot->m_pRight);
}