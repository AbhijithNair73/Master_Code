#include <iostream>
#include <algorithm>
using namespace std;


//this can be used to remove any character from an array

int removeChar(string &arr, char chRemove)
{
    int j=0;
    for (int i = 0; i < arr.size()-1; i++)
    {
        if(arr[i] != chRemove)
        {
            swap(arr[j++],arr[i]);
        }       
    }
    swap(arr[j++],arr[arr.size()-1]);
    return j;
}

int main()
{
    string ipAddr = "192.168.31.151";
    for (int i = 0; i < ipAddr.size(); i++)
    {
        cout<<ipAddr[i]<<"  ";
    }
    cout<<endl;
    int newSize = removeChar(ipAddr,'.');
    for (int i = 0; i < newSize; i++)
    {
        cout<<ipAddr[i]<<"  ";
    }
    
    return 0;
}