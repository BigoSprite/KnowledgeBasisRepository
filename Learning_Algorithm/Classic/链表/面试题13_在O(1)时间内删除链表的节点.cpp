struct Node
{
	int m_nValue;
	Node* m_pNext;
};

/*
	������13����O(1)ʱ��ɾ������ڵ�
	��Ŀ���������������ͷָ���һ���ڵ��ָ�룬����һ��������O(1)ʱ��ɾ���ýڵ㡣

	˼·����Ϊ�����޷���O(1)ʱ���ýڵ�A��ǰ���ڵ㣻����Ҫɾ��A���ǿ��Ի��A����һ���ڵ�B���ǿգ���
		  ����B��ֵ��ֵ��A��Ȼ��������ָ�뼴�ɣ�����è��̫�ӷ�������
		  �������BΪ�գ���AΪβ�ڵ㣬��ôҪɾ���������ǲ��ò���ͷ��β��������һ�Σ��ҵ�A��ǰ���ڵ����ɾ��A��
*/
void DeleteNode(Node** pHead, Node* pToBeDeleted)
{
	// �߽��������
	if (pHead == NULL || pToBeDeleted == NULL)
		return;

	// 1. �����ж���ڵ㣬��ɾ���Ľڵ㲻��β�ڵ㡣ʱ�临�Ӷ�Ϊ����O(1)
	if (pToBeDeleted->m_pNext != NULL) {
		// Ҫɾ���ڵ����һ���ڵ�
		Node* next = pToBeDeleted->m_pNext;

		// ����è��̫�ӡ�
		pToBeDeleted->m_nValue = next->m_nValue;
		pToBeDeleted->m_pNext = next->m_pNext;

		// ɾ����һ���ڵ�
		delete next;
		next = NULL;
	}
	// 2.����ֻ��һ���ڵ㣨��ʱpToBeDeleted->m_pNext == NULL && *pHead == pToBeDeleted��
	// ʱ�临�Ӷ�Ϊ����O(1)
	else if (*pHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pHead = NULL;	
	}
	// 3.�����ж���ڵ㣬��ɾ��β�ڵ㡣ʱ�临�Ӷ�Ϊ����O(N)
	else {
		// ��ΪҪɾ���Ľڵ㣨pToBeDeleted����β�ڵ�����Ŀ�ǵ�����
		// ���������޷����pToBeDeletedָ��ָ��ڵ��ָ��ǰ���ڵ��ָ��
		// ����������ָ��ͷ�ڵ��ָ��*pHead�����Ǳ���һ�������ɣ�

		Node* pNode = *pHead;
		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		// ����pNode��ָ��pToBeDeletedָ��Ľڵ��ǰ���ڵ��ָ��
		pNode->m_pNext = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}