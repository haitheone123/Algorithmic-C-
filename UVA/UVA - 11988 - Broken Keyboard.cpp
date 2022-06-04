#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void xuly(){
    string s;
    list<char>beiju;
    list<char>::iterator it;
    while(cin>>s){
        beiju.clear();
        it = beiju.begin();
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='[')
                it = beiju.begin();
            if(s[i]==']')
                it = beiju.end();
            if(s[i]!='[' && s[i]!=']')
                beiju.insert(it,s[i]);
        }
        for(it=beiju.begin();it!=beiju.end();it++){
            cout<<*it;
        }
        cout<<endl;
    }
}

int main(){
    xuly();
}