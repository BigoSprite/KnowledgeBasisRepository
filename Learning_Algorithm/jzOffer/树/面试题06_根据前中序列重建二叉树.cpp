/*
	������6���ؽ�������
	��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ��ö�������
		  ���������ǰ���������������Ľ���в������ظ������֡����磺
		  ǰ�������{1, 2, 4, 7, 3, 5, 6, 8}�����������{4, 7, 2, 1, 5, 3, 8, 6},
		  ���ؽ���ͼ2.6��ʾ�Ķ��������������ͷ�ڵ㡣

	˼·��ǰ������������ң���������������
	      --->1Ϊ����Ȼ�������������Ľ�����ҵ�ָ����ڵ��ָ�룻��������������ĳ��ȣ�
		  �������֪���������ĳ��ȣ���ôǰ��֪����������е����������м���������е����������У�����������ˡ�
		  Ȼ�󣬵ݹ�ع�����������ɡ�
	
*/
#include <exception>
struct TreeNode
{
	int m_nValue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

TreeNode* construct(int* preOrder, int* inOrder, int length)
{
	if (preOrder == NULL || inOrder == NULL || length <= 0)
		return NULL;
	return constructCore(preOrder, preOrder + length - 1,
		inOrder, inOrder + length - 1);
}

/*
	@param startPreOrder ǰ��������������ʼԪ�ص�λ�ã�ָ�룩
	@param endPreOrder ǰ�����������н���Ԫ�ص�λ�ã�ָ�룩
	@param startInOrder ����������������ʼԪ�ص�λ�ã�ָ�룩
	@param endInOrder ��������������βԪ�ص�λ�ã�ָ�룩
*/
TreeNode* constructCore(
	int* startPreOrder, int* endPreOrder,
	int* startInOrder, int* endInOrder)
{
	// ���ڵ�洢��ֵ
	int rootValue = *startPreOrder;

	//���������ڵ�
	TreeNode* pRoot = new TreeNode();
	pRoot->m_nValue = rootValue;
	pRoot->m_pLeft = NULL;
	pRoot->m_pRight = NULL;

	// �Ϸ���
	if (startPreOrder == endPreOrder) {
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return pRoot;
		else
			throw std::exception("Invalid input.");
	}

	// �������ҵ����������С�ָ����ڵ��ָ�롱��rootInOrder
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;

	// �Ϸ���
	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
		throw std::exception("Invalid input.");

	// �����������ڵ����еĳ��ȣ�leftLength
	int leftLength = rootInOrder - startInOrder;

	int* leftPreOrderEnd = startPreOrder + leftLength;// ǰ����������������н�����ָ��
	if (leftLength > 0) 
		pRoot->m_pLeft = constructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	if (leftLength < endPreOrder - startPreOrder)
		pRoot->m_pRight = constructCore(leftPreOrderEnd + 1, endPreOrder,
			rootInOrder + 1, endInOrder);

	return pRoot;
}