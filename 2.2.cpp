//2. Write a program to round off a number with n digits after decimal point using banker’s rule.
#include<bits/stdc++.h>
using namespace std;

string roundNum(string num, int d) {
    int p = num.find('.');  


    if (p == -1 || p + d + 1 >= num.length()) return num;

    char next = num[p + d + 1]; 
    char last = num[p + d];      

    if (next < '5' || (next == '5' && (last - '0') % 2 == 0)) {
        return num.substr(0, p + d + 1);
    }

    for (int i = p + d; i >= 0; i--) {
        if (num[i] == '.') continue;
        if (num[i] < '9') {
            num[i]++; 
            return num.substr(0, p + d + 1);
        }
        num[i] = '0';
    }

    return "1" + num.substr(0, p + d + 1);// (9.999 → 10.00), add '1' at the start
}

int main() {
    string num;
    int d;

    cout << "Enter number: ";
    cin >> num;
    cout << "Decimal places: ";
    cin >> d;
    cout << "Rounded: " << roundNum(num, d) << endl;

    return 0;
}

