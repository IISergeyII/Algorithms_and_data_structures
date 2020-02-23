#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;


int main() {

    //---------------------------------------------
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    //--------------------------------------------- /*/

    int n;
    bool f1 = true;
    cin >> n;

    int* a = new int[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (2*i <= n) {
            if (a[i] > a[2*i]) {
                f1 = false;
                //cout << "!! " << i << " 1!!\n";
            }
        }
        if (2*i + 1 <= n) {
            if (a[i] > a[2*i + 1]) {
                f1 = false;
                //cout << "!! " << i << " 2!!\n";
            }
        }
    }

    //cout << f1 << "\n";
    if (f1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}
