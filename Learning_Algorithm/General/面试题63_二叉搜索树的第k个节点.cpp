#include <iostream>
#include <vector>
/*
	面试题63：二叉搜索树的第k个节点
	
	题目：给定一棵二叉搜索树，请找出其中第k个大的节点。

	思路：画出一棵二叉搜索树，使用中序遍历
		 方法1：借助辅助数组
		 方法2：依次遍历节点，遍历到第k个节点，返回即可。

	考查：二叉搜索树（左子树任意节点的值 < 根节点的值 < 右子树任意节点的值）及中序遍历(左 根 右)。
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

/* -------------------------1.借助辅助数组法------------------------------- */
void inOrder(TreeNode* pRoot, std::vector<TreeNode*>& nodeVec)
{
	if (pRoot == NULL)
		return;

	// 左
	if (pRoot->m_pLeft != NULL) {
		inOrder(pRoot->m_pLeft, nodeVec);
	}
	// 根
	nodeVec.push_back(pRoot);
	// 右
	if (pRoot->m_pRight != NULL) {
		inOrder(pRoot->m_pRight, nodeVec);
	}
}

/*
 * @功能 二叉搜索树的第k个节点
 * @param pRoot 指向二叉树中根节点的指针
 * @param k 第k个节点
 */
TreeNode* getKthNode(TreeNode* pRoot, const unsigned int& k)
{
	if (pRoot == NULL || k < 1)
		return NULL;

	std::vector<TreeNode*> nodeVec;
	inOrder(pRoot, nodeVec);

	if (nodeVec.size() < k)
		return NULL;
	return nodeVec[k-1];
}

/* -------------------------2. 不借助辅助数组法TODO------------------------------- */

void main()
{

	TreeNode* G = new TreeNode();
	G->m_nValue = 8;
	G->m_pLeft = NULL;
	G->m_pRight = NULL;

	TreeNode* F = new TreeNode();
	F->m_nValue = 6;
	F->m_pLeft = NULL;
	F->m_pRight = NULL;


	TreeNode* E = new TreeNode();
	E->m_nValue = 4;
	E->m_pLeft = NULL;
	E->m_pRight = NULL;

	TreeNode* D = new TreeNode();
	D->m_nValue = 2;
	D->m_pLeft = NULL;
	D->m_pRight = NULL;

	TreeNode* C = new TreeNode();
	C->m_nValue = 7;
	C->m_pLeft = F;
	C->m_pRight = G;

	TreeNode* B = new TreeNode();
	B->m_nValue = 3;
	B->m_pLeft = D;
	B->m_pRight = E;

	TreeNode* A = new TreeNode();
	A->m_nValue = 5;
	A->m_pLeft = B;
	A->m_pRight = C;

	TreeNode* node = getKthNode(A, 3);
	if(node)
		std::cout << node->m_nValue << std::endl;

	std::cin.get();
}