#include "Singleton.h"

// 静态数据成员赋值在类外
Singleton* Singleton::_instance = nullptr;

// 构造函数为私有或保护
Singleton::Singleton()
{}

// 获得实例的静态方法
Singleton* Singleton::getInstance()
{
	if (_instance == nullptr) {
		_instance = new Singleton();
	}

	return _instance;
}
