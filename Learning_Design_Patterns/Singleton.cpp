#include "Singleton.h"

// ��̬���ݳ�Ա��ֵ������
Singleton* Singleton::_instance = nullptr;

// ���캯��Ϊ˽�л򱣻�
Singleton::Singleton()
{}

// ���ʵ���ľ�̬����
Singleton* Singleton::getInstance()
{
	if (_instance == nullptr) {
		_instance = new Singleton();
	}

	return _instance;
}
