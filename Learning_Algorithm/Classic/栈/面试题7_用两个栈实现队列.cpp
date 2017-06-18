/*
	������7��������ջʵ�ֶ���

	��Ŀ��������ջʵ��һ�����С����е��������£���ʵ����������push��pop��
		 �ֱ�����ڶ���β������ڵ���ڶ���ͷ��ɾ���ڵ�Ĺ��ܡ�

	˼·�����С����Ƚ��ȳ���ջ�����Ƚ����;
		  ά������ջm_stack_in��m_stack_out��ÿ�ζ��е���Ӳ�������Ԫ������m_stack_in��
		  ���еĳ��Ӳ�������m_stack_outΪ��ʱ���Ű�m_stack_in��Ԫ�����η���m_stack_out���ɡ�
		  ������m_stack_inջ��Ԫ�س�Ϊ��m_stack_outջ��Ԫ�أ���ʱ�ٴ�m_stack_outȡ��ʱ�����Ƕ����Ƚ��ȳ������ԡ�

*/


#include <iostream>
#include <stack>
#include <exception>

template<typename T>
class MyQueue
{
private:
	// ���Ԫ�ص�ջ
	std::stack<T> m_stack_in;
	// ����Ԫ�ص�ջ
	std::stack<T> m_stack_out;

public:
	MyQueue();
	~MyQueue();

	void push(const T& value);
	T pop();
};

template<typename T>
MyQueue<T>::MyQueue()
{}

template<typename T>
MyQueue<T>::~MyQueue()
{}

template<typename T>
void MyQueue<T>::push(const T& value)
{
	this->m_stack_in.push(value);
}

template<typename T>
T MyQueue<T>::pop()
{
	// ����m_stack_outΪ��ʱ��pushԪ����ջ
	if (this->m_stack_out.size() <= 0 ) {
		while (this->m_stack_in.size() > 0)
		{
			T top = this->m_stack_in.top();
			this->m_stack_in.pop();
			this->m_stack_out.push(top);
		}
	}

	if (this->m_stack_out.size() < 0)
		throw new std::exception("queue is empty!");
	
	T head = this->m_stack_out.top();
	this->m_stack_out.pop();

	return head;
}

void main()
{

	MyQueue<int>* que = new MyQueue<int>();
	que->push(1);
	que->push(2);
	que->push(3);
	std::cout << que->pop() << std::endl;// 1
	std::cout << que->pop() << std::endl;// 2
	std::cout << que->pop() << std::endl;// 3
	delete que;

	std::cin.get();
}