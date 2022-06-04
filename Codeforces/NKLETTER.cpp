#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string sb,se;
int lengB, lengE;
bool isValid (int pos) {
	int leng1 = lengB - pos ;
	if(leng1 > lengE) {
		return false;
	}
	for(int i=0; i<leng1; i++) {
		if(sb[i+pos]!=se[i]) {
			return false;
		}
	}
	return true;
}
void xuly() {

	cin>>sb;
	cin>>se;
	lengB = sb.length();
	lengE = se.length();
	int pos=0;
	for( pos=0; pos<lengB; pos++) {
		if(isValid(pos)) break;
	}
	int minLeng = pos + lengE;
	cout<<minLeng<<endl;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    xuly();
}
