/*

4.1. Write a program to find the least square line y = a + bx for the following data
        x     -2    -1     0     1     2
        y      1     2     3     4     5


*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n+1], y[n+1];
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];
    
    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    cout << "Least square line: y = " << a << " + " << b << "x\n";
    return 0;
}
/*

Input:

5
-2 -1 0 1 2
1 2 3 4 5

Output:

The line equation is : y = 3 + 1x

*/