#include <iostream>
using namespace std;
int peakIndex(int arr[],int high)
{
    int low=0;
    int mid;
    high-=1;
    while( low < high )
    {
        mid = low +(high - low)/2;
        if(arr[mid]>=arr[mid+1])
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}
int main()
{
    int mountainArray[]= {4,8,16,32,27,9,3};
    int n = sizeof(mountainArray)/sizeof(mountainArray[0]);
    int peak=peakIndex(mountainArray,n);
    cout<<"Peak index is:"<<peak;
    return 0;
}
