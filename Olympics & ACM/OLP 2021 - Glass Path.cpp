#include<bits/stdc++.h>
const long long mod = 1e9 + 7 ;
using namespace std;
void xuly() {
	string x,y;	
	long long t;
	cin>>t;
	while(t--) {
		long long ans = 1;
		cin>>x;
		cin>>y;
		for(int i=0; i<int(x.length()); i++) {
			if(x[i]=='O'&&y[i]=='O') {
				ans=0;
				break;
			} else if (x[i]=='X'&&y[i]=='X') {
				ans=ans*2;
				ans%=mod;
			} else if ((x[i]=='X'&&y[i]=='O')||((y[i]=='X'&&x[i]=='O'))) {
				continue;
			}
		}
		cout<<ans%(mod)<<endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	xuly();
}