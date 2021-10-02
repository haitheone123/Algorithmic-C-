#include <iostream>
using namespace std;
void hinh_chu_nhat_dac(int m,int n) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << " * ";
		}
		cout << endl;
	}
}

void hinh_chu_nhat_rong(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
				cout << " * ";
			}
			else {
				cout << "   ";

			}

		}
		cout << endl;
	}
}

void tam_giac_vuong_can(int m) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " * ";
		}
		cout << endl;
	}
}

void tam_giac_can(int m) {
	int i, j;
	for (i = 1; i <= m; i++) {
		for (int j = 1; j < 2 * m; j++) {
			if (abs(m - j) <= (i - 1)) {
				cout << " * ";
			}
			else {
				cout << "   ";
			}
			
		}
		cout << endl;
	}
		
		 
		
}

	int main() {
	
	int k, m, n, l;
	cout << " Nhap vao chieu dai cua hinh chu nhat " << endl;
	cin >> m;
	cout << " Nhap vao chieu rong cua hinh chu nhat " << endl;
	cin >> n;  
	cout << " Nhap vao canh goc vuong cua tam giac vuong can  " << endl;
	cin >> k;
	cout << " Nhap vao chieu cao cua tam giac can " << endl;
	cin >> l;
	hinh_chu_nhat_dac(m, n);
	cout << endl;
	hinh_chu_nhat_rong(m, n);
	cout << endl;
	tam_giac_vuong_can (k);
	cout << endl;
	tam_giac_can(l); 
}