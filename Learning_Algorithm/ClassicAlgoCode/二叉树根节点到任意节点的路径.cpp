struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

/**
 * @���ܣ���ͨ���������ڵ㵽����ڵ��·��
 *		  ʹ�ö�����ǰ�����
 *
 * @param pRoot ָ����������ڵ��ָ��
 * @param pNode ָ�����������ڵ��ָ��
 * @param path ��Žڵ��·��������������vector��list
 */
bool getPath(TreeNode* pRoot, TreeNode* pNode, std::vector<TreeNode*>& path)
{
	if (pRoot == NULL || pNode == NULL)
		return false;

	// ���������ȰѸ��ڵ��������
	path.push_back(pRoot);

	bool isFound = false;// ���ñ�־λ
	// �жϸ��ڵ��Ƿ�ΪҪ�ҵĽڵ�
	if (pRoot == pNode) {
		isFound = true;
	}

	// ������ע�⣺���������ı�����·��������Ԫ�ص�ɾ��������Ҫ���ݱ�־λ������
	// ��
	if (!isFound && pRoot->m_pLeft)
		isFound = getPath(pRoot->m_pLeft, pNode, path);

	// ��
	if (!isFound && pRoot->m_pRight)
		isFound = getPath(pRoot->m_pRight, pNode, path);

	if(!isFound)
		path.pop_back();

	return isFound;
}