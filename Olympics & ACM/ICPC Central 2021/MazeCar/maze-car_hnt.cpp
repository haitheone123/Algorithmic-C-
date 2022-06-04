#include <bits/stdc++.h>

#define SZ 100
#define MOD 1000000007

using namespace std;

int n, m, t;
string maze[SZ];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char ch[] = {'D', 'L', 'U', 'R'};

vector<vector<int>> mult(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> C(n * m, vector<int>(n * m));
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < n * m; j++) {
            for (int k = 0; k < n * m; k++) {
                C[i][j] += 1LL * A[i][k] * B[k][j] % MOD;
                if (C[i][j] >= MOD) {
                    C[i][j] -= MOD;
                }
            }
        }
    }
    return C;
}

int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    vector<vector<int>> base(n * m, vector<int>(n * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] != '#') {
                for (int h = 0; h < 4; h++) {
                    if (ch[h] == maze[i][j] || maze[i][j] == '+') {
                        int x = i + dx[h];
                        int y = j + dy[h];
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            base[i * m + j][x * m + y] = (maze[x][y] != '#');
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> res(n * m, vector<int>(n * m));
    for (int i = 0; i < n * m; i++) {
        res[i][i] = 1;
    }
    while (t) {
        if (t & 1) {
            res = mult(res, base);
        }
        base = mult(base, base);
        t >>= 1;
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < n * m; j++) {
            ans += res[i][j];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    cout << ans;
}