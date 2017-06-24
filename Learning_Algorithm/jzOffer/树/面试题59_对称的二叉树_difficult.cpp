/*
	������59���ԳƵĶ�����
	��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�
		   ���һ�ö����������ľ���һ������ô���ǶԳƵġ�
		   
    ˼·��ǰ�������������
	      ǰ������ĶԳƱ����㷨��������
		  
		  ���ǿ���ͨ���Ƚ�ǰ��������кͶԳƱ����������ж϶������ǲ��ǶԳƵġ�
		  
	ע�⣺Ҫ�ڱ���������ʱ��������NULLָ��Ҳ���ǽ�����
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

bool isSymmetrical(TreeNode* pRoot)
{
	return preSymmOrder_Recursively(pRoot, pRoot);
}

bool preSymmOrder_Recursively(TreeNode* pRoot1, TreeNode* pRoot2)
{
	// ��ǰ���ڵ㶼ΪNULL����ô��ǰ���ڵ�Ϊ�������ǶԳƵ�
	if(!pRoot1 && !pRoot2)
		return true;
	// ��ǰ���ڵ�����һ��ΪNULL����ô���ǶԳƵ�
	if(!pRoot1 || !pRoot2)
		return false;
	
	// ���ڵ㶼��ΪNULLʱ���ж�����洢��ֵ�Ƿ���ͬ
	if(pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	
	
	// �����������ҡ�������  ��һ��������ڱ����бȽϣ�û�н����������顣
	return preSymmOrder_Recursively(pRoot1->m_pLeft, pRoot2->m_pRight)// ����
			&& preSymmOrder_Recursively(pRoot1->m_pRight, pRoot2->m_pLeft);// �ҡ���
}











