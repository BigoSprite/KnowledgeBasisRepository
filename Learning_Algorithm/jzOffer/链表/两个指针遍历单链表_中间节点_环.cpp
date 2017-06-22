/*
	两个指针遍历链表

	思路：当我们用一个指针不能解决问题的时候，可以尝试用两个指针来遍历链表。
*/

#include <iostream>
#include <assert.h>
struct Node
{
	int m_nValue;
	Node* m_pNext;
};

/*
 * 功能：求链表的中间节点
 *		 如果链表节点总数为奇数，返回中间节点；如果为偶数，返回中间两个节点的任意一个。
 * 思路：使用两个指针A和B，B走一步，A走两步；直到A走到倒数第二个节点，B即为所起。
 */
Node* getMiddleNode(Node* pHead)
{
	// 边界条件检查
	if (pHead == NULL)
		return NULL;

	Node* B = pHead;// 每次走一步的指针B
	Node* A = pHead;// 每次走两步的指针A
	while (A->m_pNext != NULL)
	{// 当pNode->m_pNext == NULL时，pNode指向链表的尾节点
		B = B->m_pNext;
		// ！！！终止条件为A走到倒数第二个节点
		if (A->m_pNext->m_pNext != NULL)
			A = A->m_pNext->m_pNext;
		else
			break;
	}

	return B;
}


/*
 * 功能：判断单链表是否形成了环形结构
 * 思路：使用两个指针A和B，B走一步，A走两步；如果指针A走到尾节点之前A追上了B，那么形成了环。
 */
bool isSingleListHasCircle(Node* pHead)
{
	// 边界条件检查
	bool ret = false;
	if (pHead == NULL)
		return ret;

	Node* B = pHead;// 走的慢的指针
	Node* A = pHead;// 走的快的指针
	while (A->m_pNext != NULL)
	{
		// B走一步
		B = B->m_pNext;
		// A走两步并判断A是否到达了终止节点
		if (A->m_pNext->m_pNext != NULL)
			A = A->m_pNext->m_pNext;// 没有达到边界节点，继续走
		else
			break;// 达到了边界节点，但是还没有赶上B

		// 判断A是否赶上了B
		if (A == B) {// 赶上了
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