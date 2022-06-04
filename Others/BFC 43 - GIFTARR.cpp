#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void xuly(){
    ll t,n,x,h;
    cin>>t;
    while(t--){
        cin>>n>>x;
        ll maxi = -10000000009;
        ll mini =  10000000009;
        for(ll i=0;i<n;i++){
            cin>>h;
            maxi = max(maxi,h);
            mini = min(mini,h); 
        }
        cout<<(mini <= x && x <= maxi ? "YES\n" : "NO\n");
    }
}

int main(){
    xuly();
}