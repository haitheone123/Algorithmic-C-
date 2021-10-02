#include<iostream>
#include<cmath>
using namespace std;
void median_max(int t) {
	for (int i = 0; i < t; i++) {
		int l, s, mid;
		cin >> l >> s;
		mid = (l / 2) + (l % 2);
			cout << (s / (l - (mid - 1))) << endl;


	}
}
int main() {
	int t;
	cin >> t;
	median_max(t); 


}