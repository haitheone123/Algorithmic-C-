#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int,int> pa;
const long long mod =14062008;
const long long oo=1e15+7;
const int maxn=1e6+1;
const int maxN=1e3+1;

int n,k;
int a[maxn];
int kt[maxn];
int dp[maxn];


void solve() {
	cin>>n>>k;
	for(int i=1; i<=k; i++) {
		cin>>a[i];
		kt[a[i]]=1;
	}
	dp[0]=0;
	dp[1]=1;
	for(int i=2; i<=n; i++) {
		if(kt[i]==1) {
			dp[i]=0;
			continue;
		}
		dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
	}
	cout<<dp[n];


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();

}