#include<iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang " << endl; 
		cin >> a[i];

	}
}
void dem_so_lan_xuat_hien(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) count++;

	}
	cout << " So lan xuat hien cua x trong mang la " << count << endl;
}
int main() {
	int n, x, a[1000];
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	cout << " Nhap vao gia tri x " << endl;
	cin >> x;
	nhap_mang(a, n);
	dem_so_lan_xuat_hien(a, n, x);




}
