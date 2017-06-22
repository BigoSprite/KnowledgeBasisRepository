/*
	����ָ���������

	˼·����������һ��ָ�벻�ܽ�������ʱ�򣬿��Գ���������ָ������������
*/

#include <iostream>
#include <assert.h>
struct Node
{
	int m_nValue;
	Node* m_pNext;
};

/*
 * ���ܣ���������м�ڵ�
 *		 �������ڵ�����Ϊ�����������м�ڵ㣻���Ϊż���������м������ڵ������һ����
 * ˼·��ʹ������ָ��A��B��B��һ����A��������ֱ��A�ߵ������ڶ����ڵ㣬B��Ϊ����
 */
Node* getMiddleNode(Node* pHead)
{
	// �߽��������
	if (pHead == NULL)
		return NULL;

	Node* B = pHead;// ÿ����һ����ָ��B
	Node* A = pHead;// ÿ����������ָ��A
	while (A->m_pNext != NULL)
	{// ��pNode->m_pNext == NULLʱ��pNodeָ�������β�ڵ�
		B = B->m_pNext;
		// ��������ֹ����ΪA�ߵ������ڶ����ڵ�
		if (A->m_pNext->m_pNext != NULL)
			A = A->m_pNext->m_pNext;
		else
			break;
	}

	return B;
}


/*
 * ���ܣ��жϵ������Ƿ��γ��˻��νṹ
 * ˼·��ʹ������ָ��A��B��B��һ����A�����������ָ��A�ߵ�β�ڵ�֮ǰA׷����B����ô�γ��˻���
 */
bool isSingleListHasCircle(Node* pHead)
{
	// �߽��������
	bool ret = false;
	if (pHead == NULL)
		return ret;

	Node* B = pHead;// �ߵ�����ָ��
	Node* A = pHead;// �ߵĿ��ָ��
	while (A->m_pNext != NULL)
	{
		// B��һ��
		B = B->m_pNext;
		// A���������ж�A�Ƿ񵽴�����ֹ�ڵ�
		if (A->m_pNext->m_pNext != NULL)
			A = A->m_pNext->m_pNext;// û�дﵽ�߽�ڵ㣬������
		else
			break;// �ﵽ�˱߽�ڵ㣬���ǻ�û�и���B

		// �ж�A�Ƿ������B
		if (A == B) {// ������
			ret = true;
			break;
		}
	}

	return ret;
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

	Node * pNode = getMiddleNode(A);

	assert(pNode != NULL);

	std::cout << pNode->m_nValue;

	std::cin.get();
}