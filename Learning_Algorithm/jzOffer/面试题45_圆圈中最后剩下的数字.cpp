#include <iostream>
#include <list>
/*
	������43��ԲȦ�����ʣ�µ�����
			0~n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��
			ɾ����m�����֡������ʣ�µ����֡�

	˼·��1.ʹ��STL�е�list��ģ��ѭ������
*/

/*
 * @���� ԲȦ�����ʣ�µ�����
 * @param n ���ֵĸ���
 * @param m Ҫɾ����m������
 *
 * @���Ӷ� #1ʱ�临�Ӷ�O(m��n);#2�ռ临�Ӷ�O(n)
 */
int getLastNumber(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;

	// #2 ��0...n-1��Щ���ִ���list
	std::list<int> numbersList;
	for (int i = 0; i < n; ++i)
		numbersList.push_back(i);
	
	std::list<int>::iterator current = numbersList.begin();
	// #1
	while (numbersList.size() > 1) {
		for (int i = 1; i < m; ++i) {// ��m-1���ҵ�Ҫɾ���ڵ��λ�ã���������
			++current;
			if (current == numbersList.end())// ��ǰ������currentÿ��ǰ��һ��������Ҫ�ж��Ƿ񵽴�end()
				current = numbersList.begin();
		}

		// ɾ����ע��erase��ʹ�õ�����ʧЧ��
		// ����1
		//auto next = ++current;// �Ȱ�ָ����һ��Ԫ�صĵ�����������������Ϊerase��������ʹ�õ�����ʧЧ
		//if (next == numbersList.end())
		//	next = numbersList.begin();		
		//--current;// ���д��벻��ʹ��current + 1�����Ǵ���ģ���Ϊlist��֧��������ʣ�
		//numbersList.erase(current);
		//current = next;
		// ���� ����2
		current = numbersList.erase(current);// OR numbersList.erase(current++);���У�pos = current++;
		if (current == numbersList.end())
			current = numbersList.begin();
	}

	return *current;
}