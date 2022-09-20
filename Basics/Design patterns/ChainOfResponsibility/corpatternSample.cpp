#include <iostream>
using namespace std;
class ICommand
{
public:
    ICommand * next;
   virtual ICommand* setNext(ICommand * obs) = 0;
    // string Handle(string req) = 0;
};

class Command1: public ICommand
{
public:
    ICommand* setNext(ICommand * obs)
    {
        cout<<"Command1"<<endl;
        next = obs;
        return next;
    }
};

class Command2: public ICommand
{
public:
    ICommand* setNext(ICommand * obs)
    {
        cout<<"Command2"<<endl;
        next = obs;
        return next;
    }
};

class Command3: public ICommand
{
public:
    ICommand* setNext(ICommand * obs)
    {
        cout<<"Command3"<<endl;
        next = obs;
        return next;
    }
};
int main() {
  Command1 *monkey = new Command1;
  Command2 *squirrel = new Command2;
  Command3 *dog = new Command3;
  monkey->setNext(squirrel)->setNext(dog);
	return 0;
}
