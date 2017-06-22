/*
	�������
*/

#include <iostream>
#include <queue>

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

// �Բ�������ķ�ʽ��������ڵ��е�ֵ
void levelOrderTraversal(TreeNode* pRoot)
{
	// �������߽��������
	if (pRoot == NULL)
		return;

	// �������������ʹ�ö������ݽṹ
	std::queue<TreeNode*> queue;
	// ���ȰѸ��ڵ�������
	queue.push(pRoot);

	while (!queue.empty()) {
		// ȡ�����ж���Ԫ�ز��Ӷ�����ɾ��
		TreeNode* pNode = queue.front();
		queue.pop();

		// �������
		std::cout << pNode->m_nValue << " ";

		// ��
		if (pNode->m_pLeft != NULL)
			queue.push(pNode->m_pLeft);
		// ��
		if (pNode->m_pRight != NULL) 
			queue.push(pNode->m_pRight);
	}
}


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

	levelOrderTraversal(A);

	std::cin.get();
}