/*
C221050
Write a program to find the quotient polynomial q(x) such that p(x) = (x - 2) q(x) where the polynomial p(x) = x3 - 5x2 + 10x - 8 = 0 has a root at x = 2.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cout << "Enter the degree of polynomial (n): ";
    cin >> n;
    cout << "Enter the root value (x): ";
    cin >> x;
    vector<int>a(n+5),b(n+5);

    cout << "Enter the coefficients of the polynomial:\n";

    for(int i = n-1; i>=0; i--)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    b[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        b[i] = a[i+1] + (x * b[i+1]);
    }

    cout << "\nThe Quotient Polynomial q(x) is, \n";

    for(int i = n-2; i >= 0; i--){
        if(b[i] == 0){
            continue;
        }
        if(i == n-2){
            cout << b[i] << "x^" << i << " ";
            continue;
        }
        if(i == 0){
            if(b[i] >= 0) cout << "+ " << b[i] << " ";
            else cout << "- " << abs(b[i]) << " ";
            continue;
        }
        else{
            if(b[i] >= 0 ) cout << "+ "  << b[i] << "x^" << i << " ";
            else cout << "- " << abs(b[i]) << "x^" << i << " ";
        }
    }
    cout << "= 0" << endl;

    return 0;
}
