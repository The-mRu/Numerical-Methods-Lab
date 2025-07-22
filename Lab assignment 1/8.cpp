/*
C221050
Write a program to find the root of the equation x3 - 5x2 - 29 = 0, correct to 3 decimal places, by using secant method.
*/

#include<bits/stdc++.h>
using namespace std;

double error = 0.0001;

double fx(double x)
{
    return ( (x * x * x) - (5 * x * x) - 29 );
}

double calc(double x0, double x1)
{
    return x1 - ( ( (x1 - x0) / (fx(x1) - fx(x0)) ) * fx(x1) );
}


int main()
{
    double x0 = 1, x1 = 6;
    while(fabs(x0 - x1) > error)
    {
        double x2 = calc(x0,x1);
        x0 = x1;
        x1 = x2;
    }

    cout << fixed << setprecision(3) << x1 << endl;

    return 0;
}
