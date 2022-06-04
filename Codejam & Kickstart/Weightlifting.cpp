#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int n, m;
int a[111][111];
int cost[111][111];
int dp[111][111];
int main()
{
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				scanf("%d", &a[i][j]);
				ans += a[i][j] * 2;
			}
		}
		for (int i=1; i<=n; i++) {
			int tmp[111];
			for (int j=1; j<=m; j++) tmp[j] = a[i][j];
			for (int j=i; j<=n; j++) {
				for (int k=1; k<=m; k++) {
					tmp[k] = min(tmp[k], a[j][k]);
				}
				int sum = 0;
				for (int k=1; k<=m; k++) {
					sum += tmp[k];
				}
				cost[i][j] = sum;
			}
		}
		memset(dp, 20, sizeof(dp));
		for (int i=n; i>=1; i--) {
			dp[i][i] = 0;
			for (int j=i+1; j<=n; j++) {
				for (int k=i; k<j; k++) {
					dp[i][j] = min(dp[i][j], (cost[i][k] + cost[k+1][j] - 2 * cost[i][j]) * 2 + dp[i][k] + dp[k+1][j]);
				}
			}
		}
		printf("Case #%d: %d\n", t, cost[1][n] * 2 + dp[1][n]);
	}
	return 0;
}