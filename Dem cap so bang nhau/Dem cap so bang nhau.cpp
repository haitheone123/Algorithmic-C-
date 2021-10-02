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
void dem_so_cap(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) count++;
	}
	cout << " So cap so lien tiep bang nhau trong mang la " << count << endl;
}

int main() {
	int n, a[1000];
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	dem_so_cap(a, n);




}