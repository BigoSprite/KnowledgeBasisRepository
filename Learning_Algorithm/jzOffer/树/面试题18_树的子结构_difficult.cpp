/*
	������18�������ӽṹ
	��Ŀ���������ö�����A��B���ж�B�Ƿ���A���ӽṹ��

	˼·����һ����ʹ��ǰ���������A���ҵ���B�ĸ��ڵ��ֵһ���Ľڵ�R��
	      �ڶ�����ʹ��ǰ������ж�A����RΪ���ڵ�������ǲ��ǰ�������Bһ���Ľṹ��
*/
struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

// �ڶ���
bool doesTreeAHasTreeB(TreeNode* pRootA, TreeNode* pRootB);

// ��һ��
bool hasSubtree(TreeNode* pRootA, TreeNode* pRootB)
{
	bool result = false;

	if (pRootA && pRootB) {// �ǿ�
		if (pRootA->m_nValue == pRootB->m_nValue)
			result = doesTreeAHasTreeB(pRootA, pRootB);	// �ҵ�A������B���и��ڵ�ֵ��ͬ�Ľڵ�node��
														// �ж���nodeΪ���ڵ�����Ƿ����B���ӽṹ
		// ��
		if (!result)
			result = hasSubtree(pRootA->m_pLeft, pRootB);
		// ��
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