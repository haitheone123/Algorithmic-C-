//Bài 11. Nhập mảng(a, N) gồm các số nguyên dương.Nhập số X.
//Xác định vị trí của phần tử trên a có giá trị gần với X nhất.
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang : " << endl;
		cin >> a[i];
	}
}

void hieu_so(int a[], int n,int x) {
	int  b[100];
	 for (int i = 0; i < n; i++) {
		 if (a[i] > x) {
			 b[i] = a[i] - x;
		 }
		 else if (a[i] < x) {
			 b[i] = x - a[i];
		 }
		 else {
			 b[i] = 0;
		 }
	 }
	 int min = b[0];
		for (int i = 1; i < n; i++)
		{
			if (b[i] < min) {
				min = b[i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (b[i] == min) {
				cout << " Phan tu gan voi x nhat nam o vi tri thu " << i + 1 << endl;
			}
		}

	}

int main() {
	int n, a[1000], x;
	cout << "Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	cout << " Nhap vao gia tri x " << endl;
	cin >> x;
	nhap_mang(a, n);
	hieu_so(a, n, x);




}

















