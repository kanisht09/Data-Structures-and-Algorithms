#include<bits/stdc++.h>
using namespace std;
int main ()
{
    vector<int>m(5);        // Declaring a vector m of size 5.
    
    cout<<"Initial Size : "<<m.size()<<"\n";   
    
    //Taking inputs just like an array.
    for(int i=0;i<5;i++)
    {
        cin>>m[i];
    }
    // Printing the vector after inserting 5 values.
    for(int i=0;i<5;i++)
    {
        cout<<m[i]<<" ";   
    }
    cout<<"\n";
    
    /* Now we are adding one more element, say 12 into the vector
       using push_back().*/
       
    m.push_back(12);
    /*Checking the new size of vector after adding one more
     element.*/
     
    cout<<"New Size : "<<m.size()<<"\n"; 
    
    // Now we are printing the entire vector.
    for(int i=0;i<m.size();i++)
    {
        cout<<m[i]<<" ";   // The changed vector.
    }
    return 0;
}
