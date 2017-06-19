/*
	面试题57：删除链表中重复的节点

	题目：在一个排序的链表中，如何删除重复的节点？

	思路：维护两个指针pPreNode和pCurrentNode。初始时，pPreNode指向空，pCurrentNode指向第一个节点

	1. 定义一个当前节点指针cur，只要一判断到某节点和其之后的节点的值相同，就用一个变量把该值保存下来，
		然后从当前节点开始，把所有相同值的节点都删除掉；
	2. 为了拼接由于1中删除节点产生的断层，需要一个节点指针pre。只要判断出当前节点与它下一个节点的值不同，
		便可把当前节点指针赋值给pre。


	为什么传入指向头节点指针的指针作为参数？

	注意#1： 
	删除指针的意思是说释放指针所指的内存单元，指针所指的仍就是那块内存，所以一般使用时候
	都会在delete后把指针重置为NULL；
	当两个指针指向同一内存的时候特别需要注意，因为此时delete其中任意一个指针（准确说应该是指针所指向的内存）
	另外一个指针指向已被释放（已经不存在）的内存，此时通过指针对内存的操作自然会出错。

	int *p = new int;        // 申请一块内存，并用p标记
	int *q = p;              // q指向同一内存单元 
	*p = 100;              // 通过p对内存进行操作
	delete q;              // 释放内存，此时p和q均指向无效内存，
	// 一般释放内存后会把指向其内存的指针设置为null，即：p = 0;q = 0;就是为了防止你这样释放内存后仍然操作其内存   
		
*/
#include <iostream>

struct Node
{
	int m_nValue;
	Node* m_pNext;
};

void deleteDuplication(Node** pHead)//！！！传入Node* pHead也对？？？
{
	// 边界条件检查
	if (pHead == NULL || *pHead == NULL)
		return;
	// 指向前驱节点及当前节点的指针
	Node* pPreNode = NULL;
	Node* pCurrentNode = *pHead;
	// 当前节点不为空
	while (pCurrentNode != NULL) {
		// 当前节点的下一个节点
		Node* next = pCurrentNode->m_pNext;
		// 与之比较
		if (next != NULL && pCurrentNode->m_nValue == next->m_nValue) {

			// 删除操作
			Node* pToBeDel = pCurrentNode;
			int value = pCurrentNode->m_nValue;// ！！！必须先拷贝一份！不然结果是1 2 3 4 5，不是1 2 5
// 两个指针指向同一块内存，删除其一；另一个指针所指的内存没变，但内存里面的变量的值被删除了！
// pToBeDel指针和pCurrentNode指针指向同一地址；while循环体删除了pToBeDel，那么pCurrentNode也被删除
			while (pToBeDel != NULL && pToBeDel->m_nValue == value)
			{
				// ！！！继续使用next这个变量
				next = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = NULL;

				pToBeDel = next;
			}

			// 判断是否删除的时头节点
			if (pPreNode == NULL) // 是的
				*pHead = next;// ！！！记得维护头节点 pHead
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
	// 两个指针指向同一个地址的测试
	int* a = new int();
	int* b = a;// 断点执行到这里时：a和b的地址相同且为0x00a9e9a0（每次执行的地址不一样），
			   // 指针指向的变量*a和*b的值都为0！
	*b = 1;// 赋值为1
	std::cout << *a << ' ' << *b << std::endl;// 输出1 1
	delete b;
	b = NULL; // 断点执行过这行代码时，a的地址仍为0x00a9e9a0，a存放的值为-572662307; b的地址为0x00000000，存放的值<无法读取内存>
	//std::cout << *a << ' ' << *b << std::endl;// 这行代码异常


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