#include<iostream>
using namespace std;

class Singleton
{
private:
	static Singleton * instance;

	Singleton()
	{
		cout<<"Private constructor of singleton class"<<endl;
	}
	
	Singleton(const Singleton &) = delete;

	const Singleton & operator=(const Singleton &) = delete;

public:

	static Singleton * getInstance()
	{
		if(instance == NULL)
		{
			instance = new Singleton();
		}
		return instance;
	}

	void print()
	{
		cout << "Hello printer" << endl;
	}
};

Singleton * Singleton::instance = NULL;

int main()
{
	Singleton * p1 = Singleton::getInstance();
	p1 -> print();
	Singleton * p2 = Singleton::getInstance();
	p2->print();


}