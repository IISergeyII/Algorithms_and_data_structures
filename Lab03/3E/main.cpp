#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

void countSort(vector<string> &a, int n, int digit) {
    vector<int> count( (unsigned int) 'z' + 1);

    for (int i = 0; i < n; ++i) {
        count[a[i][digit]]++;
    }

    int index, t;
    index = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        t = count[i];
        count[i] = index;
        index += t;
    }

    vector<string> b(n);

    for (int i = 0; i < n; ++i) {
        char x = a[i][digit];
        b[count[x]] = a[i];
        count[x]++;
    }

    a = b;
}

void radixSort(vector<string> &a, int m, int k) {
    for (int i = 1; i <= k; ++i) {
        countSort(a, a.size(), m - i);
    }
}

int main() {

    //---------------------------------------------
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    //--------------------------------------------- /*/

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    radixSort(a, m, k);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }

}
