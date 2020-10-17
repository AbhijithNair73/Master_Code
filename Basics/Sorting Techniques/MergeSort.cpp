#include<iostream>
#include<array>
using namespace std;
printData(const std::array<int, 6> & As)
{
	for(int i=0; i<As.size();i++)
		cout<<As[i]<<" ";
	cout<<endl;
}

void mergeLogic(std::array<int, 6> & Ax, int low, int mid, int high)
{
	int i=low,j=mid+1,k=low;
	std::array<int, 100>B;
	while(i<=mid && j<=high)
	{
		if(Ax[i]<Ax[j])
			B[k++]=Ax[i++];
		else
			B[k++]=Ax[j++];
		if(i>mid)
		{
			for(j;j<=high;j++)
				B[k++]=Ax[j];
			break;
			// printData(B);		
		}
		if(j>high)
		{
			for(i;i<=mid;i++)
				B[k++]=Ax[i];
			break;
			// printData(B);
		}
	}
	for(int s=low;s<=high;s++)
		Ax[s]=B[s];
	printData(Ax);
}

void recursiveMergeSort(std::array<int, 6> &Am,int low, int high)
{
	if(low<high)
	{
		int mid =(low+high)/2;
		recursiveMergeSort(Am,low,mid);
		recursiveMergeSort(Am,mid+1,high);
		mergeLogic(Am,low,mid,high);
	}
}

int main()
{
	std::array<int, 6> Ar = {3,8,5,2,6,1};
	printData(Ar);
	cout<<"Before Merge Sort "<<endl;
	recursiveMergeSort(Ar,0,5);
	cout<<"After Merge Sort "<<endl;	
	printData(Ar);
}