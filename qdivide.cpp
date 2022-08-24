#include <iostream>
#include <string>

using namespace std;

// FUNCTIONS
// -----------------------------------------
// Runs the division algorithm
float qdivide(float a, float b);               
// Performs a single step of a Newton's approixmation 
void nstep(float &result, float a, float b);

void astep(float &result, float a, float b);
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
    cout << a << " / " << b << endl;
    cout << "-----------------" << endl << endl;

    // Store the approximation of a/b
    float approximation = qdivide(a, b);
    // Store the actual value of a/b
    float actual = a / b;
    // Print out the answers
    cout << "qdivide: " << approximation << endl;
    cout << "answer: "<< actual << endl;

}

// COMPUTES THE DIVISION
float qdivide(float a, float b) {
    // Convert a and b from floating point numbers to integers
    int _a = * (int *) & a;
    int _b = * (int *) & b;
    // Subtract a and b then add mu to approximate a/b
    int _result = (_a - _b) + 0x3F7A3BEA;
    // Convert the approximation back to a float
    float result = * (float *) & _result;

    // Run 3 interations of Newton's Method on the approximation
    nstep(result, a, b);
    nstep(result, a, b);
    nstep(result, a, b);

    // Return the answer
    return result;
}

// 1 STEP OF NEWTON'S METHOD
void nstep(float &result, float a, float b) {
    // Calculate f(x)
    float f = (result * b) - a;
    // Convert f(x) and f'(x) from floating points to integers
    int _f = * (int *) & f;
    int _fd = * (int *) & b;
    // Calculate the step interval
    int _step = (_f - _fd) + 0x3F7A3BEA;
    float step = * (float *) & _step;
    // Set result to to result - step
    result = result - step;
}

// 1 STEP OF NEWTON'S METHOD
void astep(float &result, float a, float b) {
    int _a = * (int *) & a;
    int _b = * (int *) & b;
    int _result = * (int *) & result;

    // Approximate x/z
    int _divided = (_a - _result) + 0x3f76d141;
    float divided = * (float *) & _divided;

    float numerator = divided - b;
    cout << "\tnumerator: " << numerator << endl;
    int _numerator = * (int *) & numerator;

    int _denominator = _a - (_result << 1) - 0x810B882B;
    float denominator = * (float *) & _denominator;
    cout << "\tdenominator: " << denominator << endl;

    int _step = (_numerator - _denominator) + 0x3F7A3BEA;
    float step = * (float *) & _step;

    cout << "\tapproximate step: " << step << endl;
    cout << "\tactual step: " << ((a/result) - b)/(a/(result * result)) << endl;

    // Set result to to result - step
    result = result + step;
}