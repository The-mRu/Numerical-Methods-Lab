/*
3.4 Write a program to calculate the approximate area under the curve y = ∫(0 to pi/2) esinx dx by using Simpson’s 1/3 rule

*/


#include<bits/stdc++.h>

using namespace std;


double f(double x) {
    return exp(sin(x));  // e^sin(x)
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a in radians): ";
    cin >> a;
    cout << "Enter upper limit (b in radians): ";
    cin >> b;
    cout << "Enter number of intervals (n - must be even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error: Number of intervals must be even for Simpson’s 1/3 Rule." << endl;
        return 1;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double result = (h / 3) * sum;

    cout << "\nApproximate area under e^sin(x) from " << a << " to " << b << " is: " << result << endl;

    return 0;
}
/*
Input:
0
1.5708
10
Output:
3.10439
*/