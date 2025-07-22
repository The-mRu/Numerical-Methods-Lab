/*

4.4. Write a program to solve the following Differential Equation by using Euler�s method.
        dy / dx = x3 + y,  y (0) = 1. Compute y (0.02) taking h = 0.01.

*/

#include <bits/stdc++.h>
using namespace std;



double f(double x, double y) {
    return (x * x * x + y);
}

int main() {
    double x, y, h, final_x;

   
    cout << "x0 = ";
    cin >> x;

    cout << "y0 = ";
    cin >> y;

    cout << "h = ";
    cin >> h;

    cout << "final_x: ";
    cin >> final_x;

    
    while (x <final_x) {
        y = y + h * f(x, y); 
        x = x + h;           
    }

    
    cout << fixed << setprecision(4);
    cout << "y(" << final_x << ") = " << y << endl;

    return 0;
}
/*

Input:

0 1 0.01 0.02

Output:

y(0.02) = 1.0201

*/