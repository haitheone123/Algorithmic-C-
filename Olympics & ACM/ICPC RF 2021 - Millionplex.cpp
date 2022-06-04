#include <bits/stdc++.h>

using namespace std;
const long long m = 1e9 + 7ll;
string s;
long long res = 0;
long long a[1000005];
long long x[1000005];
long long exp(long long a, long long b){
    long long res = 1;
    while( b){
        if( b&1){
            res = (res*a)%m;
        }
        b >>= 1;
        a = (a*a)%m;
    }
    return res;
}
long long pre1[1000005];
long long pre2[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++){
        a[i+1] = s[i]-'0';
    }
    x[n] = a[n];
    x[n+1] = 0;
    for(int i = n-1; i >= 1; i--){
        x[i] = a[i]*exp(10,n-i)%m + x[i+1];
        if( x[i] >= m ){
            x[i] -= m;
        }
    }
    pre1[0] = 0;
    for(int i = 1; i <= n; i++){
        pre1[i] = pre1[i-1] + x[i];
        if( pre1[i] >= m ){
            pre1[i] -= m;
        }
    }
    pre2[0] = 0;
    for(int i = 1; i <= n; i++){
        pre2[i] = (pre2[i-1] + x[i]*x[i]%m);
        if( pre2[i] >= m ){
            pre2[i] -= m;
        }
    }
    for(int i = 1; i <= n; i++){
        res += (i*x[i+1]%m*x[i+1]%m + pre2[i] + m- 2*x[i+1]%m*pre1[i]%m )*exp(10,2*(n-i)*(m-2))%m;
        res %= m;
    }
    cout << res << "\n";
    return 0;
}