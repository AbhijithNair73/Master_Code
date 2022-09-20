// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
void printStack(stack<int> sl)
{
    while(sl.size()!=0)
    {
        cout<<sl.top()<<" ";
        sl.pop();
    }
}
void addElemAtEnd(stack<int>& final, int data)
{
    if(final.empty())
    {
        final.push(data);
    }
    else
    {
        int x = final.top();
        final.pop();
        addElem(final,data);
        final.push(x);
    }
}
void reverseStack(stack<int> & local, int store)
{
    if(local.size() == 0)
    {
        return;
    }
    int result = local.top();
    local.pop();
    reverseStack(local,result);
    addElemAtEnd(local,result);
}
int main() {
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
    printStack(st);
    reverseStack(st,100);
    cout<<endl;
    printStack(st);

    return 0;
}