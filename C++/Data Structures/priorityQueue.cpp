/*
Here we will see how we can use a priority queue in cpp.
Time Complexity:

1.Creation of priority queue takes O(n) time.

2.The insertion(push()) and deletion(pop()) of priority queue takes
  O(logn).

3.Accessing the top of the priority queue (top())  takes O(1) .


*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    // Inserting elements in max-heap

    priority_queue<int> pq;

    for (auto it : arr)
        pq.push(it);

    cout << "Displaying vector using max-heap"
         << "\n";

    // we will see that the vector will be sorted in descending order

    while (!pq.empty())
    {

        cout << pq.top() << " ";

        pq.pop();
    }
    // Inserting elements in min-heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    for (auto it : arr)
        pq2.push(it);

    cout << "\nDisplaying vector using min-heap"
         << "\n";
    // we will see that the vector will be sorted in ascending order
    while (!pq2.empty())
    {

        cout << pq2.top() << " ";
        pq2.pop();
    }
    return 0;
}