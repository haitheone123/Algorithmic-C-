#include <bits/stdc++.h>
#define N 100005
using namespace std;
const long long MOD = 1e9 + 7;
int n, q, c, l, r;
long long x, a[N];
struct Matrix {
    long long c[2][2] = {0, 1, 1, 1};
};
Matrix operator*(Matrix a, Matrix b) {
    Matrix res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.c[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res.c[i][j] += a.c[i][k] * b.c[k][j] % MOD;
            }
            res.c[i][j] %= MOD;
        }
    }
    return res;
}
 
Matrix exp(long long n) {
    Matrix res = {1, 0, 0, 1};
    Matrix a;
    while (n) {
        if (n & 1) res = a * res;
        n >>= 1;
        a = a * a;
    }
    return res;
}
 
struct Node {
    long long sum1 = 1, sum2 = 1;
    Matrix lazy = {1,0,0,1};
} ST[4 * N];
 
void down(int id, int l, int r) {
    Matrix tmp = ST[id].lazy;
 
    long long t1 = ST[id << 1].sum1;
    ST[id << 1].sum1 = (t1 * tmp.c[0][0] + ST[id << 1].sum2 * tmp.c[0][1]) % MOD;
    ST[id << 1].sum2 = (t1 * tmp.c[1][0] + ST[id << 1].sum2 * tmp.c[1][1]) % MOD;
    ST[id << 1].lazy = ST[id << 1].lazy*tmp;
 
    long long t2 = ST[id << 1 | 1].sum1;
    ST[id << 1 | 1].sum1 = (t2 * tmp.c[0][0] + ST[id << 1 | 1].sum2 * tmp.c[0][1]) % MOD;
    ST[id << 1 | 1].sum2 = (t2 * tmp.c[1][0] + ST[id << 1 | 1].sum2 * tmp.c[1][1]) % MOD;
    ST[id << 1 | 1].lazy = ST[id << 1 | 1].lazy*tmp;
 
    ST[id].lazy = {1, 0, 0, 1};
}
 
void update(int id, int l, int r, int u, int v, Matrix y) {
    if (u > r || v < l) {
        return;
    }
    if (u <= l && v >= r) {
        long long t = ST[id].sum1;
        ST[id].sum1 = (t * y.c[0][0] + ST[id].sum2 * y.c[0][1]) % MOD;
        ST[id].sum2 = (t * y.c[1][0] + ST[id].sum2 * y.c[1][1]) % MOD;
        ST[id].lazy = ST[id].lazy*y;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    update(id << 1, l, mid, u, v, y);
    update(id << 1 | 1, mid + 1, r, u, v, y);
    ST[id].sum1 = (ST[id << 1].sum1 + ST[id << 1 | 1].sum1) % MOD;
    ST[id].sum2 = (ST[id << 1].sum2 + ST[id << 1 | 1].sum2) % MOD;
}
 
long long get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return 0ll;
    }
    if (u <= l && v >= r) {
        return ST[id].sum1;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    return (get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v)) % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        update(1, 1, n, i, i, exp(x-1));
    }
    while (q--) {
        cin >> c >> l >> r;
        if (c == 1) {
            cin >> x;
            update(1, 1, n, l, r, exp(x));
        } else {
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}