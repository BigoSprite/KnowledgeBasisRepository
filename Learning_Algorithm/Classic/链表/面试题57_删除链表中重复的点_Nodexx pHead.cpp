/*
	������57��ɾ���������ظ��Ľڵ�

	��Ŀ����һ������������У����ɾ���ظ��Ľڵ㣿

	˼·��ά������ָ��pPreNode��pCurrentNode����ʼʱ��pPreNodeָ��գ�pCurrentNodeָ���һ���ڵ�

	1. ����һ����ǰ�ڵ�ָ��cur��ֻҪһ�жϵ�ĳ�ڵ����֮��Ľڵ��ֵ��ͬ������һ�������Ѹ�ֵ����������
		Ȼ��ӵ�ǰ�ڵ㿪ʼ����������ֵͬ�Ľڵ㶼ɾ������
	2. Ϊ��ƴ������1��ɾ���ڵ�����Ķϲ㣬��Ҫһ���ڵ�ָ��pre��ֻҪ�жϳ���ǰ�ڵ�������һ���ڵ��ֵ��ͬ��
		��ɰѵ�ǰ�ڵ�ָ�븳ֵ��pre��


	Ϊʲô����ָ��ͷ�ڵ�ָ���ָ����Ϊ������

	ע��#1�� 
	ɾ��ָ�����˼��˵�ͷ�ָ����ָ���ڴ浥Ԫ��ָ����ָ���Ծ����ǿ��ڴ棬����һ��ʹ��ʱ��
	������delete���ָ������ΪNULL��
	������ָ��ָ��ͬһ�ڴ��ʱ���ر���Ҫע�⣬��Ϊ��ʱdelete��������һ��ָ�루׼ȷ˵Ӧ����ָ����ָ����ڴ棩
	����һ��ָ��ָ���ѱ��ͷţ��Ѿ������ڣ����ڴ棬��ʱͨ��ָ����ڴ�Ĳ�����Ȼ�����

	int *p = new int;        // ����һ���ڴ棬����p���
	int *q = p;              // qָ��ͬһ�ڴ浥Ԫ 
	*p = 100;              // ͨ��p���ڴ���в���
	delete q;              // �ͷ��ڴ棬��ʱp��q��ָ����Ч�ڴ棬
	// һ���ͷ��ڴ����ָ�����ڴ��ָ������Ϊnull������p = 0;q = 0;����Ϊ�˷�ֹ�������ͷ��ڴ����Ȼ�������ڴ�   
		
*/
#include <iostream>

struct Node
{
	int m_nValue;
	Node* m_pNext;
};

void deleteDuplication(Node** pHead)//����������Node* pHeadҲ�ԣ�����
{
	// �߽��������
	if (pHead == NULL || *pHead == NULL)
		return;
	// ָ��ǰ���ڵ㼰��ǰ�ڵ��ָ��
	Node* pPreNode = NULL;
	Node* pCurrentNode = *pHead;
	// ��ǰ�ڵ㲻Ϊ��
	while (pCurrentNode != NULL) {
		// ��ǰ�ڵ����һ���ڵ�
		Node* next = pCurrentNode->m_pNext;
		// ��֮�Ƚ�
		if (next != NULL && pCurrentNode->m_nValue == next->m_nValue) {

			// ɾ������
			Node* pToBeDel = pCurrentNode;
			int value = pCurrentNode->m_nValue;// �����������ȿ���һ�ݣ���Ȼ�����1 2 3 4 5������1 2 5
// ����ָ��ָ��ͬһ���ڴ棬ɾ����һ����һ��ָ����ָ���ڴ�û�䣬���ڴ�����ı�����ֵ��ɾ���ˣ�
// pToBeDelָ���pCurrentNodeָ��ָ��ͬһ��ַ��whileѭ����ɾ����pToBeDel����ôpCurrentNodeҲ��ɾ��
			while (pToBeDel != NULL && pToBeDel->m_nValue == value)
			{
				// ����������ʹ��next�������
				next = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = NULL;

				pToBeDel = next;
			}

			// �ж��Ƿ�ɾ����ʱͷ�ڵ�
			if (pPreNode == NULL) // �ǵ�
				*pHead = next;// �������ǵ�ά��ͷ�ڵ� pHead
			else
				pPreNode->m_pNext = next;
			pCurrentNode = next;

		}
		else {
			pPreNode = pCurrentNode;
			pCurrentNode = next;
		}		
	}
}

void main()
{
	// ����ָ��ָ��ͬһ����ַ�Ĳ���
	int* a = new int();
	int* b = a;// �ϵ�ִ�е�����ʱ��a��b�ĵ�ַ��ͬ��Ϊ0x00a9e9a0��ÿ��ִ�еĵ�ַ��һ������
			   // ָ��ָ��ı���*a��*b��ֵ��Ϊ0��
	*b = 1;// ��ֵΪ1
	std::cout << *a << ' ' << *b << std::endl;// ���1 1
	delete b;
	b = NULL; // �ϵ�ִ�й����д���ʱ��a�ĵ�ַ��Ϊ0x00a9e9a0��a��ŵ�ֵΪ-572662307; b�ĵ�ַΪ0x00000000����ŵ�ֵ<�޷���ȡ�ڴ�>
	//std::cout << *a << ' ' << *b << std::endl;// ���д����쳣


	Node* G = new Node();
	G->m_nValue = 5;
	G->m_pNext = NULL;

	Node* F = new Node();
	F->m_nValue = 4;
	F->m_pNext = G;

	Node* E = new Node();
	E->m_nValue = 4;
	E->m_pNext = F;

	Node* D = new Node();
	D->m_nValue = 3;
	D->m_pNext = E;

	Node* C = new Node();
	C->m_nValue = 3;
	C->m_pNext = D;

	Node* B = new Node();
	B->m_nValue = 2;
	B->m_pNext = C;
	
	Node* A = new Node();
	A->m_nValue = 1;
	A->m_pNext = B;

	deleteDuplication(&A);
	
	Node* node = A;
	while (node != NULL)
	{
		std::cout << node->m_nValue << ' ';
		node = node->m_pNext;
	}

	std::cin.get();
}