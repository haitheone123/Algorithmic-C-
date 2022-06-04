#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, c;
stack<ll> cars;

void xuly() {

	for(;;) {
		while(cars.size() > 0) cars.pop();
		ll j = 0;
		for(ll i = 0; i < N; i++) {
			cin>>c;
			if(c == 0) return;

			while(j < N && j != c) {
				if(cars.size() > 0 && cars.top() == c) break;
				j++;
				cars.push(j);
			}
			if(cars.top() == c) {
				cars.pop();
			}
			
		}
        if(cars.size() == 0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}

int main() {
	for(;;) {
		cin>>N;
		if(N == 0) break;

		xuly();
		cout<<endl;
	}
}