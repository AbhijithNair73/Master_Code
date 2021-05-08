#include<iostream>
using namespace std;
class Base
{
	int x_var;
protected:
	virtual int func()=0;
public:
	Base():x_var(5)
	{

	}
	int nonTestfun()
	{
		int val;
		do
		{
		val=this->func();
		cout<<"val"<<val<<endl;
		}	
		while(val==0);
		return val;
	}
};
class Derived : public Base
{

	int m_var;
//public:
	int func()
	{
		return Base::x_var;
	}
};

int main()
{
	cout<<Derived().nonTestfun()<<endl;
}