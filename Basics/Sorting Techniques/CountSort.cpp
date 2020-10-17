/*CountSort:
Count sort me ek bada array lena he with size equal to the biggest value element in unsorted array.
It is kind of keeping the frequency of each number in big array.
Then check one by one in big array and based on their frequency place them back in the orignal array.
So the result is sorted array
Simplest sort but space complexity*/

//Undone.... easy do it yourself

#include<iostream>
#include<array>
using namespace std;
printData(const std::array<int, 6> & As)
{
	for(int i=0; i<As.size();i++)
		cout<<As[i]<<" ";
	cout<<endl;
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