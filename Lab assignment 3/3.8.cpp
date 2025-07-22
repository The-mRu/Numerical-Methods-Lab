/*
3.8 Write a program to solve the following system of linear equations by using Cramer’s Rule:
           27x +   6y – z     =  85
           6x + 15y + 2z   = 72
           x +     y + 54z = 110
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    double A[3][3], B[3];

    
    cout << "Enter coefficient matrix A (3x3) row by row:\n";
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j) {
        cout << "A[" << i+1 << "][" << j+1 << "]: ";
        cin >> A[i][j];
      }

   
    cout << "Enter right-hand side vector B (3×1):\n";
    for(int i = 0; i < 3; ++i) {
      cout << "B[" << i+1 << "]: ";
      cin >> B[i];
    }

    auto det = [&](double M[3][3]) {
      return
        M[0][0] * (M[1][1]*M[2][2] - M[1][2]*M[2][1]) -
        M[0][1] * (M[1][0]*M[2][2] - M[1][2]*M[2][0]) +
        M[0][2] * (M[1][0]*M[2][1] - M[1][1]*M[2][0]);
    };
    
    double D = det(A);
    
    if (D == 0) {
      cout << "no solution.\n";
      return 1;
    }

    
    double x[3][3], y[3][3], z[3][3];
    
    for(int i = 0; i < 3; ++i) {
      // Column 0 swapped for Dx
      x[i][0] = B[i];
      x[i][1] = A[i][1];
      x[i][2] = A[i][2];
      
      // Column 1 swapped for Dy
      y[i][0] = A[i][0];
      y[i][1] = B[i]; 
      y[i][2] = A[i][2];
      
      // Column 2 swapped for Dz
      z[i][0] = A[i][0]; 
      z[i][1] = A[i][1]; 
      z[i][2] = B[i];
    }

    


    double Dx = det(x);
    double Dy = det(y);
    double Dz = det(z);
    
   
    double xx = Dx / D;
    double yy = Dy / D;
    double zz = Dz / D;
    
    // cout << fixed << setprecision(4);
    cout << "\nSolution:\n";
    cout << "x = " << xx << "\n";
    cout << "y = " << yy << "\n";
    cout << "z = " << zz << "\n";
    return 0;
}

/*
input:
6 1 -3 
1 3 -2 
2 1 4  
5 5 8
output
x = 1
y = 2
z = 1

input
27 6 -1 
6 15 2 
1 1 54 
85 72 110
output
x = 2.42548
y = 3.57302
z = 1.92595

*/

