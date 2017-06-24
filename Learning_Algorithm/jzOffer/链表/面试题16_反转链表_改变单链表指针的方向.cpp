/*
	������16����ת����
	
	��Ŀ������һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣
	
	˼·��ά������ָ�룬һ��ָ���¼β�ڵ㣨��ת�����ͷ�ڵ㣩��
		  ����һ��ָ��ָ��ǰ�ڵ��ָ�룬���һ��ָ��ָ��ǰ�ڵ����һ���ڵ㡣
		  ��������ָ�뼴�ɡ�
		  
	ʱ�临�Ӷȣ�O(N)��������һ�������ɡ�
*/

// ������Ľڵ�ṹ��
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
		Node* tmpNext = curNode->m_pNext;// #4 �ȱ��浱ǰ�ڵ����һ���ڵ�
		
		if(tmpNext == NULL)// �����ǰ�ڵ����һ���ڵ�ΪNULL��˵����ǰ�ڵ�Ϊβ�ڵ�
			reverseHead = curNode;
		
		curNode->m_pNext = preNode;// ��ת����
		
		preNode = curNode; // ������ָ��
		curNode = tmpNext;
	}
	
	return reverseHead;	
}