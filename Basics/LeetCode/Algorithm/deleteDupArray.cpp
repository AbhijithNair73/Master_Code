#include <iostream>
#include <algorithm>
using namespace std;

int removeDup(int arr[], int size)
{
    int j=0;
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            arr[j++] = arr[i];
        }       
    }
    arr[j++] = arr[size-1];
    return j;
}

int main()
{
    int arr[]={7,4,4,3,2,4,6,9,1,5,4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    int newSize = removeDup(arr,size);
    for (int i = 0; i < newSize; i++)
    {
        cout<<arr[i]<<"  ";
    }
    
    return 0;
}