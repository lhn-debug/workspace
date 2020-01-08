/*
 * 堆上创建对象：operator new
 * 栈上创建对象：构造函数、拷贝构造
 * */

class HeapOnly
{
public:
	/*在静态成员函数完成堆对象的创建*/
	static HeapOnly* CreateObj()
	{
		return new HeapOnly;
	}
private:
	/*防止调用构造函数或拷贝构造在栈上生成对象*/
	HeapOnly()
	{}
	HeapOnly(const HeapOnly& heapOnly);
};

class StackOnly
{
public:
	/*调用构造函数完成栈对象的创建*/
	StackOnly()
	{}
private:
	/*屏蔽operator new防止在堆上生成对象*/
	void* operator new(size_t size);
	void operator delete(void* p);
};
