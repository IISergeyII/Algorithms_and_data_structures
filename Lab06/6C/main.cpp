#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

class Node {

public:
    int key;

    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }

};


class Tree {
    Node* begin = nullptr;

    Node* search(Node* node, int k) {

        if (node == nullptr || node->key == k) {
            return node;
        }


        if (k < node->key) {
            return search(node->left, k);
        }
        else {
            return search(node->right, k);
        }

    }

    Node* insert(Node* node, int k) {

        if (node == nullptr) {
            return new Node(k);
        }

        if (k < node->key) {
            node->left = insert(node->left, k);
        }
        else {
            node->right = insert(node->right, k);
        }

        return node;
    }

    Node* remove(Node* node, int k) {

        if (node == nullptr) {
            return node;
        }

        if (node->key != k) {

            if (k < node->key) {
                node->left = remove(node->left, k);
            }
            else {
                node->right = remove(node->right, k);
            }

        }
        else {

            if (node->left != nullptr && node->right != nullptr) {
                Node* min = node->right;
                while (min->left != nullptr) {
                    min = min->left;
                }

                node->key = min->key;
                node->right = remove(node->right, node->key);

            } else {

                if (node->left != nullptr) {
                    node = node->left;
                }
                else {
                    node = node->right;
                }

            }

        }
        return node;
    }

    Node* next(Node* node, int k) {
        Node* current = node;
        Node* successor = nullptr;

        while (current != nullptr) {
            if (k >= current->key) {
                current = current->right;
            }
            else {
                successor = current;
                current = current->left;
            }
        }

        return successor;
    }

    Node* prev(Node* node, int k) {
        Node* current = node;
        Node* antecedent = nullptr;

        while (current != nullptr) {
            if (k <= current->key) {
                current = current->left;
            }
            else {
                antecedent = current;
                current = current->right;
            }
        }

        return antecedent;
    }


public:

    bool exists(int k) {
        return (search(begin, k) != nullptr);
    }

    void insert(int k) {
        if(!exists(k)) {
            begin = insert(begin, k);
        }

    }

    void remove(int k) {
        if (exists(k)) {
            begin = remove(begin, k);
        }
    }

    int next(int k) {
        Node* t = next(begin, k);
        if (t == nullptr) {
            return INT32_MIN;
        }
        else {
            return t->key;
        }

    }


    int prev(int k) {
        Node* t = prev(begin, k);
        if (t == nullptr) {
            return INT32_MIN;
        } else {
            return t->key;
        }
    }

};



int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    // ====================== */

    Tree a;

    while (!cin.eof()) {

        string s;
        int k;
        cin >> s >> k;

        if (s == "insert") {
            a.insert(k);
        }

        if (s == "delete") {
            a.remove(k);
        }

        if (s == "exists") {
            cout << (a.exists(k) ? "true" : "false") << "\n";
        }

        if (s == "prev") {
            int t = a.prev(k);

            if (t == INT32_MIN) {
                cout << "none";
            }
            else {
                cout << t;
            }
            cout << "\n";
        }

        if (s == "next") {
            int t = a.next(k);

            if (t == INT32_MIN) {
                cout << "none";
            }
            else {
                cout << t;
            }
            cout << "\n";

        }

    }



    return 0;
}