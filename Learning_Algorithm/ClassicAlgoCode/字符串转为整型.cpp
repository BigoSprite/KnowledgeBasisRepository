enum Status
{
	kValid = 0,
	kInvalid
};

int g_nStatus = kValid;
const int MAX = 0X7FFFFFFF;

/**
 * @功能 字符串转换为int
 * @param str 指向待输入的字符串的指针
 *
 * @NOTE 注意边界条件的检查及输入的字符合法性检查及最大最小整数溢出等问题！
 * @核心算法 遍历字符串，把每个字符对应的数字乘以10 + 字符 - '0'，如：
 *		    num = num * 10 + (ch - '0')
 */
int StrToInt(const char* str)
{
	g_nStatus = kInvalid;// 全局变量来判断输入的合法性(比如"0")

	long long result = 0;

	// 边界条件判断
	if (str != NULL && *str != '\0') {

		const char* copy = str;

		// 判断正负性
		bool isMinus = false;
		if (*copy == '+') {// 判断第一个字符是+还是-，以表示正负
			++copy;
		}
		else if (*copy == '-') {
			++copy;
			isMinus = true;
		}

		// 主逻辑
		while (*copy != '\0')
		{
			// 判断是否是0-9
			if (*copy >= '0' && *copy <= '9') {
				result = result * 10 + (*copy - '0');

				// 判断数字是否溢出
				if (result > MAX) {
					result = 0;
					break;
				}

				++copy;
			}
			else {// 如果是非法的字符，那么直接跳出循环
				result = 0;
				break;
			}
		}

		if (*copy == '\0') {// 最后的*copy == '\0'说明输入的字符串是合法的数字字符串
			g_nStatus = kValid;
			if (isMinus == true) {// 修改正负性
				result = 0 - result;
			}
		}
	}

	return (int)result;
}