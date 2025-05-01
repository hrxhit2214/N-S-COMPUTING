#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void jacobiIteration(vector<vector<double>>& A, vector<double>& b, vector<double>& x, int n, double tolerance) {
    vector<double> x_new(n); // To store new values of x
    double error;
    int iterations = 0;

    // Initialize the solution to 0 (or any initial guess)
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    do {
        error = 0.0;

        // Jacobi iteration
        for (int i = 0; i < n; i++) {
            double sum = b[i];  // Start with the right-hand side

            // Subtract the known terms from the equation
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }

            // Calculate the new value of x[i]
            x_new[i] = sum / A[i][i];
            error = max(error, fabs(x_new[i] - x[i]));  // Calculate the error
        }

        // Update x with the new values
        x = x_new;
        iterations++;

    } while (error > tolerance);  // Repeat until error is small enough

    cout << "Iterations: " << iterations << endl;
}

int main() {
    int n;
    double tolerance;

    cout << "Matrix size (n x n): ";
    cin >> n;

    // Tolerance for convergence
    cout << "Enter tolerance: ";
    cin >> tolerance;

    vector<vector<double>> A(n, vector<double>(n)); // Coefficient matrix
    vector<double> b(n); // Right-hand side vector
    vector<double> x(n); // Solution vector

    // Input matrix A
    cout << "Enter the coefficients (row by row):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Input vector b
    cout << "Enter the values of b:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Call Jacobi function
    jacobiIteration(A, b, x, n, tolerance);

    // Output the result
    cout << "Solution: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}
