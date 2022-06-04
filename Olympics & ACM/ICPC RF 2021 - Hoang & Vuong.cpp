#include<bits/stdc++.h>
using namespace std;
int t,n,x[100],y[100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		for(int i=0; i<=n; i++) {
			cin>>x[i]>>y[i];
		}
		if(n&1) {
			cout<<"Hoang"<<endl;
		} else {
			cout<<"Vuong"<<endl;
		}
	}
	return 0;
}