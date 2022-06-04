#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll l,r,a,k;
void xuly () {
	cin>>l>>r>>a>>k;
	ll divisor = k/__gcd(a,k);
	ll ans1 = ceil(l/divisor)-1;
	ll ans2 = ceil(r/divisor)-1;
	cout<<ans2-ans1<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	xuly();
}