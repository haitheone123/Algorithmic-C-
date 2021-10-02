#include<iostream>
#include<cmath>
using namespace std;
void chia_bim_bim(int y, int k, int n) {
	int count = 0;
	for (int i = 0; i <= n - y; i++) {
		if ((i + y) % k == 0) {
			count ++;
			cout << i << " ";

		}
	}
	if (count == 0) {
		cout << "-1" << endl;
	}

}
int main() {
	int y, k, n;
	cin >> y >> k >> n;
	chia_bim_bim(y, k, n);

}