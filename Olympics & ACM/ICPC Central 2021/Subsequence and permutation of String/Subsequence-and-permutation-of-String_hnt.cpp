#include <bits/stdc++.h>

#define N 100005

using namespace std;

string s, t;
int suf[N][26];
int cnt[26];
vector<int> pos[26];

bool check(int p) {
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > suf[p][i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> s >> t;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            suf[i][j] = suf[i + 1][j];
        }
        suf[i][s[i] - 'a']++;
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < t.size(); i++) {
        cnt[t[i] - 'a']++;
    }
    for (int i = 0, p = -1; i < t.size(); i++) {
        bool ok = 1;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0) {
                while (pos[j].size() > 0 && pos[j].back() <= p) {
                    pos[j].pop_back();
                }
                if (pos[j].size() > 0 && check(pos[j].back())) {
                    cout << char(j + 'a');
                    p = pos[j].back();
                    cnt[j]--;
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) {
            cout << -1;
            break;
        }
    }
}