#include <iostream>
#include <vector>
/*
	������63�������������ĵ�k���ڵ�
	
	��Ŀ������һ�ö��������������ҳ����е�k����Ľڵ㡣

	˼·������һ�ö�����������ʹ���������
		 ����1��������������
		 ����2�����α����ڵ㣬��������k���ڵ㣬���ؼ��ɡ�

	���飺����������������������ڵ��ֵ < ���ڵ��ֵ < ����������ڵ��ֵ�����������(�� �� ��)��
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

/* -------------------------1.�����������鷨------------------------------- */
void inOrder(TreeNode* pRoot, std::vector<TreeNode*>& nodeVec)
{
	if (pRoot == NULL)
		return;

	// ��
	if (pRoot->m_pLeft != NULL) {
		inOrder(pRoot->m_pLeft, nodeVec);
	}
	// ��
	nodeVec.push_back(pRoot);
	// ��
	if (pRoot->m_pRight != NULL) {
		inOrder(pRoot->m_pRight, nodeVec);
	}
}

/*
 * @���� �����������ĵ�k���ڵ�
 * @param pRoot ָ��������и��ڵ��ָ��
 * @param k ��k���ڵ�
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

/* -------------------------2. �������������鷨TODO------------------------------- */

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