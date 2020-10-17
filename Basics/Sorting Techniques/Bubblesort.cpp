//Bubble sort me neighbours ko compare krke swap krte jaana he end tak so 1st iteration of bigger loop me largest element end
//pe pohanch jayega. So ek element sort ho gya ... wese hi continuous comparison of neighbors krte rehna he
//It is adaptive and stable
//stable matlab agar duplicate values hue to unka order preserve hota he after sorting
//adaptive means if the list is already sorted then it should take minimum time

#include<iostream>
#include<array>
using namespace std;

void Bubble(array<int,5> & Ax,int n)
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

		if(flag==false)
			break;
		for(int k=0;k<5;k++)
		cout << Ax[k] <<" ";
		cout<<endl;
 	}

}

int main()
{

	std::array<int,5> A={4,3,2,6,5};

	Bubble(A,A.size());
	cout<<"Ultimate Result :"<<endl;
	for(int i=0;i<5;i++)
	cout << A[i] <<" ";
	cout << endl;

	return 0;
}