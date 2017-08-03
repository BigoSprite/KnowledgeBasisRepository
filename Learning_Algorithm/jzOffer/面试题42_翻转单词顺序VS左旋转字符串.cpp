/*
	��Ŀ1������һ��Ӣ�ľ��ӣ���ת���ӵ�˳�򣬵����ʵ�˳�򲻱䡣
		���磺"I am a student."��תΪ"student. a am I"
		
	�㷨��
		��1����ת�������ӣ�".tneduts a ma I"
		��2����ת���ʡ�"student. a am I"
*/

// ��תһ���ַ���
void reverse(char* pBegin, char* pEnd)
{
	if(pBegin == NULL || pEnd == NULL)
		return;
	
	while(pBegin < pEnd)
	{
		char* tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		
		++pBegin;
		--pEnd;
	}
}

char* reverseSentence(char* pData)
{
	if(pData == NULL)
		return NULL;
	
	char* pBegin = pData;
	char* pEnd = pData;
	while(*pEnd != '\0'){
		pEnd++;
	}
	pEnd--;
	
	// ��ת��������
	reverse(pBegin, pEnd);// ".tneduts a ma I"
	
	pBegin = pEnd = pData;
	while(*pBegin != '\0'){
		if(*pEnd != ' '){
			pEnd++;
		}else if(*pEnd == ' ' || *pEnd == '\0'){// ����ո��ĩβ
			reverse(pBegin, --pEnd);
			pBegin = ++pEnd;// �������ո�
		}else if(*pBegin == ' '){// �ӿո����������ʵĿ�ʼ��
			pBegin++;
			pEnd++;
		}
	}
	
	return pData;
}


/*
	��Ŀ2��
		�ַ��������������ǰ��ַ�����ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
		�붨��һ������ʵ���ַ���������ת�������ܡ�
		���磺����"abcdefg"������2���ú�����������ת2λ���Ľ��"cdefgab"��
		
	˼·����1��"ab|cdefg"--->"ba|gfedc"--->"cdefgab"
		  ��2��"abcdefg"--->"gfedc|ba"--->"cdefg|ab"
	˼·1�Ľⷨ�������£�
*/

char* leftRotateString(char* pStr, int n)
{
	if(pStr != NULL){
		int nLen = static_case<int>(strlen(pStr));
		if(n > 0 && nLen > 0 && n < nLen){// �߽��������
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart =  pStr + n;
			char* pSecondEnd = pStr + nLen - 1;
			
			// ��ת�ַ�����ǰn���ַ�
			reverse(pFirstStart, pFirstEnd);
			// ��ת�ַ����ĺ��沿��
			reverse(pSecondStart, pSecondEnd);
			// ��ת�����ַ���
			reverse(pStr, pSecondEnd);
		}
	}
	
	return pStr;
}

