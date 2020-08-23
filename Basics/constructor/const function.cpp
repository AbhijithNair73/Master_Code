#include<iostream>
using namespace std;
class A
{
 int x;
 public:
 static int z;
public:
   };
   int A::z=10;
main()
{
    A obj;
    cout<<"size of object "<<sizeof(obj)<<endl;
    cout<<"size of object "<<sizeof(A)<<endl;
    cout<<"size of object "<<obj.z<<endl;
cout<<"size of object "<<A::z<<endl;
}






