//Bài 17.	 Nhập số liệu  cho dãy số nguyên  a0, a1, ..., an - 1.
//Kiểm tra xem dãy đã được sắp xếp theo thứ tự tăng dần hay không.
//Nếu không hãy chỉ ra vị trí phần tử đầu tiên làm mất tính chất được sắp của dãy.

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang : " << endl;
		cin >> a[i];
	}
}

void kiem_tra(int a[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		temp = a[i] - a[i + 1];
		if (temp > 0) {
			cout << " Phan tu dau tien lam mat tinh tang dan cua day la phan tu thu " << i+2 << endl;
			break;
		}
		else continue;

	}


}
int main() {
	int n, a[100];
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	kiem_tra(a, n);

}