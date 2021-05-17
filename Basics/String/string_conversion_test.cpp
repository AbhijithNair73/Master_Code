#include<iostream>
#include<string>
using namespace std;

int main()
{
	char buf[20]="Hello World";
	string str(buf);
	cout<<buf<<"\nString = "<<str.c_str()<<endl;
}