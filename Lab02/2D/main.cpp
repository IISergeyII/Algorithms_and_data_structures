#include <iostream>
#include <vector>
#include <fstream>

#define pb push_back

using namespace std;

/*
const int N = 4;
int a[N+1];

int cnt = 0;

void QSort(int left, int right) {
    int i, j, key, buf;
    key = a[(left + right) / 2];
    i = left;
    j = right;
    while (i <= j) {
        while ( (++cnt) && a[i] < key )
            i++;
        while ( (++cnt) && a[j] > key )
            j--;

        if (i <= j) {
            buf = a[i];
            a[i] = a[j];
            a[j] = buf;
            i++;
            j--;
        }

        if (left < j)
            QSort(left, j);
        if (i < right)
            QSort(i, right);
    }
}
*/

int main() {

    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);

    int n;
    int a[100*1000];

    cin >> n;

    for (int i = 1; i <= n; ++i)
        a[i] = i;

    for (int i = 3; i <= n; ++i) {
        swap(a[i], a[(i+1)/2]);
    }

    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";



    /*
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    QSort(1, N);

    cout << "Sorted:\n";
    for (int i = 1; i <= N; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

    cout << "cnt = " << cnt;*/

}
