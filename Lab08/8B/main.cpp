#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // ====================== */

    int n;
    bool f1 = true;

    cin >> n;
    int a[n+1][n+1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                if (a[j][i] == 0) {
                    f1 = false;
                    // cout << i << " " << j << "\n";
                }
            }
            if (i == j && a[i][j] == 1) {
                f1 = false;
                // cout << i << " " << j << "\n";
            }
        }
    }

    if (f1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}