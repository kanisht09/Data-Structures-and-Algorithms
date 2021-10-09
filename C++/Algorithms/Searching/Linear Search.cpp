//Algorithm : Linear/Sequential Search
//Time Complexity : O(n) Linear growth rate Algorithm
/*
Linear/Sequential search works well for small values of array size (N) as long as the entire array can be filled in a
cache line(strong locality). Must be avoided for larger arrays.
*/
#include <iostream>
#include <vector>
#include <cstdbool>

using namespace std;

#define MAX_SIZE 10												//Maximum size of the array

bool seqSearch (vector<int>& src_array, const int& key) {
	for (size_t i = 0; i < src_array.size(); i++) {				//Iterate through the array for the key
		if (src_array[i] == key) {								//If key is found, print and return
			cout << "Key found at position " << i + 1 << '\n';
			return true;
		}
	}
	printf ("Key not Found");									//Key not found, return false
	return false;
}



int main (void) {

	vector<int> src_array (MAX_SIZE);							//Create a vector of required size
	src_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};				//Initialise the vector with values
	seqSearch (src_array, 5);									//Call Linear search function with key value to search
	return 0;
}


