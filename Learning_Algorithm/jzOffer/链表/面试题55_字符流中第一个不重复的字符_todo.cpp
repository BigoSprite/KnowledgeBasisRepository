
/*
	面试题55：字符流中第一个不重复的字符

	题目：请实现一个函数用来找出字符流只呢个第一个只出现一个的字符。
	      如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。
		  当从该字符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

	思路：字符只能一个一个的从字符流中读出来，可以定义一个容器来存放读出来的字符。
		  为了更高效的解决这个问题，需要在O(1)时间内往容器中插入和更新一个字符。
		  受面试题35启发，使用哈希表（数组实现），索引为ASII码，值为出现的次数。

*/
class CharStatistics
{
private:
	// hashTable[i]：A character with ASII value i;
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
