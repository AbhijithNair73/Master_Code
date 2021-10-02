#include<iostream>
using namespace std;

// very bad designed
// impl class wale normal me hone chahiye the... vice versa ho gya... 

class implThreadScheduler
{
public:
	virtual void runTask() = 0;
};

class Unix: public implThreadScheduler
{
public:
	void runTask()
	{
		cout<<"Unix runtask"<<endl;
	}

};

class Windows: public implThreadScheduler
{
public:
	void runTask()
	{
		cout<<"Windows run task"<<endl;
	}


};

class JVM: public implThreadScheduler
{
public:
	void runTask()
	{
		cout<<"JVM run task"<<endl;
	}
};

class ThreadScheduler
{
	int tid;
public:
	ThreadScheduler(int value, implThreadScheduler * obj)
	{
		tid = value;
		pimpl = obj;
	}
	inline int get_tid() const { return tid; }
private:
	virtual void runTask() = 0;
protected:
	implThreadScheduler * pimpl;
};


class Preemptive : public ThreadScheduler
{
public:
	Preemptive(int value, implThreadScheduler * obj)
	 : ThreadScheduler{value,obj}
	{
		
	}
	void runTask()
	{
		cout<<"Preemptive Task scheduler with tid = "<< get_tid() <<endl;
		pimpl -> runTask();
	}

};

class TimeSliced : public ThreadScheduler
{
public:
	TimeSliced(int value, implThreadScheduler * obj)
		: ThreadScheduler(value,obj)
	{

	}

	void runTask()
	{
		cout<<"TimeSliced Task scheduler with tid = "<< get_tid() <<endl;
		pimpl -> runTask();
	}
};


int main()
{
	Windows system;
	Preemptive pr(2, &system);
	pr.runTask();
	TimeSliced ts(5, &system);
	ts.runTask();
	return 0;
}

