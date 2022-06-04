//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int n;
int a[111], b[111];
int main()
{
	srand(2020010935);
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		scanf("%d", &n);
		ll sum = 0;
		for (int i=1; i<=n; i++) {
			a[i] = i==1 ? 1 : min(1000000000, a[i-1] * 2);
		}
		for (int i=n; i>=1; i--) {
			if (a[i] == 1000000000) {
				a[i] = a[i] - (n-i);
			}
		}
		for (int i=1; i<=n; i++) {
			sum += a[i];
		}
		for (int i=1; i<=n; i++) printf("%d%c", a[i], " \n"[i==n]);
		fflush(stdout);
		for (int i=1; i<=n; i++) {
			scanf("%d", &b[i]);
			sum += b[i];
		}
		sum = sum / 2;
		vector<int> ans;
		for (int i=1; i<=n; i++) {
			if (sum >= b[i]) {
				ans.PB(b[i]);
				sum -= b[i];
			}
		}
		for (int i=n; i>=1; i--) {
			if (sum >= a[i]) {
				ans.PB(a[i]);
				sum -= a[i];
			}
		}
		for (int i=0; i<ans.size(); i++) {
			printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
		}
		fflush(stdout);
	}
	return 0;
}