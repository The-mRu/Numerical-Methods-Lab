/*
3.5 Write a program to calculate the approximate area under the curve:

    y = ∫(x / (1 + x^2)) dx from a to b

using Simpson’s 3/8 Rule.

Formula:
   I = (3h/8) * [(y0 + y_n) + 3(y1+y2+y4+y6+...+y_n-2+y_n-1) ) + 2(y3+y6+... +y_n-3) ]
where:
    h = (b - a) / n
    n must be a multiple of 3
*/

#include<bits/stdc++.h>
using namespace std;


double f(double x) {
    return x / (1 + x * x); // f(x) = x / (1 + x^2)
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n - must be multiple of 3): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Error: Number of intervals must be a multiple of 3 for Simpson’s 3/8 Rule." << endl;
        return 1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    double result = (3 * h / 8) * sum;

    cout << "\nApproximate area under x / (1 + x^2) from " << a << " to " << b << " is: " << result << endl;

    return 0;
}

/*
Input:
0
1
30
Output:
0.346574
*/