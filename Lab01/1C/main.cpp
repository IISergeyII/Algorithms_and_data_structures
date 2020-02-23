#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	freopen("turtle.in", "r", stdin);
	freopen("turtle.out", "w", stdout);

	int h, w;
	cin >> h >> w;

	int a[h+2][w+2];
	for (int i = 0; i < h+2; ++i) {
        for (int j = 0; j < w+2; ++j) {
            a[i][j] = 0;
        }
	}
	for (int i = 1; i < h+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            cin >> a[i][j];
        }
	}



	for (int i = h; i > 0; --i) {
        for (int j = 1; j < w+1; ++j) {
            a[i][j] += max(a[i+1][j], a[i][j-1]);
        }
	}

	/* *********************************
	for (int i = 0; i < h+2; ++i) {
            cout << endl;
        for (int j = 0; j < w+2; ++j) {
            cout << a[i][j] << " ";
        }

	}
	cout << "\n\n";
	//********************************** */

	cout << a[1][w];

	return 0;
}

