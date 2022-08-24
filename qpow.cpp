#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// FUNCTIONS
// -----------------------------------------
// Runs the division algorithm
float qpow(float a, float b);               
// -----------------------------------------

int main() {
    
    // Variables for storing user input
    float a;
    float b;

    // Get user input
    cout << "First Number: ";
    cin >> a;
    cout << "Second Number: ";
    cin >> b;
    // Print Out the Operation Being Performed
    cout << a << " ^ " << b << endl;
    cout << "-----------------" << endl << endl;

    // Store the approximation of a/b
    float approximation = qpow(a, b);
    // Store the actual value of a/b
    float actual = pow(a,b);
    // Print out the answers
    cout << "qpow: " << approximation << endl;
    cout << "answer: "<< actual << endl;

}

// COMPUTES THE DIVISION
float qpow(float a, float b) {
    // Convert a and b from floating point numbers to integers
    int _a = * (int *) & a;
    int _b = * (int *) & b;

    // A=yX+8388608uy-1065353216y-8388608u+1065353216
    int _result = _a*b - 0x3F7A3BEA*b + 0x3F7A3BEA;
    // Convert the approximation back to a float
    float result = * (float *) & _result;

    // Return the answer
    return result;
}