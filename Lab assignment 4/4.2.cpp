/*

4.2. Write a program to find the least square parabola y = a + bx + cx2 for the following data
      x         2       4      6        8
      y         1.4     2.0     2.4     2.8


*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

   
    double Sx = 0, Sx2 = 0, Sx3 = 0, Sx4 = 0;
    double Sy = 0, Sxy = 0, Sx2y = 0;

    for (int i = 0; i < n; i++) {
        double xi = x[i], yi = y[i];
        Sx += xi;
        Sx2 += xi * xi;
        Sx3 += xi * xi * xi;
        Sx4 += xi * xi * xi * xi;
        Sy += yi;
        Sxy += xi * yi;
        Sx2y += xi * xi * yi;
    }

    // augmented matrix
    double A[3][4] = {
        {double(n), Sx, Sx2, Sy},
        {Sx, Sx2, Sx3, Sxy},
        {Sx2, Sx3, Sx4, Sx2y}
    };

    
    //used Gaussian Elimination to find unknown values
   
    for (int i = 0; i < 3; i++) {
        double pivot = A[i][i];
        for (int j = 0; j < 4; j++) {
            A[i][j] /= pivot;
        }


        for (int k = 0; k < 3; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = 0; j < 4; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    
    double a = A[0][3];
    double b = A[1][3];
    double c = A[2][3];

    
    cout << "\nBest fit parabola\n";
    cout << "y = " << a << " + " << b << "x + " << c << "x^2\n";

    return 0;
}
/*

Input:

  4
  2       4      6        8  
 1.4    2.0   2.4     2.8

Output:

Best fit parabola
y = 0.75 + 0.355x + -0.0125x^2



*/
