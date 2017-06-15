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


// ������1��Ϊ������Ӹ�ֵ���������

// û�п����쳣��ȫ�Ľⷨ
CMyString& CMyString::operator=(const CMyString& rhs)
{
	if (this != &rhs) {
		// #1. �ͷŵ��������еĿռ�
		delete[] m_pData;
		m_pData = NULL;

		// #2. ���·����ڴ�
		// ����������new char�׳��쳣����ô#1���ڴ��Ѿ��ͷŵ���,��������ɳ��������
		// ���õ���������new char�����ڴ棬����ɹ������ͷŵ�ԭ�еĿռ䣡
		m_pData = new char[strlen(rhs.m_pData) + 1];
		strcpy(m_pData, rhs.m_pData);
	}

	return *this;
}


// �����쳣��ȫ��ͬʱ���õصĽⷨ��������ʱ��������
CMyString&/* #1������������� */ CMyString::operator=(const CMyString& rhs/* #2ʹ��const�������Ч�� */)
{
	if (this != &rhs/* #3�жϴ���Ĳ����͵�ǰʵ���Ƿ�Ϊͬһ��ʵ�� */) {
		// ����һ�ݿ�����������ʱ����������if�����򣬾ͻ��Զ��������������ͷ�strTmp����Դ
		CMyString strTmp(rhs);
		// ����strTmp.m_pData�������m_pData��strTmp.m_pDataҲ��ָ����m_pData��this->m_pData������strTmp���ͷŶ���̬�ͷţ�
		char* tmp = strTmp.m_pData;
		strTmp.m_pData = this->m_pData;
		m_pData = tmp;
	}

	return *this/* #4����*this */;
}