/*
	������37����������ĵ�һ�������ڵ�
	
	��Ŀ���������������ҵ����ǵĵ�һ�������ڵ㡣����ڵ����£�

	
	˼·��#1 ���������ڵ�һ������(m���ڵ�)˳�����ÿһ���ڵ㣬û������һ���ڵ��ʱ��
		     �ڵڶ�������(n���ڵ�)��˳�����ÿ���ڵ㣻�Ƚϼ��ɡ�ʱ�临�Ӷ�O(m�� n)
			 
		  #2 ��������ջ��ʱ�临�Ӷ�O(m + n),�ռ临�Ӷ�O(m + n)
			 �ֱ�˳����������������ѽڵ�������Եĸ���ջ�С������꣬Ȼ��Ӹ���ջ�����ڵ�Ƚϣ�ֱ���õ����һ�������ڵ㡣
			 
		  #3 ʱ�临�ӶȽ���O( m + n )�ķ�����
			 
			 1->2->3
					\
					 6->7
					/	
				2->5
				
			�����������ĳ���һ�£���ô��ָ�����������ָ��ͬ���ߣ���ô��һ����ַ��ȵĽڵ㼸λ����
			������������������Ȳ�һ���أ�������ĳ���ͨ������һ���֪����
			
			��ô����˳�������������Ȼ��õ����ǵĳ��Ȳ�diff���������Ƚϳ�������diff����
			Ȼ��һ���ߣ�ֱ��������һ����ַ��ȵĽڵ㡣
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
	
	// ������һ������õ��䳤��
	Node* pNode = pHead1;
	int length1 = 0;
	while(pNode != NULL){
		++length1;
		pNode = pNode->m_pNext;		
	}
	
	// �����ڶ�������õ��䳤��
	pNode = pHead2;
	int length2 = 0;
	while(pNode != NULL){
		++length2;
		pNode = pNode->m_pNext;		
	}
	// �õ����Ȳ�
	int diff = length1 - length2;
	
	
	// ����ͷָ��
	Node* pNodeLong = pHead1;
	Node* pNodeShort = pHead2;
	if(diff < 0){
		pNodeLong = pHead2;
		pNodeShort = pHead1;
		diff = length2 - length1;
	}
	
	
	// ����diff��
	for(int i = 0; i < diff; ++i){
		pNodeLong = pNodeLong->m_pNext;
	}
	
	// ����ͬ���ˣ�һ����
	while(pNodeLong != NULL && pNodeShort != NULL){
		if(pNodeLong == pNodeShort){
			break;
		}
		pNodeLong = pNodeLong->m_pNext;
		pNodeShort = pNodeShort->m_pNext;
	}
	 
	return pNodeLong;	
}
 
 