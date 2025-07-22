/*
C221050
Write a program to find the root of the equation x3 - 6x + 4 = 0, correct to 3 decimal places, by using Newton-Raphson method.
*/

#include<bits/stdc++.h>
using namespace std;


double error = .005;


double f_x1(double x1) // Computing f(x1)
{
    return (x1 * x1 * x1) - (6 * x1) + 4;
}


double f_prime(double x1) // Computing f'(x1)
{
    return (3 * x1 * x1) - 6.0;
}
int main()
{
    double x1 = 0;
    double x2 = x1 - ( f_x1(x1) / f_prime(x1) );
    while( fabs(x2 - x1) > error )
    {
       x1 = x2;
       x2 = x1 - ( f_x1(x1) / f_prime(x1) );
    }

    cout << "The result is: " << fixed << setprecision(4) << x1 << endl;

    return 0;
}
