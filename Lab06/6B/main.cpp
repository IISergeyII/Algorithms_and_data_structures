#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

class Node {

public:
    int key;

    int left;
    int right;

    Node(int k, int l, int r) {
        key = k;
        left = l;
        right = r;
    }
};

bool isTree(Node* node, vector<Node*>& tree, int minK, int maxK) {

    if (node == nullptr) {
        return true;
    }

    if (node->key <= minK || maxK <= node->key) {
        return false;
    }
    else {
        bool l = true;
        bool r = true;

        if (node->left != 0) {
            l = isTree(tree[node->left], tree, minK, node->key);
        }
        if (node->right != 0) {
            r = isTree(tree[node->right], tree, node->key, maxK);
        }
        return l && r;

    }



}


int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    // ====================== */

    int n;
    int k, l, r;
    cin >> n;

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    vector<Node*> tree;

    for (int i = 0; i < n; ++i) {
        cin >> k >> l >> r;
        tree.push_back(new Node(k, l != 0 ? l - 1 : 0, r != 0 ? r - 1 : 0));
    }

    cout << (isTree(tree[0], tree, INT32_MIN, INT32_MAX) ? "YES" : "NO");


    return 0;
}