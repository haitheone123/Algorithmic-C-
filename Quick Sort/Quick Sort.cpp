#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
int a[1000];
int n;
void nhap_mang (a[], n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang " << endl;
		cin >> a[i + 1];
	}
}
void quick(int left, int right) {
	int i, j, x, y;
	i = left; j = right;
	x = a[left];
	do {
		while (a[i] < x && i < right) i++;
		while (a[j] > x && j > left) j--;
		if (i <= j) {
			y = a[i];
			a[i] = a[j];
			a[j] = y;
			i++; j--;
		}
	}
	while (i <= j) {
		if (left < j) {
			quick(left, j);
		}
		if (i < right) {
			quick(i, right);
		}
	}
}

void quick_sort(a,n[]) {
	quick(0, n - 1);
} 

void xuat_mang(a[],n) {
	for (int i = 0; i < n; i++) {
		cout << " " << a[i + 1];
	}
} 


int main() {
	cout << " Nhap vao so cac phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a,n);
	quick_sort(a,n);
	xuat_mang(a,n);
}