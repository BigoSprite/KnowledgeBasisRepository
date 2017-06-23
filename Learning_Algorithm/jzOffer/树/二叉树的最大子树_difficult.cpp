/*
	题目：找出二叉树中最大的子树，该子树为二叉搜索树。所谓最大的子树就是指结点数目最多的子树。
	
	思路：二叉平衡树：任意左子结点的值 < 根节点的值 < 任意右子结点的值
	
	      例如：     二叉树A        最大二叉搜索子树
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
	int data[3] = {0, 0, 0};// 分别存放最小值，最大值和节点数
	TreeNode* result = postOrder_Recursively(pRoot, data);
	
	return result;
}

// 后序遍历主逻辑——返回二叉树的最大二叉搜索子树的根节点
TreeNode* postOrder_Recursively(TreeNode* pRoot, int data[])
{
	// 递归结束的边界条件
	if(pRoot == NULL){
		data[0] = MAX;
		data[1] = -MAX;
		data[2] = 0;
		return NULL;
	}

    //递归左右子树，获取4个信息
	// 左
	TreeNode* lBST= postOrder_Recursively(pRoot->m_pLeft, data);
	int lMin = data[0];
	int lMax = data[1];
	int lSize = data[2];
	// 右
	TreeNode* rBST= postOrder_Recursively(pRoot->m_pRight, data);
	int rMin = data[0];
	int rMax = data[1];
	int rSize = data[2];
	
	// 更新当前结点为根的子树的最小值、最大值
	data[0] = lMin < pRoot->m_nValue ? lMin : pRoot->m_nValue;
	data[1] = rMax > pRoot->m_nValue ? rMax : pRoot->m_nValue;
	
	// 根
	// 情况1
	if(pRoot->m_pLeft == lBST && pRoot->m_pRight == rBST
		&& pRoot->m_nValue > lMax && pRoot->m_nValue < rMin){
		data[2] = lSize + rSize + 1;
		return pRoot;// 情况1满足时返回			
	}else{
		data[2] =  lSize > rSize ? lSize : rSize;
		// 情况2
		return lSize > rSize ? lBST : rBST;
	}
}












