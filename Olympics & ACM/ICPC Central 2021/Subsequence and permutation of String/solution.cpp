#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_map<char, int> countChars(string &s) {
    unordered_map<char, int> result;
    for(char c:s) result[c]++;
    return result;
}

void solve() {
    string s, t;
    cin>>s>>t;

    // mt: so luong tung ki tu trong xau t
    // ms: so luong tung ki tu con lai trong xau s
    unordered_map<char, int> mt = countChars(t), ms = countChars(s);

    // mc: so luong tung ki tu trong stack
    unordered_map<char, int> mc;

    // duy tri mot stack la xau con cua s va co thu tu tu dien nho nhat
    vector<char> st;

    for (char c:s) {
        // neu trong stack da co du ki tu c can thiet thi bo qua
        if (mc[c] >= mt[c]) {
            ms[c]--;
            continue;
        }

        // neu top > c va van con du so luong ki tu top de xay dung ket qua thi loai bo top
        while(st.size() > 0 && st.back() > c && mc[st.back()] + ms[st.back()] > mt[st.back()]) {
            mc[st.back()]--;
            st.pop_back();
        }
        // them c vao dinh stack.
        st.push_back(c);
        mc[c]++;

        //giam so luong ki tu c con lai.
        ms[c]--;
    }

    // neu khong lay du so ki tu cho t thi tra ve -1
    if(st.size() != t.size()) {
        cout<<-1;
        return;
    }

    string res = "";
    for(char c:st) res += c;
    cout<<res;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
