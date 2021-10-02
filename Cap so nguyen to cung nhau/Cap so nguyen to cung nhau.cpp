#include <iostream> 
using namespace std;
int songuyentocungnhau(int m, int n) {
	if (m < n) {
		for (int k = 2; k <= m; k++) {
			if (m % k == 0 && n % k == 0) {
				return 0;
			}
			return 1;
		}
	}
	
	else if (m >= n) {
		for (int k = 2; k <= n; k++) {
			if (m % k == 0 && n % k == 0) {
				return 0;
			}
			return 1;
		}

	}
	
}





int main() { 
	int m, n;
	cout << " Nhap vao hai so nguyen m,n " << endl;
	cin >> m >> n; 
	if (songuyentocungnhau(m, n) == 1) {
		cout << " m va n la hai so nguyen to cung nhau " << endl;
	}
	else {
		cout << " m va n khong phai la hai so nguyen to cung nhau " << endl;
	}

}