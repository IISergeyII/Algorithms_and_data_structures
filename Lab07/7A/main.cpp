#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

class Node {

public:
    int key;
    int leftC;
    int rightC;

    Node(int k, int l, int r) {
        key = k;
        leftC = l;
        rightC = r;
    }

    int height;

    bool leftExists() {
        return leftC != -1;
    }

    bool rightExists() {
        return rightC != -1;
    }

};

class AVL {

public:
    vector<Node*> tree;

    void calculate_height() {
        if (!tree.empty()) {
            height_pass(tree[0]);
        }

    }

    void height_pass(Node* v) {

        if (v->leftExists()) {
            height_pass(tree[v->leftC]);
        }
        if (v->rightExists()) {
            height_pass(tree[v->rightC]);
        }

        v->height = max(height_left(v), height_right(v)) + 1;
    }

    int height_left(Node* v) {
        if (v->leftExists()) {
            return tree[v->leftC]->height;
        }
        else {
            return 0;
        }
    }


    int height_right(Node* v) {
        if (v->rightExists()) {
            return tree[v->rightC]->height;
        }
        else {
            return 0;
        }
    }

    int balance(int k) {
        int l = 0;
        int r = 0;

        if (height_left(tree[k])) {
            l = tree[tree[k]->leftC]->height;
        }

        if (height_right(tree[k])) {
            r = tree[tree[k]->rightC]->height;
        }


        return r - l;
    }

};



int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    // ====================== */


    int n;
    cin >> n;

    int k, l, r;
    AVL avl;

    for (int i = 0; i < n; ++i) {
        cin >> k >> l >> r;

        avl.tree.push_back(new Node(k, l - 1, r - 1));
    }

    avl.calculate_height();

    for (int i = 0; i < avl.tree.size(); ++i) {
        cout << avl.balance(i) << "\n";
    }






    return 0;
}