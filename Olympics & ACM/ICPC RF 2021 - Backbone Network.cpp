#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    (cout<<fixed).precision(6);
    cout<<(n-1)*(n-2)/2<<endl;
    (cout<<fixed).precision(0);
    for(int i=2;i<=n;i++){
    	cout<<1<<" "<<i<<endl;
	}
}