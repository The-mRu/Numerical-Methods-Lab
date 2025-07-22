/*
3.6 Write a program to find the determinant of a 3×3 matrix.
*/

#include <iostream>
using namespace std;

int main() {
    double matrix[3][3];

    cout << "Enter the elements of the 3x3 matrix row wise:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }

    double a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    double d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    double g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];

    double determinant = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);

    cout << "\nDeterminant of the matrix is: " << determinant << endl;

    return 0;
}


/*
input:
1 2 3
4 5 6
7 8 9
output: 0
*/

