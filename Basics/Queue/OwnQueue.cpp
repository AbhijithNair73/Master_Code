#include <iostream>
#include <cstring>
using namespace std;
template<class T>
class Queue
{
    T * ptr;
    size_t m_length;
    size_t m_capacity;
public:
    Queue()
    {
        ptr = new T[5];
        m_length = 0;
        m_capacity = 5;
    }
    size_t size() const
    {
        return m_length;
    }
    size_t capacity() const
    {
        return m_capacity;
    }
    void push(T var)
    {
        if(m_length == m_capacity)
        {
            cout<<"new memory created and moved"<<endl;
            T * temp = new T[2* m_capacity];
            memcpy(temp,ptr,sizeof(T)*m_capacity);
            delete[] ptr;
            m_capacity = 2 * m_capacity;
            ptr = temp;
            temp = NULL;
        }
        ptr[m_length]=var;
        m_length++;   
    }
    void pop() 
    {
        memmove(ptr,ptr+1,sizeof(T)*m_length);
        ptr[m_length-1]=0;
        m_length--; 
    }
    T back()
    {
        return ptr[m_length-1];
    }
    T front()
    {
        return ptr[0];
    }
    bool empty()
    {
        return m_length == 0 ? true : false;
    }

};

int main()
{
    Queue<int>qobj;
    qobj.push(10);
    qobj.push(20);
    qobj.push(30);
    qobj.push(40);
    qobj.push(50);
    qobj.push(60);
    qobj.push(70);
    qobj.push(80);
    cout<<qobj.size()<<"  "<<qobj.capacity()<<endl;
    while(!qobj.empty())
    {
        std::cout<< qobj.front()<< "   top = "<< qobj.back() <<endl;
        qobj.pop();
    }
    return 0;
}