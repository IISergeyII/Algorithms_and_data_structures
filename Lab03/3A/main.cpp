#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;


int l_bin_search(int* a, int n,  int key) {
    int l = -1;
    int r = n;

    if (key < a[0] || key > a[n-1]) return -1;

    while (l < r - 1) {
        int m = (l + r) / 2;
        if (key > a[m])
            l = m;
        else
            r = m;
    }

    if (a[r] == key)
        return r;

    return -1;
}


int r_bin_search(int* a, int n,  int key) {
    int l = -1;
    int r = n;

    if (key < a[0] || key > a[n-1]) return -1;

    while (l < r - 1) {
        int m = (l + r) / 2;
        if (key >= a[m])
            l = m;
        else
            r = m;
    }

    if (a[r - 1] == key)
        return r;

    return -1;
}


int main() {

    //---------------------------------------------
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    //--------------------------------------------- /*/

    int n, m, t;

    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;


    int r_s, l_s;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        r_s = r_bin_search(a, n, t);
        l_s = l_bin_search(a, n, t);

        if (l_s != -1 && r_s != -1)
            cout << l_s + 1 << " " << r_s;
        else
            cout << "-1 -1";
        cout << "\n";
    }


}
