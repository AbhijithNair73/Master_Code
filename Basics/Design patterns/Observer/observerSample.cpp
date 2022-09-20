#include <iostream>
#include <list>
using namespace std;
class IObserver
{
public:
    IObserver() = default;
    virtual void update() = 0;
    virtual ~IObserver() = default; 
};

class Subject
{
    list<IObserver *> observerList;
public:
    Subject()=default;
    
    void attach(IObserver * obs)
    {
        cout<<"attach"<<endl;
        observerList.push_back(obs);
    }
    void detach(IObserver * obs)
    {
        observerList.remove(obs);
    }
    void notify_all()
    {
        cout<<"notifying"<<endl;
        for(auto elem: observerList)
        {
            elem->update();
        }
    }
};

class Observer1: public IObserver
{
public:
    Observer1(Subject & sbj)
    {
        sbj.attach(this);
    }
    void update() override
    {
        cout<<"Inside update of Observer1"<<endl;
    }
};

class Observer2: public IObserver
{
public:
    Observer2(Subject & sbj)
    {
        sbj.attach(this);
    }
    void update() override
    {
        cout<<"Inside update of Observer2"<<endl;
    }
};





int main() {
	Subject * sobj = new Subject();
	Observer1 * obs1 = new Observer1(*sobj);
	Observer2 * obs2 = new Observer2(*sobj);
	sobj->notify_all();
	delete sobj;
	delete obs1;
	delete obs2;
	return 0;
}
