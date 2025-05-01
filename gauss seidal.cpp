#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void gaussSeidel(vector<vector<double>>& A, vector<double>& b, vector<double>& x, int n, double tolerance) {
    vector<double> x_old(n); // Old values of x for checking error
    double error;
    int iterations = 0;

    // Initialize solution to 0 (or any starting guess)
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    do {
        error = 0.0;

        // Gauss-Seidel iteration
        for (int i = 0; i < n; i++) {
            double sum = b[i];  // Start with the right-hand side

            // Subtract the known terms from the equation
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }

            // Update x[i] with new value
            double new_x = sum / A[i][i];
            error = max(error, fabs(new_x - x[i]));  // Calculate the error
            x[i] = new_x;  // Update x[i]
        }

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

    // Call Gauss-Seidel function
    gaussSeidel(A, b, x, n, tolerance);

    // Output the result
    cout << "Solution: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}
