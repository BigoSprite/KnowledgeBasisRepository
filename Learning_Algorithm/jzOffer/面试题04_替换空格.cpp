/*
	面试题4：替换空格

	题目：请实现一个函数，把字符串中的每个空格替换成"%20"。
	     例如输入"We are happy."，则输出"We%20are%20happy."。

	思路：1.暴力法：从头到尾搜索空格，对于每个空格字符，需要移动后面O(N)个字符；因此对含有O(N)个空格字符的字符串的而言总的时间效率是O(N^2)。
	      2. 思路1慢的原因是从前往后复制每个字符需要重复移动字符多次，那么我们可考虑从后往前复制，这样可减少移动次数，从而提高效率。

	思路2的代码如下
	@时间复杂度：O(N)
	@param string 待处理的字符串
	@param length 数组string的总容量
*/
void replaceBlank(char string[], int length)// 因为每个空格需要增加两个空格来填字符，后面所有字符都要往后移动两个字节，否则就有两个字符被覆盖。
{
	// 边界条件检查
	if (string == NULL || length <= 0)
		return;

	// 统计字符串的实际长度及空格的数量
	int originalLength = 0;// 字符串的实际长度
	int numberOfBlank = 0; // 空格的数量
	int i = 0;
	while (string[i] != '\0') {
		++originalLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}

	// 替换空格后新的字符串的长度及其合法性检查
	int newLength = originalLength + 2 /*一个空格需多出两个空格来填20*/ * numberOfBlank;
	if (newLength > length)// 新长度超过了总的容量
		return;

	// 主逻辑——替换空格
	// 遍历--->循环(初始值、终止条件、操作及更新初始值)
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	// 原始索引没走到0 && 新索引没有追上原始索引 ---> 执行循环体
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (string[indexOfOriginal] != ' ') // 原始索引没有遇到空格--->复制
			string[indexOfNew--] = string[indexOfOriginal];
		else {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		--indexOfOriginal;
	}
}