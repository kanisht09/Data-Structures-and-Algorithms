#include <bits/stdc++.h>
using namespace std;
/*
    Time Complexity : O(N^2)
    Space Complexity : O(1)
    
    Where N is the length of the given array.
*/

// This function is used to swap two elements of the array.
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(vector<int>& arr, int n)
{   
    // This is used to skip extra iterations in case of sorted array.
    bool flag;

    for (int i = 0; i < n - 1; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {   
            // If the adjacent element is not sorted, swap the elements.
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = true;
            }
        }
        
        // If the array is already sorted, break from the current loop iteration.
        if (flag == false) {
            break;
        }
    }

    return;
}
signed main(){
// bubble sort algo for converting unsorted array in sorted array 

  // taking length of input array
   int n;cin>>n;
  // declaring vector of size n 
   vector<int> vi(n);
  //  taking input of unsorted array array 
  for(int i=0;i<n;i++)cin>>vi[i];

  // calling bubble sort algo function for sorting array
  bubbleSort(vi,n);
 
//  Printing result of sorted array 

for(int i=0;i<n;i++){
  cout<<vi[i]<<" ";
}

return 0 ;
}