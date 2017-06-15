struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

/**
 * @功能：普通二叉树根节点到任意节点的路径
 *		  使用二叉树前序遍历
 *
 * @param pRoot 指向二叉树根节点的指针
 * @param pNode 指向二叉树任意节点的指针
 * @param path 存放节点的路径容器，可以是vector或list
 */
bool getPath(TreeNode* pRoot, TreeNode* pNode, std::vector<TreeNode*>& path)
{
	if (pRoot == NULL || pNode == NULL)
		return false;

	// 根——首先把根节点加入容器
	path.push_back(pRoot);

	bool isFound = false;// 设置标志位
	// 判断根节点是否为要找的节点
	if (pRoot == pNode) {
		isFound = true;
	}

	// ！！！注意：左右子树的遍历及路径容器中元素的删除操作都要根据标志位来操作
	// 左
	if (!isFound && pRoot->m_pLeft)
		isFound = getPath(pRoot->m_pLeft, pNode, path);

	// 右
	if (!isFound && pRoot->m_pRight)
		isFound = getPath(pRoot->m_pRight, pNode, path);

	if(!isFound)
		path.pop_back();

	return isFound;
}