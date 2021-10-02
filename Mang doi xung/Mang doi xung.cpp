#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
void nhap_mang(int a[], int n) {
	for (int i = 1; i <= n; i++) {
		cout << " Nhap vao phan tu thu " << i << " cua mang " << endl;
		cin >> a[i];
	}
}
int day_doi_xung(int a[], int n) {
	for (int i = 1; i <= n; i++) {
		if (a[i] !=a[n - i + 1]) return 0;
	}
	return 1;

}
int main() {
	int n, a[1000];
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	if (day_doi_xung(a, n) == 1) {
		cout << " Day la mang doi xung " << endl;
	}
	else {
		cout << " Day khong phai la mang doi xung " << endl;
	}
}