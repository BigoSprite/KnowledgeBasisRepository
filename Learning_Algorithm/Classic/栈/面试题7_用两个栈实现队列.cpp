/*
	面试题7：用两个栈实现队列

	题目：用两个栈实现一个队列。队列的声明如下，请实现两个函数push和pop，
		 分别完成在队列尾部插入节点和在队列头部删除节点的功能。

	思路：队列——先进先出；栈——先进后出;
		  维护两个栈m_stack_in和m_stack_out，每次队列的入队操作：把元素置入m_stack_in。
		  队列的出队操作：当m_stack_out为空时，才把m_stack_in的元素依次放入m_stack_out即可。
		  这样，m_stack_in栈顶元素成为了m_stack_out栈底元素，此时再从m_stack_out取出时，便是队列先进先出的特性。

*/


#include <iostream>
#include <stack>
#include <exception>

template<typename T>
class MyQueue
{
private:
	// 入队元素的栈
	std::stack<T> m_stack_in;
	// 出队元素的栈
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
	// 仅当m_stack_out为空时才push元素入栈
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