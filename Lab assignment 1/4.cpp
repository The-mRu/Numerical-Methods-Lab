/*
C221050
Write a program to find the root of the equation x3 - 9x + 1 = 0, correct to 3 decimal places, by using the bisection method.

*/
#include<bits/stdc++.h>
using namespace std;

double error = .0001;

bool calc(double x)
{
    double xx = ( (x * x * x) - (9.0 * x) + 1.0 );
    if(xx < 0.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    double right = 3.0, left = 1.0;

    while(fabs(right - left) >= error)
    {
        double mid = (right + left) / 2.0;
        if(calc(mid)){
            left = mid;
        }
        else right = mid;
    }

    cout << fixed << setprecision(3) << left << endl;

    return 0;

}
