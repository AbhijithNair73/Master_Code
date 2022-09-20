// input should be sorted for this type of search
// As name suggests it is mainly used for binary tree searching

#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int>&temp, int key, int low, int high)
{
    int mid = (low+high)/2;
    if(low>high)
    {
        return false;
    }
    if (temp[mid]>key)
    {
        return BinarySearch(temp,key,low,mid-1);
    }
    else if (temp[mid] < key)
    {
        return BinarySearch(temp,key,mid+1,high);
    }
    else
    {
        return mid;
    }
}


int main()
{
    vector<int> vect={10,20,30,40,50,60,70,80};
    int totalSize = static_cast<int>(vect.size());
    int result = BinarySearch(vect,10,0,totalSize-1);
    cout<<result<<endl;
}

