#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return x * x * x - x - 2;  // Example function: f(x) = x^3 - x - 2
}
int iteration =0;
void bisection(double a, double b, double tol) {
    if (func(a) * func(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) should have opposite signs.\n";
        return;
    }

    double mid;
    while ((b - a) >= tol) {
        mid = (a + b) / 2;
        cout << "Current approximation at : "<< mid << endl;
        iteration++;

        if (func(mid) == 0.0) {  // Exact root found
            cout << "Exact root found: " << mid << endl;
            return;
        }
        
        if (func(mid) * func(a) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }

    cout << "Final root approximation: " << mid << endl;
}

int main() {
    double a = 1, b = 2, tol = 0.0001;
    bisection(a, b, tol);
    return 0;
}
