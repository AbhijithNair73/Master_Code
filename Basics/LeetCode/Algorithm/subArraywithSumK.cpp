#include <iostream>
using namespace std;

// C++ program to print subarray with sum as given sum
// #include<bits/stdc++.h>
// using namespace std;


// BruteForce
// void subArraySum(int arr[], int n, int sum)
// {
//     int curr_sum, i, j;
  
//     // Pick a starting point
//     for (i = 0; i < n; i++) {
//         curr_sum = 0;
  
//         // try all subarrays starting with 'i'
//         for (j = i ; j < n; j++) {
//            curr_sum = curr_sum + arr[j];
           
//             if (curr_sum == sum) {
//                 cout << "Sum found between indexes "
//                      << i << " and " << j ;
//                 return 1;
//             }
//             if(curr_sum > sum)
//             break;
             
            
//         }
//     }
  
//     cout << "No subarray found";
//     return 0;
// }



// Function to print subarray with sum as given sum
void subArraySum(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	// Maintains sum of elements so far
	int curr_sum = 0;

	for (int i = 0; i < n; i++)
	{
		// add current element to curr_sum
		curr_sum = curr_sum + arr[i];

		// if curr_sum is equal to target sum
		// we found a subarray starting from index 0
		// and ending at index i
		if (curr_sum == sum)
		{
			cout << "Sum found between indexes "
				<< 0 << " to " << i << endl;
			return;
		}

		// If curr_sum - sum already exists in map
		// we have found a subarray with target sum
		if (map.find(curr_sum - sum) != map.end())
		{
			cout << "Sum found between indexes "
				<< map[curr_sum - sum] + 1
				<< " to " << i << endl;
			return;
		}
		// cout<<curr_sum<<" "<<map[curr_sum]<< " "<<i<<endl;

		map[curr_sum] = i;
	}

	// If we reach here, then no subarray exists
	cout << "No subarray with given sum exists";
}

// Driver program to test above function
int main()
{
	int arr[] = {3,7,9, 1, 30, 3, 10, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 33;

	subArraySum(arr, n, sum);

	return 0;
}

