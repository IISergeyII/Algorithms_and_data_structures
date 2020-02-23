#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long cnt = 0;

void merge(vector<int> &a, int l, int m, int r) {
	vector<int> b;
	int i, j;
	i = l;
	j = m + 1;

	while (i <= m && j <= r) {
		if (a[i] <= a[j]) {
			b.emplace_back(a[i++]);
		}
		else {
			b.emplace_back(a[j++]);
			cnt += m - i + 1;
		}
	}

	while (i <= m) {
		b.emplace_back(a[i++]);
	}
	while (j <= r) {
		b.emplace_back(a[j++]);
	}

	/*for (auto &t : b) {
		a[l++] = t;
	}*/
	for (int k = l; k <= r; ++k) {
		a[k] = b[k - l];
	}

}

void mergeSort(vector<int> &a, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;

		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}

}


int main() {

#ifdef ITMO
	ifstream fin("a.in");
	ofstream fout("a.out");
#else
	string task_name = "inversions";
	ifstream fin(task_name + ".in");
	ofstream fout(task_name + ".out");
#endif



	int n, t;
	vector<int> v;

	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> t;
		v.emplace_back(t);
	}

	mergeSort(v, 0, n - 1);

	/*for (int i = 0; i < n; ++i) {
		fout << v[i] << " ";
	}*/

	fout << cnt;
}