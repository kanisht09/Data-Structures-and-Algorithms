//Algorithm : Binary Search
//Time Complexity : O(log(n)) Regressive Growth rate function
/*
Suitable for Larger array sizes
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; // size of the array
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int val;
	int low = 0;
	int high = n - 1;
	int pos = -1;
	//The value you want to search
	cin >> val;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] == val)
		{
			pos = mid + 1;
			break;
		}
		else if (a[mid] < val)
		{
			low = mid + 1; // vsl lies in the 2nd-half
		}
		else
		{
			high = mid - 1; //val lies in the 1st-half
		}
	}
	if (pos == -1)
	{
		printf("The element is not present \n");
	}
	else
	{
		printf("The value is present in the %d position", pos);
	}

	return 0;
}

//Problems across coding platforms
//https://codeforces.com/problemset/problem/1566/A
//https://codeforces.com/problemset/problem/1476/A