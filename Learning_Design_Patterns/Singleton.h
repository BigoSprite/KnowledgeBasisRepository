#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton
{
public:
	//  获得实例的静态方法
	static Singleton* getInstance();

	/// other methods

protected:
	// 构造函数为私有或保护
	Singleton();

private:
	// 静态实例成员
	static Singleton* _instance;

	/// other datas
};

#endif // __SINGLETON_H__