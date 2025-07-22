/*
3.7 Solve 3x3 linear system using Matrix Inversion Method

Equations:
a11*x + a12*y + a13*z = b1
a21*x + a22*y + a23*z = b2
a31*x + a32*y + a33*z = b3

X = A^-1 * B
*/

#include <iostream>
using namespace std;

int main() {
    double A[3][3], B[3];

    
    cout << "Enter coefficients of matrix A (3x3):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }

   
    cout << "Enter values of matrix B (3x1):\n";
    for (int i = 0; i < 3; i++) {
        cout << "B[" << i+1 << "]: ";
        cin >> B[i];
    }

    //determinant
    double det =
        A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
        A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
        A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    if (det == 0) {
        cout << "Matrix is singular. No unique solution.\n";
        return 1;
    }

    //inverse of A (adjoint / det)
    double inv[3][3];

    inv[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]) / det;
    inv[0][1] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]) / det;
    inv[0][2] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]) / det;

    inv[1][0] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]) / det;
    inv[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]) / det;
    inv[1][2] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]) / det;

    inv[2][0] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]) / det;
    inv[2][1] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]) / det;
    inv[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]) / det;

    //  A^-1 * B 
    double x[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            x[i] += inv[i][j] * B[j];

   
    cout << "\nSolution:\n";
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;
    cout << "z = " << x[2] << endl;

    return 0;
}

/*
Input:
A =
    3 1 2 
    2 -3 -1 
    1 2 1 
B =
    3 -3 4
Output:
x = 1
y = 2
z = -1

input:
1 1 1
1 2 4
1 3 4
1 6 6
Output:
x = -0.666667
y = 0
z = 1.66667
*/