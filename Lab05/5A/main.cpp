#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

template <typename T>
class HashPair {

public:
    HashPair* next;
    T date;

    HashPair(T d, HashPair* n) {
        date = d;
        next = n;
    }
};

template <typename T>
class HashSet {

private:
    const unsigned int M = 115249;
    vector<HashPair<T>*> table;

public:
    HashSet() {
        table.resize(M);
    }

    unsigned int hash(int v) {
        return ((unsigned int)v ^ M) % M;
    }

    bool exists(int v) {
        HashPair<T>* node = table[hash(v)];
        while (node != nullptr) {
            if (node->date == v) {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    void insert(int v) {
        if (exists(v)) {
            return;
        }
        int h = hash(v);
        auto* t = new HashPair<T>(v, table[h]);
        table[h] = t;
    }

    void remove(int v) {
        int h = hash(v);
        HashPair<T>* node = table[h];
        HashPair<T>* p_node = nullptr;
        while (node != nullptr) {
            if (node-> date == v) {
                if (p_node == nullptr) {
                    table[h] = node->next;
                }
                else {
                    p_node->next = node->next;
                    node->next = nullptr;
                }
            }
            p_node = node;
            node = node->next;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    // ====================== */

    HashSet<int> a;

    while (!cin.eof()) {
        string t;
        cin >> t;

        int k;
        cin >> k;

        if (t == "insert") {
            a.insert(k);
        }

        if (t == "delete") {
            a.remove(k);
        }
        if (t == "exists") {
            cout << (a.exists(k) ? "true" : "false") << "\n";
        }
    }


    return 0;
}