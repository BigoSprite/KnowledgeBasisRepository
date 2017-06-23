/*
	面试题39：二叉树的深度
	
	题目1：输入一棵二叉树的根节点，求该树的深度。
	       从根节点到叶节点依次经过的节点（含根、叶节点）形成一条路径，最长路径的长度为树的深度。
		  
	题目2：输入一棵二叉树的根节点，判断该树是不是二叉平衡树。
		   如果某二叉平衡树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
*/

struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;	
};

/// 题目1：二叉树的深度为：左、右子树深度较大的值+1
int getTreeDepth_Recursively(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return 0;// ！！！空树的深度为0；只有一个根节点的树的深度为1
	
	int left = getTreeDepth_Recursively(pRoot->m_pLeft);
	int right = getTreeDepth_Recursively(pRoot->m_pRight);
	
	int maxDepth = left > right ? left : right;
	return 1 + maxDepth;
}


/// 题目2：输入一棵二叉树的根节点，判断该树是不是二叉平衡树。
/// 任意节点的左右子树的深度相差不超过1
/*
 * #1 需要重复遍历节点多次的解法，简单单不足以打动面试官
 *                1
 *             2      3
 *          4     5       6
 *              7
 * 我们首先会判断根节点1是不是平衡的，这是需要遍历2 4 5 7；
 * 当以2为根判断是否是平衡树的时候，仍要遍历4 5 7，等等。
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
 * #2 每个节点仅遍历一次的解法
 *                1
 *             2      3
 *          4     5       6
 *              7
 * 使用后序遍历，在遍历到一个节点之前，它的左右子树已经被遍历。
 * 只要遍历每个节点的时候记录它的深度，我们就可以一边遍历，一边判断每个每个节点是否是平衡的。
 */
bool isBalancedTree_best(TreeNode* pRoot)
{
	int depth = 0;
	return isBalancedTree(pRoot, &depth);
}

bool isBalancedTree(TreeNode* pRoot, int* depth)// ！！！记录每个节点的深度
{
	if(pRoot == NULL){
		*depth = 0;// ！！！记录每个节点的深度
		return true;
	}
	
	int left, right;
	// 每个节点是二叉平衡树的情况
	if(isBalancedTree(pRoot->m_pLeft, left)// 左
		&& isBalancedTree(pRoot->m_pRight, right)){// 右
		// 记录根节点的深度
		int diff = right - left;
		if(diff <= 1 && diff >= -1){
			*depth = 1 + (left > right? left: right);
			return true;
		}
	}
	
	return false;
}


