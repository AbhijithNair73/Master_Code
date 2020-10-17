// Selection Sort
// Isme bubble sort ka ulta... hume smallest element ko target krna he...
// So pehle 3 pointers i,j and k teeno ek ko point karenge then j ko iterate krana he over the loop 
// and agar j jisko point krta he wo agar 'k' ke pointer ke value se chota he to 'k' ko j pe point krana
// he...ese jab poora loop iterate hoga tab k will be pointing to the smallest and last me usko swap 
// krdena he 'i' se so i will be pointing the smallest.
// So smallest element first iteration me sort ho jayega
// Non Adaptive and non Stable
// It does minimum number of swaps

#include<iostream>
#include<array>
using namespace std;
printData(const std::array<int, 6> & As)
{
	for(int i=0; i<As.size();i++)
		cout<<As[i]<<" ";
	cout<<endl;
}

void SelectionSort(std::array<int, 6> & Ax)
{
	int i,j,k;
	for(i=0 ; i < Ax.size()-1 ; i++)
	{
		for(j=k=i; j < Ax.size() ; j++)
		{
			if(Ax[k]>Ax[j])
				k=j;
		}
		int temp = Ax[i];
		Ax[i] = Ax[k];
		Ax[k] = temp;
		printData(Ax);
	}

}

int main()
{
	std::array<int, 6> Ar = {3,8,5,2,6,1};
	printData(Ar);
	cout<<"Before Selection Sort "<<endl;
	SelectionSort(Ar);
	cout<<"After Selection sort "<<endl;	
	printData(Ar);
}