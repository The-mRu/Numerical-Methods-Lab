/*
3.3 Write a program to calculate the approximate area under the curve y = ∫(1 to 5) log10 x dx                                     by using trapezoidal rule.
Theory:
I =h/2 [y0 + 2 (y1 + y2 + ……….  + yn-1) + yn]
*/


#include<bits/stdc++.h>

using namespace std;
double f(double x) {
    return log10(x); 
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    if (a <= 0 || b <= 0) {
        cout << "Error: log10(x) is undefined for x <= 0" << endl;
        return 1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    double result = (h / 2) * sum;

    cout << "\nApproximate area under log10(x) from " << a << " to " << b << " is: " << result << endl;

    return 0;
}
/*
Input:
1
5
10
Output:
1.75307
*/