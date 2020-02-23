#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

const int M = 1000;

struct Dot {
    int x, y;
};

int n, m;
int field[M][M];
bool used[M][M];
Dot p[M][M];
char p_c[M][M];



void bfs (Dot u) {
    used[u.x][u.y] = true;
    queue<Dot> q;
    q.push(u);

    while (!q.empty()) {
        int x, y;
        Dot u_t = q.front();
        x = u_t.x;
        y = u_t.y;
        q.pop();

        Dot U, D, R, L;
        U.x = x - 1; U.y = y;
        D.x = x + 1; D.y = y;
        R.x = x; R.y = y + 1;
        L.x = x; L.y = y - 1;

        if (field[U.x][U.y] == 0 && !used[U.x][U.y]) {
            used[U.x][U.y] = true;
            p[U.x][U.y] = u_t;
            p_c[U.x][U.y] = 'U';
            q.push(U);
        }
        if (field[D.x][D.y] == 0 && !used[D.x][D.y]) {
            used[D.x][D.y] = true;
            p[D.x][D.y] = u_t;
            p_c[D.x][D.y] = 'D';
            q.push(D);
        }

        if (field[R.x][R.y] == 0 && !used[R.x][R.y]) {
            used[R.x][R.y] = true;
            p[R.x][R.y] = u_t;
            p_c[R.x][R.y] = 'R';
            q.push(R);
        }
        if (field[L.x][L.y] == 0 && !used[L.x][L.y]) {
            used[L.x][L.y] = true;
            p[L.x][L.y] = u_t;
            p_c[L.x][L.y] = 'L';
            q.push(L);
        }


    }

}


int main() {
    ios_base::sync_with_stdio(false);
    // ======================
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    // ====================== */

    // ======================
//    freopen("pathbge1.in ", "r", stdin);
//    freopen("pathbge1.out ", "w", stdout);
    // ====================== */



    cin >> n >> m;
    char in_d;

    // . - 0
    // # - 1
    Dot S, T;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            used[i][j] = false;
            p_c[i][j] = 'N';
            field[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            used[i][j] = false;
            cin >> in_d;
            if (in_d == '.') {
                field[i][j] = 0;
            } else if (in_d == '#') {
                field[i][j] = 1;
            } else if (in_d == 'S') {
                S.x = i;
                S.y = j;
                field[i][j] = 0;
            } else {
                T.x = i;
                T.y = j;
                field[i][j] = 0;
            }
        }
    }



    bfs(S);


    /*
    cout << "Field\n";
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    cout << "Used\n";
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            cout << used[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    cout << "Parents\n";
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            cout << p[i][j].x << "," << p[i][j].y << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    */

    if (p_c[T.x][T.y] == 'N') {
        cout << "-1";
        return 0;
    }



    int K = 0;
    char ANS[1000*100];

    Dot cur = T, t;
    while ((cur.x != S.x) || (cur.y != S.y)) {
        // cout << p_c[cur.x][cur.y]; //<< " cur.x = " << cur.x << " cur.y = " << cur.y << "\n";

        ANS[K] = p_c[cur.x][cur.y];
        K++;


        t.x = cur.x;
        t.y = cur.y;
        cur.x = p[t.x][t.y].x;
        cur.y = p[t.x][t.y].y;
    }



    cout << K << "\n";
    for (int i = K - 1; i >= 0; --i) {
        cout << ANS[i];
    }

    //cout << "!" << p[2][4].x << " " << p[2][4].y << "\n";

    // cout << p_c[cur.x][cur.y];

    // cout << "\n" << S.x << " " << S.y;
    // cout << "\n" << cur.x << " " << cur.y;


    return 0;
}