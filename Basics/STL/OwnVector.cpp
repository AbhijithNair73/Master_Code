#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class Vector{
    T * ptr;
    size_t m_length;
    size_t m_capacity;
public:
    Vector()
    {
        ptr = new T[5];
        m_length = 0;
        m_capacity = 5;
    }
    ~ Vector()
    {
       delete[] ptr;
       m_length = 0;
       m_capacity = 0;
    }
    Vector(const Vector & obj)
    {
        ptr = new T[obj.m_capacity];
        m_length = obj.m_length;
        m_capacity = obj.m_capacity;
        memcpy(ptr,obj.ptr,sizeof(T)*obj.m_capacity);  
    }
    size_t size() const
    {
        return m_length;
    }
    size_t capacity() const
    {
        return m_capacity;
    }
    void push_back(T var)
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
    // function to delete last element
    void pop() 
    {
        ptr[m_length-1] = 0;
        m_length--; 
    }
    T& operator[](size_t index)
    {
        if(index < m_length)
        {
            return ptr[index];
        }
        // else
        // {
        //     // return NULL;
        // }
    }

};
int main()
{
    Vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(40);
    vect.push_back(50);
    vect.push_back(60);
    vect[5]=90;
    Vector<int> vect1(vect);
    vect.pop();
    vect1[4]=55;
    cout<<"Size = "<<vect.size()<<"  capacity = "<<vect.capacity()<<endl; 
    for(int i =0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";        
    }
    cout<<endl;
    for(int i =0; i<vect1.size(); i++)
    {
        cout<<vect1[i]<<" ";        
    }
    return 0;
}