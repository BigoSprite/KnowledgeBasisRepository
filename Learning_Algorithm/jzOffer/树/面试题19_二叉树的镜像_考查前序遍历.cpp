/*
	������19���������ľ���
	��Ŀ�������һ������������һ�ö��������ú���������ľ���

	˼·��ǰ���������ͼ
					8                       ������8
                 6     10    ----��������     10     6
               5   7  9   11                11   9  7   5
*/

struct TreeNode
{
	int m_nValue;
	TreeNode m_pLeft;
	TreeNode m_pRight;
};

void mirrorTree_Recursively(TreeNode pRoot)
{
	 �߽��������
	if (pRoot == NULL)
		return;

	 ֻ��һ���ڵ�����
	if (pRoot-m_pLeft == NULL && pRoot-m_pRight == NULL)
		return;

	 ��������������һ������
	 ��---���������ӽڵ�
	TreeNode treeNode = pRoot-m_pLeft;
	pRoot-m_pLeft = pRoot-m_pRight;
	pRoot-m_pRight = treeNode;
	 ��
	if (pRoot-m_pLeft != NULL)
		mirrorTree_Recursively(pRoot-m_pLeft);
	 ��
	if (pRoot-m_pRight != NULL)
		mirrorTree_Recursively(pRoot-m_pRight);
}