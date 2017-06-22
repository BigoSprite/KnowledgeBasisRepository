/*
	面试题25：二叉树中和为某一值的路径
	题目：输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
	      从树的根节点开始从上往下一直到叶节点所经过的节点形成一条路径。
*/
#include <vector>
struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;	
};

void findPath(TreeNode* pRoot, int sum)
{
	if(pRoot == NULL)
		return;
	std::vector<int> path;
	int currentSum = 0;
	findPath(pRoot, sum, path, currentSum);	
}


void findPath(TreeNode* pRoot, int sum, std::vector<int>& path, int currentSum)
{
	/// ！！！根
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);	
	// 是叶节点
	bool isLeaf = !pRoot->m_pLeft && !pRoot->m_pRight;
	if(sum == currentSum && isLeaf){// 找到一条路径
		// 打印路径
		
	}
	
	/// ！！！左
	if(pRoot->m_pLeft)
		findPath(pRoot->m_pLeft, sum, path, currentSum);
	
	/// ！！！右
	if(pRoot->m_pRight)
		findPath(pRoot->m_pRight, sum, path, currentSum);
	
	/// ！！！在返回父节点之前，在路径上删除当前节点
	path.pop_back();
}