#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

void xuly(){
    ll n,l;
    cin>>n>>l;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];   
    }
    sort(a.begin(),a.end());
    ll penalty = 0, sum = 0; cnt = 0;
    for(ll i=0;i<n;i++){
        if(penalty+a[i]>l){
            break;
        }
        else{
            cnt++;
            penalty += a[i];
            sum += penalty;
        }
    }
    cout<<cnt<<' '<<sum<<endl;
}
int main(){
    xuly();
}