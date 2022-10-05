/*
Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm.
In computer graphics, it is popular for its capability to detect a tiny error (like a swap of just two elements) in almost-sorted arrays and fix it with just linear
complexity (2n).

Example: It is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to the x-axis), and with incrementing y their order changes (two elements are swapped) only at intersections of two lines (Source: Wikipedia)
*/

/*
Time Complexity:O(N*N)
Space Complexity:O(1)
*/

#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Function to print an array
void printArray(vector<int> &arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int size;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {

        int a;
        cin >> a;
        arr.push_back(a);
    }

    bubbleSort(arr, size);
    cout << "Sorted array: \n";
    printArray(arr, size);
    return 0;
}