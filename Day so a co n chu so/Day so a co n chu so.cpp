#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao so nguyen thu " << i + 1 << " cua mang " << endl;
		cin >> a[i];

	}
}
void so_lon_nhat(int a[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i + 1] > a[i]) {
			max = a[i + 1];
		}
	}
	cout << " So nguyen lon nhat trong mang la " << max << endl;

}
int main() {
	int n, a[1000];
	cout << " Nhap vao so cac so nguyen cua mang " << endl;
	cin >> n;
	nhap_mang(a, n);
	so_lon_nhat(a, n);


}