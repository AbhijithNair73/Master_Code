#include<iostream>
using namespace std;
class A
{
    int num;
    int num2;
public:
    A()
    {
        cout<<"Enter number"<<endl;
        cin>>num;
        cout<<"Enter number"<<endl;
        cin>>num2;
    }
    void arm()
    {
        int k=0;
        for(int i=num;i<num2;i++)
        {

            for(int j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    k++;
                }
            }
            if(k==0)
            {
                cout<<" "<<i<<endl;

            }
            k=0;


        }
    }
};
main()
{
    A obj;
    obj.arm();
}
