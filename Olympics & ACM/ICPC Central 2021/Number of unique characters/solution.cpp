#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void solve() {
    int tc;
    cin>>tc;
    while(tc--) {
        string s;
        cin>>s;
        int n = s.size();

        // mp: chua tat ca vi tri xuat hien cua ki tu c, va 2 phan tu -1, n
        unordered_map<char, vector<int>> mp;

        for(int i=0; i<n; i++) {
            char c = s[i];
            if(!mp.count(c)) mp[c].push_back(-1);
            mp[c].push_back(i);
        }

        ll res = 0;
        // xet tat ca ki tu co trong xau
        for(auto p:mp) {
            vector<int> v = p.second;
            // them -1 vao dau, n vao cuoi de de tinh toan
            v.push_back(n);
            // voi moi vi tri xuat hien cua ki tu c
            // ket qua bang tich do dai cua hai nua khong cua c
            // vd: ...A....
            // ket qua se la (3+1)*(4+1) (co 3 ki tu khac A ben trai, 4 ki tu khac A ben phai)
            for(int i=1; i<v.size()-1; i++) {
                res += 1LL*(v[i]-v[i-1])*(v[i+1]-v[i]);
            }
        }

        cout<<res<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
