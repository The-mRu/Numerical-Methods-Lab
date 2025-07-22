/*
2. The following values of f (x) are given.

x          1  2  3   4    5
y = f(x)   1  8  27  64   125

Write a program to find the values of y when x = 1.7 by using Newton&#39;s forward interpolation
formula.
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

    for(int i=0;i<n;i++){
        table[i][0]=y[i];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            table[j][i]=table[j+1][i-1]-table[j][i-1];
        }
    }

    // cout << "Difference Table : " << endl;
    // cout << fixed << setprecision(2);
    
    // for(int i=0;i<n;i++){
    //     cout << "x=" << x[i] << "\ty=" << table[i][0];
    //     for(int j=1;j<n-i;j++){
    //         cout << "\t" << table[i][j];
    //     }
    //     cout << endl;
    // }
     
    double X;
    cout << "Enter x : ";
    cin >> X;
    double h = x[1] - x[0];
    double u = (X - x[0]) / h; 
    double y_answer = y[0];  
    double u_term = u;  
    double fact = 1; 

    for(int i=1;i<n;i++){
        fact *= i; 
        y_answer += (u_term * table[0][i]) / fact; 
        u_term *= (u - i); 
    }
    cout << "Ans = " << y_answer << endl;

}
