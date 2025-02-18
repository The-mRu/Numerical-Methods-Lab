#include <bits/stdc++.h>
using namespace std;

int digits(string num) {  
    int count = 0;
    bool foundNonZero = false;

    for (char ch : num) { 
        if (ch == '.') continue;
        if (ch != '0') foundNonZero = true;
        if (foundNonZero) count++;
    }

    return count;
}

int main() {
    string number;
    cout << "Enter a number: ";
    cin >> number;
    
    int result = digits(number);  
    cout << "Significant Digits: " << result << endl;

    return 0;
}
