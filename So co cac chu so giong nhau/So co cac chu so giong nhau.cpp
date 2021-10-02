#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int so_dac_biet(int n) {
	int i, j;
	while (n > 0) {
		i = n % 10;
		n = n / 10;
		j = n % 10;
		if (i != j) {
			return 0;
		}

	}
	return 1;

}
int main () {
	int n;
cout << " Nhap vao so nguyen n " << endl;
cin >> n;
for (int i = 1; i <= n; i++) {
	if (so_dac_biet(i) == 1) {
		cout << " " << i;
	}
}



}