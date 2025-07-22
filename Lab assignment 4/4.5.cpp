/*

4.5. Write a program to solve the following Differential Equation by using Runge – Kutta method.
       dy / dx = x + y, y (0) = 1.  Compute y (0.1) and y (0.2)  taking h = 0.1.

*/

#include<bits/stdc++.h>
using namespace std;

double fun(double x, double y) {
    return x + y; 
}

int main() {
    double x0, y0, h, xn;

    
    cout << "x0 =  ";
    cin >> x0;

    cout << "y0 = ";
    cin >> y0;

    cout << "h = ";
    cin >> h;

    cout << "xn = ";
    cin >> xn;

    double x = x0;
    double y = y0;
    double m1,m2,m3,m4;

    
    while (x < xn) {
        
        m1 = fun(x, y);
        m2 = fun(x + h / 2.0, y + (m1 * h) / 2.0);
        m3 = fun(x + h / 2.0, y + (m2 * h) / 2.0);
        m4 = fun(x + h, y + m3 * h);

        double m = m1 + 2 * m2 + 2 * m3 + m4;

        y = y + (m / 6.0) * h;
        x = x + h;
    }

    cout << "\ny(" << xn << ") = " << y << endl;

    return 0;
}
/*

Input:

0 1 0.1 0.1

Output:

y(0.1) = 1.11034

*/
