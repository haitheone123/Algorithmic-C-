#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int n,m;
bool visited[1000000];
vector<int> v[1000000];

long long fact(int a){
    long long p=1;
    for(int i=2;i<=a;i++){
        p*=i;
        p=p%MOD;
    }
    return p;
}

int dfs(int s) {
    stack <int> S;
    int count=0;
    S.push(s);
    visited[s]=true;
    while(!S.empty()) {
        count++;
        int v2=S.top();
        S.pop();
        for (int i = 0; i <v[v2].size(); i++){
            if(visited[v[v2][i]]==false){
               visited[v[v2][i]]=true;
               S.push(v[v2][i]);
            }
        }
    }
    return count;
}

int main(){
    //freopen("data/2.in", "r",stdin);
    //freopen("data/10.out", "w", stdout);
    int x,y;
    cin >> n >> m;
    vector<int> ss;

    for (int i = 0; i < m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        visited[i]=false;
    }

    int conn=0;

    for (int i = 0; i < n; i++){
        if(visited[i]==false){
            ss.push_back(dfs(i));
            conn++;
        }
    }
    long long power=0;

    for(int i=0;i<conn;i++){
        //cout<<ss[i]<< " ";
        if (ss[i] > 2) {
            power += fact(ss[i]);
            power = power % MOD;
        }
    }

    //cout << endl;
    cout << power << endl;
    return 0;
}
