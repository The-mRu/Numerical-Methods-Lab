/*
C221050
3.Write a program to evaluate a polynomial f(x) = x3 - 2x2 + 5x + 10  by using Horner's rule x = 5.
*/



#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the value of n = ";
    int n,x;
    cin >> n;

    vector<int> a(n+5),p(n+5);

    for(int i = n; i >= 0; i--){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Value of x = ";

    cin >> x;

    p[n+1] = 0;

    for(int i = n; i >= 0; i--){
        p[i] = (p[i+1] * x) + a[i];
    }

    cout << "The answer is = " << p[0] << endl;

    return 0;

}
