/*
	������24�������������ĺ����������
	��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
		  ������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��

		  ��           ��            ��
	˼·��{5, 7, 6,    9, 11, 10,     8}
	     ������������Ҹ�===>��������һ��Ԫ���Ǹ��ڵ�洢��ֵ��
		 �����������������������ڵ��ֵ < ���ڵ��ֵ < �����������ڵ��ֵ

		 ��������¼һ������i��ָ���������������ĵ�һ��Ԫ�ء���������i���еݹ鼴�ɡ�
*/
bool verifySquenceOfBST_Recursively(int data[], int length)
{
	if (data == NULL || length <= 0)
		return false;
	
	int rootValue = data[length - 1];
	
	// ��¼һ������i��ָ���������������ĵ�һ��Ԫ�أ��ҵ���
	int i = 0;
	for (; i < length - 1; ++i) {
		if (data[i] > rootValue)
			break;
	}
	// �ж��������Ƿ���϶���������������
	int j = i;
	for (; j < length - 1; ++j) {
		if (data[j] < rootValue)
			return false;
	}

	// �ж��������ǲ��Ƕ���������
	bool isLeft = true;
	if (i > 0) 
		isLeft = verifySquenceOfBST_Recursively(data, i);

	// �ж��������ǲ��Ƕ���������
	bool isRight = true;
	if (i < length - 1)
		isRight = verifySquenceOfBST_Recursively(data + i, length - i - 1);

	return isLeft&&isRight;
}