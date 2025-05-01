#include <iostream>
#include <cmath>
#include <iomanip>  // Include for formatting

using namespace std;

double function(double x) {
    return x * x * x - 2 * x - 1;
}

void regula_falsi(double a, double b, double tol) {
    if (function(a) * function(b) >= 0) {
        cout << "Invalid interval.\n";
        return;
    }

    double mid;
    int iterations = 0;

    cout << fixed << showpoint << setprecision(6); // Ensures correct floating-point format

    while (true) {
        mid = a - (function(a) * (b - a)) / (function(b) - function(a));

        cout << "Iteration " << ++iterations << ": Root =" << mid << endl;

        if (abs(function(mid)) < tol) {
            cout << "Final root: " << mid << endl;
            break;
        }

        if (function(mid) > 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
}

int main() {
    double a = 1, b = 2, tol = 0.0001;
    regula_falsi(a, b, tol);
    return 0;
}
