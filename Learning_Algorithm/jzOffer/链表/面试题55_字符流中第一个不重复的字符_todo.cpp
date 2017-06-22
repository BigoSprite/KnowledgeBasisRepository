
/*
	������55���ַ����е�һ�����ظ����ַ�

	��Ŀ����ʵ��һ�����������ҳ��ַ���ֻ�ظ���һ��ֻ����һ�����ַ���
	      �磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���'g'��
		  ���Ӹ��ַ����ж���ǰ�����ַ�"google"ʱ����һ��ֻ����һ�ε��ַ���'l'��

	˼·���ַ�ֻ��һ��һ���Ĵ��ַ����ж����������Զ���һ����������Ŷ��������ַ���
		  Ϊ�˸���Ч�Ľ��������⣬��Ҫ��O(1)ʱ�����������в���͸���һ���ַ���
		  ��������35������ʹ�ù�ϣ������ʵ�֣�������ΪASII�룬ֵΪ���ֵĴ�����

*/
class CharStatistics
{
private:
	// hashTable[i]��A character with ASII value i;
	// hashTable[i] = -1: The character has not found;
	// hashTable[i] = -2: The character has been found for multiple times;
	// hashTable[i] >= 0: The character has been found only once.
	int hashTable[256];
	int index;
public:
	CharStatistics():index(0) {
		for (int i = 0; i < 256; ++i) {
			hashTable[i] = -1;
		}
	}

	void insert(char ch)
	{
		if (hashTable[ch] == -1)
			hashTable[ch] == index;
		else if (hashTable[ch] >= 0) 
			hashTable[ch] = -2;

		++index;
	}

	char firstAppearingOnce()
	{
		char ch = '\0';
		int minIndex = std::numeric_limits<int>::max();
		for (int i = 0; i < 256; ++i) {
			if (hashTable[i] >= 0 && hashTable[i] < minIndex) {
				ch = (char)i;
				minIndex = hashTable[i];
			}
		}
		return ch;
	}

};
