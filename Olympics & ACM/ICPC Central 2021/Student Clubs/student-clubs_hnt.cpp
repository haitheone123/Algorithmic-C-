#include <bits/stdc++.h>

#define N 100005
#define MOD 1000000007

using namespace std;

int n, m;
vector<int> g[N];
int f[N];
int mark[N];
int cnt;

void dfs(int u) {
    cnt++;
    mark[u] = 1;
    for (auto v : g[u]) {
        if (mark[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1LL * i * f[i - 1] % MOD;
    }    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            cnt = 0;
            dfs(i);
            if (cnt > 2) {
                ans += f[cnt];
                if (ans >= MOD) {
                    ans -= MOD;
                }
            }
        }
    }
    cout << ans;
}