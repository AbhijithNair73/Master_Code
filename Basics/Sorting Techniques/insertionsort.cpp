#include<iostream>
#include<array>
using namespace std;
printData(const std::array<int, 6> & As)
{
	for(int i=0; i<As.size();i++)
		cout<<As[i]<<" ";
	cout<<endl;
}

void InsertionSort(std::array<int, 6> & Ax)
{
	int x=0,j;
	for(int i=1 ; i < Ax.size() ; i++)
	{
		j=i-1;
		x=Ax[i];
		while(j>=0 && x < Ax[j])
		{
			Ax[j+1]=Ax[j];
			j--;
		}
		Ax[j+1]=x;
		printData(Ax);
	}

}

int main()
{
	std::array<int, 6> Ar = {3,8,5,2,6,1};
	printData(Ar);
	cout<<"Before InsertionSort "<<endl;
	InsertionSort(Ar);
	cout<<"After InsertionSort "<<endl;	
	printData(Ar);
}