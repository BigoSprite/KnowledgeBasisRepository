/*
	��������ģ��һ��ջ

	��Ŀ������������ģ��һ��ջ����ʵ��push��pop��top������

	˼·�����С����Ƚ��ȳ���ջ�����Ƚ����;
	��ջ����Ԫ������ѹ�뵽�ǿյĶ��У���һ��Ԫ��ѹ������A
	��ջ���Ѷ���A��ǰn-1��Ԫ�ص�������B���ѵ�n��Ԫ��ȥ������ʱ������B�У��´β��������B������
	ջ�����Ѷ���A��ǰn-1��Ԫ�ص�������B���ѵ�n��Ԫ����Ϊջ��

	�ο���http://blog.csdn.net/wangyangkobe/article/details/5910362
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
		//���ڶ���ֻ��һ��Ԫ�أ�Ϊ�����ӵ�Ԫ��
		// ���ȱ�����
		m_queue1.pop();
	}
	else {
		for (int i = 0; i < m_queue2.size() - 1; ++i) {
			m_queue1.push(m_queue2.front());
			m_queue2.pop();
		}
		//���ڶ���ֻ��һ��Ԫ�أ�Ϊ�����ӵ�Ԫ��
		// ���ȱ�����
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
		//���ڶ���ֻ��һ��Ԫ�أ�Ϊ�����ӵ�Ԫ��
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
		//���ڶ���ֻ��һ��Ԫ�أ�Ϊ�����ӵ�Ԫ��
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