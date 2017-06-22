#include <iostream>
#include <stack>
struct Node
{
	int m_nValue;
	Node* m_pNext;
};
/*
	面试题5：从尾到头打印链表

	题目：输入一个链表的头节点，从尾到头反过来打印出每个节点的值。

	思路：从头到到尾遍历链表，最后遍历到的链表最先被输出；因此可使用栈或递归。
*/
void printNodeReversingly_iteratively(Node* pHead)
{
	if (pHead == NULL)
		return;

	std::stack<Node*> nodeStack;
	// 遍历一遍
	Node* pNode = pHead;
	while (pNode != NULL)
	{
		nodeStack.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodeStack.empty()) {
		pNode = nodeStack.top();
		nodeStack.pop();
		std::cout << pNode->m_nValue << " ";
	}
}

void printNodeReversingly_Recursively(Node* pHead)
{
	if (pHead != NULL) {
		if (pHead->m_pNext != NULL) {
			printNodeReversingly_Recursively(pHead->m_pNext);
		}
		std::cout << pHead->m_nValue << " ";
	}
}