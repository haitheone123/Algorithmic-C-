#include<bits/stdc++.h>
using namespace std;
int n,a;
map<int,int>mp;
set<int>s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	s.clear();
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a;
		mp[a]++;
		if(mp[a]==1) {
			s.insert(a);
		} else {
			s.erase(a);
		}
		if(!s.size()) {
			cout<<-1<<endl;
		} else {
			cout<<*s.begin()<<endl;
		}
	}
}