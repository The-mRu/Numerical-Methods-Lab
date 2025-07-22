/*
C221050
Write a program to find the root of the equation x3 - x + 2 = 0, correct to 3 decimal places, by using false position method.
*/

#include<bits/stdc++.h>
using namespace std;


double error = .00005;

double f_x(double x)
{
    return ((x * x * x) - x + 2) * 1.00;
}

int main()
{
    double x1 = -2.0, x2 = 1.0;

    double x0 = x1 - ( ( f_x(x1) * (x2- x1) ) / ( f_x(x2) - f_x(x1) ) );

    if( f_x(x1) * f_x(x0) < 0.0 )
    {
        x2 = x0;
    }
    else
    {
        x1 = x0;
    }

    double x0_prev = x0;

    x0 =x1-((f_x(x1)*(x2- x1))/(f_x(x2)-f_x(x1)));

    while( abs(x0_prev - x0) > error )
    {
        if( f_x(x1) * f_x(x0) < 0.0 )
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }

        x0_prev = x0;
        x0 = x1 - ( ( f_x(x1) * (x2- x1) ) / ( f_x(x2) - f_x(x1) ) );
    }

    cout << fixed << setprecision(3) << x0 << endl;

    return 0;
}
