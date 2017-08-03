/*
	题目1：输入一个英文句子，反转句子的顺序，但单词的顺序不变。
		例如："I am a student."翻转为"student. a am I"
		
	算法：
		（1）翻转整个句子；".tneduts a ma I"
		（2）翻转单词。"student. a am I"
*/

// 翻转一个字符串
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
	
	// 翻转整个句子
	reverse(pBegin, pEnd);// ".tneduts a ma I"
	
	pBegin = pEnd = pData;
	while(*pBegin != '\0'){
		if(*pEnd != ' '){
			pEnd++;
		}else if(*pEnd == ' ' || *pEnd == '\0'){// 到达空格或末尾
			reverse(pBegin, --pEnd);
			pBegin = ++pEnd;// 调整到空格处
		}else if(*pBegin == ' '){// 从空格处自增到单词的开始处
			pBegin++;
			pEnd++;
		}
	}
	
	return pData;
}


/*
	题目2：
		字符串的左旋操作是把字符串的前面的若干个字符转移到字符串的尾部。
		请定义一个函数实现字符串的左旋转操作功能。
		比如：输入"abcdefg"和数字2，该函数返回左旋转2位到的结果"cdefgab"。
		
	思路：（1）"ab|cdefg"--->"ba|gfedc"--->"cdefgab"
		  （2）"abcdefg"--->"gfedc|ba"--->"cdefg|ab"
	思路1的解法代码如下：
*/

char* leftRotateString(char* pStr, int n)
{
	if(pStr != NULL){
		int nLen = static_case<int>(strlen(pStr));
		if(n > 0 && nLen > 0 && n < nLen){// 边界条件检查
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart =  pStr + n;
			char* pSecondEnd = pStr + nLen - 1;
			
			// 翻转字符串的前n个字符
			reverse(pFirstStart, pFirstEnd);
			// 翻转字符串的后面部分
			reverse(pSecondStart, pSecondEnd);
			// 翻转整个字符串
			reverse(pStr, pSecondEnd);
		}
	}
	
	return pStr;
}

