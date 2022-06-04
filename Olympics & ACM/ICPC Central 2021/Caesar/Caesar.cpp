#include <bits/stdc++.h>

using namespace std;
int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	freopen("C:\\Users\\ASUS\\GoogleDriver_pmtuanAtDut.udn.vn\\OLP\\OLPICPC2021\\DeICPCMienTrung\\PhamMInhTuan\\xx. Caesar\\data\\secret\\8.in","r",stdin);
	freopen("C:\\Users\\ASUS\\GoogleDriver_pmtuanAtDut.udn.vn\\OLP\\OLPICPC2021\\DeICPCMienTrung\\PhamMInhTuan\\xx. Caesar\\data\\secret\\8.ans","w",stdout);
	string s;
	int k;
	cin >> s;
	//cout << s;
	cin >> k;
	while (k-->0){
		int n,x,y;
		cin >> n >> x >> y;
		for (int i=x-1; i<y; i++){
			s[i] = 'A' + ((s[i] - 'A' + n) % 26);
		}
	}
	cout << s;
	return 0;
}
