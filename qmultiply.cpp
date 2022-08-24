#include <iostream>
#include <string>

using namespace std;

// FUNCTIONS
// -----------------------------------------
// Runs the division algorithm
float qmultiply(float a, float b);               
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
    cout << a << " * " << b << endl;
    cout << "-----------------" << endl << endl;

    // Store the approximation of a/b
    float approximation = qmultiply(a, b);
    // Store the actual value of a/b
    float actual = a * b;
    // Print out the answers
    cout << "qmultiply: " << approximation << endl;
    cout << "answer: "<< actual << endl;

}

// COMPUTES THE DIVISION
float qmultiply(float a, float b) {
    // Convert a and b from floating point numbers to integers
    int _a = * (int *) & a;
    int _b = * (int *) & b;
    // Subtract a and b then add mu to approximate a/b
    int _result = (_a + _b) + 0xC085C416;
    // Convert the approximation back to a float
    float result = * (float *) & _result;

    // Return the answer
    return result;
}