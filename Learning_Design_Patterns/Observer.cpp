#include "Observer.h"

// �۲���1
ConcreteObeserver1::ConcreteObeserver1(Subject* pSubject)
	:m_pSubject(pSubject)
{
	//
}

void ConcreteObeserver1::update()
{
	//
}

// �۲���2
ConcreteObserver2::ConcreteObserver2(Subject* pSubject)
	:m_pSubject(pSubject)
{
	//
}

void ConcreteObserver2::update()
{
	//
}


// Ŀ��
void ConcreteSubject::attachObserver(Observer* observer)
{
	this->m_observerList.push_back(observer);
}

void ConcreteSubject::detachObserver(Observer* observer)
{
	this->m_observerList.remove(observer);
}

void ConcreteSubject::notifyObservers()
{
	for (auto it = m_observerList.begin(); it != m_observerList.end(); ++it) {
		(*it)->update();
	}
}