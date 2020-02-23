#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

struct cNode {
    int date;
    cNode *next;
};

void s_push(cNode **top, int d) {

    cNode *q;
    q = new cNode();
    q->date = d;
    if (top == NULL) {
        *top = q;
    }
    else {
        q->next = *top;
        *top = q;
    }
}

int s_delete(cNode **top) {
    cNode *q = *top;
    int d = q->date;

    (*top) = q->next;
    free(q);

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    // ====================== */

    int n, t;
    char com;
    cin >> n;

    cNode *top = NULL;

    for (int i = 0; i < n; ++i) {
        cin >> com;
        if (com == '+') {
            cin >> t;
            s_push(&top, t);
        } else {
            t = s_delete(&top);
            cout << t << "\n";
        }
    }


    return 0;
}