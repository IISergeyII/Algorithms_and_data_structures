#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Сортировка вставками
    freopen("smallsort.in", "r", stdin);
	freopen("smallsort.out", "w", stdout);

	int n, key, j;
	cin >> n;
	int a[n];



	for (int i = 0; i < n; ++i) {
        cin >> a[i];
	}

	for (int i = 1; i < n; ++i) {
        key = a[i];
        j = i;

        while (j > 0 && a[j-1] > key) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = key;
	}

	for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
	}

    return 0;
}
