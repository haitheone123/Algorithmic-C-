#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang " << endl;
		cin >> a[i];
	}
}
void so_lon_thu_hai(int a[], int n) {
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < a[i + 1]) {
			max1 = a[i + 1];
		}
	}
	for (int i = 0; i < n; i++) {
		if (max1 == a[i]) continue;
		else if (max2 < a[i]) {
			max2 = a[i];
		}

	}
	cout << " Phan tu lon thu hai cua mang la " << max2 << endl;

}
int main() {
	int n, a[1000];
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	so_lon_thu_hai(a, n);

}
