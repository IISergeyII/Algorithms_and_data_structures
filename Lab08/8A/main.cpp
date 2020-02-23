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

    int n, m;
    cin >> n >> m;
    int a[n+1][n+1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
        }
    }

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        a[x-1][y-1]++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}