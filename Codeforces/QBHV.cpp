#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string a;
void xuly() {
	cin>>a;
	ll leng = a.length();
	sort(a.begin(),a.end());
	string res;
	int count=0;
	do {
		count++;
		res+=a;
		res+='\n';
	} while(next_permutation(a.begin(),a.end()));
	cout<<count<<'\n';
	cout<<res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	xuly();
}