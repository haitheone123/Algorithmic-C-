#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void solve(ifstream &is, ofstream &os) {
    int tc;
    is>>tc;
    while(tc--) {
        string s;
        is>>s;
        int n = s.size();

        // mp: chua tat ca vi tri xuat hien cua ki tu c, va 2 phan tu -1, n
        unordered_map<char, vector<int>> mp;

        for(int i=0; i<n; i++) {
            char c = s[i];
            if(!mp.count(c)) mp[c].push_back(-1);
            mp[c].push_back(i);
        }

        ll res = 0;
        for(auto p:mp) {
            vector<int> v = p.second;
            v.push_back(n);

            for(int i=1; i<v.size()-1; i++) {
                res += 1LL*(v[i]-v[i-1])*(v[i+1]-v[i]);
            }
        }

        os<<res<<"\n";
    }
    is.close();
    os.close();
}

string to_name(int i) {
    string s = to_string(i);
    while(s.size() < 2) s = "0" + s;
    return s;
}

int from = 5;
void forsolve() {
    for(int i=0; i<from; i++) {
        ifstream is("data/" + to_name(i) + ".in");
        ofstream os("data/" + to_name(i) + ".ans");
        solve(is, os);
    }
}

void generator();

int main()
{
    ios::sync_with_stdio(0);
    srand(time(NULL));
    generator();
    forsolve();
    return 0;
}

void randgen(vector<int> sz) {
    for(int n:sz) {
        ofstream os("data/" + to_name(from++) + ".in");
        os<<"10\n";
        for(int tc=0; tc<10; tc++) {
            string s = "";
            int low = rand()%26;
            int high = rand()%26;
            if(low > high) swap(low, high);
            for(int i=0; i<n; i++) {
                s += 'a' + low +rand()%(high-low+1);
            }
            os<<s<<"\n";
        }
        os.close();
    }
}

void spegen(vector<int> sz) {
    for(int n:sz) {
        ofstream os("data/" + to_name(from++) + ".in");
        os<<"10\n";
        for(int tc=0; tc<10; tc++) {
            string s = "";
            int low = rand()%15;
            int high = low + rand()%4 + 1;
            int nlow = rand()%5;
            for(int i=nlow; i<n; i++) {
                s += 'a' + low;
            }
            for(int i=0; i<nlow; i++) {
                s += 'a' + high;
            }
            random_shuffle(s.begin(), s.end());
            os<<s<<"\n";
        }
        os.close();
    }
}

void generator() {
    randgen({5,5,5,10,10,10,50,50,50,100,1000,1000,100000,100000,100000,100000});
    spegen({10,10,1000,1000,100000,100000,100000});
}
