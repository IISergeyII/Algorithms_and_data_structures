#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

vector<int> a;
vector<int> p;
int n = 0;
int min_t = 0;

int parentIndex(int i) {
    return (i - 1) / 2;
}

int parent(int* a, int i) {
    return a[parentIndex(i)];
}

int left_child_index(int i) {
    return 2 * i + 1;
}

int right_child_index(int i) {
    return 2 * i + 2;
}

int find(int k) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == k) {
            return i;
        }
    }
    return -1;
}

void sift_down(int i) {
    int x = i;
    if ((left_child_index(i) < n) && (a[left_child_index(i)] < a[i])) {
        x = left_child_index(i);
    }
    if ((right_child_index(i) < n) && a[right_child_index(i)] < a[x]) {
        x = right_child_index(i);
    }
    if (x != i) {
        swap(a[i], a[x]);
        swap(p[i], p[x]);
        sift_down(x);
    }
}

void sift_up(int i) {
    while (a[i] < a[parentIndex(i)]) {
        swap(a[i], a[parentIndex(i)]);
        swap(p[i], p[parentIndex(i)]);
        i = parentIndex(i);
    }
}

bool extract_min() {
    if (a.empty()) {
        return false;
    }

    // cout << a[0];
    min_t = a[0];

    swap(a[0], a[n - 1]);
    swap(p[0], p[n - 1]);


    a.pop_back();
    p.pop_back();
    n--;

    sift_down(0);

    return true;
}

void push(int v, int priority) {
    a.push_back(v);
    p.push_back(priority);
    // cout << a[0];
    n++;
    sift_up(n - 1);
}

void decrease_key(int k, int v) {
    int i = find(k);
    a[i] = v;
    sift_up(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    // ====================== */

    string t;
    int priority = -1;

    while (cin >> t) {
        priority++;

        if (t == "push") {
            int k;
            cin >> k;

            push(k, priority);
        }

        if (t == "extract-min") {
            if (extract_min()) {
                cout << min_t << "\n";
            }
            else {
                cout << "*" << "\n";
            }
        }

        if (t == "decrease-key") {
            int k, m;
            cin >> k >> m;
            decrease_key(k - 1, m);
        }
    }



    return 0;
}