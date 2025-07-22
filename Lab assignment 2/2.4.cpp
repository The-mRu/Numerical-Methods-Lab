/*
4. The following values of f (x) are given.

x           1  2  3   4   5
y = f(x)    1  8  27  64  125

Write a program to find the values of x for which f (x) = 85 by using Lagrange�s inverse
interpolation formula.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "n = ";
    cin>>n;

    double x[n],y[n],table[n][n];
    cout << "Value of x : ";
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    cout << "Value of y : ";
    for(int i=0;i<n;i++){
        cin>>y[i];
    }

    double fx,ans=0;
    cout << "f(x) = ";
    cin >> fx;

    for(int i=0;i<n;i++){
        double t1=1.0,t2=1.0;
        for(int j=0;j<n;j++){
            if(j==i) continue;
            t1 *= (fx - y[j]);
            t2 *= (y[i] - y[j]);
        }
        ans += ((double)((t1/t2)*x[i]));
    }
    cout << "X = " << ans << endl;

}