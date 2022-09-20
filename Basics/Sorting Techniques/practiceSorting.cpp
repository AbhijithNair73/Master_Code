// Online C++ compiler to run C++ program online
#include <iostream>
#include <array>
using namespace std;
void swap(int *ptr, int *qptr)
{
	int temp = *ptr;
	*ptr = *qptr;
	*qptr = temp;
}
void Bubble(array<int,5> & Ax,int n)
{
    for(int i = 0;i<n-1;++i)
    {
        cout<<i<<endl;
        for(int j=0;j<n-1-i;j++)
        {
            cout<<j<<" "<<Ax[j]<<" "<<Ax[j+1]<<endl;
            if(Ax[j]>Ax[j+1])
            {
                swap(Ax[j],Ax[j+1]);
            }
        }
    }
}

void SelectionSort(array<int,5> & Ax,int n)
{
    int i=0,j=0,k=0;
    for(i = 0;i<n-1;++i)
    {
        for(j=i+1,k=i;j<n;++j)
        {
            if(Ax[j]<Ax[i])
            {
                k=j;
            }
        }
        swap(Ax[i],Ax[k]);
    }
}

void InsertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main()
{

	std::array<int,5> A={4,3,2,6,5};
// 	Bubble(A,A.size());
//     SelectionSort(A,A.size());
    InsertionSort(A,A.size());
	cout<<"Ultimate Result :"<<endl;
	for(int i=0;i<5;i++)
	cout << A[i] <<" ";
	cout << endl;

	return 0;
}