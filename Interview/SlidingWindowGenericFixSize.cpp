#include<iostream>
#include<utility>
#include<array>
using namespace std;
pair<int,int> slidingWindow(array<int,8> a, int sum, int K)
{
    int currentWindow = 0;
    for(int i=0;i<K;i++)
    {
        currentWindow+=a[i];
    }
    cout<<"First window sum = "<<currentWindow<<endl;
    if(currentWindow == sum)
    {
        return make_pair(a[0],a[0+K-1]);
    }
    // start from the element uptill which u already counted the size. 
    for(int i=K; i<a.size();++i)
    {
       currentWindow = currentWindow + a[i] - a[i-K];
       if(currentWindow == sum)
       {
            return make_pair(a[i-K+1],a[i]);
       }     
    }
}
int main()
{
    array<int,8> arr= {5,1,4,6,11,0,13,-1};
    int sum = 12;
    int K=3;
    pair<int,int> ret;
    ret = slidingWindow(arr, sum, K);
    cout<<ret.first<< " "<<ret.second<<endl; 
    return 0;
}