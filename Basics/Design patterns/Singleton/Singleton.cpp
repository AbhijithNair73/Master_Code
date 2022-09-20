#include<iostream>
using namespace std;

class Singleton
{
private:

	Singleton()
	{
		cout<<"Private constructor of singleton class"<<endl;
	}
	

public:
	Singleton(const Singleton &) = delete;
	const Singleton & operator=(const Singleton &) = delete;

	static Singleton & getInstance()
	{
			static Singleton stn;
			return stn;
	}

	void print()
	{
		cout << "Hello printer" << endl;
	}
};


int main()
{
	Singleton p1 = Singleton::getInstance();
	p1.print();
	Singleton p2 = Singleton::getInstance();
	p2.print();
}