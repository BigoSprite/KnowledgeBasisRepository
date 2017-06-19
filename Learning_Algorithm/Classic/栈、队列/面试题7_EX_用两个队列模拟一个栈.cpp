/*
	两个队列模拟一个栈

	题目：用两个队列模拟一个栈。并实现push、pop和top方法。

	思路：队列——先进先出；栈——先进后出;
	入栈：将元素依次压入到非空的队列，第一个元素压倒对列A
	出栈：把队列A的前n-1个元素倒到队列B，把第n个元素去掉。此时数据在B中，下次操作，则对B操作。
	栈顶：把队列A的前n-1个元素倒到队列B，把第n个元素作为栈顶

	参考：http://blog.csdn.net/wangyangkobe/article/details/5910362
*/


#include <iostream>
#include <queue>
#include <exception>

template<typename T>
class MyStack
{
private:
	std::queue<T> m_queue1;
	std::queue<T> m_queue2;

public:
	MyStack();
	~MyStack();

	void push(const T& value);
	void pop();
	T top();
};

template<typename T>
MyStack<T>::MyStack()
{}

template<typename T>
MyStack<T>::~MyStack()
{}

template<typename T>
void MyStack<T>::push(const T& value)
{
	if (m_queue1.empty() && m_queue2.empty()) {
		m_queue1.push(value);
	}
	else if (!m_queue1.empty() && m_queue2.empty()) {
		m_queue1.push(value);
	}
	else if (m_queue1.empty() && !m_queue2.empty() ) {
		m_queue2.push(value);
	}
}

template<typename T>
void MyStack<T>::pop()
{
	if (!m_queue1.empty()) {
		for (int i = 0; i < m_queue1.size() - 1; ++i) {
			m_queue2.push(m_queue1.front());
			m_queue1.pop();
		}
		//现在队列只有一个元素，为最后入队的元素
		// 最先被弹出
		m_queue1.pop();
	}
	else {
		for (int i = 0; i < m_queue2.size() - 1; ++i) {
			m_queue1.push(m_queue2.front());
			m_queue2.pop();
		}
		//现在队列只有一个元素，为最后入队的元素
		// 最先被弹出
		m_queue2.pop();
	}
}

template<typename T>
T MyStack<T>::top()
{
	if (!m_queue1.empty()) {
		for (int i = 0; i < m_queue1.size() - 1; ++i) {
			m_queue2.push(m_queue1.front());
			m_queue1.pop();
		}
		//现在队列只有一个元素，为最后入队的元素
		T result = m_queue1.front();
		m_queue1.pop();
		m_queue2.push(result);
		return result;
	}
	else {
		for (int i = 0; i < m_queue2.size() - 1; ++i) {
			m_queue1.push(m_queue2.front());
			m_queue2.pop();
		}
		//现在队列只有一个元素，为最后入队的元素
		T result = m_queue2.front();
		m_queue2.pop();
		m_queue1.push(result);
		return result;
	}
}

void main()
{

	MyStack<int>* s = new MyStack<int>();
	for (int i = 0; i <= 9; ++i) {
		s->push(i);
	}

	std::cout << s->top() << std::endl;
	delete s;

	std::cin.get();
}