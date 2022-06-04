#include <bits/stdc++.h>

using namespace std;

int ccw(pair<long long, long long> a, pair<long long, long long> b) {
    long long d = a.first * b.second - a.second * b.first;
    if (d < 0) {
        return -1;
    } else {
        return d > 0 ? 1 : 0;
    }
}

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    pair<long long, long long> ab = {b.first - a.first, b.second - a.second};
    pair<long long, long long> ac = {c.first - a.first, c.second - a.second};
    pair<long long, long long> ad = {d.first - a.first, d.second - a.second};
    return ccw(ab, ac) * ccw(ab, ad) > 0;
}

void solve() {
    int x[4], y[4];
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        pair<int, int> a = {x[i], y[i]};
        for (int j = i + 1; j < 4; j++) {
            pair<int, int> b = {x[j], y[j]};
            for (int u = 0; u < 3; u++) {
                if (u != i && u != j) {
                    pair<int, int> c = {x[u], y[u]};
                    for (int v = u + 1; v < 4; v++) {
                        if (v != i && v != j && v != u) {
                            pair<int, int> d = {x[v], y[v]};
                            cnt += check(a, b, c, d);
                        }
                    }
                }
            }
        }
    }
    if (cnt == 4) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}