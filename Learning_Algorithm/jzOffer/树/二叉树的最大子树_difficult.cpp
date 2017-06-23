/*
	��Ŀ���ҳ�������������������������Ϊ��������������ν������������ָ�����Ŀ����������
	
	˼·������ƽ�������������ӽ���ֵ < ���ڵ��ֵ < �������ӽ���ֵ
	
	      ���磺     ������A        ��������������
						7
					   / \
					  5   8   -------->    5
					 / \   \              / \
                    3   6   4            3   6
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;	
};

const int MAX = 100000;

TreeNode* findMaxBST(TreeNode* pRoot)
{
	int data[3] = {0, 0, 0};// �ֱ�����Сֵ�����ֵ�ͽڵ���
	TreeNode* result = postOrder_Recursively(pRoot, data);
	
	return result;
}

// ����������߼��������ض����������������������ĸ��ڵ�
TreeNode* postOrder_Recursively(TreeNode* pRoot, int data[])
{
	// �ݹ�����ı߽�����
	if(pRoot == NULL){
		data[0] = MAX;
		data[1] = -MAX;
		data[2] = 0;
		return NULL;
	}

    //�ݹ�������������ȡ4����Ϣ
	// ��
	TreeNode* lBST= postOrder_Recursively(pRoot->m_pLeft, data);
	int lMin = data[0];
	int lMax = data[1];
	int lSize = data[2];
	// ��
	TreeNode* rBST= postOrder_Recursively(pRoot->m_pRight, data);
	int rMin = data[0];
	int rMax = data[1];
	int rSize = data[2];
	
	// ���µ�ǰ���Ϊ������������Сֵ�����ֵ
	data[0] = lMin < pRoot->m_nValue ? lMin : pRoot->m_nValue;
	data[1] = rMax > pRoot->m_nValue ? rMax : pRoot->m_nValue;
	
	// ��
	// ���1
	if(pRoot->m_pLeft == lBST && pRoot->m_pRight == rBST
		&& pRoot->m_nValue > lMax && pRoot->m_nValue < rMin){
		data[2] = lSize + rSize + 1;
		return pRoot;// ���1����ʱ����			
	}else{
		data[2] =  lSize > rSize ? lSize : rSize;
		// ���2
		return lSize > rSize ? lBST : rBST;
	}
}












