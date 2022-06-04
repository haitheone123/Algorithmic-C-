#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("copper.inp", "r", stdin);
    freopen("copper.out", "w", stdout);
    int n;
	cin >> n;
	vector<long double> a(n);{
		for (auto& x : a) cin >> x;
	}
	vector<long double> s(n);{
		s[0] = a[0];
		for (int i = 1; i < n; ++i) s[i] = (s[i-1] + a[i]);
	}
	auto mean = [&](int L, int H){
		return (s[H] - (L ? s[L-1] : 0.0)) / (H-L+1);
	};
	vector<int> f(n);{
		for (int i = 0; i < n; ++i){
			int& j = f[i] = i;
			while (j && mean(j, i) < mean(f[j-1], j-1)) j = f[j-1];
		}
	}
	vector<long double> b(n);{
		for (int i = n-1; i >= 0; ){
			int j = f[i];
			b[i] = mean(j, i);
			for (int t = j; t < i; ++t) b[t] = b[i];
			i = j-1;
		}
	}
	long double ans = 0;
	for (int i = 0; i < n; ++i) ans += (a[i]-b[i]) * (a[i]-b[i]);
	ans = sqrt(ans);
	// cout << setprecision(20) << ans;
    printf("%.10Lf", ans);
 
	return 0;
}