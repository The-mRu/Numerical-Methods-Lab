/*

11. Write a program to solve the following system of linear equations by using Jacobi's method.
          83x +  11y  -  4z = 95
           3x +   8y  + 29z = 71
           7x +  52y  + 13z = 104

Key Notes:
- Jacobi's Method updates each variable using only values from the previous iteration.
- Formula:
    x_i^(k+1) = (1 / a_ii) * (b_i - Σ a_ij * x_j), for j ≠ i
- It stops when all values converge (change is smaller than a tolerance value).
- Make sure the coefficient matrix is diagonally dominant for guaranteed convergence.


*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of unknowns = ";
    cin >> n;

    double a[10][10], x[10] = {0}, temp[10], b[10];
    double tolerance = 0.0001;  // Stopping criteria
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
        // Calculate new values for x1, x2, ..., xn
        for (int i = 0; i < n; ++i) {
            double sum = b[i];
            for (int j = 0; j < n; ++j) {
                if (j != i) sum -= a[i][j] * x[j];  
            }
            temp[i] = sum / a[i][i]; // Update xi 
        }

         bool done = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(temp[i] - x[i]) > tolerance) {
                done = false;  
            }
            x[i] = temp[i];  
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