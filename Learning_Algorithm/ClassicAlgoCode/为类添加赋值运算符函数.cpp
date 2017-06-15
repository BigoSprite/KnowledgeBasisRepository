class CMyString
{
public:
	// ctor
	CMyString(char* pData = nullptr);
	// default ctor
	CMyString(const CMyString& rhs);
	// dtor
	~CMyString();
private:
	char* m_pData;
};


// 面试题1：为该类添加赋值运算符函数

// 没有考虑异常安全的解法
CMyString& CMyString::operator=(const CMyString& rhs)
{
	if (this != &rhs) {
		// #1. 释放掉自身已有的空间
		delete[] m_pData;
		m_pData = NULL;

		// #2. 重新分配内存
		// ！！！假如new char抛出异常，那么#1的内存已经释放掉了,很容易造成程序崩溃。
		// 更好的做法是先new char分配内存，分配成功了再释放掉原有的空间！
		m_pData = new char[strlen(rhs.m_pData) + 1];
		strcpy(m_pData, rhs.m_pData);
	}

	return *this;
}


// 考虑异常安全的同时更好地的解法——和临时变量交换
CMyString&/* #1返回自身的引用 */ CMyString::operator=(const CMyString& rhs/* #2使用const引用提高效率 */)
{
	if (this != &rhs/* #3判断传入的参数和当前实例是否为同一个实例 */) {
		// 创建一份拷贝，它是临时变量；出了if作用域，就会自动调用析构函数释放strTmp的资源
		CMyString strTmp(rhs);
		// 交换strTmp.m_pData和自身的m_pData；strTmp.m_pData也就指向了m_pData，this->m_pData会随着strTmp的释放而动态释放！
		char* tmp = strTmp.m_pData;
		strTmp.m_pData = this->m_pData;
		m_pData = tmp;
	}

	return *this/* #4返回*this */;
}