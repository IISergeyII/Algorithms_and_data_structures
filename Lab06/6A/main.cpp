#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;
/*
class Node {

public:
    int key;
    int h = 1;

    int left;
    int right;

    Node (int k, int l, int r) {
        key = k;
        left = l;
        right = r;
    }
};

int traversal(Node* node, vector<Node*>& tree, int maxH) {
    if (node == nullptr) {
        return maxH;
    } else {
        return max();
    }
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    // ====================== */

    int n;
    int k, l, r;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> h(n);
    h[0] = 1;
    for (int i = 1; i < n; ++i) {
        h[i] = 0;
    }


    for (int i = 0; i < n; ++i) {
        cin >> k >> l >> r;

        if (l != 0) {
            h[l-1] = h[i] + 1;
        }
        if (r != 0) {
            h[r-1] = h[i] + 1;
        }
    }

    int maxH = 0;
    for (int i = 0; i < n; ++i) {
        maxH = max(h[i], maxH);
    }

    /* =======================================
    for (int i = 0; i < n; ++i) {
        cout << i << " " << h[i] << "\n";
    }
    cout << "\n";
    // ======================================= */

    cout << maxH;


    return 0;
}