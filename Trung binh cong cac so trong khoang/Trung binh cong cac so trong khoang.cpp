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

void trung_binh_cong(int a[], int n,int b, int c) {
	int sum = 0;
	int count = 0;
	if (b <= c) {
		for (int i = 0; i < n; i++) {
			if (a[i] >= b && a[i] <= c) {
				sum = sum + a[i];
				count++;
			}
		}
		cout << " Trung binh cong cua cac phan tu trong khoang tu b den c la " << (sum / count) << endl;

	}
	if (b >= c) {
		for (int i = 0; i < n; i++) {
			if (a[i] <= b && a[i] >= c) {
				sum = sum + a[i];
				count++;
			}
		}
		cout << " Trung binh cong cua cac phan tu trong khoang tu c den b la " << (sum / count) << endl;

	}

}


int main() {
	int n, a[1000], b, c;
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	cout << " Nhap vao b va c " << endl;
	cin >> b >> c;
	nhap_mang(a, n);
	trung_binh_cong(a, n, b, c);


}