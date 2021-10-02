#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;



void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao so nguyen thu " << i + 1 << " cua mang " << endl;
		cin >> a[i + 1];
	}
}




void Bubble_Sort(int a[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j >= i + 1; j--) {
			if (a[j - 1] > a[j]) {
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}


void xuat_mang(int a[], int n) {
	cout << " Mang sau khi sap xep theo thu tu tang dan la " << endl;
	for (int i = 0; i < n; i++) {
		cout <<" " << a[i+1];

	}
} 

int main() {
	int n, a[1000];
	cout << " Nhap vao so cac phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	Bubble_Sort(a, n);
	xuat_mang(a, n);


}