#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	int Ar[15]={9,9,3,9,3,1,8,8,8,3,3,3,5,5,5};
	for (auto& x: Ar) cout << " " << x;
	cout<<endl;
	unordered_map<int,int> hmap;
	for(int i=0;i<15;i++)
	{
		hmap[Ar[i]]++;
	}
	for (auto& x: hmap) cout << " " << x.first << ":" << x.second;
	cout<<endl;
	
	return 0;
}
