#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void xuly() {
	set<string>andydict;
	string s;
	while (cin >> s) {
		string temp = "";
		int p = 0;
		for (int i = 0; i <s.length(); i++) {
			if (isalpha(s[i])) {
				p = 1;
				if (s[i] >='A'&&s[i] <='Z') {
					s[i] = s[i] + 32;
				}
				temp = temp + s[i];
			} 
			else {
				if (p) {
					andydict.insert(temp);
					p = 0;
					temp = "";
				}
			}
		}
		if (p){
			andydict.insert(temp);
		}
			
	}
	for (set<string>::iterator it = andydict.begin(); it != andydict.end(); it++)
		cout << *it << endl;
}
int main() {
	xuly();
}