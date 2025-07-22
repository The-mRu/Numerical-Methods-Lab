/*
C221050

Solve a system of linear equations using Gauss–Jordan Elimination
Ax = b  → converts to [I | x] form

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of unknowns (n): ";
    cin >> n;

    double mat[100][101]; 

    
    cout << "\nEnter the augmented matrix (row-wise: (a11 a12 a13.... b1)):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j <= n; ++j) {
            cin >> mat[i][j];
        }
    }

   
    for (int i = 0; i < n; ++i) {
        
        double pivot = mat[i][i];
        if (pivot == 0) {
            cout << "Zero pivot found. Cannot proceed without partial pivoting.\n";
            return 1;
        }
        for (int j = 0; j <= n; ++j) {
            mat[i][j] /= pivot;
        }

        //  Make other elements in current column zero
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = mat[k][i];
                for (int j = 0; j <= n; ++j) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }

    cout << fixed << setprecision(6);
    cout << "\nSolution:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << mat[i][n] << "\n";
    }

    return 0;
}

/*
Input:
3
2 1 1 10
3 2 3 18
1 4 9 16
Output:
x1 = 7
x2 = -9
x3 = 5

*/