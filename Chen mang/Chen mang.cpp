//Bài 14. Nhập 2 mảng(a, N) và(b, M) và số nguyên p(0≤p < N).
//Hãy chèn mảng b vào vị trí p của a.
#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
void nhap_mang(int a[], int n,int b[],int m) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang 1 " << endl;
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang 2 " << endl;
		cin >> b[i];
	}
}

void chen_mang(int a[], int n, int b[], int m, int p) {
	int c[1000];
	for (int i = 0; i < p; i++)
	{
		c[i] = a[i];
	}
	for (int i = p; i < m + p; i++)
	{
		c[i] = b[i - p];
	}
	for (int i = p + m; i < n + m; i++)
	{
		c[i] = a[i - m];
	}
	for (int i = 0; i < n + m; i++)
	{
		cout <<" " << c[i];
	}
}



int main() {
	int a[100], b[100], m, n, p;
	cout << " Nhap vao so phan tu cua mang 1 " << endl;
	cin >> n;
	cout << " Nhap vao so phan tu cua mang 2 " << endl;
	cin >> m;
	cout << " Nhap vao vi tri p " << endl;
	cin >> p;
	nhap_mang(a, n, b, m);
	chen_mang(a, n, b, m, p);





}
 

















