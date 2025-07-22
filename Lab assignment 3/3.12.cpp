/*
12. Write a program to solve the following system of linear equations by using Gauss-Seidel method.

        10x1  +   x2   +    x3     = 12
         2x1  + 10x2   +    x3     = 13
         2x1  +   2x2  +  10x3     = 14


Key Notes:
- Gauss-Seidel updates each variable using the **latest values** as soon as they are available.
- Formula:
    x_i^(k+1) = (1 / a_ii) * (b_i - Σ a_ij * x_j), using latest x_j for j < i and old x_j for j > i
- It stops when all values converge (change is smaller than a tolerance value).
- Diagonal dominance improves convergence.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of unknowns = ";
    cin >> n;

    double a[10][10], b[10], x[10] = {0};  
    double tolerance = 0.0001; 
    int maxIterations = 100;

    cout << "Enter the augmented matrix row by row (coefficients + constant):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Equation " << i + 1 << ":\n";
        for (int j = 0; j < n; ++j) {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
        cout << "b[" << i + 1 << "] = ";
        cin >> b[i];
    }

    int iter = 0;
    while (iter < maxIterations) {
        bool done = true;

        // Update each variable using most recent values
        for (int i = 0; i < n; ++i) {
            double sum = b[i];

            for (int j = 0; j < n; ++j) {
                if (j != i)
                    sum -= a[i][j] * x[j];   
            }

            double new_xi = sum / a[i][i];

            if (fabs(new_xi - x[i]) > tolerance)
                done = false;

            x[i] = new_xi;   
        }

        if (done) break;  
        iter++;
    }


    cout << "\nFinal Result:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
/*

Input:

3
83 11 -4 95
7 52 13 104
2 8 29 71


Output:

x1 = 1.06116
x2 = 1.35696
x3 = 2.00076

*/
