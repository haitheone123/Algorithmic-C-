#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	string res;
    	res.clear();
    	while(n>1){
    		if(n & 1){
    			res.push_back('R');
			}
			else {
				res.push_back('L');
			}
			n >>= 1ll;
		}
		reverse(res.begin(),res.end());
		cout<<res<<endl;
	}
	return 0;
}