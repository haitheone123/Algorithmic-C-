//Beginner Free Contest
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void xuly(){
    string s;
    cin>>s;
    vector<char>x,y;
    for(char i:s){
        if(isupper(i)) x.push_back(i);
        if(islower(i)) y.push_back(i);
    }
    sort(x.begin(),x.end());
    reverse(x.begin(),x.end());
    sort(y.begin(),y.end());
    reverse(y.begin(),y.end());
    for(char i:x) cout<<i;
    for(char j:y) cout<<j;
}
int main(){
    xuly();
}