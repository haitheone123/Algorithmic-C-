#include <bits/stdc++.h>

using namespace std;
int n;
long long a, b;
long long res = 1e18;
long long x, y, r;
long long kc;
int main() {
	//freopen("cow.inp","r",stdin);
	//freopen("cow.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y >> r;
		res = min(res,(long long)ceil(sqrt((a-x)*(a-x)+(b-y)*(b-y)))-1-r);
	}
	cout << res;
	return 0;
}