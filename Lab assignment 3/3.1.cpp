/*


3.1 Find the first and second derivative at x = 1
   using Newton's Forward Difference formula.

x         1   2   3   4   5
y=f(x)    1   8   27  64  125


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
Input:
5
1 2 3 4 5
1 8 27 64 125
1
Output:
f'(X)  = 3
f''(X) = 6


input:
5
2 4 6 8 10
1.23 4.11 6.23 10.34 12.34
4
output:
f'(X)  = 0.735417
f''(X) = -0.0472917
Input:
6
1 2 3 4 5 6
1 8 27 64 125 216
1
Output:
f'(X)  = 3
f''(X) = 6
*/
