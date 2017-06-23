/*
	������39�������������
	
	��Ŀ1������һ�ö������ĸ��ڵ㣬���������ȡ�
	       �Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�һ��·�����·���ĳ���Ϊ������ȡ�
		  
	��Ŀ2������һ�ö������ĸ��ڵ㣬�жϸ����ǲ��Ƕ���ƽ������
		   ���ĳ����ƽ����������ڵ���������������������1����ô������һ��ƽ���������
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;	
};

/// ��Ŀ1�������������Ϊ������������Ƚϴ��ֵ+1
int getTreeDepth_Recursively(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return 0;// ���������������Ϊ0��ֻ��һ�����ڵ���������Ϊ1
	
	int left = getTreeDepth_Recursively(pRoot->m_pLeft);
	int right = getTreeDepth_Recursively(pRoot->m_pRight);
	
	int maxDepth = left > right ? left : right;
	return 1 + maxDepth;
}


/// ��Ŀ2������һ�ö������ĸ��ڵ㣬�жϸ����ǲ��Ƕ���ƽ������
/// ����ڵ���������������������1
/*
 * #1 ��Ҫ�ظ������ڵ��εĽⷨ���򵥵������Դ����Թ�
 *                1
 *             2      3
 *          4     5       6
 *              7
 * �������Ȼ��жϸ��ڵ�1�ǲ���ƽ��ģ�������Ҫ����2 4 5 7��
 * ����2Ϊ���ж��Ƿ���ƽ������ʱ����Ҫ����4 5 7���ȵȡ�
 */
bool isBalancedTree_bad(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return true;
	
	int left = getTreeDepth_Recursively(pRoot->m_pLeft);
	int right = getTreeDepth_Recursively(pRoot->m_pRight);
	
	int diff = right - left;
	if(diff <- 1 || diff > 1)
		return false;
	
	return isBalancedTree_bad(pRoot->m_pLeft) && isBalancedTree_bad(pRoot->m_pRight);	
}


/*
 * #2 ÿ���ڵ������һ�εĽⷨ
 *                1
 *             2      3
 *          4     5       6
 *              7
 * ʹ�ú���������ڱ�����һ���ڵ�֮ǰ���������������Ѿ���������
 * ֻҪ����ÿ���ڵ��ʱ���¼������ȣ����ǾͿ���һ�߱�����һ���ж�ÿ��ÿ���ڵ��Ƿ���ƽ��ġ�
 */
bool isBalancedTree_best(TreeNode* pRoot)
{
	int depth = 0;
	return isBalancedTree(pRoot, &depth);
}

bool isBalancedTree(TreeNode* pRoot, int* depth)// ��������¼ÿ���ڵ�����
{
	if(pRoot == NULL){
		*depth = 0;// ��������¼ÿ���ڵ�����
		return true;
	}
	
	int left, right;
	// ÿ���ڵ��Ƕ���ƽ���������
	if(isBalancedTree(pRoot->m_pLeft, left)// ��
		&& isBalancedTree(pRoot->m_pRight, right)){// ��
		// ��¼���ڵ�����
		int diff = right - left;
		if(diff <= 1 && diff >= -1){
			*depth = 1 + (left > right? left: right);
			return true;
		}
	}
	
	return false;
}


