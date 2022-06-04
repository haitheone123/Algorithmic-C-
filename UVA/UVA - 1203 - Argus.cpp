#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void xuly(){
    char s[20];
	ll qnum, p, n;
	priority_queue<pair<ll, pair<ll, ll> >,
			vector<pair<ll, pair<ll, ll> > >,
			greater<pair<ll, pair<ll, ll> > > > pq;

	while (cin>>s, strcmp("#", s)) {
		cin>>qnum>>p;
		pq.push(pair<ll, pair<ll, ll> >(p, pair<ll, ll>(qnum, p)));
	}

	cin>>n;
	while (n--) {
		pair<ll, pair<ll, ll> > pr = pq.top();
		pq.pop();

		cout<<pr.second.first<<endl;

		pr.first += pr.second.second;
		pq.push(pr);
	}

}

int main() {
	xuly();
}