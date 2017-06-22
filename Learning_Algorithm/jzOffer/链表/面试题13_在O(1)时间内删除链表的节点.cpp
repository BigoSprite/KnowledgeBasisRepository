struct Node
{
	int m_nValue;
	Node* m_pNext;
};

/*
	面试题13：在O(1)时间删除链表节点
	题目：给定单向链表的头指针和一个节点的指针，定义一个函数在O(1)时间删除该节点。

	思路：因为我们无法以O(1)时间获得节点A的前驱节点；但是要删除A我们可以获得A的下一个节点B（非空），
		  并把B的值赋值给A，然后调整相关指针即可（“狸猫换太子法”）。
		  但是如果B为空，即A为尾节点，那么要删除它，我们不得不从头到尾遍历链表一次，找到A的前驱节点后再删除A。
*/
void DeleteNode(Node** pHead, Node* pToBeDeleted)
{
	// 边界条件检查
	if (pHead == NULL || pToBeDeleted == NULL)
		return;

	// 1. 链表有多个节点，且删除的节点不是尾节点。时间复杂度为——O(1)
	if (pToBeDeleted->m_pNext != NULL) {
		// 要删除节点的下一个节点
		Node* next = pToBeDeleted->m_pNext;

		// “狸猫换太子”
		pToBeDeleted->m_nValue = next->m_nValue;
		pToBeDeleted->m_pNext = next->m_pNext;

		// 删除下一个节点
		delete next;
		next = NULL;
	}
	// 2.链表只有一个节点（此时pToBeDeleted->m_pNext == NULL && *pHead == pToBeDeleted）
	// 时间复杂度为——O(1)
	else if (*pHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pHead = NULL;	
	}
	// 3.链表有多个节点，且删除尾节点。时间复杂度为——O(N)
	else {
		// 因为要删除的节点（pToBeDeleted）是尾节点且题目是单链表，
		// 所以我们无法获得pToBeDeleted指针指向节点的指向前驱节点的指针
		// 还好我们有指向头节点的指针*pHead，我们遍历一遍链表即可！

		Node* pNode = *pHead;
		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		// 现在pNode是指向pToBeDeleted指向的节点的前驱节点的指针
		pNode->m_pNext = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}