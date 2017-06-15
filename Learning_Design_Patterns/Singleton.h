#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton
{
public:
	//  ���ʵ���ľ�̬����
	static Singleton* getInstance();

	/// other methods

protected:
	// ���캯��Ϊ˽�л򱣻�
	Singleton();

private:
	// ��̬ʵ����Ա
	static Singleton* _instance;

	/// other datas
};

#endif // __SINGLETON_H__