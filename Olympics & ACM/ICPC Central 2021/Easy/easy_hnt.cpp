#include <bits/stdc++.h>

#define N 1005

using namespace std;

int n;
int a[N];

int main() {
    cin >> n;
    int cnt_neg = 0;
    int cnt_zero = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt_neg += a[i] < 0;
        cnt_zero += a[i] == 0;
    }
    if (cnt_neg & 1) {
        if (cnt_zero) {
            cout << 0;
        } else {
            int p = 0;
            a[0] = -1e9 + 1;
            for (int i = 1; i <= n; i++) {
                if (a[i] < 0 && a[p] < a[i]) {
                    p = i;
                }
            }
            int res = 1;
            for (int i = 1; i <= n; i++) {
                if (i != p) {
                    res = 1LL * res * a[i] % 1000000007;
                }
            }
            cout << res;
        }
    } else {
        if (cnt_zero > 1) {
            cout << 0;
        } else {
            for (int i = 1; i <= n; i++) {
                a[i] = abs(a[i]);
            }
            sort(a + 1, a + n + 1);
            int res = 1;
            for (int i = cnt_zero + 1; i <= n; i++) {
                res = 1LL * res * a[i] % 1000000007;
            }
            cout << res;
        }
        
    }
}