/*
	������25���������к�Ϊĳһֵ��·��
	��Ŀ������һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
	      �����ĸ��ڵ㿪ʼ��������һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����
		  
		  ���磺��Ϊ22��·����10->3->7��10->12
					10
			    5		 12
			 4     7
	

		����      ����				�Ƿ���Ҷ�ڵ�			·��				·���ڵ�ֵ�ĺ�
		----------------------------------------------------------------------------------------
		 ��       ����10������			 ��					10					10
		 ��		 ����5 ����			 ��					10,5				15
		 ��		 ����4 ����			 ��					10,5,4				19
		 ��		 ����4���˻�5����ȥ4	 ��					10,5				15
		 ��		 ����7 ���ң�			 ��				    10,5,7				22
		 ��		 ��ӡ·��		

		�������Ĳ������ݹ鼴�ɡ�
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
	/// ��������
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);	
	// ��Ҷ�ڵ�
	bool isLeaf = !pRoot->m_pLeft && !pRoot->m_pRight;
	if(sum == currentSum && isLeaf){// �ҵ�һ��·��
		// ��ӡ·��
		
	}
	
	/// ��������
	if(pRoot->m_pLeft)
		findPath(pRoot->m_pLeft, sum, path, currentSum);
	
	/// ��������
	if(pRoot->m_pRight)
		findPath(pRoot->m_pRight, sum, path, currentSum);
	
	/// �������ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ�ڵ�
	path.pop_back();
}