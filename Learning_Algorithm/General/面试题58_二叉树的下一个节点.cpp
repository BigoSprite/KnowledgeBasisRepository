#include <iostream>
#include <list>
/*
	������58������������һ���ڵ�
	
	��Ŀ������һ�ö�����������һ���ڵ㣬����ҳ��������˳�����һ���ڵ㣿
		 ���еĽڵ㣨���ڵ���⣩�����������ֱ�ָ�������ӽڵ��ָ�����⣬����һ��ָ�򸸽ڵ��ָ�롣

	˼·����һ����������д������������У��۲췢�֣�
		 1.����ýڵ�������������ô�ýڵ������������һ���ڵ����������������ӽڵ㣻
		 2.����ýڵ�û��������
			2-1.���ýڵ����丸�ڵ�����ӽڵ㣬��ýڵ�ĸ��ڵ㼴Ϊ����
			2-2.���ýڵ����丸�ڵ�����ӽڵ㣬��ýڵ����һ���ڵ�Ϊ
				һֱ���ϱ����丸�ڵ㣬ֱ�����ڵ���ĳ�ڵ�A�����ӽ�㣻��A��Ϊ����
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
	TreeNode* m_pParent;
};
/*
 * @���� ����������һ���ڵ�
 * @param pNode ָ���������ĳ�ڵ��ָ��
 */
TreeNode* getNextNode(TreeNode* pNode)
{
	// �߽��������
	if (pNode == NULL)
		return NULL;

	TreeNode* pResult = NULL;

	// 1. �ڵ���������Ϊ��===>���������������ӽڵ�
	if (pNode->m_pRight != NULL) {		
		TreeNode* pTmp = pNode->m_pRight;
		while (pTmp->m_pLeft != NULL)
			pTmp = pTmp->m_pLeft;

		pResult = pTmp;
	}
	// 2.�ڵ��������Ϊ��
	else if (pNode->m_pParent != NULL) {
		// 2-1.�ڵ�Ϊ���ӽڵ�===>���ڵ㼴Ϊ����
	    if (pNode == pNode->m_pParent->m_pLeft)
	    	pResult = pNode->m_pParent;
		// 2-2.�ڵ�Ϊ���ӽڵ�===>TODO
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