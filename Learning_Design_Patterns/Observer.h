#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <list>

// 抽象类
class Observer
{
public:
	virtual void update() = 0;
};

class Subject
{
public:
	virtual void attachObserver(Observer*) = 0;
	virtual void detachObserver(Observer*) = 0;
	virtual void notifyObservers() = 0;
};



// 具体类
class ConcreteObeserver1 : public Observer
{
public:
	ConcreteObeserver1(Subject* pSubject);
	virtual void update();

private:
	Subject* m_pSubject;
};

class ConcreteObserver2 : public Observer
{
public:
	ConcreteObserver2(Subject* pSubject);
	virtual void update();

private:
	Subject* m_pSubject;
};


class ConcreteSubject : public Subject
{
public:
	virtual void attachObserver(Observer* observer);
	virtual void detachObserver(Observer* observer);
	virtual void notifyObservers();

private:
	std::list<Observer*> m_observerList;
};

#endif // __OBSERVER_H__
