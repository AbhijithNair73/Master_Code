// Quick Sort - It also follows Divide and Conquer strategy. Not the fastest.
// https://www.youtube.com/watch?v=7h1s2SojIRw&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=36
// Abdul bari explanation
// 1. Add one infinite value element at the end of array.
//	2.Take first element as pivot and start one crawler pointer from element next to pivot 
// 			and other crawler pointer from last element.
//  3. first pointer should traverse and point to element greater than pivot and
//  4. second pointer should traverse and point to element smaller than pivot, then perform swap.
//  5. Once i and j crosses(only after crossing), the j th position is the actual position of pivot.
//  6. So swap pivot to jth position

/*
While dividing the array, the pivot element should be positioned in such a way
that elements less than pivot are kept on the left side and elements greater
than pivot are on the right side of the pivot. 
The left and right subarrays are also divided using the same approach. 
This process continues until each subarray contains a single element.

Quicksort Complexity
Time Complexity				 
Best					O(n*log n)
Worst					O(n2)			
Average					O(n*log n)
Space Complexity					O(log n)			
Stability					No
*/
// Code: Swap with first element as pivot
//https://stackoverflow.com/questions/6740183/quicksort-with-first-element-as-pivot-example



// Video explanation for last element as Pivot:https://www.youtube.com/watch?v=UqVxcO4oNXA
#include <iostream>
using namespace std; 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i=start;
	int j=start+1;
	for(;j<=end-1;j++)
	{
		if(arr[j]<=pivot)
		{
			swap(&arr[j],&arr[i]);
			i++;
		}
	}
	swap(&arr[end],&arr[i]);
	return i;
}

void quickSort(int arr[], int start, int end)
{
	if(start<end)
	{
		int partitionpos = partition(arr, start, end);
		quickSort(arr, start, partitionpos-1);
		quickSort(arr, partitionpos+1, end);
	}
}
