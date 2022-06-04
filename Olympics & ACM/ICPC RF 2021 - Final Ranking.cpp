#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,k;
const ll m=1e9 +7 ;
ll exp(ll a, ll b){
	ll res =1;
	while(b){
		if(b&1){
			res=(res*a)%m;
		}
		b>>=1;
		a=(a*a)%m;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
    cout<<(n+1-k)*exp(2,k-1)%m;
    // du cho co k, k+1 hay k+2 (tinh tien den n) doi duoc huy chuong thi van se co 2^(n-1) cach sap xep cho bxh
    return 0;
}