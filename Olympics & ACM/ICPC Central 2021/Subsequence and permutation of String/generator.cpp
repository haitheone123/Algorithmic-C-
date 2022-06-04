#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_map<char, int> countChars(string &s) {
    unordered_map<char, int> result;
    for(char c:s) result[c]++;
    return result;
}

void solve(ifstream &is, ofstream &os) {
    string s, t;
    is>>s>>t;

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
        os<<-1;
        return;
    }

    string res = "";
    for(char c:st) res += c;
    os<<res;

    is.close();
    os.close();
    return;
}

string to_name(int i) {
    string s = to_string(i);
    while(s.size() < 2) s = "0" + s;
    return s;
}

int from = 17;
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

void randgen(vector<vector<int>> sz){
    for(vector<int> v:sz) {
        int ns = v[0], nt = v[1];
        string s = "", t = "";
        ofstream os("data/" + to_name(from++) + ".in");
        for(int i=0; i<ns; i++) s += ('a' + v[2] + rand()%(v[3]-v[2]+1));
        for(int i=0; i<nt; i++) t += ('a' + v[4] + rand()%(v[5]-v[4]+1));

        os<<s<<"\n"<<t;
        os.close();
    }
}

void pergen(vector<int> sz) {
    for(int n:sz) {
        ofstream os("data/" + to_name(from++) + ".in");
        string s = "";
        for(int i=0; i<n; i++) s += 'a' + rand()%26;
        os<<s<<"\n";
        random_shuffle(s.begin(), s.end());
        os<<s;
        os.close();
    }

    for(int n:sz) {
        ofstream os("data/" + to_name(from++) + ".in");
        string s = "";
        for(int i=0; i<n; i++) s += 'a' + rand()%26;
        os<<s<<"\n";
        random_shuffle(s.begin(), s.end());
        s[rand()%n] = 'a' + rand()%26;
        os<<s;
        os.close();
    }
}

void generator() {
    pergen({50,100,500,1000,1000,10000,100000});
    randgen({
        {100,80,0,1,0,1},
        {100,80,3,4,3,4},
        {1000,500,0,5,0,5},
        {1000,500,0,5,1,5},
        {1000,900,0,5,0,5},
        {1000,900,0,5,1,5},
        {1000,900,16,17,16,17},
        {1000,900,16,17,16,17},
        {1000,500,10,10,10,10},
        {1000,1000,17,17,17,17},
        {1000,1000,18,18,18,18},
        {1000,500,0,25,1,24},
        {1000,500,0,25,1,24},
        {1000,500,7,14,7,14},
        {1000,500,18,20,18,20},
        {1000,700,0,25,1,24},
        {1000,900,0,25,1,24},
        {100000,90000,0,25,0,25},
        {100000,90000,5,10,6,10},
        {100000,90000,9,10,9,10},
        {100000,90000,9,10,10,10}
    });
}
