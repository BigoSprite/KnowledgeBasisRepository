/*
	面试题15：链表的倒数第k个节点

	题目：输入一个链表，输出该链表的倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，
		 即链表的尾节点是倒数第1个节点。如：1->2->3->4->5->6的倒数第3个节点是4。

    	思路：维护两个指针A和B；让A和B之间差k-1步。
		 先让A走k-1步，然后B放在头节点位置，和A一起走；直到A到达尾节点时，B指向的节点即为所求。
*/
#include <iostream>
#include <assert.h>
struct Node
{
	int m_nValue;
	Node* m_pNext;
};

/*
 * 功能：链表的倒数第k个节点
 * @param pHead 指向链表头节点的指针
 * @param k 倒数第k个节点
 *
 * 时间复杂度：O(N)；仅需要遍历一遍链表。
 */
Node* getKthNodeToTail(Node* pHead, unsigned int k) 
{
	if (pHead == NULL || k < 0)
		return NULL;

	Node*  A = pHead;// 第一个指针先走k-1步
	for (int i = 0; i < k - 1; ++i) {
		if (A->m_pNext != NULL)
			A = A->m_pNext;
		else// 到达了尾节点，因为链表的长度＜k
			return NULL;
	}

	Node* B = pHead;// 第二个指针
	while (A->m_pNext != NULL)// 第二指针走到尾节点时停止
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
