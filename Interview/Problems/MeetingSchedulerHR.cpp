#include <cmath>
#include <cstdio>
#include <list>
#include<iomanip>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

void convertFloatToOutput(float ip)
{
    int num = static_cast<int>(ip);
    float dec = ip - num; 
    dec = dec * 60;
    cout << setw(2) << setfill('0') << num <<" ";   
    cout << setw(2) << setfill('0') <<round(dec) <<" ";
}


bool comparepair(pair<float,float>f1, pair<float,float> f2)
{
    return f1.first < f2.first;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int number;
    cin >> number;
    float meetingTime;
    cin >> meetingTime;
    meetingTime = meetingTime/60;
    meetingTime = floor(meetingTime * 100) / 100;
    int startHr=0,startMin=0;
    int endHr=0, endMin=0;
    list<pair<float,float>> time;
    list<pair<float,float>> output;
    for(int idx=0;idx<number;idx++)
    {
        cin>>startHr;
        cin>>startMin;
        cin>>endHr;
        cin>>endMin;
        float start = startHr,end = endHr;
        start += (static_cast<float>(startMin)/60);
        end += (static_cast<float>(endMin)/60);
        start = floor(start * 100) / 100;
        end = floor(end * 100) / 100;
        time.push_back(make_pair(start,end));
    }
    time.sort(comparepair);
    pair<float,float>currentPair = time.front();
    if(currentPair.first > meetingTime)
    {
       output.push_back(make_pair(0,currentPair.first)); 
    }
    // cout<<"meetingTime: "<<meetingTime<<endl;
    for (auto itr = time.begin(); itr != std::next(time.end(),-1); itr++)
    {
        pair<float,float>local = (*itr);
        pair<float,float>local2 = *std::next(itr,1);
        // cout<<" 1 = "<<local2.first<<" 2 = "<<local.second<<endl;
        if((local2.first - local.second) >= meetingTime)
        {
            output.push_back(make_pair(local.second,local2.first));
        }
    }
    pair<float,float>last = time.back();
    if(24-last.second >= meetingTime)
    {
        output.push_back(make_pair(last.second,0));
    }
    for (auto currentPair : output)
    {
        convertFloatToOutput(currentPair.first);
        convertFloatToOutput(currentPair.second);
        cout << '\n';
    }
    return 0;
}
