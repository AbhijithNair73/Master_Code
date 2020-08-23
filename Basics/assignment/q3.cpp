#include<iostream>
using namespace std;
float area(float r)
{
    float a;
    a=4*(3.14)*r*r;
    return a;
}
float area(float l,float w)
{
    float a;
    a=l*w;
    return a;
}
float area(float b,float h,float x)
{
    float a;
    a=x*h*b;
    return a;
}
main()
{
    float radius;
    float length,width;
    float breadth,height,x;
    float total;
    int i;
    L1:
    cout<<"select 0 for triangle area \n 1 for sphere\n 2 for rectangle"<<endl;
    cin>>i;
    if(i==0)
    {
        cout<<"triangle area :"<<"add breadth height"<<endl;
        x=((float)1/(float)2);
        cin>>breadth>>height;
        total=area(breadth,height,x);
        cout<<"total area is "<<total<<endl;
    }
    else if(i==1)
    {
        cout<<"sphere area :"<<"add radius"<<endl;
        cin>>radius;
        total=area(radius);
        cout<<"total area is "<<total<<endl;
    }
    else if(i==2)
    {
        cout<<"rectangle area :"<<"add length and width"<<endl;
        cin>>length>>width;
        total=area(length,width);
        cout<<"total area is "<<total<<endl;
    }
    else
    {
        cout<<"unknown option\n"<<endl;
        goto L1;
    }
}

