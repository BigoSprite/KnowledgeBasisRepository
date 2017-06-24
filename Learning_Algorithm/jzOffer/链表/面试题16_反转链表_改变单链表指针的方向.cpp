/*
	面试题16：反转链表
	
	题目：定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
	
	思路：维护三个指针，一个指针记录尾节点（反转链表的头节点）；
		  另外一个指针指向当前节点的指针，最后一个指针指向当前节点的上一个节点。
		  遍历调整指针即可。
		  
	时间复杂度：O(N)，即遍历一次链表即可。
*/

// 单链表的节点结构体
struct Node
{
	int m_nValue;
	Node* m_pNext;	
};

Node* reverseList(Node* pHead)
{
	Node* reverseHead = NULL; 	 // #1
	
	Node* preNode = NULL;    	 // #2
	Node* curNode = pHead;       // #3	 1->2->3->4->5->6
	while(curNode != NULL)
	{
		Node* tmpNext = curNode->m_pNext;// #4 先保存当前节点的下一个节点
		
		if(tmpNext == NULL)// 如果当前节点的下一个节点为NULL，说明当前节点为尾节点
			reverseHead = curNode;
		
		curNode->m_pNext = preNode;// 反转链表
		
		preNode = curNode; // 向后调整指针
		curNode = tmpNext;
	}
	
	return reverseHead;	
}