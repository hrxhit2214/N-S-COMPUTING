#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;
    vector<vector<float>> mat(n, vector<float>(n + 1));

    cout << "Enter the augmented matrix (coefficients and RHS):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        float diag = mat[i][i];
        if (diag == 0) {
            cout << "Zero on diagonal, can't proceed!\n";
            return -1;
        }
        for (int j = 0; j <= n; j++) {
            mat[i][j] /= diag;
        }
        for (int k = i + 1; k < n; k++) {
            float factor = mat[k][i];
            for (int j = 0; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }
    vector<float> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n]; 
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
    }
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }

    return 0;
}
