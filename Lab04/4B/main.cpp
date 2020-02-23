#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    // ====================== */

    int n, t;
    char cmd;
    cin >> n;
    vector<int> q(n);

    int start, end;
    start = end = n - 1;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == '+') {
            cin >> t;
            q[start] = t;
            start--;
        } else {
            cout << q[end] << "\n";
            end--;
        }
    }

    return 0;
}