/*
	面试题35：第一个只出现一次的字符

	题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。

	思路：1. 从头到尾遍历字符串，拿当前字符与后面的所有字符相比较，如果当前字符与后面所有字符均不相等；该字符即为所求。
			 这种方法为暴力搜索方法，时间复杂度为：O(N^2)。
		  2. 使用哈希表(使用数组,因为数组大小为常数，所以空间复杂度为O(1))存储，把时间复杂度降低至O(N)。
			 因为所有字符对应的ASII码有0~255种可能，那么使用一个256大小的数组存放，键为字符对应的ASII码，值为字符出现的次数。

	时间复杂度：O(N)；空间复杂度O(1)
*/
char getFirstCharNotRepeating(const char* str)
{
	// 边界条件检查
	if (str == NULL)
		return '\0';

	// 空间复杂度O(1)
	// 构造哈希表
	unsigned int hashTable[256] = {0};

	// 时间复杂度：O(N)
	// 遍历字符串，更新哈希表中字符出现的次数
	const char* pHashKey = str;
	while (*pHashKey != '0')
	{
		hashTable[*pHashKey /* 一个字符，对应一个ASII码 */ ]++;
		pHashKey++;
	}
	
	// 时间复杂度：O(N)
	// 再次遍历字符串，使用O(1)时间找到字符在哈希表中的出现的次数
	pHashKey = str;
	while (pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1) {
			return *pHashKey;
		}
		pHashKey++;
	}
	return '\0';
}