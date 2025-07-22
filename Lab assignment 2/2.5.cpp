/*
The following values of f (x) are given. Prepare the divided difference table for the following data
            x     1      3     4      6      10
  y  =  f(x)  0     18   58   190   920
Write a program to find the values of y when x = 2.7 by using Newton's divided difference formula.
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    double x[10], y[10], table[10][10];

    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i << ": ";
        cin >> x[i];
    }

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) {
        cout << "y" << i << ": ";
        cin >> y[i];
    }
    double X;
    cout << "Enter X to find f(x): ";
    cin >> X;

    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    double ans = table[0][0];
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (X - x[i - 1]);
        ans += table[0][i] * term;
    }
    cout << fixed << setprecision(5);
    cout << "f(" << X << ") = " << ans << endl;
    return 0;

}

/*
Input 1:
5
5 7 11 13 21
150 392 1452 2366 9702
Output:
f(6) is : 252
Input 2:
5
1      3     4      6      10
0     18   58   190   920
2.7
Output:
f(2.7) is : 9.35463
*/
