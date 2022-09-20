#include <iostream>
#include <memory>
using namespace std;

class Box
{
    int size;
    string contents;
public:
    Box() = default;
    Box(int _size, string _contents): size(_size), contents(_contents) {}
    Box(const Box & obj)
    {
        size = obj.size;
        contents = obj.contents;
    }
    Box& operator=(const Box & obj)
    {
        if(this != &obj)
        {
            size = obj.size;
            contents = obj.contents; 
        }
        return *this;
    }

    void Display()
    {
        cout<<this->size<<"  "<<this->contents<<endl;
    }
    
    ~Box()
    {
        cout<<"Destructor called"<<endl;
    }

};

int main()
{
    // method 1 assignment
    // unique_ptr<Box> mptr(new Box(10,"Hello"));
    // mptr->Display();
    
    // method 2 assignment
    // unique_ptr<Box> mptr = make_unique<Box>(10,"greet");
    // mptr->Display();
    
    // method 3
    // unique_ptr<Box> mptr1 = make_unique<Box>(10,"home");
    // mptr1->Display();
    // unique_ptr<Box> mptr2;
    // mptr2 = std::move(mptr1);
    // mptr2->Display();
    
    // method4
    //   Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p.
    // unique_ptr<Box> mptr1 = make_unique<Box>(10,"Peace");
    // mptr1->Display();
    // mptr1.reset();
    
    // alternative
    // unique_ptr<Box> mptr1 = make_unique<Box>(10,"Peace");
    // mptr1->Display();
    // unique_ptr<Box> mptr2;
    // mptr2.reset(mptr1.release());
    // mptr2->Display();
    // mptr2.reset();
    
    // Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
    // This call does not destroy the managed object, but the unique_ptr object is released from the responsibility of deleting the object. Some other entity must take responsibility for deleting the object at some point.
    //  unique_ptr<Box> mptr1 = make_unique<Box>(10,"Welcome");
    //  Box * bptr = mptr1.release();
    //  bptr->Display();
    //  delete bptr;
    
    // get -> returns stored pointer
    unique_ptr<Box> mptr1 = make_unique<Box>(10,"Peace");
    mptr1->Display();
    Box * bptr = mptr1.get();
    bptr->Display();
    mptr1->Display();
    
    // error case - by deleting bptr, which should not be done bcoz mptr1 is still holding the data.
    // delete bptr; // double free error
    
    
    // unique_ptr::operator[]
    //   std::unique_ptr<int[]> foo (new int[5]);
    //   for (int i=0; i<5; ++i) foo[i] = i;
    //   for (int i=0; i<5; ++i) std::cout << foo[i] << ' ';
    
    
    return 0;
}