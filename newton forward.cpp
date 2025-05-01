#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the forward difference
void forwardDifference(vector<double>& y, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j] = y[j] - y[j - 1];
        }
    }
}

// Function to perform Newton's Forward Interpolation
double newtonForwardInterpolation(vector<double>& x, vector<double>& y, int n, double value) {
    forwardDifference(y, n);  // Calculate the forward differences

    // Calculate the value of the polynomial at 'value'
    double result = y[0];  // First term is always y0
    double term = 1;  // Initialize term as (x - x0)
    double h = x[1] - x[0];  // Assuming uniform spacing of x

    for (int i = 1; i < n; i++) {
        term *= (value - x[i - 1]);  // Update term as (x - xi)
        result += (term / factorial(i)) * y[i];  // Add the next term
    }

    return result;
}

// Function to calculate factorial (used for denominator in the formula)
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    double value;

    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    // Input the x and y values
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    cout << "Enter the value to interpolate: ";
    cin >> value;

    // Calculate the interpolated value using Newton's Forward Interpolation
    double result = newtonForwardInterpolation(x, y, n, value);

    cout << "Interpolated value at " << value << " is: " << result << endl;

    return 0;
}
