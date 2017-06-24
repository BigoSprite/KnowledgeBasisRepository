/*
	面试题59：对称的二叉树
	题目：请实现一个函数，用来判断一棵二叉树是不是对称的。
		   如果一棵二叉树和它的镜像一样，那么它是对称的。
		   
    思路：前序遍历：根左右
	      前序遍历的对称遍历算法：根右左
		  
		  我们可以通过比较前序遍历序列和对称遍历序列来判断二叉树是不是对称的。
		  
	注意：要在遍历二叉树时把遇到的NULL指针也考虑进来。
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
	// 当前根节点都为NULL，那么当前根节点为根的树是对称的
	if(!pRoot1 && !pRoot2)
		return true;
	// 当前根节点中有一个为NULL，那么不是对称的
	if(!pRoot1 || !pRoot2)
		return false;
	
	// 根节点都不为NULL时，判断里面存储的值是否相同
	if(pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	
	
	// ！！！根左右、根右左  ！一起遍历，在遍历中比较；没有借助辅助数组。
	return preSymmOrder_Recursively(pRoot1->m_pLeft, pRoot2->m_pRight)// 左、右
			&& preSymmOrder_Recursively(pRoot1->m_pRight, pRoot2->m_pLeft);// 右、左
}











