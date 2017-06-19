/*
	������15������ĵ�����k���ڵ�

	��Ŀ������һ���������������ĵ�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ������
		 �������β�ڵ��ǵ�����1���ڵ㡣�磺1->2->3->4->5->6�ĵ�����3���ڵ���4��

    ˼·��ά������ָ��A��B����A��B֮���k-1����
		 ����A��k-1����Ȼ��B����ͷ�ڵ�λ�ã���Aһ���ߣ�ֱ��A����β�ڵ�ʱ��Bָ��Ľڵ㼴Ϊ����
*/
#include <iostream>
#include <assert.h>
struct Node
{
	int m_nValue;
	Node* m_pNext;
};

/*
 * ���ܣ�����ĵ�����k���ڵ�
 * @param pHead ָ������ͷ�ڵ��ָ��
 * @param k ������k���ڵ�
 *
 * ʱ�临�Ӷȣ�O(N)������Ҫ����һ������
 */
Node* getKthNodeToTail(Node* pHead, unsigned int k) 
{
	if (pHead == NULL || k < 0)
		return NULL;

	Node*  A = pHead;// ��һ��ָ������k-1��
	for (int i = 0; i < k - 1; ++i) {
		if (A->m_pNext != NULL)
			A = A->m_pNext;
		else// ������β�ڵ㣬��Ϊ����ĳ��ȣ�k
			return NULL;
	}

	Node* B = pHead;// �ڶ���ָ��
	while (A->m_pNext != NULL)// �ڶ�ָ���ߵ�β�ڵ�ʱֹͣ
	{
		B = B->m_pNext;
		A = A->m_pNext;
	}

	return B;	
}

void main()
{
	Node* G = new Node();
	G->m_nValue = 7;
	G->m_pNext = NULL;

	Node* F = new Node();
	F->m_nValue = 6;
	F->m_pNext = G;

	Node* E = new Node();
	E->m_nValue = 5;
	E->m_pNext = F;

	Node* D = new Node();
	D->m_nValue = 4;
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

	int k = 2;
	Node * pNode = getKthNodeToTail(A, k);

	assert(pNode != NULL);

	std::cout << pNode->m_nValue;

	std::cin.get();
}