/*
3.2 The following values of f (x) are given.
     x              1     2     3       4        5
   y = f(x)     1     8    27     64     125
Write a program to find the first derivative and the second derivative of the function tabulated above at the point x = 1.5.

*/

#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cout << "Enter number of points (n): ";
    cin >> n;

    double x[100], y[100], diff[100][100];


    cout << "Enter x values:\n";
    for (int i = 0; i < n; ++i)
        cin >> x[i];


    cout << "Enter y = f(x) values:\n";
    for (int i = 0; i < n; ++i)
        cin >> diff[i][0];  // y

    // forward difference table
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n - j; ++i)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    double X;
    cout << "Enter value of X : ";
    cin >> X;

    double h = x[1] - x[0];
    double u = (X - x[0]) / h;

    // Factorial
    double f2 = 2, f3 = 6, f4 = 24;

    // First derivative
    double f1 = (1 / h) * (
                    diff[0][1] +
                    ((2*u - 1) * diff[0][2]) / f2 +
                    ((3*u*u - 6*u + 2) * diff[0][3]) / f3 +
                    ((4*u*u*u - 18 * u * u + 22 * u - 6) * diff[0][4]) / f4
                );

    // Second derivative
    double f2nd = (1 / (h * h)) * (
                      diff[0][2] +
                      ((6*u - 6) * diff[0][3]) / f3 +
                      ((12*u*u - 36*u + 22) * diff[0][4]) / f4
                  );

    // cout << fixed << setprecision(4);
    cout << "\nf'(X)  = " << f1 << endl;
    cout << "f''(X) = " << f2nd << endl;

    return 0;
}
/*

input:
5
1 2 3 4 5
1 8 27 64 125
1.5
Output:
f'(X)  = 6.75
f''(X) = 9
*/
