class Hun_Singleton
{
public:
	static Hun_Singleton * getInstance()
	{
		return &m_instance;
	}
private:
	Hun_Singleton(){}
	Hun_Singleton(Hun_Singleton const& hun_singleton){}
	Hun_Singleton& operator=(Hun_Singleton const& hun_singleton){}
	static Hun_Singleton m_instance;
};

Hun_Singleton Hun_Singleton::m_instance;

int main()
{
	return 0;
}
