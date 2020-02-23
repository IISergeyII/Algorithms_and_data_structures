#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

const int M = 1000*1000;

int n, m;
vector<int> g[M];
bool used[M];
int dist[M];

void bfs (int u) {
    used[u] = true;
    queue<int> q;
    q.push(u);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (!used[v]) {
                used[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
//    // ======================
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    // ====================== */

    // ======================
    freopen("pathbge1.in ", "r", stdin);
    freopen("pathbge1.out ", "w", stdout);
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
        dist[i] = 0;
    }

    bfs(0);

    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }


    return 0;
}