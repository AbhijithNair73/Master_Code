#include<iostream>
using namespace std;
class Complex
{
    int real;
    int img;
public:
    Complex()
    {
        cout<<"Enter real & img"<<endl;
        cin>>real>>img;
    }
    Complex(int x)
    {

    }
    void print_data()
    {
        cout<<real<<"+"<<"i"<<img<<endl;
    }
    Complex addition(Complex *&s2)
    {
        Complex r(1);
      r.real=real+s2->real;
      r.img=img+s2->img;
      cout<<r.real<<"  "<<r.img<<endl;
      return r;
    }
    /*void subtraction(Complex *s2)
    {
      real=real-s2->real;
      img=img-s2->img;
    }*/
};
main()
{
    Complex *s1,*s2,s3(1);
    s1=new Complex;
    s2=new Complex;
    s1->print_data();
    s2->print_data();
    s3=s1->addition(s2);
    s3.print_data();
}
