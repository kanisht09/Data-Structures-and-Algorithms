
//Algorithm : Ternary Search
//Time complexity : O(log(n))
/*
Ternary search is used to find the maximum/ minimum value of a function (f) over a range [left, right] (both inclusive).
Provided the function is unimodal i.e the function has a finite (but not necessarily unique) global Maxima/Minima.
Each iteration splits the range in 3 (almost equal) parts, and 1/3rd of the range is rejected.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double f (long double input) {
	long double value = (-1 * (long double)pow(input, 2) + 4.0L) / 4.0L;
	return value;
}

long double ternary_search(long double left, long double right) {
	long double eps = 1e-9;              				//set the error tolerance limit
	while (right - left > eps) {						//continue iterations until reqired tolerance is reached
		double m1 = left + (right - left) / 3;			//split range in 3, [left, m1, m2, right]
		double m2 = right - (right - left) / 3;
		double f1 = f(m1);      						//evaluates the function at m1
		double f2 = f(m2);      						//evaluates the function at m2
		if (f1 < f2)
			left = m1;									//Narrow down the search space to 2/3rd of previous space
		else
			right = m2;
	}
	return f(left);                    					//return the maximum of f(x) in [l, r]
}


int main (void) {
	//Let the function be x^2 + 4y - 4 = 0 , a down facing parabola
	//The function achieves a Global maxima of 1 at x = 0, does not have a global minima
	cout << fixed << setprecision(8) << ternary_search (-5, 5) << '\n';				//Calculate max value in range [-5, 5]

}

//Questions across Coding Platforms
//https://codeforces.com/problemset/problem/1288/A
//https://www.spoj.com/problems/KOPC12A/