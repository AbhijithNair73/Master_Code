/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;
mutex mtx2;
class SingleOwner
{
    int m_var;
    int var2;
    SingleOwner(){cout<<"Ctor called"<<endl;};
    static SingleOwner * mptr;
public:
    SingleOwner(const SingleOwner & copyObj)=delete;
    SingleOwner& operator=(const SingleOwner & copyObj)=delete;
    ~SingleOwner() {
        cout<<"Dtor called"<<endl;
        delete mptr;
    }
    static SingleOwner* get_Instance()
    // {
    //     static SingleOwner sobj;
    //     return &sobj;
    // }
    {
        if(mptr)
        {
            return mptr;
        }
        else
        {
            mtx.lock();
            if(mptr)
            {
                
            }
            else
            {
                mptr = new SingleOwner();
            }
            mtx.unlock();
            return mptr;
        }
    }
    int getVar()
    {
        return m_var;
    }
    void setVar(int var)
    {
        m_var = var;
    }
    int getVar2()
    {
        return var2;
    }
    void setVar2(int var)
    {
        var2 = var;
    }
};

void accessVariable()
{
    // mtx2.lock();
    SingleOwner * thOwner = SingleOwner::get_Instance();
    thOwner->setVar(20);
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"From thread "<<":"<<this_thread::get_id()<<thOwner->getVar()<<endl;
    // mtx2.unlock();
    
}

SingleOwner*SingleOwner::mptr = NULL;

int main()
{
    thread thobj1(accessVariable);
    thread thobj2(accessVariable);
    thobj1.join();
    thobj2.join();
    SingleOwner * sptr = SingleOwner::get_Instance();
    // sptr->setVar(10);
    cout<<sptr->getVar()<<endl;
    return 0;
}