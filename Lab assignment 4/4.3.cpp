/*
4.3. Write a program to find the best possible values of a and b from the relation y = ae^bx for the following data:
     x	2	10	26	61
     y	600	500	400	350

y= a⋅e^(bx)
ln(y) = ln(a) + bx
Y = ln(y)
A = ln(a)
Y = A + bx
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

   
    double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

    for (int i = 0; i < n; i++) {
        double Xi = x[i];
        double Yi = log(y[i]);  
        
        sumX += Xi;
        sumY += Yi;
        sumX2 += Xi * Xi;
        sumXY += Xi * Yi;
    }

   
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double A = (sumY - b * sumX) / n;

    double a = exp(A); 

    
    cout << "\nBest fit exponential curve:\n";
    cout << "y = " << a << " * e^(" << b << "x)\n";

    return 0;
}
/*

Input:

 4
2 10 26 61
600 500 400 350

Output:

Best fit exponential curve:
y = 558.191 * e^(-0.00846335x)



*/
