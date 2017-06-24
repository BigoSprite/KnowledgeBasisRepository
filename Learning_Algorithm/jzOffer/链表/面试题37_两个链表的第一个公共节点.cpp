/*
	面试题37：两个链表的第一个公共节点
	
	题目：输入两个链表，找到它们的第一个公共节点。链表节点如下：

	
	思路：#1 蛮力法：在第一个链表(m个节点)顺序遍历每一个节点，没遍历到一个节点的时候，
		     在第二个链表(n个节点)上顺序遍历每个节点；比较即可。时间复杂度O(m· n)
			 
		  #2 借助辅助栈。时间复杂度O(m + n),空间复杂度O(m + n)
			 分别顺序遍历两个链表，并把节点置入各自的辅助栈中。遍历完，然后从辅助栈弹出节点比较，直到得到最后一个公共节点。
			 
		  #3 时间复杂度降到O( m + n )的方法。
			 
			 1->2->3
					\
					 6->7
					/	
				2->5
				
			如果两个链表的长度一致，那么让指向两个链表的指针同步走，那么第一个地址相等的节点几位所求。
			问题是如果两个链表长度不一样呢？且链表的长度通过遍历一遍才知道。
			
			那么，先顺序遍历两个链表，然后得到它们的长度差diff，让链表长度较长的先走diff步，
			然后一起走，直到遇到第一个地址相等的节点。
*/
struct Node
{
	int m_nValue;
	Node* m_pNext;	 
};
 
Node* getFirstNode(Node* pHead1, Node* pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL)
		return NULL;
	
	// 遍历第一个链表得到其长度
	Node* pNode = pHead1;
	int length1 = 0;
	while(pNode != NULL){
		++length1;
		pNode = pNode->m_pNext;		
	}
	
	// 遍历第二个链表得到其长度
	pNode = pHead2;
	int length2 = 0;
	while(pNode != NULL){
		++length2;
		pNode = pNode->m_pNext;		
	}
	// 得到长度差
	int diff = length1 - length2;
	
	
	// 调整头指针
	Node* pNodeLong = pHead1;
	Node* pNodeShort = pHead2;
	if(diff < 0){
		pNodeLong = pHead2;
		pNodeShort = pHead1;
		diff = length2 - length1;
	}
	
	
	// 先走diff步
	for(int i = 0; i < diff; ++i){
		pNodeLong = pNodeLong->m_pNext;
	}
	
	// 现在同步了，一起走
	while(pNodeLong != NULL && pNodeShort != NULL){
		if(pNodeLong == pNodeShort){
			break;
		}
		pNodeLong = pNodeLong->m_pNext;
		pNodeShort = pNodeShort->m_pNext;
	}
	 
	return pNodeLong;	
}
 
 