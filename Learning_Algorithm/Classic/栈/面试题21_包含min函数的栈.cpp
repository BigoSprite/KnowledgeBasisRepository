/*
	������21������min������ջ

	��Ŀ������һ��ջ���ݽṹ����д���ڸ��������ܹ��õ�ջ����СԪ�صĺ�����
		 �ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��

    ˼·������ջm_data��������ݣ����һ������ջm_min�������СԪ�ء�
*/

#include <stack>
#include <assert.h>

template<typename T>
class StackWithMin
{
private:
	std::stack<T> m_data;
	std::stack<T> m_min;

public:
	// ѹ��ջ
	void push(const T& value);
	// ɾ��ջ��Ԫ��
	void pop();
	// �����СԪ��
	void min();
};

template<typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template<typename T>
void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() >0);

	m_data.pop();
	m_min.pop();
}

template<typename T>
void StackWithMin<T>::min()
{
	assert(m_data.size() > 0 && m_min.size() >0);

	m_min.top();
}
