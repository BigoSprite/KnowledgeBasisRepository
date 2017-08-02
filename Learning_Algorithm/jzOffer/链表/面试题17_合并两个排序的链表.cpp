
面试题 17： 合并两个排序后的链表

struct Node
{
	int m_iValue;
	Node* m_pNext;
};

Node* merge(Node* head1, Node* head2)
{
	// 边界条件检查
	if(head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
		
	// 合并后指向链表的头节点的指针
	Node* mergedHead = NULL;
	if(head1->m_iValue < head2->m_iValue){
		mergedHead = head1;
		mergedHead->m_pNext = merge(head1->m_pNext, head2);
	}else{
		mergedHead = head2;
		mergedHead->m_pNext = merge(head1, head2->m_pNext);
	}
	
	return mergedHead;
}