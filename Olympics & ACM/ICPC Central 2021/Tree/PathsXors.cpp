#include <bits/stdc++.h>

#define N 250005

using namespace std;

int n, m;
int a[N], b[N];

int cnt = 1;
int parent[N], sign[N], rnk[N], pw[N];
vector<pair<int&, int>> steps;

int get_root(int u) {
    return parent[u] != u ? get_root(parent[u]) : u;
}

int get_sign(int u) {
    return parent[u] != u ? sign[u] ^ get_sign(parent[u]) : sign[u];
}

bool add_edge(int u, int v, int b) {
    int ru = get_root(u);
    int rv = get_root(v);
    if (ru != rv) {
        if (rnk[ru] < rnk[rv]) {
            swap(ru, rv);
            swap(u, v);
        }
        if ((get_sign(u) ^ get_sign(v)) != b) {
            steps.push_back({sign[rv], sign[rv]});
            sign[rv] ^= 1;   
        }
        steps.push_back({parent[rv], parent[rv]});
        steps.push_back({rnk[ru], rnk[ru]});
        rnk[ru] += rnk[rv];
        parent[rv] = ru;
    } else {
        if ((get_sign(u) ^ get_sign(v)) != b) {
            return false;
        }
    }
    return true;
}

void undo(int moment) {
    while (steps.size() > moment) {
        steps.back().first = steps.back().second;
        steps.pop_back();
    }
}

void solve(int l, int r) {
    if (l == r) {
        int moment = steps.size();
        if (add_edge(a[l], b[l], 1)) {
            cnt++;
        }
        undo(moment);
    } else {
        int mid = (l + r) >> 1;
        int moment = steps.size();
        bool ok = true;
        for (int i = mid + 1; i <= r; i++) {
            if (!add_edge(a[i], b[i], 1)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            solve(l, mid);
        }
        undo(moment);
        ok = true;
        for (int i = l; i <= mid; i++) {
            if (!add_edge(a[i], b[i], 0)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            solve(mid + 1, r);
        }
        undo(moment);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
    }    
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] << 1;
        if (pw[i] >= 998244353) {
            pw[i] -= 998244353;
        }
        parent[i] = i;
        rnk[i] = 1;
    }
    solve(1, m);
    int num = n;
    for (int i = 1; i <= m; i++) {
        if (get_root(a[i]) != get_root(b[i])) {
            add_edge(a[i], b[i], 0);
            num--;
        }
    }
    // cout << cnt << " " << num << "\n";
    cout << (1LL * cnt * pw[num - 1] % 998244353);
}