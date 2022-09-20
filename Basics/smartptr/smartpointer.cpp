#include <iostream>
#include <cstring>
using namespace std;
class Rectangle
{
    int height;
    int width;
public:
    Rectangle() = default;
    Rectangle(int _height, int _width)
    {
        height = _height;
        width = _width;
    }
    int CalculateArea()
    {
        return height * width;
    }
};

template <class T>
class Smart_pointer
{
    T * ptr;
public:
    Smart_pointer()
    {
        ptr  = nullptr;
    }
    Smart_pointer(const Smart_pointer & obj) = delete;
    Smart_pointer& operator= (const Smart_pointer & obj) = delete;
    Smart_pointer& operator= (Smart_pointer && obj)
    {
        cout<<"Move"<<endl;
        //move assignment
         if (this != &obj)
         {
             ptr = obj.ptr;
             obj.ptr = nullptr;
         }
        return *this;
    }
    Smart_pointer(T * _ptr)
    {
        ptr  = _ptr;
    }
    T& operator *()
    {
        if(ptr)
        {
            return (*ptr);
        }
    }
    T* operator ->()
    {
        if(ptr)
        {
            return (ptr);
        }
    }
    T* get()
    {
        if(ptr)
        {
            return (ptr);
        }
    }
    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
    void reset()
    {
        if(ptr)
        {
            delete ptr;
            ptr = nullptr;
        }
    }

    ~ Smart_pointer()
    {
        delete ptr;
    }
};

int main()
{
   Smart_pointer<Rectangle> uptr(new Rectangle(10,20));
    Smart_pointer<Rectangle> uptr2;
    // uptr.reset();
    Rectangle * rptr = uptr.get();
    // uptr2 = std::move(uptr);
   cout<<uptr->CalculateArea()<<endl;
    
    
}