#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int P = 1000 * 100;
const double E = 0.000001;

int n;
double ind[P], acc[P];

int find_ind(double v){
    for (int i = 0; i < n; ++i) {
        if (abs(v - ind[i]) < E) {
            return i;
        }
	}
}

int main()
{
	freopen("sortland.in", "r", stdin);
	freopen("sortland.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> acc[i];
		ind[i] = acc[i];
	}


	// ***Intersection sort***
	double t;
	int j;
	for (int i = 1; i < n; ++i) {
		t = acc[i];
		j = i;

		while (j > 0 && acc[j - 1] > t) {
			acc[j] = acc[j - 1];
			j--;
		}
		acc[j] = t;
	}
	// *** ***

	/*__________________________________________

	for (int i = 0; i < n; ++i) {
        cout << acc[i] << " ";
	}
	cout << "\n";

	//__________________________________________ */
	double min_v = acc[0];
	double mid_v = acc[n/2];
	double max_v = acc[n-1];

	cout << find_ind(min_v) + 1 << " ";
	cout << find_ind(mid_v) + 1 << " ";
	cout << find_ind(max_v) + 1 << " ";

	return 0;
}

