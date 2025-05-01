#include <iostream>
#include <cmath>

using namespace std;

// Function for which we need to find the root
double f(double x) {
    return x*x - 4;  // Example: f(x) = x^2 - 4 (Root at x = 2 or x = -2)
}

void secantMethod(double x0, double x1, double tolerance, int maxIter) {
    double x2, f0, f1;
    int iterations = 0;

    while (iterations < maxIter) {
        f0 = f(x0);  // f(x0)
        f1 = f(x1);  // f(x1)

        // Secant formula
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        // Check for convergence
        if (fabs(x2 - x1) < tolerance) {
            cout << "Root found: " << x2 << endl;
            cout << "Iterations: " << iterations + 1 << endl;
            return;
        }

        // Update for next iteration
        x0 = x1;
        x1 = x2;
        iterations++;
    }

    cout << "Root not found within the maximum number of iterations." << endl;
}

int main() {
    double x0, x1, tolerance;
    int maxIter;

    // Input the initial guesses and tolerance
    cout << "Enter first guess (x0): ";
    cin >> x0;
    cout << "Enter second guess (x1): ";
    cin >> x1;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    // Call secant method function
    secantMethod(x0, x1, tolerance, maxIter);

    return 0;
}
