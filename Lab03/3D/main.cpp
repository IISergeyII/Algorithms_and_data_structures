#include <iostream>
#include <vector>

using namespace std;

template <class ArrElements>
class BinaryHeapSort {

public:

    static void buildHeap(ArrElements* a, size_t n) {
        for (int i = n/2; i >= 0; --i) {
            siftDown(a, n, i);
        }
    }

    static void siftDown(ArrElements* a, size_t n, int i) {
        int left, right, j;

        while (2*i + 1 < n) {
            left = 2*i + 1;
            right = 2*i + 2;

            j = left;
            if (right < n && a[right] > a[left])
                j = right;
            if (a[i] >= a[j])
                break;
            swap(&a[i], &a[j]);
            i = j;
        }
    }

    static void swap(ArrElements *a, ArrElements *b) {
        ArrElements tmp = *a;
        *a = *b;
        *b = tmp;
    }





    static void heapSort(ArrElements* a, size_t n) {

        buildHeap(a, n);

        size_t heapSize = n;
        for (size_t i = 0; i < n-1; ++i) {
            swap(&a[0], &a[n - 1 - i]);
            heapSize--;
            siftDown(a, heapSize, 0);
        }
    }


};




int main() {

    //---------------------------------------------
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    //--------------------------------------------- /*/

    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    BinaryHeapSort<long long>::heapSort(a, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}