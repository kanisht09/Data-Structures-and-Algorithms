/*
Algorithm : Dynamic Matrix Chain Multiplication
Time Complexity : O(n^2) where n is the no of matrices
*/



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printMandS (vector<vector<int>>& mcm_matrix, vector<vector<int>>& s, size_t size) {    //Utility function for printing Matrices mcm_matrix and s
    printf ("The matrix mcm_matrix :\n");
    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < size + 1; j++) {
            printf ("%d\t", mcm_matrix[i][j]);
        }
        printf ("\n");
    }
    printf ("\n\n");

    printf ("The matrix S :\n");
    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < size + 1; j++) {
            printf ("%d ", s[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");
    return;
}

void printOptimalParenths (vector<vector<int>>& s, size_t start, size_t end) {          //Prints optimal parenthesization order
    if (start == end) {
        cout << "A" << start;
    }
    else {
        cout << "(";
        printOptimalParenths (s, start, s[start][end]);
        printOptimalParenths (s, s[start][end] + 1, end);
        cout << ")";
    }
    return;
}

void matrix_chain_order (vector<int>& dimensions) {
    int n = dimensions.size() - 1;                                                      //Calculate number of matrices

    vector<vector<int>> mcm_matrix (n + 1, vector<int> (n + 1, 0LL));                   //Initialise mcm_matrix with dimensions (n+1) x (n+1)
    vector<vector<int>> s (n + 1, vector<int> (n + 1, 0LL));                            //Initialise Parenthesization matrix with dimensions (n+1) x (n+1)

    //Set diagonal elements to 0 as a matrix multiplication with itself is redundant
    for (int i = 1; i <= n; i++) {
        mcm_matrix[i][i] = 0;
    }


    for (int l = 2; l <= n; l++) {                          //Length of the contiguous section of matrices considered at each iteration (varies from 2 to n)
        for (int i = 1; i <= n - l + 1; i++) {              //Index of the start of each contiguous section considered
            int j = i + l - 1;                              //Index of the end of each contiguous section considered
            mcm_matrix[i][j] = INT_MAX;                     //Set cost of multiplication of section i to j as INFINITY
            for (int k = i; k <= j - 1; k++) {              //Perform partition of the chosen section
                int cost = mcm_matrix[i][k] + mcm_matrix[k + 1][j] + (dimensions[i - 1] * dimensions[k] * dimensions[j]);
                if (cost < mcm_matrix[i][j]) {
                    mcm_matrix[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printMandS (mcm_matrix, s, n);
    int min_cost = mcm_matrix[1][n];
    int start_idx = 1;
    int end_idx = n;
    cout << "The minimum cost is : " << min_cost << '\n';
    cout << "The optimal parenthesization order is : " << '\n';
    printOptimalParenths (s, start_idx, end_idx);

}

int main (void) {
    cout << "Dynamic MCM Solution\n\n";
    size_t n_matrices = 5;                                          //Number of matrices to multiply

    /* Let dimensions of matrices be :-
    A1 = 10 x 20
    A2 = 20 x 30
    A3 = 30 x 40
    A4 = 40 x 50
    A5 = 50 x 60
    */

    vector<int> dimensions (n_matrices + 1);                        //Create a vector of size 6 to store all dimensions
    dimensions = {10, 20, 30, 40, 50, 60};

    cout << "The Dimensions Matrix is : ";
    for (auto& i : dimensions) {
        cout << i << " ";
    }
    cout << endl;

    //After pushing, the vector "dimensions" looks like this :- [10, 20, 30, 40, 50, 60]

    matrix_chain_order (dimensions);

    return 0;
}

//Standard problems across platforms :-
//N/A