enum Status
{
	kValid = 0,
	kInvalid
};

int g_nStatus = kValid;
const int MAX = 0X7FFFFFFF;

/**
 * @���� �ַ���ת��Ϊint
 * @param str ָ���������ַ�����ָ��
 *
 * @NOTE ע��߽������ļ�鼰������ַ��Ϸ��Լ�鼰�����С������������⣡
 * @�����㷨 �����ַ�������ÿ���ַ���Ӧ�����ֳ���10 + �ַ� - '0'���磺
 *		    num = num * 10 + (ch - '0')
 */
int StrToInt(const char* str)
{
	g_nStatus = kInvalid;// ȫ�ֱ������ж�����ĺϷ���(����"0")

	long long result = 0;

	// �߽������ж�
	if (str != NULL && *str != '\0') {

		const char* copy = str;

		// �ж�������
		bool isMinus = false;
		if (*copy == '+') {// �жϵ�һ���ַ���+����-���Ա�ʾ����
			++copy;
		}
		else if (*copy == '-') {
			++copy;
			isMinus = true;
		}

		// ���߼�
		while (*copy != '\0')
		{
			// �ж��Ƿ���0-9
			if (*copy >= '0' && *copy <= '9') {
				result = result * 10 + (*copy - '0');

				// �ж������Ƿ����
				if (result > MAX) {
					result = 0;
					break;
				}

				++copy;
			}
			else {// ����ǷǷ����ַ�����ôֱ������ѭ��
				result = 0;
				break;
			}
		}

		if (*copy == '\0') {// ����*copy == '\0'˵��������ַ����ǺϷ��������ַ���
			g_nStatus = kValid;
			if (isMinus == true) {// �޸�������
				result = 0 - result;
			}
		}
	}

	return (int)result;
}