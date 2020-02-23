#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

void find_k(int* a, int l, int r, int k) {

    int key = a[(l + r) / 2];
    int it1 = l;
    int it2 = r;
    while (it1 <= it2) {
        while (a[it1] < key)
            it1++;
        while (a[it2] > key)
            it2--;
        if (it1 <= it2) {
            swap(a[it1], a[it2]);
            it1++;
            it2--;
        }
    }

    if (l <= it2 && k <= it2) find_k(a, l, it2, k);
    if (it1 <= r && k >= it1) find_k(a, it1, r, k);


}

int main() {

    //---------------------------------------------
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    //--------------------------------------------- /*/

    int n, k, A, B, C;
    cin >> n >> k;
    int* a = new int[n];

    cin >> A >> B >> C >> a[0] >> a[1];


    for (int i = 2; i < n; ++i) {
        a[i] = A * a[i-2] + B * a[i-1] + C;
    }

    find_k(a, 0, n-1, k-1);
    cout << a[k-1];

}
