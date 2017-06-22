/*
	������4���滻�ո�

	��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
	     ��������"We are happy."�������"We%20are%20happy."��

	˼·��1.����������ͷ��β�����ո񣬶���ÿ���ո��ַ�����Ҫ�ƶ�����O(N)���ַ�����˶Ժ���O(N)���ո��ַ����ַ����Ķ����ܵ�ʱ��Ч����O(N^2)��
	      2. ˼·1����ԭ���Ǵ�ǰ������ÿ���ַ���Ҫ�ظ��ƶ��ַ���Σ���ô���ǿɿ��ǴӺ���ǰ���ƣ������ɼ����ƶ��������Ӷ����Ч�ʡ�

	˼·2�Ĵ�������
	@ʱ�临�Ӷȣ�O(N)
	@param string ��������ַ���
	@param length ����string��������
*/
void replaceBlank(char string[], int length)// ��Ϊÿ���ո���Ҫ���������ո������ַ������������ַ���Ҫ�����ƶ������ֽڣ�������������ַ������ǡ�
{
	// �߽��������
	if (string == NULL || length <= 0)
		return;

	// ͳ���ַ�����ʵ�ʳ��ȼ��ո������
	int originalLength = 0;// �ַ�����ʵ�ʳ���
	int numberOfBlank = 0; // �ո������
	int i = 0;
	while (string[i] != '\0') {
		++originalLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}

	// �滻�ո���µ��ַ����ĳ��ȼ���Ϸ��Լ��
	int newLength = originalLength + 2 /*һ���ո����������ո�����20*/ * numberOfBlank;
	if (newLength > length)// �³��ȳ������ܵ�����
		return;

	// ���߼������滻�ո�
	// ����--->ѭ��(��ʼֵ����ֹ���������������³�ʼֵ)
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	// ԭʼ����û�ߵ�0 && ������û��׷��ԭʼ���� ---> ִ��ѭ����
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (string[indexOfOriginal] != ' ') // ԭʼ����û�������ո�--->����
			string[indexOfNew--] = string[indexOfOriginal];
		else {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		--indexOfOriginal;
	}
}