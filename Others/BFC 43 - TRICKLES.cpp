#include <bits/stdc++.h>

using namespace std;

#define cnt(a) CNT[a]
#define f(a, b) F[a][b]

const int maxn = 2e5 + 5;
const int mode = 1e9 + 7;

int n, m;
int arr[maxn], CNT[5005];
long long F[5005][5];

int power(int a, long long b) {
    if (b == 0)
        return 1;
    int ans = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1)
            ans = 1ll * ans * a % mode;
        a = 1ll * a * a % mode;
    }
    return ans;
}

void xuly(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i], cnt(arr[i])++;

    sort(arr + 1, arr + n + 1);
    n = unique(arr + 1, arr + n + 1) - arr - 1;

    int lim = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            lim = max(lim, arr[i] + arr[j]);

    f(0, 0) = 1;
    int ans = 0;
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        for (int s = arr[i] + 1; s <= lim; ++s) {
            int d = 3 * s + 5 * arr[i];
            if ((d % 3 == 0 || d % 5 == 0 || d % 8 == 0) && f(s, 2)) {
                long long mu = 1ll * f(s, 2) * cnt(arr[i]);
                ans = 1;
                res = 1ll * res * power(s - arr[i], mu) % mode;
            }
        }
        for (int s = lim; s >= arr[i]; --s)
            f(s, 2) = f(s, 2) + 1ll * f(s - arr[i], 1) * cnt(arr[i]);
        f(arr[i], 1) = cnt(arr[i]);
    }

    if (ans == 0)
        res = 0;
    cout << res << '\n';
   
}

int main() {
    xuly();
   
}