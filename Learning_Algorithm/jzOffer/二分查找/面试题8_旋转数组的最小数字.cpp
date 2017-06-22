/*
	������8����ת�������С����
	��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
		  ����һ����������������һ����ת�������ת�������СԪ�ء�
		  ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��

	˼·��1.��������˳��������飬�ҵ���СԪ�أ�ʱ�临�Ӷ�O(N)��û�õ���ת��������ԣ����Թٲ������⡣
	      2.ʹ�ö��ֲ��ң�ʱ�临�Ӷ�O(logN)��
		    ά����������start��end�����м�����middle���жϸ�������Ӧֵλ���ĸ���������������:
				2-1.��data[middle] >= data[start]������λ��ǰ��ĵ��������飬��start=middle����С��Χ��
				2-2.��data[middle] <= data[end]������λ�ں���ĵ��������飬��end=middle����С��Χ��
				2-3.��start��end���ڣ������1����ôֹͣѭ����end��ָԪ�ؼ�Ϊ��СԪ�ء�
*/
int getMinNumber(int data[], int length)
{
	if (data == NULL || length <= 0)
		throw new std::exception("Invalid parameters.");// ������

	int start = 0;
	int end = length - 1;
	// middle������Сֵ������
	int middle = start;// ���������������ǰ��ĵ�0��Ԫ�ذᵽ����ĩβ������ѭ����ִ�У�ֱ�ӷ�������ĵ�һ��Ԫ��
	while (data[start] >= data[end]) {// ǰ��������Ӧ��ֵʼ�մ��ں���Ĳ�ѭ��

		if (end - start == 1) {// ������ ѭ������ֹ����
			middle = start;// middle������Сֵ������
			break;
		}

		middle = (end - start) / 2 + start;

		// ���������start��end��middle����������Ӧ��ֵ��ȣ���ôֻ��ʹ��˳�������Сֵ
		if (data[start] == data[middle] && data[end] == data[middle])
			return getMinInOrder(data, start, end);

		if (data[middle] >= data[start]) {
			start = middle;
		}
		else if (data[middle] <= data[end]) {
			end = middle;
		}
	}

	return data[middle];// middle
}

/*
	˳�����data�����е���Сֵ
	����start��end��������Ϊ�����ҵ����������data��������
*/
int getMinInOrder(int data[], int start, int end)
{
	int min = data[start];
	for (int i = start + 1; i <= end; ++i) {
		if (data[i] < min) {
			min = data[i];
		}
	}
	return min;
}

