/*
3.9 Write a program to solve the following system of linear equations by using Gaussian Elimination method.
          2x +  y  +   z = 10
           x  + 4y + 9z = 16
          3x + 2y + 3z = 18
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
     
    double M[3][4];

    
    cout << "Enter coefficients and RHS for each equation:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Equation " << i+1 << ":\n";
        for (int j = 0; j < 4; ++j) {
            if (j < 3)
                cout << "  A[" << i+1 << "][" << j+1 << "]: ";
            else
                cout << "  b[" << i+1 << "]: ";
            cin >> M[i][j];
        }
    }

   
    for (int p = 0; p < 2; ++p) {
        for (int r = p+1; r < 3; ++r) {
            double factor = M[r][p] / M[p][p];
            for (int c = p; c < 4; ++c) {
                M[r][c] -= factor * M[p][c];
            }
        }
    }

    
    double x[3];
    for (int i = 2; i >= 0; --i) {
        double sum = M[i][3];  
        for (int j = i+1; j < 3; ++j) {
            sum -= (M[i][j] * x[j]); 
        }
        x[i] = sum / M[i][i];
    }

    
    // cout << fixed << setprecision(6);
    cout<< "\nSolution:\n";
    cout << "x = " << x[0] << "\n";
    cout << "y = " << x[1] << "\n";
    cout << "z = " << x[2] << "\n";

    return 0;
}
/*
Input:
2 1 1 10
3 2 3 18
1 4 9 16
Output:
x1 = 7
x2 = -9
x3 = 5
Input:
2 1 1 10
1 4 9 16
3 2 3 18
*/