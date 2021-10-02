#include <iostream> 
using namespace std;

void nhap_mang (int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Nhap vao phan tu thu " << i + 1 << " cua mang " << endl;
		cin >> a[i];
	}
}
 
void tim_kiem(int a[], int n, int x) {
	int danhDau = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << " Phan tu thu " << i+1 << " mang gia tri "<< x << endl;
			danhDau = 1;
		}
	}
	if (danhDau != 1) {
		cout << " Khong ton tai phan tu mang gia tri " << x << endl;
	}
	
}



	  
	

int main() {
	int a[100], n;
	cout << " Nhap vao so phan tu cua mang " << endl;
	cin >> n;
	int x;
	cout << " Nhap vao gia tri x " << endl;
	cin >> x;
	nhap_mang(a, n);
	tim_kiem(a, n, x); 


}