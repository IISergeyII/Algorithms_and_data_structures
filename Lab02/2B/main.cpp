#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>


using namespace std;

void mergeSort(vector< pair<string, string> > &a, size_t start, size_t end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (a[start].first > a[start + 1].first)
            swap(a[start], a[start + 1]);
        return;
    }

    mergeSort(a, start, start + (end - start) / 2);
    mergeSort(a, start + (end - start) / 2, end);
    vector< pair<string, string> > b;
    size_t b1 = start;
    size_t e1 = start + (end - start) / 2;
    size_t b2 = e1;
    while (b.size() < end - start)
    {
        if (b1 >= e1 || (b2 < end && a[b2].first < a[b1].first ))
        {
            b.push_back(a[b2]);
            ++b2;
        }
        else
        {
            b.push_back(a[b1]);
            ++b1;
        }
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b[i - start];
}

int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int n;
    string c_t, n_t; // temporary variables
    vector< pair<string, string> > v;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c_t >> n_t;
        v.push_back(make_pair(c_t, n_t));
    }


    mergeSort(v, 0, v.size());

    //cout << "------------------------------------------\n";

    string sN = ""; // temp country name
    for (int i = 0; i < n; ++i) {
        if (v[i].first != sN)
        {
            sN = v[i].first;
            cout << "=== " << sN << " ===\n";
        }

        cout << v[i].second << "\n";
    }


}
