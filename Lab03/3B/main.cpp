#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;

#define EPS 0.0000001




int main() {
    // ======================
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
    // ======================

    int n;
    vector<double> h;

    cin >> n;
    h.resize(n);
    cin >> h[0];


    // ============================
    double l = 0, r = h[0];
    int zeroes;
    while (r - l > EPS) {
        zeroes = 0;
        h[1] = (l + r) / 2;

        bool is_up = true;
        for (int i = 2; i < n; ++i) {
            h[i] = 2 * h[i - 1] - h[i - 2] + 2;

            if (h[i] == 0)
                zeroes++;
            if (h[i] < 0 || zeroes > 1) {
                is_up = false;
                break;
            }

        }
        if (is_up) {
            r = h[1];
        } else {
            l = h[1];
        }

    }
    // ====================

    cout.precision(2);
    cout << fixed << h[n - 1];

    return 0;
}