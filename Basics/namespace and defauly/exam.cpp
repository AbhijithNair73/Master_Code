#include<iostream>
using namespace std;
namespace first
{
    int x=0;
    void test()
    {
        cout<<"test func in 1"<<endl;
    }
}
namespace second
{
    int y=100;
    void test1()
    {
        cout<<"test in func2"<<endl;
    }
}

using second::x;
main()
{
    using namespace first;
    cout<<x<<endl;
    test();
}
