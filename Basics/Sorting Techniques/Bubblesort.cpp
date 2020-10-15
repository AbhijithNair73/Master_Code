#include<iostream>
#include<array>
using namespace std;

void Bubble(array<int,10> & Ax,int n)
{
	int i,j;
	bool flag=false;

	for(i=0;i<n-1;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
		{
			if(Ax[j] > Ax[j+1])
			{
				int temp = Ax[j];
				Ax[j] = Ax[j+1];
				Ax[j+1] = temp;
				flag=true;
			}
		}
		if(flag==0)
			break;
 	}

}

int main()
{

	std::array<int,10> A={11,13,7,12,16,9,24,5,10,3};

	Bubble(A,A.size());

	for(int i=0;i<10;i++)
	cout << A[i] <<" ";
	cout << endl;

	return 0;
}