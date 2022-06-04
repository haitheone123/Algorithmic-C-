#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void xuly(){
    ll n;
    cin>>n;
    vector<char>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll count1 = (n-11)/2, count2 =(n-11)/2,id;
    for(ll i=0;i<n;i++){
        if(a[i]=='8'){
            count1--;
            if(count1==-1){
                id=i;
                break;
            }

        }
    }
    if(count1>-1){
        cout<<"NO"<<endl;
        return;
    }
    if((id-(n-11)/2)>(n-11)/2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES";
}

int main(){
    xuly();
}