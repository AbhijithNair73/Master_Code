#include<iostream>
using namespace std;
main()
{
    try
    {
       // throw "abc";
       // throw 'a';
        throw 12.5f;
        throw 10;

    }
    catch(int x)
    {
        cout<<"Int catch"<<endl;
    }
     catch(float x)
    {
        cout<<"float catch"<<endl;
    }
     catch(char x)
    {
        cout<<"char catch"<<endl;
    }
     catch(double x)
    {
        cout<<"double catch"<<endl;
    }
     catch(...)
    {
        cout<<"default catch"<<endl;
    }
}
