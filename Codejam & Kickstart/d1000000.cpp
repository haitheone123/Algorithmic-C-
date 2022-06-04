#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void xuly(){
    ll t;
    cin>>t;
    ll x=t;
    while(t--){
        cout<<"Case #"<<x-t<<": ";
        ll n,count=0,res=0;
        cin>>n;
        vector<ll>s(n);
        for(ll i=0;i<n;i++){
            cin>>s[i];
        }
       
        sort(s.begin(),s.end());
        for(ll i=0;i<n;i++){
            count++;
            if(count>s[i]){
                count--;
                continue;
            }
            else{
                res++;
            }
        }
        cout<<res<<endl;
    }
}
int main(){
	xuly();
}