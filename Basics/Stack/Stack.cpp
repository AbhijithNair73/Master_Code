#include<iostream>
#include<vector>
using namespace std;
template<typename T>
struct DATAType
{
	T data;
	struct DATAType * next;
};
template<typename T>
class Stack
{
private:
	T Ar[200];
	//T * Ar;
	T *last;  //last for future use when memory will be allocated dynamically
	int siize;
public:
	Stack()
	{
		cout<<"Default Constructor"<<endl;
		siize = 0;
		last=Ar;
	}
	void push(T a)
	{
		siize++;
		Ar[siize]=a;
		last++;
	}
	void pop(void)
	{
		if(siize>0)
		{
			siize--;
			last--;
		}
		else
		{
			cout<<"Cannot pop"<<endl;
		}
	}
	T top(void)
	{
		int fail = -1;
		if(siize>0)
			return Ar[siize];
		else
			return fail;

	}

	bool empty(void)
	{
		if(siize>0)
			return false;
		else
			return true;
	}

	int size(void)
	{
		return siize;
	}

	void display() 
	{
		int top = siize;
   		if(top>0) 
   		{
     		 cout<<"Stack elements are:";
     		 for(int i=top; i>=1; i--)
     		 cout<<Ar[i]<<" ";
    		  cout<<endl;
   		} 
  		 else
   		cout<<"Stack is empty"<<endl;
	}

	//void swap(void);
	//void emplace(T a);
};

int main()
{
	Stack<int> st;
	int val=0;
	int ch;
	cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Top"<<endl;
    cout<<"5) Empty"<<endl;
    cout<<"6) size"<<endl;
    cout<<"7) Exit"<<endl;
    do 
    {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) 
      {
         case 1: 
         {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            st.push(val);
            break;
         }
         case 2: 
         {
            st.pop();
            break;
         }
         case 3: 
         {
            st.display();
            break;
         }
         case 4: 
         {
            cout<<"Top Element :"<<st.top()<<endl;;
            break;
         }
         case 5: 
         {
            cout<<"Empty :"<<st.empty()<<endl;
            break;
         }
         case 6: 
         {
            cout<<"Size :"<<st.size()<<endl;
            break;
         }
         case 7: 
         {
            cout<<"Exit"<<endl;
            break;
         }
         default: 
         {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=7);
	return 0;
}