#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
std::mutex mtx;
using namespace std;
void printData(const char * arg)
{
    cout<<arg<<endl;
    std::this_thread::sleep_for(chrono::seconds(10));
    cout<<"slept for 10"<<endl;
}
int main()
{
    std::string str("My string");
    thread thobj(printData,str.c_str());
    if(thobj.joinable())
    {
        thobj.detach();
    }
    cout<<"Main thread ends"<<endl;
}