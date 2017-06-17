/*
	面试题21：包含min函数的栈

	题目：定义一个栈数据结构，请写出在该类型中能够得到栈的最小元素的函数。
		 在该栈中，调用min、push及pop的时间复杂度都是O(1)。

        思路：数据栈m_data来存放数据；另加一个辅助栈m_min来存放最小元素。
	      栈的push操作：数据栈和辅助栈同时进行元素的压入操作，压入元素的值为“栈顶元素和压入值较小”的值。
	      同理，元素的pop操作，两个栈都要进行pop操作。
*/

#include <stack>
#include <assert.h>

template<typename T>
class StackWithMin
{
private:
	// 数据栈
	std::stack<T> m_data;
	// 存放最小元素的栈
	std::stack<T> m_min;

public:
	// 压入栈
	void push(const T& value);
	// 删除栈顶元素
	void pop();
	// 获得最小元素
	void min();
};

template<typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	// 压入的元素值为较小的值
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
