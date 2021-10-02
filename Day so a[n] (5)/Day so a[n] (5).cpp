//Nhập số liệu  cho dãy số nguyên  a0, a1, ..., an - 1   và  một giá trị thực  x.
//Giả sử dãy  a đã được sắp xếp theo thứ tự tăng dần.
//Hãy chèn  giá trị  x vào dãy  a sao cho vẫn giữ được tính sắp xếp của mảng.
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
void nhap_mang(float a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang : " << endl;
		cin >> a[i];
	}
}
void chen_so_va_xuat_mang(float a[], int n, float x) {
	int i = n - 1;
		
	while (i > 0 && a[i] > x){
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = x;
	n++;
	for (int i = 0; i < n; i++) {
		cout << " " << a[i];
	}

}


int main() {
	int n;
	float a[1000], x;
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	cout << " Nhap vao gia tri x " << endl;
	cin >> x;
	nhap_mang(a, n);
	chen_so_va_xuat_mang(a, n, x);
	
	


}
