#include <bits/stdc++.h>

#define N 500005

using namespace std;

char s[N];
int ps[N];
int k;

int main() {
    gets(s);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        ps[x] += n;
        ps[y + 1] -= n;
    }
    int n = strlen(s);
    for (int i = 1; i <= n; i++) {
        ps[i] += ps[i - 1];
        s[i - 1] = ((s[i - 1] - 'A') + ps[i]) % 26 + 'A';
    }
    puts(s);
}