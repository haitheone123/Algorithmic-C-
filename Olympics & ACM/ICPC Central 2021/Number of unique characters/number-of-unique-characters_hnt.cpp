#include <bits/stdc++.h>

#define N 100005

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> pos(26, vector<int>());
    for (int i = 0; i < 26; i++) {
        pos[i].push_back(-1);
    }
    for (int i = 0; i < s.size(); i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        pos[i].push_back(s.size());
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < pos[i].size() - 1; j++) {
            ans += 1LL * (pos[i][j] - pos[i][j - 1]) * (pos[i][j + 1] - pos[i][j]);
        }
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}