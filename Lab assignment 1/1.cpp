/*
C221050
1. Write a program to count number of significant digits in a given number.
*/
#include <iostream>
#include <string>
using namespace std;

int countDigit(string number) {
    bool decimalFound = false;
    string integerPart, decimalPart;

    // Split the number into integer and decimal parts
    for (char c : number) {
        if (c == '.') {
            decimalFound = true;
            continue;
        }
        if (!decimalFound) integerPart += c;
        else decimalPart += c;
    }

    // Remove leading zeros from integer part
    int start = 0;
    while (start < integerPart.size() && integerPart[start] == '0') {
        start++;
    }
    integerPart = integerPart.substr(start);

    // Handle numbers without decimal points (remove trailing zeros)
    if (!decimalFound) {
        int end = integerPart.size() - 1;
        while (end >= 0 && integerPart[end] == '0') {
            end--;
        }
        integerPart = integerPart.substr(0, end + 1);
    }

    // Handle numbers starting with decimal point (remove leading zeros from decimal)
    if (integerPart.empty()) {
        int startDecimal = 0;
        while (startDecimal < decimalPart.size() && decimalPart[startDecimal] == '0') {
            startDecimal++;
        }
        decimalPart = decimalPart.substr(startDecimal);
    }

    // Count all remaining digits
    return integerPart.size() + decimalPart.size();
}

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    int result = countDigit(num);
    cout << "Total significant digits: " << result << endl;

    return 0;
}
