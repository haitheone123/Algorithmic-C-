#include <iostream> ;
using namespace std;
void nhap_ham(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao so nguyen thu " << i + 1 << " cua mang " << endl;
		cin >> a[i];
	}
}


void xuat_ham(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " " << a[i];
	}
}


void bubble_sort(int a[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j - 1] > a[j]) {
				// doi cho a[j] va a[j-1]
				temp = a[j];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}






int main() {
	int a[100];
	int n;
	cout << "Nhap vao so cac so hang cua mang " << endl;
	cin >> n;
	nhap_ham(a, n);
	bubble_sort(a, n);
	xuat_ham(a, n);






}