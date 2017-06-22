#include <iostream>
#include <stack>
struct Node
{
	int m_nValue;
	Node* m_pNext;
};
/*
	������5����β��ͷ��ӡ����

	��Ŀ������һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ��

	˼·����ͷ����β�������������������������ȱ��������˿�ʹ��ջ��ݹ顣
*/
void printNodeReversingly_iteratively(Node* pHead)
{
	if (pHead == NULL)
		return;

	std::stack<Node*> nodeStack;
	// ����һ��
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