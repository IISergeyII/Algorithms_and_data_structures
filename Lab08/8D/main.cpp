#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int M = 1000*1000;

int n, m;
vector<int> g[M];
vector<int> comp[M];
bool used[M];

int I = 0;

void dfs (int v) {
    used[v] = true;
    comp[I].push_back(v);
    //cout << "!" << I << " ";
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
//    // ======================
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    // ====================== */

    // ======================
    freopen("components.in ", "r", stdin);
    freopen("components.out ", "w", stdout);
    // ====================== */


    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    for (int i = 0; i < M; ++i) {
        used[i] = false;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);

//            for (size_t j = 0; j < comp[I].size(); ++j) {
//                cout << " " << comp[I][j] << " ";
//            }
//            cout << "\n";
            I++;
        }

    }


    int res[n+1];

    for (size_t i = 0; i < I; ++i) {
        for (size_t j = 0; j < comp[i].size(); ++j) {
            //cout << comp[i][j] << " ";
            res[ comp[i][j] ] = i;
        }
        //cout << "\n";
    }

    cout << I << "\n";
    for (size_t i = 0; i < n; ++i) {
        cout << res[i] + 1 << " ";
    }

    return 0;
}